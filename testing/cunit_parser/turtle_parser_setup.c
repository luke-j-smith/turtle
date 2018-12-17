/* 
 * File contains definitions of all functions which are used 
 * set-up the program. Independent of the parsing process. 
 */ 
#include "turtle_parser_setup.h"

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

/* Setup Prog pointer, read in strs and set key values. */ 
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
   
  /* Return file pointer to the start of the file. */    
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
  p->program = memory_for_program(p->totalStrs) ;
  
  if(pointer_is_null(p->program)){
    fclose(progFile) ; 
    CODE_ERROR(PROG_CONT_MEM, ProgContMem) ; 
  }
  
  p->place = STARTING_PLACE ;  
    
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
