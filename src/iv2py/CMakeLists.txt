cmake_minimum_required(VERSION 3.14)
project(iv2py LANGUAGES CXX)

pybind11_add_module(${PROJECT_NAME} MODULE
    main.cpp
    fasta.cpp
    sam.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ivio::ivio)
