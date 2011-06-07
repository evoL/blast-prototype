include_directories (
  .
  ${INCDIRS}
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
  ${LIBS}
)