cmake_minimum_required(VERSION 3.15)
project(21su_pa02_template)

set(CMAKE_CXX_STANDARD 17)

add_executable(21su_pa02_template main.cpp DSVector.h Tweet.cpp Tweet.h DSString.cpp DSString.h Sort.cpp Sort.h Date.cpp Date.h)

set (input01 "data/su21_pa02.csv")

foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()
