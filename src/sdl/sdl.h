#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCALE_WINDOW 10

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} sdl_t;

// function declaration
bool sdl_init(sdl_t *sdl);
void sdl_cleanup(sdl_t *sdl);
void sdl_render_frame(sdl_t *sdl);
bool sdl_handle_inputs(void);
void sdl_show_display(sdl_t *sdl);
 

#endif // SDL_H
