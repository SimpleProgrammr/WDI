#!/usr/bin/env bash
> results_int.txt
if [ ! -f "./numbers.txt" ]; then
    echo "Błąd: Plik $INPUT_FILE nie istnieje"
    exit 1
fi

# Sprawdzenie czy program dec2bin istnieje i jest wykonywalny
if [ ! -x "./dec2bin" ]; then
    echo "Błąd: Program ./dec2bin nie istnieje lub nie jest wykonywalny"
    exit 1
fi

while IFS= read -r line; do
  result=$(./dec2bin $line)
  "$line -> $result" >> "results_int.txt"
done < numbers.txt

