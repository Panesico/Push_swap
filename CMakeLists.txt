cmake_minimum_required(VERSION 3.12)

project(test)
include_directories(libft)
file(GLOB SOURCES_LIBFT "libft/*.c")
add_library(LIBFT STATIC ${SOURCES_LIBFT})
include_directories(includes)
file(GLOB SOURCES_PUSH_SWAP "srcs/*.c")
add_library(PUSH_SWAP STATIC ${SOURCES_PUSH_SWAP})
file(GLOB SOURCES "srcs/*.c" "libft/*.c")
add_executable(test ${SOURCES})

