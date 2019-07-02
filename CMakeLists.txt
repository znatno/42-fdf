cmake_minimum_required(VERSION 3.8)
project(FdF C)

include_directories(libft minilibx_macos)
link_directories(libft minilibx_macos)

set(CMAKE_C_STANDARD 99)

add_executable(FdF main.c read.c struct.c)
target_link_libraries(FdF -lft -lmlx "-framework OpenGL" "-framework AppKit")