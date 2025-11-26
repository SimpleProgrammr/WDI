#!/bin/bash
> numbers.txt
for i in {1..10}; do
  rand_num=$(shuf -i 1-256 -n 1)
  echo $rand_num
  echo $rand_num >> numbers.txt
done

