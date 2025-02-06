# Swig & Go & C++

This is a sample project using [Go](https://go.dev/) with C++, combining them using [Swig](https://swig.org/).

There are two subfolders

 * `pal` contains a palindrome API written in C++
 * `rev` contains a string reverser written in C++

Both contain the Swig interface and simple Go unit tests.

## Getting started

You need to install 

1. Swig - https://www.swig.org/download.html
2. Go - https://go.dev/dl a.k.a Golang
3. C++
4. CMake
5. Ninja or Make

On Linux, these are all available via Apt (or similar) packages. 

Two scripts are provided: `build+test` and `clean`.
