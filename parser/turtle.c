/* 
 * Contains main() for the Turtle parser and nothing else - 
 * Facilitates easy testing (ie, just swap this file out). 
 */ 
#include "turtle.h"
#include "turtle_parser.h"


int main(int argc, char *argv[])
{
  Prog *p = NULL ; 
  FILE *progFile = NULL ; 
  
  /* Ensure correct number of inputs on command line. */ 
  if(argc != EXPECTED_NUMBER_OF_COMMAND_LINE_ARGS){  
    CODE_ERROR(ARGC, Argc) ; 
  }
  
  p = memory_for_Prog() ; 
    
  if(pointer_is_null(p)){
    CODE_ERROR(PROG_MEM, ProgMem) ; 
  }
    
  set_up_program(p, progFile, argv[1]) ; 
  
  /* Once file has been correctly read in, start parsing. */
  parser_program_main(p) ; 
        
  free_program_memory(&p) ;     

  return 0 ; 
}
