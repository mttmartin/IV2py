#include "record_reader.h"

#include <ivio/ivio.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
void init_fasta_mod(py::module& parent_mod) {
    auto mod = parent_mod.def_submodule("fasta");

    // Provding the record class
    py::class_<ivio::fasta::record>(mod, "record")
        .def(py::init<>([](std::string id, std::string seq) {
            return ivio::fasta::record {
                .id  = std::move(id),
                .seq = std::move(seq),
            };
        }), py::arg("id") = "", py::arg("seq") = "")
        .def_readwrite("id", &ivio::fasta::record::id)
        .def_readwrite("seq", &ivio::fasta::record::seq)
        .def("__repr__", [](ivio::fasta::record const& o) -> std::string {
            return "<ivpy.fasta.record id '" + o.id + "', seq '" + std::string{o.seq} + "'>";
        })
    ;

    // Providing the reader class
    py::class_<record_reader<ivio::fasta::reader>>(mod, "reader")
        .def(py::init([](std::string const& path) {
            return std::make_unique<record_reader<ivio::fasta::reader>>(path);
        }), py::arg("file"))
        .def("__iter__", [](record_reader<ivio::fasta::reader>& r) {
            return py::make_iterator(r.view.begin(), r.view.end());
        }, py::keep_alive<0, 1>())
    ;

    // Providing the writer class
    py::class_<ivio::fasta::writer>(mod, "writer")
        .def(py::init([](std::string const& path) {
            return std::make_unique<ivio::fasta::writer>(ivio::fasta::writer::config{path});
        }), py::arg("file"))
        .def("write", [](ivio::fasta::writer& writer, ivio::fasta::record const& record) {
            writer.write(record);
        }, py::arg("record"))
        .def("close", [](ivio::fasta::writer& writer) {
            writer.close();
        })
    ;
}
