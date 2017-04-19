#include <stdio.h>
#include <tilemesh.h>

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  size_t len;
  tilemesh::Writer tm;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    try {
      tm.write(data, len);
    } catch (char *err) {
      printf("error: %s\n", err);
    }
  } while (len == 4096);
  printf("areas: %d\n", tm.tdata.areas.length);
  return 0;
}
