#!/bin/bash

mkdir -p bin

g++ main.cpp -o bin/main -O3

if [ $? -eq 0 ]; then
    ./bin/main
else
    echo "Compilation failed."
fi