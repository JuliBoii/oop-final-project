cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(oop-final-project LANGUAGES CXX)

set(HEADER_FILES include/Game.h
        include/Shader.h
        include/Texture.h
        include/ResourceManager.h
)

set(SOURCE_FILES src/main.cpp
        src/Game.cpp
        src/Shader.cpp
        src/Texture.cpp
        src/ResourceManager.cpp
)

include(ExternalProject)
ExternalProject_Add(
        SOIL
        PREFIX "${CMAKE_BINARY_DIR}/lib"
        GIT_REPOSITORY https://github.com/kbranigan/Simple-OpenGL-Image-Library.git
        GIT_TAG "master"
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
)

# Prevent build on all targets build
set_target_properties(SOIL PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Define ${CMAKE_INSTALL_...} variables
include(GNUInstallDirs)

# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})

# Add target link
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW 2.2 REQUIRED)
find_package(ASSIMP 5.3 REQUIRED)
find_package(Freetype 2.13 REQUIRED)
find_package(glm REQUIRED)

#Execute compile command
add_executable(game ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(game glfw
        GLEW::glew
        assimp::assimp
        Freetype::Freetype
        glm::glm
        soil
        ${OPENGL})

target_include_directories(game PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

# Make sure third-party is built before executable
add_dependencies(game SOIL)


# FOR MAC
if (APPLE)
    target_link_libraries(game "-framework OpenGL")
    target_link_libraries(game "-framework GLUT")
    target_link_libraries(game "-framework Cocoa")
    target_link_libraries(game "-framework IOKit")
    target_link_libraries(game "-framework CoreVideo")
endif ()

