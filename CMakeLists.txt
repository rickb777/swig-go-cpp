cmake_minimum_required (VERSION 3.27)
#set (CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Go_Swig_Cpp_demo)

include (cmake/go.cmake)

#==================================================================================================
# SWIG integration

find_package (SWIG)

if (!SWIG_FOUND)
    message ("SWIG not found. Please install SWIG (>=v4.2.0) or fix its installation.")
    return ()
endif ()

message ("Found SWIG ${SWIG_VERSION}")

#==================================================================================================
# Address sanitization
# see e.g. https://felsoci.sk/blog/using-address-sanitizer-asan-in-a-cmake-project.html

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fsanitize=undefined -fsanitize=address")
    target_link_options (asan-demo BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address)
endif ()

#==================================================================================================

include (UseSWIG)

#--------------------------------------------------------------------------------------------------

set (CONTACTS_SWIG_FILE "contacts/interface.i")
set_source_files_properties (${CONTACTS_SWIG_FILE} PROPERTIES
        CPLUSPLUS ON
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

set (CONTACTS_SWIG_MODULE_NAME "contacts")

swig_add_library (${CONTACTS_SWIG_MODULE_NAME}
        TYPE SHARED
        LANGUAGE go
        OUTPUT_DIR "${CMAKE_SOURCE_DIR}/contacts" # in-place files make Go development easier
        SOURCES ${CONTACTS_SWIG_FILE}
)

set_target_properties (${CONTACTS_SWIG_MODULE_NAME} PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

#--------------------------------------------------------------------------------------------------

set (PAL_SWIG_FILE "pal/interface.i")
set_source_files_properties (${PAL_SWIG_FILE} PROPERTIES
        CPLUSPLUS ON
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

set (PAL_SWIG_MODULE_NAME "paler")

swig_add_library (${PAL_SWIG_MODULE_NAME}
        TYPE SHARED
        LANGUAGE go
        OUTPUT_DIR "${CMAKE_SOURCE_DIR}/pal" # in-place files make Go development easier
        SOURCES ${PAL_SWIG_FILE}
)

set_target_properties (${PAL_SWIG_MODULE_NAME} PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

#--------------------------------------------------------------------------------------------------

set (REV_SWIG_FILE "rev/interface.i")
set_source_files_properties (${REV_SWIG_FILE} PROPERTIES
        CPLUSPLUS ON
        SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

set (REV_SWIG_MODULE_NAME "rever")

swig_add_library (${REV_SWIG_MODULE_NAME}
        TYPE SHARED
        LANGUAGE go
        OUTPUT_DIR "${CMAKE_SOURCE_DIR}/rev" # in-place files make Go development easier
        SOURCES ${REV_SWIG_FILE}
)

set_target_properties (${REV_SWIG_MODULE_NAME} PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

#==================================================================================================

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

#==================================================================================================
# Application Code

include_directories (".")

set (contacts_api_sources
        contacts/Contacts.cpp
        contacts/Contacts.h
)

set (pal_api_sources
        pal/Palindrome.cpp
        pal/Palindrome.h
)

set (rev_api_sources
        rev/Reverse.cpp
        rev/Reverse.h
)

add_library (cpp_api
        ${pal_api_sources}
        ${rev_api_sources}
)

#--------------------------------------------------------------------------------------------------
# the 'cmd' directory holds runnable Go & C++ commands

add_executable (cpp_main
        cmd/main.cpp
        ${contacts_api_sources}
        ${pal_api_sources}
        ${rev_api_sources}
)

add_subdirectory (cmd)

#target_link_libraries (cpp_main
#        ${cpp_api}
#)
