# Introduction

**IVpy** provides python bindings for **IVio**.
The goal is to cover typical functionality for **bioinformatics**.

## Support

 - **fasta** (rw) + **gzip** (rw)

(description - rw: read/write, ro: read-only)

**Note**: Currently only Linux is supported.

## Usage

For python we have a package called **ivpy**.
This can be easily installed via `pip install ivpy`.


Here an example of reading a fasta file:
```python
import ivpy

for record in ivpy.fasta.reader(file='file.fa'):
    print(record.id)
    print(record.seq)
```

To write a fasta file, each record has to be provided as a fasta::record
```python
import ivpy

record = ivpy.fasta.record(id="my id", seq="somesequence")

writer = ivpy.fasta.writer(file='file.fa')
writer.write(record)
writer.close()
```


## API Reference
Following classes are currently available:

  + `ivpy.fasta.record`
  + `ivpy.fasta.reader`
  + `ivpy.fasta.writer`

