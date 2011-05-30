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

add_library (
  engine
  Engine.cpp
  EventListener.cpp
  Events.cpp
  Screen.cpp
  Surface.cpp
  ImageSurface.cpp
  TextSurface.cpp
)

target_link_libraries (
  engine
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLTTF_LIBRARY}
)