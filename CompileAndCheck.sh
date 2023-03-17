#!/bin/bash
cd `dirname $0`

make
./quine > out.cpp
diff -s rockcutter.cpp out.cpp
