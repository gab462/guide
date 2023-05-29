#!/bin/sh

set -xe

make -C ..

c99 -Wall -Wextra -Wshadow -pedantic **/*.c main.c sdl2.c ../libguide.a `sdl2-config --cflags --libs` #-ggdb
