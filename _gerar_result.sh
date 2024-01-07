#!/bin/bash

for i in {1..20}; do
    ./a.out | xargs ./push_swap | wc -l >> saida.txt
    tempo_aleatorio=$(( (RANDOM % 6) + 1 ))
    sleep $tempo_aleatorio
done
