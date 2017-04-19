#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <o5mdecoder.h>
#include <tilemesh.h>
#include <tilemesh_features.h>
#include <string.h>

static char tmp[256];

size_t tilemesh_find_feature (TilemeshFeatures *features, char *key, char *value) {
  TilemeshFeaturesIterator ti;
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

size_t find_feature (TilemeshFeatures *features, o5mdecoder::Doc *doc) {
  size_t ftype;
  char *key, *value;
  while (doc->getTag(&key,&value)) {
    ftype = tilemesh_find_feature(features, key, value);
    if (ftype > 0) return ftype;
  }
  return 0;
}

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  char *dbuf = (char*) malloc(16384);
  char *table = (char*) malloc(256*15000);
  o5mdecoder::Decoder d(dbuf,16384,table);

  uint64_t ref;
  std::map<uint64_t,Tilemesh::Position*> nodes;
  std::map<uint64_t,Tilemesh::Position*>::const_iterator ipt;

  TilemeshFeatures features;
  tilemesh_load_features(&features);
  Tilemesh::Data tdata;
  Tilemesh::Position *pos;
  Tilemesh::Point *pt;
  Tilemesh::Area *area;
  Tilemesh::Line *line;
  Tilemesh::Outline *outline;
  Tilemesh::List<Tilemesh::Position> *poslist;
  Tilemesh::List<Tilemesh::Position> *aplist;
  Tilemesh::List<Tilemesh::Cell> *aclist;

  size_t len, ftype;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    d.write(data, len);
    try {
      while (d.read()) {
        if (d.node) {
          pt = new Tilemesh::Point(d.node->id, find_feature(&features, d.node),
            d.node->lon, d.node->lat);
          tdata.points.push(pt);
          pos = new Tilemesh::Position(d.node->lon, d.node->lat);
          nodes[d.node->id] = pos;
        } else if (d.way) {
          ftype = find_feature(&features, d.way);
          poslist = new Tilemesh::List<Tilemesh::Position>;
          while (d.way->getRef(&ref)) {
            ipt = nodes.find(ref);
            if (ipt == nodes.end()) continue;
            poslist->push(ipt->second);
          }
          if (poslist->length >= 2
          && poslist->first->data == poslist->last->data) { // closed, area
            outline = new Tilemesh::Outline(d.way->id, ftype, poslist);
            tdata.outlines.push(outline);
            aplist = new Tilemesh::List<Tilemesh::Position>;
            aclist = new Tilemesh::List<Tilemesh::Cell>;
            Tilemesh::triangulate(aplist,aclist,poslist);
            area = new Tilemesh::Area(d.way->id, ftype, aplist, aclist);
            tdata.areas.push(area);
          } else { // open, line
            line = new Tilemesh::Line(d.way->id, ftype, poslist);
            tdata.lines.push(line);
          }
        }
      }
    } catch (char *err) {
      printf("error: %s\n", err);
    }
  } while (len == 4096);
  printf("areas: %d\n", tdata.areas.length);
  return 0;
}
