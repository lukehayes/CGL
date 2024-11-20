#ifndef GL_DEBUG_PROG_H
#define GL_DEBUG_PROG_H

#include "glad/glad.h"
#include "xx/gl/shader.h"
#include "xx/gl/texture.h"

/**
* This file is purely for testing a basic OpenGL setup.
*/

typedef struct GLProgram
{
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    GLShader shader;
    Texture* texture;

} GLProgram;

GLProgram GLInitProgram();

#endif // !GL_DEBUG_PROG_H
