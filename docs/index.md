# Introduction

**IVpy** provides python bindings for **IVio**.
The goal is to cover typical functionality for **bioinformatics**.

## Support

 - **fasta** (ro) + **gzip** (ro)

(description - rw: read/write, ro: read-only)

**Note**: Currently only Linux is supported.

## Usage

For python we have a package called **ivpy**.
This can be easily installed via `pip install ivpy`.


Here an example of reading a fasta file:
```python
import ivpy

for record in ivpy.fasta.reader('file.fa'):
    print(record.id)
    print(record.seq)
```


## API Reference
Following classes are currently available:

  + `ivpy.fasta.record`
  + `ivpy.fasta.reader`

