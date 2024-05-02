# see http://google.github.io/googletest/quickstart-cmake.html

# GoogleTest requires at least C++14
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include (FetchContent)

FetchContent_Declare (
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
        #        SUBBUILD_DIR ${PROJECT_BINARY_DIR}/googletest-subbuild
        #        BINARY_DIR ${PROJECT_BINARY_DIR}/googletest-build
        #        SOURCE_DIR ${PROJECT_BINARY_DIR}/googletest-src
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable (googletest)

set (GTEST_INCLUDE ${PROJECT_BINARY_DIR}/googletest-src/googletest/include)
set (INCLUDE_DIRECTORIES ${GTEST_INCLUDE} ${INCLUDE_DIRECTORIES})