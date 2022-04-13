if(APPLE)
  # set(CMAKE_BUILD_RPATH "@executable_path/../src")

  # To search shared libraries in the same folder
  set(CMAKE_INSTALL_RPATH "@executable_path")
endif(APPLE)

add_executable(testhello testhello.c)

target_link_libraries(testhello PUBLIC hello)

install(TARGETS testhello
    RUNTIME DESTINATION ${INSTALL_DIR})