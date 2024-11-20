#include "xx/gl/debug_program.h"

GLProgram GLInitProgram()
{
    GLProgram program;

    glGenVertexArrays(1, &program.vao);
    glBindVertexArray(program.vao);

    glGenBuffers(1, &program.vbo);

    float vertices[] = {
	//X     Y     Z     R     G     B     U(S)  V(T)
	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // top left
    };

    glBindBuffer(GL_ARRAY_BUFFER, 1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    glGenBuffers(1, &program.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, program.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	program.texture = TextureCreate("../assets/images/debug16.png");

    return program;
}
