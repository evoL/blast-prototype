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

file (GLOB SRCS "*.cpp")
file (GLOB HDRS "*.h") 

add_library (
  engine
  ${SRCS}
  ${HDRS}
)

target_link_libraries (
  engine
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLTTF_LIBRARY}
)