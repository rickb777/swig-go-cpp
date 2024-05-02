cmake_minimum_required (VERSION 3.27)

# Set the project name
project (Go_Swig_Cpp_demo)

include (cmake/go.cmake)
include (cmake/gtest.cmake)

#--------------------------------------------------------------------------------------------------
# SWIG integration

find_package (SWIG)

if (!SWIG_FOUND)
    message ("SWIG not found. Please install SWIG (>=v4.2.0) or fix its installation.")
    return ()
endif ()

message ("Found SWIG ${SWIG_VERSION}")

#--------------------------------------------------------------------------------------------------
# Address sanitization
# see e.g. https://felsoci.sk/blog/using-address-sanitizer-asan-in-a-cmake-project.html

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fsanitize=undefined -fsanitize=address")
    target_link_options (asan-demo BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address)
endif ()

#--------------------------------------------------------------------------------------------------

include (UseSWIG)
set (SWIG_FILE "cpp/interface.i")
set_source_files_properties (${SWIG_FILE} PROPERTIES
        CPLUSPLUS ON
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

set (SWIG_MODULE_NAME "essay")
set (CMAKE_SWIG_FLAGS -c++ -go -cgo -intgosize 64)
message ("CMAKE_SWIG_FLAGS: ${CMAKE_SWIG_FLAGS}")

swig_add_library (${SWIG_MODULE_NAME}
        TYPE SHARED
        LANGUAGE go
        OUTPUT_DIR "${CMAKE_SOURCE_DIR}/cpp" # in-place files make Go development easier
        SOURCES ${SWIG_FILE}
)

#target_include_directories(${SWIG_MODULE_NAME} PRIVATE ${HIDAPI_INCLUDE_DIR})

#swig_link_libraries(${SWIG_MODULE_NAME} PUBLIC stduuid)
#swig_link_libraries(${SWIG_MODULE_NAME} PUBLIC fmt::fmt-header-only)
#swig_link_libraries(${SWIG_MODULE_NAME} PUBLIC nlohmann_json nlohmann_json::nlohmann_json)

set_target_properties (${SWIG_MODULE_NAME} PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

#--------------------------------------------------------------------------------------------------
# Application Code

message ("----- include -----")
message (${INCLUDE_DIRECTORIES})
add_library (cpp_api
        cpp/Reverse.cpp
        cpp/Palindrome.cpp
)

#--------------------------------------------------------------------------------------------------

add_subdirectory (cmd)

#--------------------------------------------------------------------------------------------------
# Unit tests

# enable CTest testing
enable_testing ()

# Add a testing executable
#add_executable (cpp_unit_tests cpp/unit_tests.cpp)

#target_link_libraries (cpp_unit_tests
#        cpp_api
#        gtest
#        gtest_main
#)

#add_test (test_all cpp_unit_tests)

