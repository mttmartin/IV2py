# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14)
project(iv2py LANGUAGES CXX)

pybind11_add_module(${PROJECT_NAME} MODULE
    main.cpp
    fasta.cpp
    sam.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ivio::ivio)
