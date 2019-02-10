#!/bin/bash
#Program:
#   Used to delete the executable files

string=$(find . ! -name "*.*")
for file in $string
do
    rm $file
done
