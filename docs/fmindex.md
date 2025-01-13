<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->
# FM-Index

An FM-Index is a data structure that supports fast searches for exact searches.

---
## Functions and classes
  - `iv2py.fmindex`
  - `iv2py.fmindex.load`
  - `iv2py.fmindex.search`
  - `iv2py.fmindex.save`


## Example usages
=== "Construct & Search"
    Constructs an fmindex and searches for all occurences of "CG".
    ```python
    import iv2py as iv

    reference = ["AACCGGTT", "ACGT"]
    index = iv.fmindex(reference=reference, samplingRate=16)

    result = index.search("CG")
    print(result)

    """search with errors"""
    result2 = index.search("CG", k=1);
    ```

    *Output*:
    ```
    [(0, 3), (1, 1)]
    ```

=== "Construct & Save"
    Constructs an fmindex an saves it to disk.
    ```python
    import iv2py as iv

    reference = ["AACCGGTT", "ACGT"]
    index = iv.fmindex(reference=reference, samplingRate=16)
    index.save("myindex.idx")
    ```

=== "Load & Search"
    Loads an fmindex and searches for all occurences of "CG".
    ```python
    import iv2py as iv

    index = iv.fmindex(path="myindex.idx")

    result = index.search("CG")
    print(result)

    """search with errors"""
    result2 = index.search("CG", k=1);
    ```

    *Output*:
    ```
    [(0, 3), (1, 1)]
    ```
