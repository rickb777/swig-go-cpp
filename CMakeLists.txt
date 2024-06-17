cmake_minimum_required (VERSION 3.27)
#set (CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Go_Swig_Cpp_demo)

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

include_directories ("cpp")

set (cpp_api_sources
        cpp/Reverse.cpp
        cpp/Palindrome.cpp
)

add_library (cpp_api
        ${cpp_api_sources}
)

#--------------------------------------------------------------------------------------------------
# the 'cmd' directory holds runnable commands

add_subdirectory (cmd)
