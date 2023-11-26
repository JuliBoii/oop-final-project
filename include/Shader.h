//
// Created by Angel Hernandez on 11/21/23.
//

#ifndef OOP_FINAL_PROJECT_SHADER_H
#define OOP_FINAL_PROJECT_SHADER_H

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    GLint id;

    Shader() {}

    Shader &use();

    void compile(const GLchar *vertexSource, const GLchar *fragmentSource, const GLchar *geometrySource = nullptr);

    void setFloat(const GLchar *name, GLfloat value, GLboolean useShader = false);

    void setInteger(const GLchar *name, GLint value, GLboolean useShader = false);

    void setVector2F(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);

    void setVector2F(const GLchar *name, const glm::vec2 &value, GLboolean useShader = false);

    void setVector3F(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);

    void setVector3F(const GLchar *name, const glm::vec3 &value, GLboolean useShader = false);

    void setVector4F(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);

    void setVector4F(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);

    void setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);

private:
    // Checks if compilation or linking failed and if so, print the error logs
    static void checkCompileErrors(GLuint object, std::string type);
};

#endif //OOP_FINAL_PROJECT_SHADER_H
