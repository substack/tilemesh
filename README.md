# tilemesh

work in progress

```
ipfs cat QmNPkqYfis1XV2CcAyE9ByttxGnvvtVJ4VfFXtbBWnd7fW/2/6/2/6.o5m.gz | gunzip > 6.o5m
osmconvert 6.o5m --out-pbf | node tomesh.js > 6.json
```

# steps

1. parse an o5m file
2. separate features into points, lines, areas, and outlines
3. populate vector text atlas with labels
4. sort separated features by importance

# data format

Here is an example:

```
TILEMESH\n
1.2.3\n
```

## magic number

newline-terminated string (9 bytes): "TILEMESH\n"

## version

newline-terminated string: "SEMVER\n"

The format of SEMVER is generally "MAJOR.MINOR.PATCH" with MAJOR, MINOR, and
PATCH as integers expressed in ascii text in the range 0 to 65535, inclusive.

SEMVER may contain additional release information after a dash character "-".
Be lenient with what you expect here.

## lengths

newline-terminated string of comma-separated byte lengths for each section:

* points
* lines
* areas
* outlines
* labels
* characters

## points

The number of points is the byte length of this section divided by 18 (8+8+2).

* position - (lon,lat) vec2 tuples (float32be,float32be) (8 bytes)
* id - uint64be to float32be vec2 (see algorithm below) (8 bytes)
* type - uint16be (2 bytes)

## lines

Each line is terminated by a point with an id of 0.

* position - (lon,lat) vec2 tuples (float32be,float32be) (8 bytes)
* id - uint64be represented by a float32be vec2 (see algorithm below) (8 bytes)
* type - uint16be (2 bytes)

# uint64be to vec2 float32be algorithm

...

