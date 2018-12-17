/* 
 * Contains main() for Turtle interpreter and nothing else - 
 * Facilitates easy testing (ie, just swap this file out). 
 */ 
#include "turtle2.h"
#include "turtle_interp2.h"

int main(void)
{
  unsigned int checkIfEnd ; 
  Prog *p = NULL ; 
  
  /* Clean up all SDL output when we exit. */
  atexit(SDL_Quit) ;
  
  p = memory_for_Prog() ; 
    
  if(pointer_is_null(p)){
    CODE_ERROR(PROG_MEM, ProgMem) ; 
  }
    
  initialise_Prog(p) ; 
  
  interpreter_for_program_main(p) ; 
  

  do{
    checkIfEnd = read_in_string_from_command(p) ; 
  } while(checkIfEnd) ;
  
  /* Keep SDL display until event occurs (click, etc.).*/ 
  keep_sdl_until_finished(p->sw) ;
              
  free_program_memory(&p) ;     

  return 0 ; 
}



