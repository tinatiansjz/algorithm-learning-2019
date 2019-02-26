#!/bin/bash
dir=$(ls)

for file in $dir
do
#    echo -e $file
    grep "printf("%lld", A[head]);" $file
    if [ $? -eq 0 ]; then
        echo -e $file
    fi
done
