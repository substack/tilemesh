#ifndef TILEMESH_H
#define TILEMESH_H
#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <o5mdecoder.h>
#include <tilemesh_features.h>
#include <endian.h>

namespace tilemesh {

const char magic[11] = "TILEMESH\n\0";
const char version[256] = "1.0.0\n\0";
static char tmp[256];
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
  uint32_t i;
  uint32_t j;
  uint32_t k;
  Cell (uint32_t _i, uint32_t _j, uint32_t _k) {
    i = _i;
    j = _j;
    k = _k;
  }
};
struct Area {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  List<Cell> *cells;
  Area (uint64_t _id, uint16_t _type,
  List<Position> *plist, List<Cell> *clist) {
    id = _id;
    type = _type;
    positions = plist;
    cells = clist;
  }
};
struct Data {
  List<Point> points;
  List<Line> lines;
  List<Line> outlines;
  List<Area> areas;
  Data () {
  }
};
void triangulate (List<Position> *outplist, List<Cell> *outclist,
List<Position> *inplist) {
  // TODO
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
  Line *outline;
  List<Position> *poslist;
  List<Position> *aplist;
  List<Cell> *aclist;
  ListItem<Point> *ipoint;
  ListItem<Position> *ipos;
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
          outline = new Line(decoder->way->id, ftype, poslist);
          tdata.outlines.push(outline);
          aplist = new List<Position>;
          aclist = new List<Cell>;
          triangulate(aplist,aclist,poslist);
          area = new Area(decoder->way->id, ftype, aplist, aclist);
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
        case 0:
          n = strlen(magic);
          if (len-pos < n) return true;
          strncpy(data+pos, magic, n);
          *outlen = (pos += n);
          readstage++;
          break;
        case 1:
          n = strlen(version);
          if (len-pos < n) return true;
          strncpy(data+pos, version, n);
          *outlen = (pos += n);
          readstage++;
          break;
        case 2: // point length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.points.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage++;
          ipoint = tdata.points.first;
          break;
        case 3: // point data
          if (ipoint == NULL) {
            readstage++;
            continue;
          }
          if (len-pos < Point::size) return true;
          *outlen = (pos += ipoint->data->write(data+pos));
          ipoint = ipoint->next;
          break;
        case 4: // line length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.lines.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage++;
          iline = tdata.lines.first;
          break;
        case 5: // line data
          if (iline == NULL) {
            readstage = 7;
            continue;
          }
          if (len-pos < Line::size) return true;
          *outlen = (pos += iline->data->write(data+pos));
          ipos = iline->data->positions->first;
          readstage++;
          break;
        case 6: // line point
          if (ipos == NULL) {
            readstage = 5;
            iline = iline->next;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        case 7: // outline length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.outlines.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage++;
          iline = tdata.outlines.first;
          break;
        case 8: // outline data
          if (iline == NULL) {
            readstage = 10;
            continue;
          }
          if (len-pos < Line::size) return true;
          *outlen = (pos += iline->data->write(data+pos));
          ipos = iline->data->positions->first;
          readstage++;
          break;
        case 9: // outline point
          if (ipos == NULL) {
            readstage = 8;
            iline = iline->next;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        default:
          return false;
          break;
      }
    }
  }
};
};
#endif
