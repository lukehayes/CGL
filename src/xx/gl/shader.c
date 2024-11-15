#include "xx/gl/shader.h"
#include "glad/glad.h"
#include <stdio.h>
#include <stdlib.h>
#include "xx/io.h"

GLShader GLShaderInit()
{
    GLShader shader;

    const char *vertexShaderSource = IOReadFile("../assets/shaders/VSH-Basic.glsl");
    const char *fragmentShaderSource = IOReadFile("../assets/shaders/FSH-Basic.glsl");

   // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s\n", infoLog );
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED %s\n", infoLog );
    }
    // link shaders
    shader.program = glCreateProgram();
    glAttachShader(shader.program, vertexShader);
    glAttachShader(shader.program, fragmentShader);
    glLinkProgram(shader.program);
    // check for linking errors
    glGetProgramiv(shader.program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader.program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED %s\n", infoLog );
    }

    free(vertexShaderSource);
    free(fragmentShaderSource);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shader;
}
