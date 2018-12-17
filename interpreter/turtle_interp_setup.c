/* 
 * File contains definitions of all functions which are used 
 * set-up the program for the interpreter. 
 */ 
#include "turtle_interp_setup.h"

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

/* Setup Prog pointer, read in str.s and set key values. */ 
void set_up_program(Prog *p, FILE *progFile, char *argv1)
{  
  if(open_file(&progFile, argv1) != Success){
    free_program_memory(&p) ; 
    CODE_ERROR(NOT_OPENED, NotOpened) ; 
  }

  p->totalStrs = number_strings_in_file(progFile) ; 
  
  initialise_Prog(p, progFile) ; 
      
  /* Check num. strs in p->program matches num. in file. */
  if(read_in_strings(progFile, p) != p->totalStrs){
    fclose(progFile) ; 
    free_program_memory(&p) ; 
    CODE_ERROR(FILE_SIZE, FileSize) ; 
  }
  
  if(close_file(&progFile) != Success){
    free_program_memory(&p) ; 
    CODE_ERROR(NOT_CLOSED, NotClosed) ; 
  }
  
  return ; 
}

/* Used to open a readable file and report on the success.*/
unsigned int open_file(FILE **progFile, char *argv1)
{ 
  *progFile = fopen(argv1, "r") ; 
    
  if(pointer_is_null(*progFile) == True){
    return Failure ; 
  }
    
  return Success ; 
}

/* Determines size of file/program, then resets file ptr. */ 
unsigned int number_strings_in_file(FILE *progFile)
{
  char tempStr[MAX_STR_LEN] ; 
  unsigned int numStrs ; 
  
  numStrs = 0 ; 
  
  /* Keep scanning in strings until end of file reached. */
  while(fscanf(progFile, "%s", tempStr) != EOF){
    numStrs++ ; 
    /* Exit if a string scanned in is > assumed max size. */
    if(string_length_too_long(tempStr)){
      fclose(progFile) ; 
      CODE_ERROR(STR_LONG, StrLong) ; 
    }
  }
      
  if(fseek(progFile, 0, SEEK_SET) != 0){
    fclose(progFile) ; 
    CODE_ERROR(FSEEK, FSeek) ; 
  }

  return numStrs ; 
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

/* Sets starting values and allocates space for Prog ptr. */
void initialise_Prog(Prog *p, FILE *progFile)
{
  unsigned int i ; 
  
  p->program = memory_for_program(p->totalStrs) ;
  
  if(pointer_is_null(p->program)){
    fclose(progFile) ; 
    free_program_memory(&p) ; 
    CODE_ERROR(PROG_CONT_MEM, ProgContMem) ; 
  }
  
  p->place = STARTING_PLACE ;  
  
  p->temp.value = STARTING_TEMP_VALUE ; 
      
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    p->var[i] = NULL ;   
  }
  
  p->currentMove = NO_MOVE ;
  
  initialise_turtle_position(&(p->turtle)) ; 
  
  Neill_SDL_Init(&(p->sw)) ;
    
  return ; 
}

/* Define starting position and direction of Turtle. */ 
void initialise_turtle_position(TurtlePos *turtle)
{
  turtle->current.x = TURTLE_STARTING_X ; 

  turtle->current.y = TURTLE_STARTING_Y ; 

  turtle->previous.x = TURTLE_STARTING_X ; 

  turtle->previous.y = TURTLE_STARTING_Y ; 
  
  turtle->theta = POINT_NORTH ; 
  
  return ; 
} 

/* Allocate space for pointer of type char *, size 'size'.*/ 
char **memory_for_program(unsigned int size)
{
  char **program = NULL ; 
  
  program = (char **)calloc(size, sizeof(char *)) ; 
  
  return program ; 
}

/* Creates dynamic structure to hold all strings in file. */
unsigned int read_in_strings(FILE *progFile, Prog *p)
{
  char tempStr[MAX_STR_LEN] ; 
  unsigned int counter, strLength ;
  
  counter = strLength = 0 ; 
  
  while(fscanf(progFile, "%s", tempStr) != EOF){
    /* Add 1 to strlen() output for null character. */ 
    strLength = strlen(tempStr) + 1 ; 
    
    /* Allocate memory for the exact length of string. */ 
    p->program[counter] = memory_for_string(strLength) ; 
  
    /* If no memory, exit. Otherwise, copy string read in.*/
    if(pointer_is_null(p->program[counter])){
      free_program_memory(&p) ; 
      fclose(progFile) ; 
      CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
    }
    else{
      strcpy( p->program[counter++], tempStr) ; 
    }
  }
  
  /* Return the total number of strings read in from file.*/
  return counter ;
}

/* Allocate space for a pointer of type char, size strLen.*/ 
char *memory_for_string(unsigned int strLen)
{
  char *string = NULL ; 
  
  string = (char *)calloc(strLen, sizeof(char)) ;
  
  return string ; 
}

/* Frees all memory allocated to the Prog structure. */ 
void free_program_memory(Prog **p) 
{
  unsigned int i ;
  Prog *pFree = NULL ;
  
  pFree = *p ; 
  
  /* Free memory allocated to each string from file. */  
  for(i = 0 ; i < pFree->totalStrs ; i++){
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

/* Used to close a file, if successful sets ptr to null. */
unsigned int close_file(FILE **progFile)
{
  if(fclose(*progFile) != 0){
    return Failure ; 
  }
  
  *progFile = NULL ; 
    
  return Success ;
}

/* Estimates length of expression to determine stack size.*/
unsigned int estimate_polish_length(Prog *p)
{
  unsigned int currentPlace, expressionLength ; 
  
  currentPlace = p->place ; 
  expressionLength = 0 ; 
  
  while(within_expression_and_file(currentPlace++, p)){
    expressionLength++ ; 
  }
  
  return expressionLength ; 
}

/* Returns true until either ";" or end of file reached. */ 
unsigned int within_expression_and_file(unsigned int place,\
Prog *p)
{
  if(place < p->totalStrs){
    if(!str_same(p->program[place], EXPRESSION_TERM_CHAR)){
      return True ; 
    }
  }

  return False ; 
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


