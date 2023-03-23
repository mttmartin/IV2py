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

