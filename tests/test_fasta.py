# SPDX-FileCopyrightText: 2025 Matthew Martin <matthew@mttmartin.com>
# SPDX-License-Identifier: MIT

import iv2py as iv

def test_fasta_read(tmp_path):
    # Setup an example fasta file
    records = {"1": "ATGATG", "2": "TTTTTT" }
    fasta_path = tmp_path/"input.fa"
    with open(fasta_path, "w") as f:
        for record in records:
            f.write(f">{record}\n")
            f.write(records[record]+"\n")

    for i, record in enumerate(iv.fasta.reader(file=fasta_path)):
        assert record.seq == records[str(record.id)]
        assert str(i+1) == record.id

def test_fasta_write(tmp_path):
    fasta_path = tmp_path/"output.fa"
    record = iv.fasta.record(id="1", seq="ATG")

    assert fasta_path.is_file() is False
    writer = iv.fasta.writer(file=fasta_path)
    writer.write(record)
    writer.close()
    assert fasta_path.is_file() is True

    for record in iv.fasta.reader(file=fasta_path):
        assert record.id == "1"
        assert record.seq == "ATG"



