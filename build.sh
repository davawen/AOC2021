#! /usr/bin/env bash

mkdir -p bin

for f in *.c
do
	gcc $f -o bin/${f%%.*}
done
