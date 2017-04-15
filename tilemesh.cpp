#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <o5mdecoder.h>
#include <tilemesh_features.h>
#include <string.h>

struct Point { float lon, lat; };

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

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  char *dbuf = (char*) malloc(4096);
  char *table = (char*) malloc(256*15000);
  o5mdecoder::Decoder d(dbuf,table);

  uint64_t ref;
  char *key, *value;
  std::map<uint64_t,Point> nodes;
  std::map<uint64_t,Point>::const_iterator ipt;
  Point *pt;

  TilemeshFeatures features;
  tilemesh_load_features(&features);

  size_t len, ftype;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    d.write(data, len);
    try {
      while (d.read()) {
        if (d.node) {
          pt = &(nodes[d.node->id]);
          pt->lon = d.node->lon;
          pt->lat = d.node->lat;
        } else if (d.way) {
          ftype = 0;
          while (d.way->getTag(&key,&value)) {
            ftype = tilemesh_find_feature(&features, key, value);
            if (ftype > 0) break;
          }
          printf("area %u", ftype);
          while (d.way->getRef(&ref)) {
            ipt = nodes.find(ref);
            if (ipt == nodes.end()) continue;
            printf(" %f,%f", ipt->second.lon, ipt->second.lat);
          }
          printf("\n");
        }
      }
    } catch (char *err) {
      printf("error: %s\n", err);
    }
  } while (len == 4096);
  return 0;
}
