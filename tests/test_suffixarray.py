# SPDX-FileCopyrightText: 2025 Matthew Martin <matthew@mttmartin.com>
# SPDX-License-Identifier: MIT

import iv2py as iv

def test_suffixarray():
    reference = "Hello world"
    sa = iv.create_suffixarray("Hello world")
    assert reference[sa[0]-1] == "o"
    assert reference[sa[-1]-1] == " "
