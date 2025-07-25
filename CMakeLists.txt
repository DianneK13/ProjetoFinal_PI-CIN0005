cmake_minimum_required(VERSION 3.31)
project(ProjetoFinal_PI_CIN0005)

set(CMAKE_CXX_STANDARD 14)

include_directories(include external/raylib/src)

add_subdirectory(external/raylib)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(ProjetoFinal_PI_CIN0005
        src/main.c
        include/game.h
        include/player.h
        include/fases.h
        include/utility.h
        src/game.c
        src/fases.c
        src/utility.c
        src/player.c)

# Linka com raylib e libs do sistema
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} raylib m pthread dl rt X11)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} raylib "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()
