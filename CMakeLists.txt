cmake_minimum_required (VERSION 2.8)

project (cuboid)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set (Boost_USE_STATIC_LIBS    OFF)
set (Boost_USE_MULTITHREADED  ON)
set (Boost_USE_STATIC_RUNTIME ON)

find_package (SDL REQUIRED)
find_package (SDL_image REQUIRED)
find_package (SDL_ttf REQUIRED)
find_package (Boost 1.44 REQUIRED)

if (SDL_FOUND)
    message ("-- SDL found")
endif()
if (Boost_FOUND)
    message ("-- Boost found: version ${Boost_LIB_VERSION}")
endif ()

set (INCDIRS
    ${SDL_INCLUDE_DIR}
    ${SDLIMAGE_INCLUDE_DIR}
    ${SDLTTF_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
)
set (LIBS
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY}
    ${SDLTTF_LIBRARY}
    ${Boost_LIBRARIES}
)

add_subdirectory (src)