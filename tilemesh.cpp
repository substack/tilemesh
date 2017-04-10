#include <stdio.h>
#include <stdlib.h>
#include <o5mdecoder.h>

struct Features {
};

uint16_t feature_type (Features *features, char *key, char *value) {
  return 1;
}

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  char *dbuf = (char*) malloc(4096);
  char *key, *value;
  o5mdecoder::Decoder d(dbuf);
  o5mdecoder::Node node;
  o5mdecoder::Way way;
  o5mdecoder::Rel rel;
  Features *features;
  size_t len;
  uint16_t type;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    d.write(data, len);
    try {
      while (d.read(&node, &way, &rel)) {
        if (d.type == o5mdecoder::NODE) {
          while (node.getTag(&key, &value)) {
            type = feature_type(features, key, value);
            if (type > 0) {
              printf("node,%u\n", type);
              break;
            }
          }
        } else if (d.type == o5mdecoder::WAY) {
          while (way.getTag(&key, &value)) {
            type = feature_type(features, key, value);
            if (type > 0) {
              printf("way,%u\n", type);
              break;
            }
          }
        } else if (d.type == o5mdecoder::REL) {
          while (rel.getTag(&key, &value)) {
            type = feature_type(features, key, value);
            if (type > 0) {
              printf("rel,%u\n", type);
              break;
            }
          }
        }
      }
    } catch (char *err) {
      fprintf(stderr, "error: %s\n", err);
      return 1;
    }
  } while (len == 4096);
  return 0;
}
