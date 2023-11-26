#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Game.h"
#include "ResourceManager.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);

const GLuint screenWidth = 1920;
const GLuint screenHeight = 1440;

Game shooter(screenWidth, screenHeight);

int main(int argc, char *argv[]) {
    // Initialize GLFW library
    if (!glfwInit()) return -1;

    // Define version and compatibility settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window and context
    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "Shooter", nullptr, nullptr);

    if (!window) {
        // null will be returned if creation fails
        glfwTerminate();
        return -1;
    }

    // Establish the window's context current
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();
    glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

    // Specifies how many monitor-refreshes GLFW should wait
    // before swapping the back-buffer and the displayed frame.
    // Also known as V-Sync
    glfwSwapInterval(0);

    glfwSetKeyCallback(window, keyCallback); // Registering Callbacks

    // OpenGL Config.
    glViewport(0, 0, screenWidth, screenHeight);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC1_ALPHA);

    // Initialize game
    shooter.init();

    // DeltaTime variables
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;

    // Start Game within Menu State
    shooter.state = GameActive;

    while (!glfwWindowShouldClose(window)) {
        // Calculate delta time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        // Manage user input
        shooter.processInput(deltaTime);

        // Update game state
        shooter.update(deltaTime);

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shooter.render();

        glfwSwapBuffers(window);
    }

    // Delete all resources as loaded using the resource manager
    ResourceManager::clear();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    // if you press ESC and set windowShouldClose to True, the external
    // loop will close the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            shooter.keys[key] = GL_TRUE;
        } else if (action == GLFW_RELEASE) {
            shooter.keys[key] = GL_FALSE;
        }
    }
}
