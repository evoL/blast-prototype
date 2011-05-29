set (
  SOURCES
  main.cpp
)

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

find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)
find_package (SDL_ttf REQUIRED)

if (NOT SDL_FOUND)
  message (FATAL_ERROR "SDL not found!")
endif ()

include_directories (
  .
  ${SDL_INCLUDE_DIR}
  ${SDLIMAGE_INCLUDE_DIR}
  ${SDLTTF_INCLUDE_DIR}
)

add_executable (
  cuboid
  ${SOURCES}
  ${ADDITIONAL}
)

target_link_libraries (
  cuboid
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLTTF_LIBRARY}
)