#include <pybind11/pybind11.h>

namespace py = pybind11;
void init_fasta_mod(py::module& mod);

PYBIND11_MODULE(ivpy, mod) {
    init_fasta_mod(mod);
}
