cmake_minimum_required(VERSION 3.14)
project(ivpy LANGUAGES CXX)

pybind11_add_module(ivpy MODULE
    main.cpp
    fasta.cpp)
target_link_libraries(ivpy PRIVATE ivio::ivio)
