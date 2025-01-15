// SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
// SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
// SPDX-License-Identifier: BSD-3-Clause
#include <filesystem>
#include <fmindex-collection/fmindex-collection.h>
#include <fstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl/filesystem.h>
#include <sstream>

#include <cereal/archives/binary.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/vector.hpp>

namespace py = pybind11;
namespace fmc = fmindex_collection;

void init_fmindex_mod(py::module& mod) {
//    auto mod = parent_mod.def_submodule("fmindex");

    using Index = fmc::VariableFMIndex;

    // Providing the fmindex class
    py::class_<Index>(mod, "fmindex")
        .def(py::init<>([](std::vector<std::string> reference, size_t samplingRate, size_t threadNbr) {
            return Index { reference, samplingRate, threadNbr };
        }), py::arg("reference") = std::vector<std::string>{}, py::arg("samplingRate") = 16, py::arg("threadNbr") = 1)
        .def(py::init<>([](std::filesystem::path path) {
            auto index = Index{};
            auto ifs     = std::ifstream{path, std::ios::binary};
            auto archive = cereal::BinaryInputArchive{ifs};
            archive(index);
            return index;
        }), py::arg("path"))
        .def("search", [](Index const& index, std::string const& query, size_t k) -> std::vector<std::tuple<size_t, size_t>> {
            return index.search(query, k);
        }, py::arg("query"), py::arg("k") = 0)
        .def("load", [](Index& index, std::filesystem::path const& path) {
            auto ifs     = std::ifstream{path, std::ios::binary};
            auto archive = cereal::BinaryInputArchive{ifs};
            archive(index);
        }, py::arg("path"))
        .def("save", [](Index& index, std::filesystem::path const& path) {
            auto ofs     = std::ofstream{path, std::ios::binary};
            auto archive = cereal::BinaryOutputArchive{ofs};
            archive(index);
        }, py::arg("path"))
        .def("__repr__", [](Index const& index) -> std::string {
            auto ss = std::stringstream{};
            ss << "<iv2py.fmindex ";
            ss << "0x" << std::hex << &index;
            ss << " >";
            return ss.str();
        })
    ;
}
