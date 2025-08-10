#!/bin/sh

FILE=$1

clang-format -i $FILE
gcc $FILE -o output.o -Wall -Wextra -Werror -pedantic
./output.o