// SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
// SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
// SPDX-License-Identifier: BSD-3-Clause
#include <ivsigma/ivsigma.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
void init_sigma_mod(py::module& mod) {
//    auto mod = parent_mod.def_submodule("sigma");

    mod.def("normalize", [](std::string v) -> std::string {
        auto ret = ivs::normalize_char<ivs::iupac>(v);
        if (auto pos = ivs::verify_char(ret); pos.has_value()) {
            auto message = std::string{}
                            + "Character "
                            + "'" + v[*pos] + "'"
                            + " (" + std::to_string(v[*pos]) + ")"
                            + " at position " + std::to_string(*pos)
                            + " is not a valid IUPAC code";
            throw std::domain_error{message};
        }
        return ret;
    });

    mod.def("verify", [](std::string v) -> std::optional<size_t> {
        return ivs::verify_char(v);
    });

    mod.def("uniq_characters", [](std::string v) -> size_t {
        auto arr = std::array<size_t, 256>{};
        for (auto c : v) {
            arr[static_cast<size_t>(c)] += 1;
        }
        size_t ct{0};
        for (auto e : arr) {
            ct += (e != 0);
        }
        return ct;
    });

}
