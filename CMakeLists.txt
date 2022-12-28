cmake_minimum_required(VERSION 3.14)
project(pmvankerSocket LANGUAGES CXX)
# required for unit testing using CMake's ctest command
include(CTest)
enable_testing()
################################################################################
if(USE_GCOV)
    SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    SET(GCC_COVERAGE_LINK_FLAGS "-lgcov")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )               
endif(USE_GCOV)
################################################################################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)
### Build external library - libpmvankerSocket
add_library(pmvankerSocket SHARED
  library/libpmvankerSocket/Socket.cpp
  library/libpmvankerSocket/Socket.hpp
  )
add_library(doctest INTERFACE IMPORTED)
target_compile_definitions(pmvankerSocket PRIVATE PMVANKERSOCKET_LIBRARY)
add_subdirectory(ClientServerApp)
add_subdirectory(MultiClientServerApp)