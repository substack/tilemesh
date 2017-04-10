struct Point {
  uint64_t id;
  uint16_t type;
  float lon, lat;
};

struct Position {
  float lon, lat;
};

struct Line {
  uint64_t id;
  uint16_t type;
  size_t length;
  Position *positions;
};

struct Outline {
  uint64_t id;
  uint16_t type;
  size_t length;
  Position *positions;
};

struct Cell {
  uint32_t i;
  uint32_t j;
  uint32_t k;
};

struct Area {
  uint64_t id;
  uint16_t type;
  size_t position_len;
  Position *positions;
  size_t cell_len;
  Cell *cells;
};

struct Tile {
  const char magic[9];
  const char version[256];
  size_t point_len;
  Point* points;
  size_t line_len;
  Line* lines;
  size_t area_len;
  Area* areas;
  size_t outline_len;
  Outline *outlines;
};
