# Swig & Go & C++

This is a sample project using [Go](https://go.dev/) with C++, combining them using [Swig](https://swig.org/).

There are two subfolders

 * `pal` contains a palindrome API written in C++
 * `rev` contains a string reverser written in C++

Both contain the Swig interface and simple Go unit tests.

## Getting started

You need to install 

1. Swig >= 4.2.0 - https://www.swig.org/download.html
2. Go >= 1.22 - https://go.dev/dl a.k.a Golang
3. C++ >= 12 (C++17)
4. CMake >= 3.28
5. Ninja-build or Make

On Linux, these are all available via Apt (or similar) packages, but this rarely provides the latest versions.

If this matters to you, building Swig from source (`./configure && make && sudo make instal`) is often a wise 
choice. It requires that you've already installed `libpcre2-dev`.

Also, it's easy to install the latest Go from `go.dev/dl`.

Two scripts are provided: `build+test` and `clean`.
