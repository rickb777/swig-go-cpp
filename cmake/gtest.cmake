# see http://google.github.io/googletest/quickstart-cmake.html

# GoogleTest requires at least C++14 but we've adopted C++17 instead
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include (FetchContent)

FetchContent_Declare (
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
#        SYSTEM
        FIND_PACKAGE_ARGS NAMES GTest
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
#set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable (googletest)
