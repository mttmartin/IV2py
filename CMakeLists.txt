# SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
# SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
# SPDX-License-Identifier: CC0-1.0
cmake_minimum_required (VERSION 3.14)

# Set compiler options (we know this is not used as a library)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc -DNOMINMAX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Wextra -Wno-stringop-overread")
endif()

project(IV2py)

include(cmake/CPM.cmake)

CPMaddPackage(NAME cereal
    GITHUB_REPOSITORY USCiLab/cereal
    GIT_TAG v1.3.2
    OPTIONS
        "SKIP_PERFORMANCE_COMPARISON ON"
        "BUILD_SANDBOX OFF"
        "BUILD_DOC OFF"
        "WITH_WERROR OFF"
    EXCLUDE_FROM_ALL TRUE
)
CPMaddPackage("gh:SGSSGene/fmindex-collection#feat/VariableFMIndex")
CPMaddPackage("gh:iv-project/IVio#main")
CPMaddPackage("gh:iv-project/IVSigma#main")
CPMaddPackage("gh:pybind/pybind11#v2.11.1")


add_subdirectory(src/iv2py)
