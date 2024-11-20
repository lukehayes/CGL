#include "xx/window.h"
#include "xx/gl/debug_program.h"
#include "xx/gl/texture.h"
#include "xx/gl/camera3d.h"
#include "cglm/cglm.h"

typedef struct Entity
{
    vec3 position;
    vec3 color;
} Entity;



void Draw(GLProgram* program, Entity* entity, Camera3D* camera)
{
    mat4 modelMatrix      = GLM_MAT4_IDENTITY_INIT;

    glUseProgram(program->shader.program);

    // glm_rotated(modelMatrix, sin(c1) / 10.0, (vec3){1,1,1});
     glm_translate(modelMatrix, entity->position);

    glBindTexture(GL_TEXTURE_2D, program->texture->texture);
    glBindVertexArray(program->vao);


    Camera3DUpdate(camera, &program->shader);
    GLShaderUniformMat4(&program->shader, "model", modelMatrix);
    GLShaderUniform3F(&program->shader, "uColor", 
                                        entity->color[0],
                                        entity->color[1],
                                        entity->color[2]);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main(int argc, char *argv[])
{
    Window* window = WindowCreate(800,600, "Title");

    GLProgram prog  = GLInitProgram();
    GLShader shader = GLShaderInit();
    Camera3D camera = Camera3DCreate((vec3){0.0f,0.0f,5.0f});
    GLProgram prog2  = GLInitProgram();


    prog.shader = shader;
    prog2.shader = shader;
    Texture* texture = TextureCreate("../assets/images/debug16.png");

    Entity e1 = {.position = {0,0,-10}, .color = {1,0,0}};
    Entity e2 = {.position = {4,2,-10}, .color = {1,1,0}};

    const int MAX = 10;
    Entity entities[MAX][MAX];

    for(int x = 0; x<= MAX - 1; x++)
    {
        for(int y = 0; y<= MAX - 1; y++)
        {
            Entity e = {.position = {3 * x,3 * y,-3}, .color = {1,x / 2.0,y / 2.0}};
            entities[x][y] = e;
        }
    }

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

        c1 += 0.01;



    glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        camera.position[0] = sin(c1) * 10.0;
        camera.position[1] = cos(c1) * 10.0;
        camera.position[2] = -cos(c1) * 100.0;

        e2.position[0] = sin(c1) * 3.0;
        e2.position[1] = cos(c1) * 3.0;
        e2.position[2] = -cos(c1) * 10.0;

        for(int x = 0; x<= MAX - 1; x++)
        {
            for(int y = 0; y<= MAX - 1; y++)
            {
                Entity e = entities[x][y];
                Draw(&prog, &entities[x][y], &camera);
            }

        }

        Draw(&prog, &e1, &camera);
        Draw(&prog2, &e2, &camera);

        SDL_GL_SwapWindow(window->frame);
    }


    TextureDestroy(texture);

    WindowDestory(window);
}
