#!/bin/bash
find -name \*.o5m.gz | (while read line; do
  out=`echo $line | sed 's/\.o5m\.gz$/.json/'`
  osmconvert --out-pbf $line | tilemesh > $out
done)
