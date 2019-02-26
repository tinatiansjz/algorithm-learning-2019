#!/bin/bash
dir=$(ls)

for file in $dir
do
#    echo -e $file
    grep "https://ac.nowcoder.com/acm/contest" $file
    if [ $? -eq 0 ]; then
        echo -e $file
    fi
done
