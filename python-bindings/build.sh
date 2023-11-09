#!/usr/bin/bash
# SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
# SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
# SPDX-License-Identifier: CC0-1.0

cd "$(dirname "$0")"

docker run -u $(id -u) -ti --rm -e PLAT="manylinux_2_28_x86_64" -v $(pwd)/..:/code quay.io/pypa/manylinux_2_28_x86_64 /code/python-bindings/build-wheels.sh
