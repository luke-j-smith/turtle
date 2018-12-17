/* 
 * Contains main() for Turtle interpreter and nothing else - 
 * Facilitates easy testing (ie, just swap this file out). 
 */ 
#include "turtle1.h"
#include "turtle_interp1.h"

int main(int argc, char *argv[])
{
  Prog *p = NULL ; 
  FILE *progFile = NULL ; 
  
  /* Clean up all SDL output when we exit. */
  atexit(SDL_Quit) ;
   
  /* Ensure correct number of inputs on command line. */ 
  if(argc != EXPECTED_NUMBER_OF_COMMAND_LINE_ARGS){  
    CODE_ERROR(ARGC, Argc) ; 
  }
  
  p = memory_for_Prog() ; 
    
  if(pointer_is_null(p)){
    CODE_ERROR(PROG_MEM, ProgMem) ; 
  }
    
  set_up_program(p, progFile, argv[1]) ;
    
  set_up_functions(p) ;  
  
  /* Set the place in the program to start of MAIN. */ 
  p->place = p->mainStart ; 
    
  interpreter_for_program_main(p) ; 
  
  /* Keep SDL display until event occurs (click, etc.). */ 
  keep_sdl_until_finished(p->sw) ; 
          
  free_program_memory(&p) ;     

  return 0 ; 
}

