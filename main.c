#include "xx/window.h"

int main(int argc, char *argv[]) {
    
    Window* window = WindowCreate(800,600, "Title");

    while(1)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        glClearColor(0,0,0,1);

        SDL_GL_SwapWindow(window->frame);
    }


    WindowDestory(window);
}
