#!/usr/bin/env bash
> raport.txt
while IFS= read -r line; do
  binval=$(./dec2bin "$line")
  bin2decval=$(./bin2dec "$binval")
  echo "$line -> $binval -> $bin2decval" >> raport.txt
done < numbers.txt