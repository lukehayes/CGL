#include "xx/window.h"
#include "xx/gl/debug_program.h"
#include "xx/gl/texture.h"
#include "cglm/cglm.h"

int main(int argc, char *argv[])
{
    Window* window = WindowCreate(800,600, "Title");

    GLProgram prog  = GLInitProgram();
    GLShader shader = GLShaderInit();

    mat4 modelMatrix      = GLM_MAT4_IDENTITY_INIT;
    mat4 projectionMatrix = GLM_MAT4_IDENTITY_INIT;
    mat4 viewMatrix       = GLM_MAT4_IDENTITY_INIT;


    Texture texture = TextureCreate("../assets/images/debug16.png");

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

        glBindTexture(GL_TEXTURE_2D, texture.texture);
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
