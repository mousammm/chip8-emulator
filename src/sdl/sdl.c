#include "sdl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sdl_init(sdl_t *sdl){
     if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) !=0 )) {
        fprintf(stderr, "Could not initialized SDL: %s\n",SDL_GetError());
        return false; //failed
     }   

   // create a window 
    sdl->window = SDL_CreateWindow("Chip8",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCALE_WINDOW*64,SCALE_WINDOW*32,SDL_WINDOW_SHOWN);
    if (!sdl->window) {
        fprintf(stderr, "Could not create Window: %s\n",SDL_GetError());
        return false; //failed
    }

   // create a renderer 
   sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
     if (!sdl->renderer) {
        fprintf(stderr, "Could not create Render: %s\n",SDL_GetError());
        return false; //failed
    }
    return true;
}

void sdl_cleanup(sdl_t *sdl){
     if(sdl->window) SDL_DestroyWindow(sdl->window);
     if(sdl->renderer) SDL_DestroyRenderer(sdl->renderer);
     SDL_Quit();
}

void sdl_render_frame(sdl_t *sdl){
       SDL_SetRenderDrawColor(sdl->renderer,0,0,100,255); // set bg color
       SDL_RenderClear(sdl->renderer); // clear initial renderer
       SDL_RenderPresent(sdl->renderer); // show actual window/update display
}

bool sdl_handle_inputs(void){
       SDL_Event event;
       while (SDL_PollEvent(&event)) {
          switch (event.type) {
             case SDL_QUIT:
                return false;
               break;
             case SDL_KEYDOWN:
                  switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        printf("Escape exiting\n");
                        return false;
                        break;
                    case SDLK_SPACE:
                        printf("Space pressed\n");
                        break;
                }
               break;
             case SDL_KEYUP:
               break;
             default:
               break;
          }
       }
    return true;
}


void sdl_show_display(sdl_t *sdl){

    bool running = true;
    while (running) {
      //handle inputs
     running = sdl_handle_inputs();

      // render frame 
      sdl_render_frame(sdl);

      SDL_Delay(16);
    }
  }
