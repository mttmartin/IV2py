# SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
# SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
# SPDX-License-Identifier: CC0-1.0
cmake_minimum_required(VERSION 3.14)
project(iv2py LANGUAGES CXX)

pybind11_add_module(${PROJECT_NAME} MODULE
    main.cpp
    fasta.cpp
    fmindex.cpp
    sam.cpp
    sigma.cpp
    suffixarray.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ivio::ivio
    ivsigma::ivsigma
    fmindex-collection::fmindex-collection
    cereal::cereal
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
