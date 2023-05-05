#!/bin/sh
FLAGS="${FLAGS:- -O3 -fomit-frame-pointer}"

echo cc $FLAGS -I../.. -o libco.o -c ../../libco.c
echo c++ $FLAGS -I../.. -c test_timing.cpp
echo c++ $FLAGS -o test_timing libco.o test_timing.o
echo c++ $FLAGS -I../.. -c test_args.cpp
echo c++ $FLAGS -o test_args libco.o test_args.o
echo c++ $FLAGS -std=c++11 -I../.. -c test_serialization.cpp
echo c++ $FLAGS -o test_serialization libco.o test_serialization.o

cc $FLAGS -I../.. -o libco.o -c ../../libco.c
c++ $FLAGS -I../.. -c test_timing.cpp
c++ $FLAGS -o test_timing libco.o test_timing.o
c++ $FLAGS -I../.. -c test_args.cpp
c++ $FLAGS -o test_args libco.o test_args.o
c++ $FLAGS -std=c++11 -I../.. -c test_serialization.cpp
c++ $FLAGS -o test_serialization libco.o test_serialization.o
rm -f *.o
