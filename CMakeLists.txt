cmake_minimum_required(VERSION 3.26)
project(oop-final-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include/glm)

set(SOURCE_FILES src/main.cpp
        src/Game.cpp
        include/Game.h
)

# Add target link
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW 2.2 REQUIRED)
find_package(ASSIMP 5.3 REQUIRED)
find_package(Freetype 2.13 REQUIRED)
#find_package(GLM REQUIRED)

#Execute compile command
add_executable(game ${SOURCE_FILES})

#target_link_libraries(game glfw GLEW::glew assimp::assimp glm::glm ${OPENGL} ${FREETYPE_LIBRARIES})
target_link_libraries(game glfw GLEW::glew assimp::assimp ${OPENGL} ${FREETYPE_LIBRARIES})
target_include_directories(game PRIVATE ${GLM_H} ${FREETYPE_INCLUDE_DIRS})
target_include_directories(game PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

# FOR MAC
if (APPLE)
    target_link_libraries(game "-framework OpenGL")
    target_link_libraries(game "-framework GLUT")
    target_link_libraries(game "-framework Cocoa")
    target_link_libraries(game "-framework IOKit")
    target_link_libraries(game "-framework CoreVideo")
endif ()

