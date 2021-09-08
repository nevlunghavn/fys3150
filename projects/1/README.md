# FYS3150 Project 1

This directory contains the C++ and Python code as well as the generated data,
LaTeX documentation and other utilities for the first FYS3150 project

## Directroy structure
```
.
├── img
│   ├── problem2-fig-x-u.pdf
│   └── rel_err.pdf
├── README.md
└── src
    ├── c++
    │   ├── makefile
    │   ├── problem2
    │   └── problem2.cpp
    ├── data
    │   └── x_u.dat
    └── python
        └── problem2.py

```
## Compilation and running

C++ code is compiled and run using the make command in the C++ directory. This creates 
data output files in the data directory

Python code is run using the command 
python problem2.py in the python directory. 
This reads data from the data directory and produces 
plots and store them as PDF files in the img directory.

