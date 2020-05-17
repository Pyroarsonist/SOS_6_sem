cmake_minimum_required(VERSION 3.15)
project(lab_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_3 main.cpp Processor.cpp Processor.h Request.cpp Request.h CountTime.cpp CountTime.h StreamOperator.cpp StreamOperator.h)