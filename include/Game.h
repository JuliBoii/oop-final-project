//
// Created by Angel Hernandez on 11/20/23.
//

#ifndef OOP_FINAL_PROJECT_GAME_H
#define OOP_FINAL_PROJECT_GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Represents the current state of the Game
enum GAMESTATE {
    GameActive,
    GameMenu,
    GameWin
};

class Game {
public:
    GAMESTATE state;
    GLboolean keys[1024];
    GLuint width, height;

    Game(GLuint width, GLuint height);

    ~Game();

    // Initialize Game State
    void init();

    // Game Loop
    // Splitting the render Logic from the
    // Movement Logic (processInput)
    void processInput(GLfloat dt);

    void update(GLfloat dt);

    void render();
};


#endif //OOP_FINAL_PROJECT_GAME_H
