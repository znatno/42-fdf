cmake_minimum_required(VERSION 3.13)
project(FdF C)

set(CMAKE_C_STANDARD 99)

include_directories(libft)
include_directories(minilibx_macos)
include_directories(libft/include)
include_directories(include)
link_directories(libft)
link_directories(minilibx_macos)

set(SOURCE
        src/main.c
        src/read.c
        src/fill.c
        src/view.c)

add_executable(FdF ${SOURCE})

target_link_libraries(FdF -lmlx -lft "-framework OpenGL" "-framework AppKit")