#!/usr/bin/env bash

echo "The top 3 airports:"
cut -d ',' -f 18 $1|sort |uniq -c |sort -n |tail -3

echo "The number of unique airports:"
cut -d ',' -f 18 $1|sort |uniq |wc -l
