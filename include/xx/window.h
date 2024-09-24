#ifndef XX_WINDOW_H
#define XX_WINDOW_H

#include "glad/glad.h"
#include "SDL2/SDL.h"
#include <stdlib.h>

typedef struct Window
{
    SDL_Window* frame;
    SDL_GLContext* context;


} Window;


Window* WindowCreate(int width, int height, const char* title)
{

    Window* window = malloc(sizeof(Window));


	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		fprintf(stderr, "ERROR: %s\n", SDL_GetError());
	}

	SDL_GL_LoadLibrary(NULL);

	// Request an OpenGL 4.6 context (should be core)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	// Also request a depth buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window->frame = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width, height,
	    SDL_WINDOW_OPENGL);

	window->context = SDL_GL_CreateContext(window->frame);

	SDL_GL_MakeCurrent(window->frame,
	window->context);

	// Check OpenGL properties
	printf("OpenGL loaded\n");
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	printf("Vendor:   %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version:  %s\n", glGetString(GL_VERSION));
    
    return window;
}


void WindowDestory(Window* window)
{
	SDL_GL_DeleteContext(window->context);
	SDL_DestroyWindow(window->frame);

    free(window);
    window = NULL;
}

#endif
