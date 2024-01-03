// SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
// SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
// SPDX-License-Identifier: BSD-3-Clause
#include <filesystem>
#include <fmindex-collection/fmindex-collection.h>
#include <fstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include <cereal/archives/binary.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/vector.hpp>

namespace py = pybind11;
namespace fmc = fmindex_collection;

void init_suffixarray_mod(py::module& mod) {
    mod.def("create_suffixarray", [](std::string reference, int threadNbr) {
        return fmindex_collection::createSA(std::span{reinterpret_cast<uint8_t const*>(reference.data()), reference.size()}, threadNbr);
    }, py::arg("reference"), py::arg("threadNbr") = 1);
}
