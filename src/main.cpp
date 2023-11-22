#include "Base.h"

void key_callback(GLFWwindow* window, const int key, int scancode, const int action, const int mode) {
    // if you press ESC and set windowShouldClose to True, the external
    // loop will close the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    std::cout << "ESC\n" << mode;
}

int main() {
    // This is required to use functions not included
    // in opengl.lib
    glewExperimental = GL_TRUE;

    // Initialize GLFW library
    if (!glfwInit())
        return -1;

    // Define version and compatibility settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create window and context
    GLFWwindow* window = glfwCreateWindow(1920, 1440, "Game", nullptr, nullptr);

    if (!window) {
        // null will be returned if creation fails
        glfwTerminate();
        return -1;
    }

    // Establish the window's context current
    glfwMakeContextCurrent(window);

    // Specifies how many monitor-refreshes GLFW should wait
    // before swapping the backbuffer and the displayed frame.
    // Also known as V-Sync
    glfwSwapInterval(0);

    glfwSetKeyCallback(window, key_callback); // Registering Callbacks

    if (glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
        glfwTerminate();
    }

    //Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        // Select empty color RGBA
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
