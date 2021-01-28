#!/bin/sh

gcc -Wall -Werror -g --std=c99 $1 -o ${1%%.*}
