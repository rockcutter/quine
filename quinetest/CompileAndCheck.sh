#!/bin/bash
cd `dirname $0`

make
./quine > out.cpp
diff -s main.cpp out.cpp
