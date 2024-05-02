set (go_files swig-go-cpp/swig-go-cpp.go)

set (cgo_deps cpp_api)

add_cgo_executable (swig-go-cpp go_files cgo_deps ${CMAKE_CURRENT_BINARY_DIR})
