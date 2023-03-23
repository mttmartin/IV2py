#include "record_reader.h"

#include <ivio/ivio.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
void init_sam_mod(py::module& parent_mod) {
    auto mod = parent_mod.def_submodule("sam");

    // Provding the record class
    py::class_<ivio::sam::record>(mod, "record")
        .def(py::init<>([](std::string qname,
                           int32_t     flag,
                           std::string rname,
                           int32_t     pos,
                           int32_t     mapq,
                           std::string cigar,
                           std::string rnext,
                           int32_t     pnext,
                           int32_t     tlen,
                           std::string seq,
                           std::string qual,
                           std::string tags) {

            return ivio::sam::record {
                .qname   = qname,
                .flag    = flag,
                .rname   = rname,
                .pos     = pos,
                .mapq    = mapq,
                .cigar   = cigar,
                .rnext   = rnext,
                .pnext   = pnext,
                .tlen    = tlen,
                .seq     = seq,
                .qual    = qual,
                .tags    = tags,
            };
        }), py::arg("qname") = "",
            py::arg("flag")  = 0,
            py::arg("rname") = "",
            py::arg("pos")   = 0,
            py::arg("mapq")  = 0,
            py::arg("cigar") = "",
            py::arg("rnext") = "",
            py::arg("pnext") = 0,
            py::arg("tlen")  = 0,
            py::arg("seq")   = "",
            py::arg("qual")  = "",
            py::arg("tags")  = "")
        .def_readwrite("qname", &ivio::sam::record::qname)
        .def_readwrite("flag",  &ivio::sam::record::flag)
        .def_readwrite("rname", &ivio::sam::record::rname)
        .def_readwrite("pos",   &ivio::sam::record::pos)
        .def_readwrite("mapq",  &ivio::sam::record::mapq)
        .def_readwrite("cigar", &ivio::sam::record::cigar)
        .def_readwrite("rnext", &ivio::sam::record::rnext)
        .def_readwrite("pnext", &ivio::sam::record::pnext)
        .def_readwrite("tlen",  &ivio::sam::record::tlen)
        .def_readwrite("seq",   &ivio::sam::record::seq)
        .def_readwrite("qual",  &ivio::sam::record::qual)
        .def_readwrite("tags",  &ivio::sam::record::tags)
        .def("__repr__", [](ivio::sam::record const& o) -> std::string {
            return std::string{"iv2py.sam.record:"}
                   + "\n  id: "   + o.qname
                   + "\n  flag:"  + std::to_string(o.flag)
                   + "\n  rname:" + o.rname
                   + "\n  pos:"   + std::to_string(o.pos)
                   + "\n  mapq:"  + std::to_string(o.mapq)
                   + "\n  cigar:" + o.cigar
                   + "\n  rnext:" + o.rnext
                   + "\n  pnext:" + std::to_string(o.pnext)
                   + "\n  tlen:"  + std::to_string(o.tlen)
                   + "\n  seq:"   + o.seq
                   + "\n  qual:"  + o.qual
                   + "\n  tags:"  + o.tags;
        })
    ;

    // Providing the reader class
    py::class_<record_reader<ivio::sam::reader>>(mod, "reader")
        .def(py::init([](std::string const& path) {
            return std::make_unique<record_reader<ivio::sam::reader>>(path);
        }), py::arg("file"))
        .def("header", [](record_reader<ivio::sam::reader>& r) {
            return r.reader_.header;
        })
        .def("__iter__", [](record_reader<ivio::sam::reader>& r) {
            return py::make_iterator(r.view.begin(), r.view.end());
        }, py::keep_alive<0, 1>())
    ;

    // Providing the writer class
    py::class_<ivio::sam::writer>(mod, "writer")
        .def(py::init([](std::string const& path, std::vector<std::string> const& header) {
            auto config = ivio::sam::writer::config{
                .output = path,
                .header = header
            };
            return std::make_unique<ivio::sam::writer>(config);
        }), py::arg("file"), py::arg("header") = std::vector<std::string>())
        .def("write", [](ivio::sam::writer& writer, ivio::sam::record const& record) {
            writer.write(record);
        }, py::arg("record"))
        .def("close", [](ivio::sam::writer& writer) {
            writer.close();
        })
    ;
}
