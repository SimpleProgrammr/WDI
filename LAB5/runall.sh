#!/usr/bin/env bash
echo "Compiling..."
gcc ./bin2dec.c -o ./bin2dec
gcc ./dec2bin.c -o ./dec2bin
gcc ./decfrac2bin.c -o ./decfrac2bin
echo "Compiled!"


chmod +x ./bin2dec
chmod +x ./dec2bin
chmod +x ./decfrac2bin
chmod +x ./gen_numbers.sh
chmod +x ./test_rounttrip.sh

echo "Generating numbers..."
./gen_numbers.sh
echo "Number ready!"

echo "Running tests..."
./test_rounttrip.sh
echo "Done!"

echo $DATE >> raport.txt


