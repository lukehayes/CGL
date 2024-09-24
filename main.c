#include "xx/window.h"

int main(int argc, char *argv[])
{
    Window* window = WindowCreate(800,600, "Title");

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


        glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glClearColor(0,0,0,1);

        SDL_GL_SwapWindow(window->frame);
    }


    WindowDestory(window);
}
