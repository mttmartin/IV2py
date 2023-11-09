// SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
// SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
// SPDX-License-Identifier: BSD-3-Clause
#pragma once

#include <string>
#include <ranges>

template <typename reader>
struct record_reader {
    reader reader_;

    record_reader(std::string const& path)
        : reader_{{path}}
    {}

    using record_view = typename reader::record_view;
    using record      = typename reader::record;

    static auto init(reader& reader_) {
        return reader_ | std::views::transform([](record_view v) -> record {
            return v;
        });
    }
    decltype(init(reader_)) view = init(reader_);
};

