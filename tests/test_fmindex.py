# SPDX-FileCopyrightText: 2025 Matthew Martin <matthew@mttmartin.com>
# SPDX-License-Identifier: MIT

import pytest

import iv2py as iv


@pytest.mark.parametrize("reference,pattern,expected", [(["AACCGGTT", "ACGT"], "CG", [(0, 3), (0, 10)])])
def test_load(tmp_path, reference, pattern, expected):
    index_path = tmp_path / "myindex.idx"
    index = iv.fmindex(reference=reference, samplingRate=16)

    # test that we are actually writing a file to the right place
    assert index_path.is_file() is False
    index.save(index_path)
    assert index_path.is_file() is True

    index_2 = iv.fmindex(index_path)

    # if we can still get valid search results, the index should be okay
    assert index_2.search(pattern) == expected 

@pytest.mark.parametrize("reference,pattern,expected", [(["AACCGGTT", "ACGT"], "GGT", [(0, 5), (0, 10), (0, 4)])])
def test_search_mismatches(reference, pattern, expected):
    index = iv.fmindex(reference=reference, samplingRate=16)

    assert index.search(pattern, k=1) == expected

@pytest.mark.parametrize("reference,pattern,expected", [(["AACCGGTT", "ACGT"], "CG", [(0, 3), (0, 10)])])
def test_search(reference, pattern, expected):
    index = iv.fmindex(reference=reference, samplingRate=16)

    assert index.search(pattern) == expected

