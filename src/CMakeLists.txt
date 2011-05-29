add_subdirectory (engine)

configure_file (
  "configuration.h.in"
  "configuration.h"
)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  # Mac OS X
  set (
    ADDITIONAL
    ../SDLMain.m
  )
endif ()

include_directories (
  .
  engine
)

add_executable (
  cuboid
  main.cpp
  ${ADDITIONAL}
)

target_link_libraries (
  cuboid
  engine
)