#!/bin/bash

g++ main.cpp STATIC/Sources/*.cpp DYNAMIC/Sources/*.cpp Sources/*.cpp -o main ; ./main