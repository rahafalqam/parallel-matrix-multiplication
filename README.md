# Parallel Matrix Multiplication

## Overview

This project was developed as part of the **Operating Systems (ENCS3390)** course. It implements and compares multiple approaches for matrix multiplication using parallel programming with POSIX Threads (Pthreads) in C.

The project evaluates the performance, scalability, and speedup of different parallelization strategies on matrices of various sizes and thread counts. :contentReference[oaicite:0]{index=0}

---

## Implemented Approaches

- Baseline (Single-threaded)
- Row-wise Parallel Matrix Multiplication
- Column-wise Parallel Matrix Multiplication
- Block (Tiled) Parallel Matrix Multiplication

---

## Features

- Matrix multiplication implemented in C
- Multithreading using POSIX Threads (Pthreads)
- Performance comparison between different parallelization strategies
- Execution time measurement
- Speedup analysis using Amdahl's Law
- Experimental evaluation with different matrix sizes and thread counts

---

## Technologies

- C Programming Language
- POSIX Threads (Pthreads)
- GCC Compiler
- Windows (MinGW)

---

## Performance Evaluation

The project compares the execution time of four implementations using:

- Matrix sizes:
  - 100 × 100
  - 500 × 500
  - 1000 × 1000

- Thread counts:
  - 2 Threads
  - 8 Threads
  - 16 Threads

Performance metrics include execution time, speedup, scalability, and efficiency. :contentReference[oaicite:1]{index=1}

---

## Repository Structure

```
.
├── osproject.c
├── OSProjectReport.pdf
└── README.md
```

---

## Results

Experimental results show that multithreading provides significant performance improvements for large matrices. Among the implemented strategies, the Block (Tiled) approach achieved the best overall performance for large-scale matrix multiplication due to improved cache locality. :contentReference[oaicite:2]{index=2}

---

## Course

**ENCS3390 – Operating Systems**

Faculty of Engineering & Technology  
Birzeit University

---

## Authors

- Rahaf Mahmoud
- Abdalrahman Abdullah
