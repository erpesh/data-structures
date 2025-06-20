# Data Structures in C

Writing data structures to learn C.

## 🛠 Build Instructions

### Build Entire Program

```bash
make
```
Compiles all `.c` files into a single program executable.

### Build and Run Individual Components

Each module (list, array, hashmap) can be built and run separately:

#### 🔹 List Module

```bash
make list       # Compiles list/ and array/ sources into list_demo
make list-run   # Compiles and runs ./list_demo
```

#### 🔹 Array Module

```bash
make array
make array-run
```

#### 🔹 Hashmap Module

```bash
make hashmap
make hashmap-run
```

> **Note:** These commands assume that each folder has `.c` files with a `main()` function when needed (e.g., `usage.c` in `list/`).

### 🧹 Clean Up

```bash
make clean
```
Removes all `.o` files and compiled executables.

## 📁 Folder Structure

```
project-root/
├── main.c                # Optional main entry point
├── list/
│   ├── list.c
│   ├── list.h
│   └── usage.c           
├── array/
│   ├── array.c
│   └── array.h
├── hashmap/
│   ├── hashmap.c
│   └── hashmap.h
├── Makefile
└── README.md
```

## ✅ Requirements

- GCC or compatible C compiler
- Make