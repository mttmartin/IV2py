// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include <pybind11/pybind11.h>

namespace py = pybind11;
void init_fasta_mod(py::module& mod);
void init_sam_mod(py::module& mod);

PYBIND11_MODULE(iv2py, mod) {
    init_fasta_mod(mod);
    init_sam_mod(mod);
}
