# Works with 3.11 and tested through 3.18
cmake_minimum_required(VERSION 3.11...3.18)

# Project name and a few useful settings. Other commands can pick up the results
project(
  BuildSharedLibraryExample
  VERSION 0.1
  DESCRIPTION "An example static library with CMake"
  LANGUAGES C)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
#   set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# RPATH setting for dynamic library
set(CMAKE_SKIP_RPATH FALSE)

if(APPLE)
  message(STATUS "Setting MacOSX RPath")
  message(STATUS "INSTALL_DIRS: ${CMAKE_INSTALL_PREFIX}/lib")
  # enable/disable `@rpath` in the install name for any shared library being built on macOS
  # note: default is TRUE, which result built dylib with install name like `@rpath/libtest_library.dylib`
  set(CMAKE_MACOSX_RPATH TRUE)

  # note: you should avoid change install name for any shared library being built on macOS
  # For recomendation, change `CMAKE_INSTALL_RPATH`
  # set(CMAKE_INSTALL_NAME_DIR "")
  # set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR TRUE)

  # Recommendations here for providing a fully relocatable executable/package by using `@executable_path` or `loader_path`
  set(CMAKE_INSTALL_RPATH "")
  # set(CMAKE_BUILD_RPATH "@executable_path")
  # keep build and install the same setting, otherwise the default `BUILD_RPATH` will set to an abosulate path to the shared library
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif(APPLE)

# The compiled library code is here
add_subdirectory(src)

# The tests code is here
add_subdirectory(tests)