# FYS3150 Project 1

This directory contains the C++ and Python code as well as the generated data,
and other utilities for the first FYS3150 project

## Directroy structure
```
├── img
│   └── problem2-fig-x-u.pdf
├── README.md
└── src
    ├── cpp
    │   ├── makefile
    │   ├── problem2
    │   ├── problem2.cpp
    │   ├── problem7
    │   └── problem7.cpp
    ├── data
    │   ├── poisson.dat
    │   └── x_u.dat
    └── python
        └── problem2.py

```
## Compilation and linking

* cd src/cpp
* make

## Running the CPP programs

* cd src/cpp
* ./problem2
* ./problem7

These commands will produce the two data files in the data directory.

## Running the Python programs

* cd src/python
* python3 problem2.py

This command will read the data file from the 
data directory, generate a plot and store it as a PDF 
file in the img directory.


