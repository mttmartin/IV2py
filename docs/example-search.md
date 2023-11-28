<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->
# Search with FM-Index

This example loads a `file.fasta` file and creates an index `file.fmindex`.
If the index already exists it is loaded from disk.
The programs continues to search for "AA". The results depend on the contents of `file.fasta`


```python
import iv2py as iv
import os

# load index or create an index
if os.path.exists("file.fmindex"):
    # load fm index from disk
    index = iv.fmindex(path="file.fmindex")
else:
    # load fasta file - normalize sequences (e.g.: make everything capital letters, check for invalid characters)
    reference = [iv.normalize(rec.seq) for rec in iv.fasta.reader("file.fasta")]

    # build fmindex
    index = iv.fmindex(reference=reference, samplingRate=16)

    index.save("file.fmindex")

# search through fmindex
res = index.search("CG")
print(res)
```

*file.fasta*:
```
>name1
AACCGGTT
>name2
acgtacgt
```

*output*:
```
[(0, 3), (1, 5), (1, 1)]
```

