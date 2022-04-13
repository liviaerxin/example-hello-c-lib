if(APPLE)
  # Default is @rpath, if you want to change apply these
  # set(CMAKE_INSTALL_NAME_DIR "@loader_path")

  # To search other shared libraries in the same folder
  set(CMAKE_INSTALL_RPATH "@loader_path")
endif(APPLE)

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(hello hello.c)

target_include_directories(hello PUBLIC ../include)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

install(TARGETS hello DESTINATION ${INSTALL_DIR})