#include <stdio.h>   // input/output 
#include <stdlib.h>  // exit(EXIT_SUCCESS)
#include "sdl/sdl.h"


int main(int argc,char **argv){
    (void) argc;
    (void) argv;

   //sdl initialisation
   sdl_t sdl = {0};
   if(!sdl_init(&sdl)) exit(EXIT_FAILURE);
   printf("SDL initialise seccessfully!\n");

   // sdl show display
   sdl_show_display(&sdl);
  
   // sdl cleanup
   sdl_cleanup(&sdl);
   printf("SDL cleanup seccessfully!\n");

    exit(EXIT_SUCCESS);
}

