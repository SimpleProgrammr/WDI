#!/usr/bin/env bash
> raport.txt
while IFS= read -r line; do
  binval=$(echo ./dec2bin line)
  bin2decval=$(echo ./bin2dec $binval)
  echo $binval "->" bin2decval >> raport.txt
done < numbers.txt