#include "xx/gl/shader.h"
#include "glad/glad.h"
#include <stdio.h>
#include <stdlib.h>
#include "xx/io.h"


GLShader GLShaderInit()
{
    GLShader shader;

    const char *vertexShaderSource = IOReadFile("../assets/shaders/VSH-Camera3D.glsl");
    const char *fragmentShaderSource = IOReadFile("../assets/shaders/FSH-Camera3D.glsl");

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

void GLShaderUniform1F(GLShader* shader, const char* name, float v1)
{
    glUniform1f(
        glGetUniformLocation(shader->program, name),
        v1);
}

void GLShaderUniform2F(GLShader* shader, const char* name, float v1, float v2)
{
    glUniform2f(
        glGetUniformLocation(shader->program, name),
        v1,v2);
}

void GLShaderUniform3F(GLShader* shader, const char* name, float v1, float v2, float v3)
{
    glUniform3f(
        glGetUniformLocation(shader->program, name),
        v1,v2,v3);
}

void GLShaderUniform4F(GLShader* shader, const char* name, float v1, float v2, float v3, float v4)
{
    glUniform4f(
        glGetUniformLocation(shader->program, name),
        v1,v2,v3,v4);
}

void GLShaderUniformMat4(GLShader* shader, const char* name, mat4 m)
{
    glUniformMatrix4fv(
        (glGetUniformLocation(shader->program, name)), 
        1, GL_FALSE, m[0]);
}
