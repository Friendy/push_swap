#!/bin/zsh
ARG=$(jot -r -s " " 500 10000000 99999999)
echo $ARG;
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l