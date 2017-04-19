#ifndef TILEMESH_H
#define TILEMESH_H
#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <o5mdecoder.h>
#include <tilemesh_features.h>

namespace tilemesh {

const char magic[10] = "TILEMESH\n";
const char version[256] = "1.0.0\n";
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
  Point (uint64_t _id, uint16_t _type, float _lon, float _lat) {
    id = _id;
    type = _type;
    lon = _lon;
    lat = _lat;
  }
};
struct Position {
  float lon, lat;
  Position (float _lon, float _lat) {
    lon = _lon;
    lat = _lat;
  }
  bool operator==(Position &p) {
    return lon == p.lon && lat == p.lat;
  }
};
struct Line {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  Line (uint64_t _id, uint16_t _type, List<Position> *poslist) {
    id = _id;
    type = _type;
    positions = poslist;
  }
};
struct Outline {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  Outline (uint64_t _id, uint16_t _type, List<Position> *poslist) {
    id = _id;
    type = _type;
    positions = poslist;
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
  List<Area> areas;
  List<Outline> outlines;
  Data () {
  }
};
void triangulate (List<Position> *outplist, List<Cell> *outclist,
List<Position> *inplist) {
  // TODO
}
size_t find_feature_kv (tilemesh::Features *features, char *key, char *value) {
  tilemesh::FeaturesIterator ti;
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
struct o5mWriter {
  char *data, *dbuf, *table;
  o5mdecoder::Decoder *decoder;
  uint64_t ref;
  std::map<uint64_t,tilemesh::Position*> nodes;
  std::map<uint64_t,tilemesh::Position*>::const_iterator ipt;
  tilemesh::Features features;
  tilemesh::Data tdata;
  tilemesh::Position *pos;
  tilemesh::Point *pt;
  tilemesh::Area *area;
  tilemesh::Line *line;
  tilemesh::Outline *outline;
  tilemesh::List<tilemesh::Position> *poslist;
  tilemesh::List<tilemesh::Position> *aplist;
  tilemesh::List<tilemesh::Cell> *aclist;
  o5mWriter () {
    dbuf = (char*) malloc(16384);
    table = (char*) malloc(256*15000);
    decoder = new o5mdecoder::Decoder(dbuf,16384,table);
    load_features(&features);
  }
  void write (char *data, size_t len) {
    size_t ftype;
    decoder->write(data, len);
    while (decoder->read()) {
      if (decoder->node) {
        pt = new tilemesh::Point(decoder->node->id,
          tilemesh::find_feature(&features, decoder->node),
          decoder->node->lon, decoder->node->lat);
        tdata.points.push(pt);
        pos = new tilemesh::Position(decoder->node->lon, decoder->node->lat);
        nodes[decoder->node->id] = pos;
      } else if (decoder->way) {
        ftype = tilemesh::find_feature(&features, decoder->way);
        poslist = new tilemesh::List<tilemesh::Position>;
        while (decoder->way->getRef(&ref)) {
          ipt = nodes.find(ref);
          if (ipt == nodes.end()) continue;
          poslist->push(ipt->second);
        }
        if (poslist->length >= 2
        && poslist->first->data == poslist->last->data) { // closed, area
          outline = new tilemesh::Outline(decoder->way->id, ftype, poslist);
          tdata.outlines.push(outline);
          aplist = new tilemesh::List<tilemesh::Position>;
          aclist = new tilemesh::List<tilemesh::Cell>;
          tilemesh::triangulate(aplist,aclist,poslist);
          area = new tilemesh::Area(decoder->way->id, ftype, aplist, aclist);
          tdata.areas.push(area);
        } else { // open, line
          line = new tilemesh::Line(decoder->way->id, ftype, poslist);
          tdata.lines.push(line);
        }
      }
    }
  }
  bool read (char *data, size_t len, size_t *outlen) {
    return false;
  }
};
};
#endif
