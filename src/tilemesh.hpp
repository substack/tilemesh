#ifndef TILEMESH_HPP
#define TILEMESH_HPP
#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <tilemesh_features.hpp>
#include <vendor/o5mdecoder.hpp>
#include <vendor/earcut.hpp>
#include <endian.h>

namespace tilemesh {

const char magic[11] = "TILEMESH\n\0";
const char version[256] = "1.0.0\n\0";
static char tmp[256];
static double ptx[512];
static double pty[512];

enum STAGES {
  MAGIC_STAGE = 0,
  VERSION_STAGE = 1,
  PTLEN_STAGE = 2,
  PTDATA_STAGE = 3,
  LINELEN_STAGE = 4,
  LINEDATA_STAGE = 5,
  LINEPT_STAGE = 6,
  AREALEN_STAGE = 7,
  AREADATA_STAGE = 8,
  AREAPT_STAGE = 9,
  AREACELL_STAGE = 10,
  FINAL_STAGE = 11
};

template<class T> struct ListItem {
  T *data;
  ListItem<T> *next;
  ListItem (T *_data) {
    data = _data;
    next = NULL;
  }
};
template<class T> struct List {
  size_t length;
  ListItem<T> *first;
  ListItem<T> *last;
  List () {
    length = 0;
    first = NULL;
    last = NULL;
  }
  void push (T* p) {
    ListItem<T> *item = new ListItem<T>(p);
    if (!first) first = item;
    if (last) {
      last->next = item;
    }
    last = item;
    length++;
  }
};
struct Point {
  uint64_t id;
  uint16_t type;
  float lon, lat;
  static const size_t size = 18;
  Point (uint64_t _id, uint16_t _type, float _lon, float _lat) {
    id = _id;
    type = _type;
    lon = _lon;
    lat = _lat;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    // assumes integer byte order is the same as floating point byte order
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lon));
    pos += sizeof(float);
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lat));
    pos += sizeof(float);
    return pos;
  }
};
struct Position {
  float lon, lat;
  static const size_t size = 8;
  Position (float _lon, float _lat) {
    lon = _lon;
    lat = _lat;
  }
  bool operator==(Position &p) {
    return lon == p.lon && lat == p.lat;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lon));
    pos += sizeof(float);
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lat));
    pos += sizeof(float);
    return pos;
  }
};
struct Line {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  static const size_t size = 12;
  Line (uint64_t _id, uint16_t _type, List<Position> *poslist) {
    id = _id;
    type = _type;
    positions = poslist;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) positions->length);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Cell {
  uint16_t i;
  uint16_t j;
  uint16_t k;
  static const size_t size = 6;
  Cell (uint16_t _i, uint16_t _j, uint16_t _k) {
    i = _i;
    j = _j;
    k = _k;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint16_t*)(dst+pos) = htobe16(i);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16(j);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16(k);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Area {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  List<Cell> *cells;
  static const size_t size = 14;
  Area (uint64_t _id, uint16_t _type,
  List<Position> *plist, List<Cell> *clist) {
    id = _id;
    type = _type;
    positions = plist;
    cells = clist;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) positions->length);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) cells->length);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Data {
  List<Point> points;
  List<Line> lines;
  List<Area> areas;
  Data () {
  }
};
void triangulate (List<Cell> *outclist, List<Position> *inplist) {
  std::vector<std::vector<std::array<float,2>>> polygon;
  std::vector<std::array<float,2>> first;
  polygon.push_back(first);
  ListItem<Position> *ipos = inplist->first;
  std::array<float,2> apt;
  while (ipos != NULL) {
    apt = { ipos->data->lon, ipos->data->lat };
    polygon[0].push_back(apt);
    ipos = ipos->next;
  }
  std::vector<uint16_t> cells = mapbox::earcut<uint16_t>(polygon);
  std::array<float,2> *pt;
  size_t len = cells.size();
  for (size_t i = 0; i < len; i+=3) {
    outclist->push(new Cell(cells[i+0], cells[i+1], cells[i+2]));
  }
}
size_t find_feature_kv (Features *features, char *key, char *value) {
  FeaturesIterator ti;
  size_t i,j;
  for (i = 0; key[i] != 0; i++) tmp[i] = key[i];
  tmp[i++] = '.';
  for (j = 0; value[j] != 0; j++) tmp[i++] = value[j];
  tmp[i++] = 0;
  ti = features->find(tmp);
  if (ti == features->end()) {
    ti = features->find(key);
    if (ti == features->end()) return 0;
    else return ti->second;
  }
  return ti->second;
}
size_t find_feature (Features *features, o5mdecoder::Doc *doc) {
  size_t ftype;
  char *key, *value;
  while (doc->getTag(&key,&value)) {
    ftype = find_feature_kv(features, key, value);
    if (ftype > 0) return ftype;
  }
  return 0;
}
struct o5m {
  char *data, *dbuf, *table;
  o5mdecoder::Decoder *decoder;
  uint64_t ref;
  std::map<uint64_t,Position*> nodes;
  std::map<uint64_t,Position*>::const_iterator ipt;
  Features features;
  Data tdata;
  Position *pos;
  Point *pt;
  Area *area;
  Line *line;
  List<Position> *poslist;
  List<Cell> *aclist;
  ListItem<Point> *ipoint;
  ListItem<Position> *ipos;
  ListItem<Cell> *icell;
  ListItem<Line> *iline;
  ListItem<Area> *iarea;

  size_t readpos, readnum;
  uint16_t readstage;
  o5m () {
    dbuf = (char*) malloc(16384);
    table = (char*) malloc(256*15000);
    decoder = new o5mdecoder::Decoder(dbuf,16384,table);
    load_features(&features);
    readpos = 0;
    readstage = 0;
  }
  void write (char *data, size_t len) {
    size_t ftype;
    decoder->write(data, len);
    while (decoder->read()) {
      if (decoder->node) {
        pt = new Point(decoder->node->id,
          find_feature(&features, decoder->node),
          decoder->node->lon, decoder->node->lat);
        tdata.points.push(pt);
        pos = new Position(decoder->node->lon, decoder->node->lat);
        nodes[decoder->node->id] = pos;
      } else if (decoder->way) {
        ftype = find_feature(&features, decoder->way);
        poslist = new List<Position>;
        while (decoder->way->getRef(&ref)) {
          ipt = nodes.find(ref);
          if (ipt == nodes.end()) continue;
          poslist->push(ipt->second);
        }
        if (poslist->length >= 2
        && poslist->first->data == poslist->last->data) { // closed, area
          aclist = new List<Cell>;
          triangulate(aclist,poslist);
          area = new Area(decoder->way->id, ftype, poslist, aclist);
          tdata.areas.push(area);
        } else { // open, line
          line = new Line(decoder->way->id, ftype, poslist);
          tdata.lines.push(line);
        }
      }
    }
  }
  bool read (char *data, size_t len, size_t *outlen) {
    size_t n, pos = 0;
    *outlen = 0;
    while (true) {
      switch (readstage) {
        case MAGIC_STAGE:
          n = strlen(magic);
          if (len-pos < n) return true;
          strncpy(data+pos, magic, n);
          *outlen = (pos += n);
          readstage = VERSION_STAGE;
          break;
        case VERSION_STAGE:
          n = strlen(version);
          if (len-pos < n) return true;
          strncpy(data+pos, version, n);
          *outlen = (pos += n);
          readstage = PTLEN_STAGE;
          break;
        case PTLEN_STAGE: // point length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.points.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = PTDATA_STAGE;
          ipoint = tdata.points.first;
          break;
        case PTDATA_STAGE: // point data
          if (ipoint == NULL) {
            readstage = LINELEN_STAGE;
            continue;
          }
          if (len-pos < Point::size) return true;
          *outlen = (pos += ipoint->data->write(data+pos));
          ipoint = ipoint->next;
          break;
        case LINELEN_STAGE: // line length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.lines.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = LINEDATA_STAGE;
          iline = tdata.lines.first;
          break;
        case LINEDATA_STAGE: // line data
          if (iline == NULL) {
            readstage = AREALEN_STAGE;
            continue;
          }
          if (len-pos < Line::size) return true;
          *outlen = (pos += iline->data->write(data+pos));
          ipos = iline->data->positions->first;
          readstage = LINEPT_STAGE;
          break;
        case LINEPT_STAGE: // line point
          if (ipos == NULL) {
            readstage = LINEDATA_STAGE;
            iline = iline->next;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        case AREALEN_STAGE: // area length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.areas.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = AREADATA_STAGE;
          iarea = tdata.areas.first;
          break;
        case AREADATA_STAGE: // area data
          if (iarea == NULL) {
            readstage = FINAL_STAGE;
            continue;
          }
          if (len-pos < Area::size) return true;
          *outlen = (pos += iarea->data->write(data+pos));
          ipos = iarea->data->positions->first;
          readstage++;
          break;
        case AREAPT_STAGE: // area point
          if (ipos == NULL) {
            readstage = AREACELL_STAGE;
            icell = iarea->data->cells->first;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        case AREACELL_STAGE: // area cell
          if (icell == NULL) {
            readstage = AREADATA_STAGE;
            iarea = iarea->next;
            continue;
          }
          if (len-pos < Cell::size) return true;
          *outlen = (pos += icell->data->write(data+pos));
          icell = icell->next;
          break;
        case FINAL_STAGE:
        default:
          return false;
          break;
      }
    }
  }
};
};
#endif
