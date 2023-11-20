cmake_minimum_required(VERSION 3.26)
project(oop-final-project)

set(CMAKE_CXX_STANDARD 17)

set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.8/include/GLFW)
set(SOURCE_FILES src/main.cpp)

include_directories(${GLEW_H} ${GLFW_H})

# Add target link
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

#Execute compile command
add_executable(oop-final-project ${SOURCE_FILES})

# For MACOS
if (APPLE)
    target_link_libraries(oop-final-project "-framework OpenGL")
    target_link_libraries(oop-final-project "-framework GLUT")
    target_link_libraries(oop-final-project "-framework Cocoa")
    target_link_libraries(oop-final-project "-framework IOKit")
endif ()