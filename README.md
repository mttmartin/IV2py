<!--
    SPDX-FileCopyrightText: 2006-2023, Knut Reinert & Freie Universität Berlin
    SPDX-FileCopyrightText: 2016-2023, Knut Reinert & MPI für molekulare Genetik
    SPDX-License-Identifier: CC-BY-4.0
-->

# IV2py

Wrapper code to bring libraries from the iv-project to python, currently supported are:

- [IVSigma](https://iv-project.github.io/IVSigma/)
- [IVio](https://iv-project.github.io/IVio/)
- [fmindex-collection](https://github.com/SGSSGene/fmindex-collection)

## Documentation/API Reference
Checkout the [documentation](https://iv-project.github.io/IV2py/) for details on this library.

## Release
For release, download the artifacts from the github action workflow and upload them with twine:
```
    unzip artifacts.zip
    twine upload --repository testpypi *.whl --verbose`
```
