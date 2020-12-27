#!/bin/bash

SRC=./src
OUTPUT=./output
COMPILER_FLAGS=-Ofast

function init_cats() {
    mkdir -p $OUTPUT
    clang -std=c17 $SRC/cat_alt.c -o $OUTPUT/cat_alt $COMPILER_FLAGS
    clang -std=c17 $SRC/cat_kr.c -o $OUTPUT/cat_kr $COMPILER_FLAGS
    clang++ -std=c++17 $SRC/cat++.cpp -o $OUTPUT/cat++ $COMPILER_FLAGS
    echo 🐈 meow
}

function remove_cats() {
    rm $OUTPUT/*
}
