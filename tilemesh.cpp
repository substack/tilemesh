#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <o5mdecoder.h>
#include <tilemesh.h>
#include <string.h>

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  char *dbuf = (char*) malloc(16384);
  char *table = (char*) malloc(256*15000);
  o5mdecoder::Decoder d(dbuf,16384,table);

  uint64_t ref;
  std::map<uint64_t,tilemesh::Position*> nodes;
  std::map<uint64_t,tilemesh::Position*>::const_iterator ipt;

  tilemesh::Features features;
  tilemesh::load_features(&features);
  tilemesh::Data tdata;
  tilemesh::Position *pos;
  tilemesh::Point *pt;
  tilemesh::Area *area;
  tilemesh::Line *line;
  tilemesh::Outline *outline;
  tilemesh::List<tilemesh::Position> *poslist;
  tilemesh::List<tilemesh::Position> *aplist;
  tilemesh::List<tilemesh::Cell> *aclist;

  size_t len, ftype;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    d.write(data, len);
    try {
      while (d.read()) {
        if (d.node) {
          pt = new tilemesh::Point(d.node->id,
            tilemesh::find_feature(&features, d.node),
            d.node->lon, d.node->lat);
          tdata.points.push(pt);
          pos = new tilemesh::Position(d.node->lon, d.node->lat);
          nodes[d.node->id] = pos;
        } else if (d.way) {
          ftype = tilemesh::find_feature(&features, d.way);
          poslist = new tilemesh::List<tilemesh::Position>;
          while (d.way->getRef(&ref)) {
            ipt = nodes.find(ref);
            if (ipt == nodes.end()) continue;
            poslist->push(ipt->second);
          }
          if (poslist->length >= 2
          && poslist->first->data == poslist->last->data) { // closed, area
            outline = new tilemesh::Outline(d.way->id, ftype, poslist);
            tdata.outlines.push(outline);
            aplist = new tilemesh::List<tilemesh::Position>;
            aclist = new tilemesh::List<tilemesh::Cell>;
            tilemesh::triangulate(aplist,aclist,poslist);
            area = new tilemesh::Area(d.way->id, ftype, aplist, aclist);
            tdata.areas.push(area);
          } else { // open, line
            line = new tilemesh::Line(d.way->id, ftype, poslist);
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
