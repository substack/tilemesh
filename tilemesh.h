namespace Tilemesh {
  const char magic[10] = "TILEMESH\n";
  const char version[256] = "1.0.0\n";
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
    ListItem<T> *head;
    ListItem<T> *tail;
    List () {
      length = 0;
      head = NULL;
      tail = NULL;
    }
    void push (T* p) {
      ListItem<T> *item = new ListItem<T>(p);
      if (!head) head = item;
      if (tail) {
        tail->next = item;
      }
      tail = item;
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
    List<Position> positions;
    List<Cell> cells;
    Area (uint64_t _id, uint16_t _type) {
      id = _id;
      type = _type;
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
};
