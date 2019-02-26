#!/bin/bash
#Program:
#   Used to delete the executable files

string=$(find . ! -name "*.*" -type f)
for file in $string
do
    rm $file
done
