cmake_minimum_required(VERSION 3.12)
project(db_ex)

set(CMAKE_CXX_STANDARD 14)

add_executable(db_ex main.cpp token.h token.cpp condition_parser.cpp condition_parser.h condition_parser_test.cpp test_runner.cpp test_runner.h date.cpp date.h database.cpp database.h node.cpp node.h)