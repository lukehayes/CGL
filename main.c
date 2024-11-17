#include "xx/window.h"
#include "xx/gl/debug_program.h"
#include "cglm/cglm.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char *argv[])
{
    Window* window = WindowCreate(800,600, "Title");

    GLProgram prog  = GLInitProgram();
    GLShader shader = GLShaderInit();

    mat4 modelMatrix      = GLM_MAT4_IDENTITY_INIT;
    mat4 projectionMatrix = GLM_MAT4_IDENTITY_INIT;
    mat4 viewMatrix       = GLM_MAT4_IDENTITY_INIT;


    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../assets/images/debug16.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture\n");
    }
    stbi_image_free(data);



    static float c1 = 0.0;


    int RUNNING = 1;
    while(RUNNING)
    {

        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_KEYDOWN)
            {
                switch (Event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        RUNNING = 0;
                        break;
                    default:
                        break;
                }
            }
        }

        c1 += 0.1;

        glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.program);

        /*glm_rotated(modelMatrix, sin(c1) / 10.0, (vec3){1,1,1});*/
        /*glm_translate(modelMatrix, (vec3){sin(c1) / 100.0, cos(c1) / 100.0,0});*/

        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(prog.vao);

        GLShaderUniformMat4(&shader, "model", modelMatrix);
        GLShaderUniformMat4(&shader, "projection", projectionMatrix);
        GLShaderUniformMat4(&shader, "view", viewMatrix);

        GLShaderUniform3F(&shader, "color", 0.2, 0.831, 0.427);

        /*glDrawArrays(GL_TRIANGLES, 0, 3);*/
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        SDL_GL_SwapWindow(window->frame);
    }


    WindowDestory(window);
}
