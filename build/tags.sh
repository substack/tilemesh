#!/bin/bash

load () {
  curl -sS "http://wiki.openstreetmap.org/w/api.php?titles=$1&action=query\
&prop=revisions&rvprop=content&format=json" \
    | jsonstream query.pages.*.revisions.0 | json 0.\*
}

echo category,type
load Map_Features \
  | sed '0,/^== Primary features/ d; 0,/^$/ {/^{{Map_Features:/ !d
      s/^{{Map_Features://; s/}}$// p}; d' \
  | while read page; do
    load "Template:Map_Features:$page" \
      | grep "Tag:$page=" | sed 's/.*Tag://; s/}}.*//'
  done \
  | sed 's/=/,/; s/\]\].*'
