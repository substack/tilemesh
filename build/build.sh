#!/bin/bash
./tags.sh > ../data/features.csv
node feature-json.js < ../data/features.csv > ../data/features.json
node feature-enum.js < ../data/features.csv > ../data/features.glsl
