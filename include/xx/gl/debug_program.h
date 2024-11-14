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


GLShader GLInitShader()
{
    GLShader shader;

    const char *vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";



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
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shader;
}


GLProgram GLInitProgram()
{
    GLProgram program;
    
    glGenVertexArrays(1, &program.vao);
    glBindVertexArray(program.vao);


    glGenBuffers(1, &program.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, 1);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    program.shader = GLInitShader();

    return program;
}

#endif // !GL_DEBUG_PROG_H
