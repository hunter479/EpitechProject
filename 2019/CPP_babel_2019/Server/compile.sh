#!/bin/bash
##
## EPITECH PROJECT, 2019
## CPP_babel_2019
## File description:
## compile
##

mkdir build
cd build
conan install .. --build missing
cmake ..
cmake –build .
