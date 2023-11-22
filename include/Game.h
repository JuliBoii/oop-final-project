//
// Created by Angel Hernandez on 11/20/23.
//

#ifndef GAME_H
#define GAME_H

#include "Base.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game {
public:
    GameState State;
    GLboolean Keys[1024];
    GLuint Width, Height;

    Game(GLuint Width, GLuint Height);

    ~Game();

    // Initiaialize Game State
    void Init();

    // Game Loop
    // Splitiing the Render Logic from the
    // Movement Logic (ProcessInput)
    void ProcessInput(GLfloat dt);

    void Update(GLfloat dt);

    void Render();
};


#endif //GAME_H
