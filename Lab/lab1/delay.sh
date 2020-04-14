#!/usr/bin/env bash 

# Tells OS that the script is in bash

echo -n "Min delay: "
cut -d ',' -f 5 $1|sort -n|head -1

echo -n "Max delay: "
cut -d ',' -f 5 $1|sort -n|tail -1

