#!/usr/bin/env bash
> raport.txt
while IFS= read -r line; do
  ./dec2bin line > $binval
  ./bin2dec $binval > $bin2decval
  echo $binval "->" bin2decval >> raport.txt
done < numbers.txt