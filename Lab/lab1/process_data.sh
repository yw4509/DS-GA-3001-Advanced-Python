#!/usr/bin/env bash 
# Tells OS that the script is in bash

echo "Data Processing"
# To store the output of a command as a variable in bash:
# var=$(command) or var=`command`

echo -e "The name of the file is:" $1 "\n"

lines=$(wc -l < $1)
echo -e "The file has" $lines "lines\n"

colnames=$(head -n 1 < $1)
echo "Column names are: "
echo $colnames