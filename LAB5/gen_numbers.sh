#!/usr/bin/env bash
> numbers.txt
for i in {1..10}; do
  rand_num=$(RANDOM % 256)
  echo rand_num
  echo rand_num >> numbers.txt
done