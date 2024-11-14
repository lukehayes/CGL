#ifndef GL_DEBUG_PROG_H
#define GL_DEBUG_PROG_H

#include "glad/glad.h"
#include "stdio.h"

/**
* This file is purely for testing a basic OpenGL setup.
*/

typedef struct GLShader
{
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

} GLShader;

typedef struct GLProgram
{
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    GLShader shader;

} GLProgram;


GLShader GLInitShader();

GLProgram GLInitProgram();

#endif // !GL_DEBUG_PROG_H
