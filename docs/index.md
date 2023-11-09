<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->

# Introduction

**IV2py** provides python bindings for **IVio**.
The goal is to cover typical functionality for **bioinformatics**.

## Support

 - **fasta** (rw) + **gzip** (rw)
 - **sam** (rw)

(description - rw: read/write, ro: read-only)

**Note**: Currently only Linux is supported.

## Usage

For python we have a package called **iv2py**.
This can be easily installed via `pip install iv2py`.


Here an example of reading a fasta file:
```python
import iv2py as iv

for record in iv.fasta.reader(file='file.fa'):
    print(record.id)
    print(record.seq)
```

To write a fasta file, each record has to be provided as a fasta::record
```python
import iv2py as iv

record = iv.fasta.record(id="my id", seq="somesequence")

writer = iv.fasta.writer(file='file.fa')
writer.write(record)
writer.close()
```


## API Reference
Following classes are currently available:

  + `iv2py.fasta.record`
  + `iv2py.fasta.reader`
  + `iv2py.fasta.writer`
  + `iv2py.sam.record`
  + `iv2py.sam.reader`
  + `iv2py.sam.writer`

