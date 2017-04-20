#include <stdio.h>
#include <tilemesh.h>

int main (int argc, char **argv) {
  char *data = (char*) malloc(4096);
  size_t len;
  tilemesh::o5m tm;
  do {
    len = fread(data, sizeof(char), 4096, stdin);
    try {
      tm.write(data, len);
    } catch (char *err) {
      printf("error: %s\n", err);
    }
  } while (len == 4096);
  while (tm.read(data, 4096, &len)) {
    fwrite(data, sizeof(char), len, stdout);
  }
  return 0;
}
