# CSE 165 Final Project

## Game was made to run on MacOS

The application was made in [CLion](https://www.jetbrains.com/clion/).
So I am unsure if the application will run properly in other IDE's.

This project was made following the tutorial made by [Learning OpenGL](https://learnopengl.com).

Dependencies:

- GLEW
- GLFW
- GLM
- [SOIL](https://github.com/kbranigan/Simple-OpenGL-Image-Library)
- ASSIMP
- Freetype

All dependencies (except SOIL) were installed using Homebrew for MacOS.

**_If you do not have Homebrew on your Mac system follow the instructions for installation
at the following:_** [Homebrew](https://brew.sh)

To install dependencies run the following commands in a new terminal:

`brew install assimp freetype glm glfw glew`

Once the dependencies have been installed into the system. _Assuming you have [CMAKE](https://cmake.org) and Make
already on your system._

In the terminal Make a build folder in the project folder: `oop-final-project % mkdir build`

    |-oop-final-project

        |--build

        |--include

        |--src

In a terminal move into the build folder.

`cd build`

Then you will generate the Makefile using the command:

`cmake ../`

Then, in the same build folder, you will build the Makefile using the command:

`make`

**_The first time you run this command, it will fail. That is fine, just run the command again and it should work._**