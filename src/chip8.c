#include <stdio.h>   // input/output 
#include <stdbool.h> // bool fun 
#include <stdlib.h>  // exit(EXIT_SUCCESS)
#include <SDL2/SDL.h> // audio video inputs 

#define SCALE_WINDOW 20

typedef struct {
   SDL_Window *window;
   SDL_Renderer *renderer;
} sdl_t;

bool init_sdl(sdl_t *sdl);
void sdl_cleanup(sdl_t *sdl);
void sdl_show_display(sdl_t *sdl);
 
int main(int argc,char **argv){
    (void) argc;
    (void) argv;

   sdl_t sdl = {0};
   if(!init_sdl(&sdl)) exit(EXIT_FAILURE);
   printf("SDL initialise seccessfully!\n");

   sdl_show_display(&sdl);
  
   sdl_cleanup(&sdl);
   printf("SDL cleanup seccessfully!\n");

    exit(EXIT_SUCCESS);
}

bool init_sdl(sdl_t *sdl){
     if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) !=0 )) {
        fprintf(stderr, "Could not initialized SDL: %s\n",SDL_GetError());
        return false; //failed
     }   

   // create a window 
    sdl->window = SDL_CreateWindow("Chip8",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCALE_WINDOW*64,SCALE_WINDOW*32,0);
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
};

void sdl_cleanup(sdl_t *sdl){
     SDL_DestroyWindow(sdl->window);
     SDL_DestroyRenderer(sdl->renderer);
     SDL_Quit();
};

void sdl_show_display(sdl_t *sdl){
   bool running = true;
   while (running) {
       SDL_Event event;
       while (SDL_PollEvent(&event)) {
          switch (event.type) {
             case SDL_QUIT:
               running = false;
               break;
             case SDL_KEYDOWN:
                  switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        printf("Escape pressed - exiting\n");
                        running = false;
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
       SDL_SetRenderDrawColor(sdl->renderer,0,10,255,255); // set bg color
       SDL_RenderClear(sdl->renderer); // clear initial renderer
       SDL_RenderPresent(sdl->renderer); // show actual window/update display

       SDL_Delay(16); // 60hz
   };
}
