//
// Created by Angel Hernandez on 11/21/23.
//

#ifndef OOP_FINAL_PROJECT_TEXTURE_H
#define OOP_FINAL_PROJECT_TEXTURE_H

#include <GL/glew.h>

class Texture2D {
public:
    // Holds the id of the texture object, used for all texture operations to reference to this particular texture
    GLuint id;
    // Texture image dimensions
    GLuint width, height; // width and height of loaded image in pixels
    // Texture Format
    GLuint internalFormat; // Format of texture object
    GLuint imageFormat; // Format of loaded image
    // Texture configuration
    GLuint wrapS; // Wrapping mode on S axis
    GLuint wrapT; // Wrapping mode on T axis
    GLuint filterMin; // Filtering mode if texture pixels < screen pixels
    GLuint filterMax; // Filtering mode if texture pixels > screen pixels
    // Constructor (sets default texture modes)
    Texture2D();

    // Generates texture from image data
    void generate(GLuint WIDTH, GLuint HEIGHT, unsigned char *data);

    // Binds the texture as the current active GL_TEXTURE_2D texture object
    void bind() const;
};

#endif //OOP_FINAL_PROJECT_TEXTURE_H
