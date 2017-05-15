# tilemesh

gpu-oriented binary map format for webgl/opengl vector tiles

The tilemesh format is designed to be compact over the wire and to run on the
gpu with minimal (linear time) pre-processing. The format is designed to make
few assumptions about the final presentation so that the same data can be shared
on p2p networks for varried use-cases and customizations. The layout of the
format is created to map directly to GL primitive types so that shader
attributes and elements can operate on large blocks of memory with a small
number of draw calls.

As of version 1.0.0, the data format does not specify how text labels should
work.

# usage

The tilemesh command reads o5m data on stdin and writes tilemesh data on stdout:

``` sh
$ tilemesh < input.o5m > output.tilemesh
```

# o5m data

You can turn many kinds of OpenStreetMap data into [o5m data][] using
[osmconvert][]:

```
$ osmconvert input.osm.pbf --out-o5m | tilemesh > output.tilemesh
$ osmconvert input.osm.xml --out-o5m | tilemesh > output.tilemesh
```

You can also download ad-hoc o5m tiles of planet-osm from a bounding box
(west,east,south,north) using [peermaps][]:

``` sh
$ peermaps data -f o5m -155.5 19.53 -149.5 19.60 | tilemesh > output.tilemesh
```

[osmconvert]: https://wiki.openstreetmap.org/wiki/Osmconvert
[peermaps]: http://peermaps.org
[o5m data]: http://wiki.openstreetmap.org/wiki/O5m

# data format

* magic number (9 bytes) "TILEMESH\n"
* version (newline-delimited string, up to 256 bytes) "1.0.0\n"

* number of points (4 bytes, `uint32_t` big endian)
** point.id (8 bytes, `uint64_t` big endian)
** point.type (2 bytes, `uint16_t` big endian)
** point.lon (4 bytes, `float32` big endian)
** point.lat (4 bytes, `float32` big endian)

* number of lines (4 bytes, `uint32_t` big endian)
** line.id (8 bytes, `uint64_t` big endian)
** line.type (2 bytes, `uint16_t` big endian)
** number of line.positions (2 bytes, `uint16_t` big endian)
*** position.lon (4 bytes, `float32` big endian)
*** position.lat (4 bytes, `float32` big endian)

* number of areas (4 bytes, `uint32_t` big endian)
** area.id - (8 bytes, `uint64_t` big endian)
** area.type - (2 bytes, `uint16_t` big endian)
** number of area.positions (2 bytes, `uint16_t` big endian)
** number of area.cells (2 bytes, `uint16_t` big endian)
*** position.lon (4 bytes, `float32` big endian)
*** position.lat (4 bytes, `float32` big endian)
*** cell.i (2 bytes, `uint16_t` big endian)
*** cell.j (2 bytes, `uint16_t` big endian)
*** cell.k (2 bytes, `uint16_t` big endian)

For each area, all of the positions are listed followed by all of the cells.
The points in each area retain the original order from the input file.

Type `uint64_t` integers are generated procedurally from the
[map_features](OpenStreetMap wiki page on Map_features). You can inspect the
type values in `src/tilemesh_features.hpp`.

[map_features]: http://wiki.openstreetmap.org/w/index.php?title=Map_Features

# pre-processing pipeline tips

The categories in the tilemesh data format are designed to correspond to these
GL primitive types:

* points - `GL_POINTS`
* lines - `GL_LINE_STRIP`
* area - `GL_TRIANGLES` for meshes and `GL_LINE_STRIP` for outlines

However some pre-processing is necessary at run time to format the data properly
first and to add custom attributes.

To build `GL_LINE_STRIP` geometry,

To give lines width, you can calculate two opposing line normals and store each
normal as a vec2 in an attribute.

To give area meshes an outline, use the point data in each area to build a line
strip in addition to a triangle mesh.

