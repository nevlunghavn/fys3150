# FYS3150 Project 2

This directory contains the C++ and Python code as well as the generated data,
and other utilities for the second FYS3150 project

## Directroy structure
```
.
├── cpp
│   ├── include
│   │   ├── project2.hpp
│   │   └── utils.hpp
│   ├── main.cpp
│   ├── makefile
│   ├── output
│   │   ├── problem6a.output
│   │   └── problem6b.output
│   ├── problem3
│   ├── problem3.cpp
│   ├── problem4
│   ├── problem4.cpp
│   ├── problem5
│   ├── problem5.cpp
│   ├── problem6b
│   ├── problem6b.cpp
│   ├── project2.cpp
│   └── utils.cpp
├── python
│   ├── output
│   │   ├── problem7a.pdf
│   │   ├── scaling-with-N-dense.pdf
│   │   └── scaling-with-N.pdf
│   ├── problem7.py
│   ├── scaling_with_N_dense.py
│   └── scaling_with_N.py
└── README.md

5 directories, 23 files


```
## Compilation and linking

* cd src/cpp
* make

## Running the CPP programs

* cd src/cpp
* ./problem3
* ./problem4
* ./problem5 
* ./problem6b

All computational output is to terminal.

## Running the Python programs

* cd src/python
* python3 problem7.py  
* python3 scaling_with_N_dense.py  
* python3 scaling_with_N.py

These commands generate plots and store them as PDF 
files in the output directory.


