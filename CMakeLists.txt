cmake_minimum_required (VERSION 3.27)
#set (CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Go_Swig_Cpp_demo)

include (cmake/gtest.cmake)
include (cmake/go.cmake)

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

message("GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}") # Include GoogleTest directories
include_directories(${googletest_SOURCE_DIR}/googletest/include) # Include GoogleTest directories
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

set_target_properties (${SWIG_MODULE_NAME} PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

#--------------------------------------------------------------------------------------------------
# Application Code

message ("----- cpp api -----")
message ("googletest_SOURCE_DIR: ${googletest_SOURCE_DIR}")

include_directories ("cpp")

set (cpp_api_sources
        cpp/Reverse.cpp
        cpp/Palindrome.cpp
)

add_library (cpp_api
        ${cpp_api_sources}
)

#--------------------------------------------------------------------------------------------------
# Unit tests

# enable GTest testing
enable_testing ()

set (test_sources
        cpp/unit_tests.cpp.txt
)

#file (GLOB_RECURSE test_sources CONFIGURE_DEPENDS
#        cpp/unit_tests.cpp
#)

#add_executable (all_tests
#        ${test_sources}
#        ${cpp_api_sources}
#)

# Add a testing executable
#add_executable (cpp_unit_tests cpp/unit_tests.cpp)

#target_link_libraries (all_tests
#        GTest::gtest_main
#)

include (GoogleTest)
#gtest_discover_tests (all_tests)

#--------------------------------------------------------------------------------------------------
# the 'cmd' directory holds runnable commands

add_subdirectory (cmd)
