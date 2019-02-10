#!/bin/bash
python3 gen.py > data.txt
./D < data.txt > Dresult.txt
./AC < data.txt > ACresult.txt
diff Dresult.txt ACresult.txt
