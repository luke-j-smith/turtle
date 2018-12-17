/* 
 * File contains definitions of all functions which are used 
 * set-up the program for the interpreter. 
 */ 
#include "turtle_interp_setup2.h"

/* Allocate space in memory for a pointer of type Prog. */ 
Prog *memory_for_Prog(void) 
{
  Prog *p = NULL ; 
  
  p = (Prog *)calloc(1, sizeof(Prog)) ; 
  
  return p ; 
}

/* Used to check if a pointer is null (eg, after calloc). */ 
unsigned int pointer_is_null(void *pointer)
{
  if(pointer == NULL)
  {
    return True ; 
  }

  return False ;
}

/* Sets starting values and allocates space for Prog ptr. */
void initialise_Prog(Prog *p)
{
  unsigned int i ; 
  
  p->program = memory_for_program(INITIAL_PROGRAM_SIZE) ;
  
  if(pointer_is_null(p->program)){
    CODE_ERROR(PROG_CONT_MEM, ProgContMem) ; 
  }
  
  p->capacity = INITIAL_PROGRAM_SIZE ; 
  
  p->place = STARTING_PLACE ;  
  
  p->inDoLoop = False ; 
  
  p->temp.value = STARTING_TEMP_VALUE ; 
      
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    p->var[i] = NULL ;   
  }
  
  p->currentMove = NO_MOVE ;
  
  initialise_turtle_position(&(p->turtle)) ; 
  
  Neill_SDL_Init(&(p->sw)) ;
    
  return ; 
}

void initialise_turtle_position(TurtlePos *turtle)
{
  turtle->current.x = TURTLE_STARTING_X ; 

  turtle->current.y = TURTLE_STARTING_Y ; 

  turtle->previous.x = TURTLE_STARTING_X ; 

  turtle->previous.y = TURTLE_STARTING_Y ; 
  
  turtle->theta = 0.0 ; 
  
  return ; 
} 

/* Allocate space for pointer of type char *, size 'size'.*/ 
char **memory_for_program(unsigned int size)
{
  char **program = NULL ; 
  
  program = (char **)calloc(size, sizeof(char *)) ; 
  
  return program ; 
}

/* Allocate space for a pointer of type char, size strLen.*/ 
char *memory_for_string(unsigned int strLen)
{
  char *string = NULL ; 
  
  string = (char *)calloc(strLen, sizeof(char)) ;
  
  return string ; 
}

/* Ensures string length within assumed maximum length. */ 
unsigned int string_length_too_long(char str[MAX_STR_LEN])
{
  unsigned int i, check ; 
  
  check = True ; 
  
  i = 0 ;
  /* 
   * Keep checking until null character found, or maximum 
   * assumed length reached. If null not found, report.
   */  
  while((check == True) && (i < MAX_STR_LEN)){
    if(str[i] == '\0'){
      check = False ; 
    }
    i++ ; 
  }

  return check ; 
}

/* Frees all memory allocated to the Prog structure. */ 
void free_program_memory(Prog **p) 
{
  unsigned int i ;
  Prog *pFree ;
  
  pFree = *p ; 
    
  for(i = 0 ; i < pFree->capacity ; i++){
    if(pFree != NULL){
      free(pFree->program[i]) ; 
      
      pFree->program[i] = NULL ;
    } 
  }
  
  pFree->totalStrs = 0 ;
  
  free(pFree->program) ;
  
  pFree->program = NULL ; 
  
  /* Free any variables that have been set. */ 
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    if(pFree->var[i] != NULL){
      free(pFree->var[i]) ; 
      
      pFree->var[i] = NULL ; 
    }
  }
  
  /* Free any memory allocated to the stack. */ 
  free_stack(&(pFree->s)) ; 
  
  free(pFree) ;
  *p = NULL ; 

  return ; 
}

/* Allocates memory for stack and sets starting values. */
void initialise_stack(Prog *p, unsigned int length)
{  
  p->s.size = length ; 

  p->s.stack = (VarValue *)calloc(p->s.size, \
  sizeof(VarValue)) ;
  
  if(pointer_is_null(p->s.stack)){
    free_program_memory(&p) ; 
    CODE_ERROR(STACK_MEM, StackMem) ; 
  } 
  
  p->s.top = STACK_TOP_START_VALUE ;

  return ; 
}

/* Pushes value onto the stack and updates ToS values. */ 
void push(Prog *p, double value)
{
  if(p->s.top >= p->s.size){
    free_program_memory(&p) ; 
    CODE_ERROR(STACK_FULL, StackFull) ; 
  }

  p->s.stack[p->s.top].value = value ; 
  
  p->s.top += 1 ; 

  return ; 
}

/* Free memory allocated for the stack. */ 
void free_stack(PolishStack *s)
{ 
  if(s->stack != NULL){
  
    free(s->stack) ; 
    
    s->stack = NULL ; 
  
    if(s->stack != NULL){
      CODE_ERROR(STACK_FREE, StackFree) ; 
    }
  }
  
  return ; 
}

/* Used to convert input angle from degrees to radians. */ 
double degrees_to_radians(double degrees) 
{
  double radians ; 

  degrees = fmod(degrees, DEGREES_IN_CIRCLE) ; 
  
  radians = (degrees * (M_PI / HALF_DEGREES_IN_CIRCLE)) ; 

  return radians ; 
}
