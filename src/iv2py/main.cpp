// SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
// SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
// SPDX-License-Identifier: BSD-3-Clause
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <filesystem>

namespace py = pybind11;
void init_fasta_mod(py::module& mod);
void init_fmindex_mod(py::module& mod);
void init_sam_mod(py::module& mod);
void init_sigma_mod(py::module& mod);
void init_suffixarray_mod(py::module& mod);

PYBIND11_MODULE(iv2py, mod) {
    //provides conversion from std::string to std::filesystem::path
    py::class_<std::filesystem::path>(mod, "Path")
        .def(py::init<std::string>());
    py::implicitly_convertible<std::string, std::filesystem::path>();

    init_fasta_mod(mod);
    init_fmindex_mod(mod);
    init_sam_mod(mod);
    init_sigma_mod(mod);
    init_suffixarray_mod(mod);
}
