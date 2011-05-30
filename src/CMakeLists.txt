add_subdirectory (engine)

configure_file (
  "configuration.h.in"
  "configuration.h"
)

find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)
find_package (SDL_ttf REQUIRED)

if (NOT SDL_FOUND)
  message (FATAL_ERROR "SDL not found!")
endif ()

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
  ${SDL_INCLUDE_DIR}
  ${SDLIMAGE_INCLUDE_DIR}
  ${SDLTTF_INCLUDE_DIR}
)

add_executable (
  cuboid
  main.cpp
  ${ADDITIONAL}
)

target_link_libraries (
  cuboid
  engine
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLTTF_LIBRARY}
)