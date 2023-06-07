cmake_minimum_required(VERSION 3.0)
project(addrBook)
add_executable(addrBook.out main.cpp contacts.h contacts.cpp)
set(CMAKE_BUILD_TYPE Debug)