#!/bin/sh

gcc -D TEST="$1" main.c libftprintf.a -o test
./test
rm test
