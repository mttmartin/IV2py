<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->
# Suffix Array

Algorithm to construct a suffix array.

---
## Functions and classes
  - `iv2py.create_suffixarray`


## Example usages
=== "Construct and print BWT"
    Constructs an suffix array and uses it to print a bwt.
    ```python
    import iv2py as iv

    reference = "Hello World"
    """ creates a suffix array """
    sa = iv.create_suffixarray(reference)

    """ prints the BWT """
    for pos in sa:
        print(reference[pos-1])
    ```

    *Output*:
    ```
    o
    d
     
    H
    W
    e
    l
    o
    l
    r
    o
    t

    ```

## API
### Suffix Array construction
```py
iv2py.create_suffixarray(reference)
```
Returns the suffix array of `reference`. It will assume each byte as a single character/position in the string.


