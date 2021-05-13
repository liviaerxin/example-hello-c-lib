if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../src")
endif(APPLE)

add_executable(testhello testhello.c)

target_link_libraries(testhello PUBLIC hello)
