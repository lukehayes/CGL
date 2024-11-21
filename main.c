#include "xx/window.h"
#include "xx/gl/debug_program.h"
#include "xx/gl/texture.h"
#include "xx/gl/camera3d.h"
#include "xx/math/rand.h"
#include "cglm/cglm.h"
#include <cglm/affine-pre.h>

typedef struct Entity
{
    vec3 position;
    vec3 rotation;
    vec3 scale;
    vec3 color;
} Entity;


void Draw(GLProgram* program, Entity* entity, Camera3D* camera)
{
    mat4 modelMatrix      = GLM_MAT4_IDENTITY_INIT;

    glUseProgram(program->shader.program);

    // glm_rotated(modelMatrix, sin(c1) / 10.0, (vec3){1,1,1});
    glm_translate(modelMatrix, entity->position);

    glm_scale(modelMatrix, entity->scale);

    glBindTexture(GL_TEXTURE_2D, program->texture->texture);
    glBindVertexArray(program->vao);


    Camera3DUpdate(camera, &program->shader);
    GLShaderUniformMat4(&program->shader, "uModel", modelMatrix);
    GLShaderUniform3F(&program->shader, "uColor", 
                                        entity->color[0],
                                        entity->color[1],
                                        entity->color[2]);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main(int argc, char *argv[])
{
    Window* window = WindowCreate(800,600, "Title");

    GLProgram prog   = GLInitProgram("../assets/images/debug16.png");
    GLShader shader  = GLShaderInit();
    Camera3D camera  = Camera3DCreate((vec3){0.0f,0.0f,10.0f});
    GLProgram prog2   = GLInitProgram("../assets/images/debug32.png");

    prog.shader      = shader;
    prog2.shader     = shader;
    Texture* texture = TextureCreate("../assets/images/debug16.png");

    Entity e1 = {.position = {0,0,-10}, .color = {1,0,0}};
    Entity e2 = {.position = {4,2,-10}, .color = {1,1,0}};

    const int MAX = 10;
    Entity entities[MAX][MAX];

    for(int x = 0; x<= MAX - 1; x++)
    {
        for(int y = 0; y<= MAX - 1; y++)
        {
            int px = RandRangeI(-30,30);
            int py = RandRangeI(-30,30);
            int pz = RandRangeI(-30,30);

            int cx = RandRangeI(0,1);
            int cy = RandRangeI(0,1);
            int cz = RandRangeI(0,1);

            int rx = RandRangeI(0,360);
            int ry = RandRangeI(0,360);
            int rz = RandRangeI(0,360);

            int sx = RandRangeI(1,4);
            int sy = RandRangeI(1,4);
            int sz = RandRangeI(1,4);

            Entity e = {
                .position = {px,py,pz}, 
                .rotation = {rx,ry,rz},
                .scale = {sx,sy,sz},
                .color = {cx,cy,cz}
            };
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

        camera.position[0] = -sin(c1) * 10.0;
        camera.position[1] = -cos(c1) * 10.0;
        camera.position[2] = cos(c1) * 10.0;

        /*e2.position[0]     = sin(c1) * 3.0;*/
        /*e2.position[1]     = cos(c1) * 3.0;*/
        /*e2.position[2]     = -cos(c1) * 10.0;*/

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
