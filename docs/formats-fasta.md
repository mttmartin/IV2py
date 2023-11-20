<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->
# FASTA

Supports reading and writing [fasta files 🔗](https://blast.ncbi.nlm.nih.gov/doc/blast-topics/).
Files can be wrapped into zipped files using zlib (file ending .gz).
All classes/functions are available through the `iv2py.fasta` module.

---
## Functions and classes
  - `iv2py.fasta.record`
  - `iv2py.fasta.reader`
  - `iv2py.fasta.writer`


---
## Example usages
=== "Reading from fasta"
    Loads a file and prints it to the command line.
    The file is being read line by line.
    ```python
    import iv2py as iv

    for record in iv.fasta.reader(file='file.fa'):
        print(record.id)
        print(record.seq)
    ```

=== "Write to fasta"
    Writes a record to a fasta file.
    ```python
    import iv2py as iv

    record = iv.fasta.record(id="my id", seq="somesequence")

    writer = iv.fasta.writer(file='file.fa')
    writer.write(record)
    writer.close()
    ```
