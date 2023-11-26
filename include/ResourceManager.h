//
// Created by Angel Hernandez on 11/21/23.
//

#ifndef OOP_FINAL_PROJECT_RESOURCEMANAGER_H
#define OOP_FINAL_PROJECT_RESOURCEMANAGER_H

#include <map>
#include <string>

#include <GL/glew.h>

#include "Texture.h"
#include "Shader.h"

class ResourceManager {
public:
    // Resource Storage
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Texture2D> textures;

    // Loads (and generates) a shader program from file loading view,
    // fragment (and geometry) shader's source code. If gShaderFile is not
    // nullptr, it also loads a geometry shader
    static Shader loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile,
                             const GLchar *gShaderFile, std::string name);

    // Retrieves a stored shader
    static Shader getShader(std::string name);

    // Loads (and generates) a texture form file
    static Texture2D loadTexture(const GLchar *file, GLboolean alpha, std::string name);

    // Retrieves a stored texture
    static Texture2D getTexture(std::string name);

    // Properly de-allocates all loaded resources
    static void clear();

private:
    /*
     * Private Constructor, we do not want any actual resource manager objects
     * Its members and functions should be publicly available (static).
     * */
    ResourceManager() {};

    // Loads and generates a shader from file
    static Shader
    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

    // Loads a single texture from file
    static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};


#endif //OOP_FINAL_PROJECT_RESOURCEMANAGER_H
