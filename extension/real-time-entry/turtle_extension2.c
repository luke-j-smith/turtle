/* 
 * Extension to the Turtle program - allows for Turtle 
 * program to be written from the command line. The input
 * program can be saved to a file. 
 */
#include "turtle_extension2.h"

/* Used to read in string directly from command line. */ 
unsigned int read_in_string_from_command(Prog *p) 
{
  char tempStr[MAX_STR_LEN] ; 
  
  /* If in a DO loop, no need to take in any input. */ 
  if(p->inDoLoop == True){
    return Success ; 
  }
  
  if(scanf("%s", tempStr) != 1){
    free_program_memory(&p) ; 
    CODE_ERROR(SCANF, Scanf) ; 
  }
  
  /* Check that string is within assumed maximum size. */
  if(string_length_too_long(tempStr)){
    free_program_memory(&p) ; 
    CODE_ERROR(STR_LONG, StrLong) ; 
  }
    
  check_if_end_sequence(tempStr, p) ; 
  
  add_string_to_program(tempStr, p) ; 

  return Success ; 
}

/* Check whether user wants to exit program. */ 
void check_if_end_sequence(char str[MAX_STR_LEN], Prog *p)
{
  /* Can either exit and discard program, ... */ 
  if(str_same(str, END_SQUENCE)){
    free_program_memory(&p) ; 
    
    exit(EXIT_SUCCESS) ; 
  }
  
  /* Or exit, and save program to a file. */ 
  if(str_same(str, SAVE_FILE_SEQUENCE)){
    create_and_save_file(p) ; 
  
    free_program_memory(&p) ; 
    
    exit(EXIT_SUCCESS) ; 
  }

  return ; 
} 

/* Adds typed in string to program. */ 
void add_string_to_program(char str[MAX_STR_LEN], Prog *p)
{
  unsigned int strLen ; 
    
  (p->totalStrs)++ ;
  
  check_program_capacity(p) ; 
  
  strLen = strlen(str) + 1 ; 
  
  p->program[p->place] = memory_for_string(strLen) ; 
  
  strcpy(p->program[p->place], str) ; 
  
  return ; 
}

void check_program_capacity(Prog *p) 
{
  /* Create a new program if capacity is reached. */ 
  if(at_capacity(p->totalStrs, p->capacity)){
    create_new_program_array(p) ; 
  }

  return ; 
}

/* Create new, larger, program. Copy old, then scrap it. */ 
void create_new_program_array(Prog *p)
{
  unsigned int oldSize ; 
  char **old = NULL ; 
  
  oldSize = p->capacity ; 
  
  old = p->program ; 
  
  p->capacity = new_capacity(oldSize) ; 
  
  p->program = memory_for_program(p->capacity) ; 
  
  if(pointer_is_null(p->program)){
    CODE_ERROR(PROG_CONT_MEM, ProgContMem) ; 
  }
  
  transfer_words(p->program, old, p) ; 
  
  free(old) ; 

  return ; 
}

/* Copy strings from old program to new one at a time. */ 
void transfer_words(char **new, char **old, Prog *p)
{
  unsigned int i, strLen ;   

  for(i = 0 ; i <= p->totalStrs ; i++){
    if(old[i] != NULL){
      strLen = strlen(old[i]) + 1 ; 
      
      new[i] = memory_for_string(strLen) ; 
      
      strcpy(new[i], old[i]) ; 
      
      free(old[i]) ; 
    }
  }

  return ; 
}

/* If chosen, create a file and copy program into it. */ 
void create_and_save_file(Prog *p)
{
  char name[MAX_STR_LEN], *type = FILE_TYPE, *file ; 
  unsigned int nameLen ; 
  
  if(scanf("%s", name) != 1){
    free_program_memory(&p) ; 
    CODE_ERROR(SCANF, Scanf) ;
  }
  
  if(string_length_too_long(name)){
    free_program_memory(&p) ; 
    CODE_ERROR(STR_LONG, StrLong) ; 
  }
  
  nameLen = strlen(name) + strlen(type) + 1 ; 
  
  file = memory_for_string(nameLen) ; 
  
  strcat(file, name) ; 
  
  /* Append file name with .txt - this can be changed. */
  strcat(file, type) ; 
  
  fill_file(p, file) ; 
    
  free(file) ; 
  
  return ; 
}

/* Write program to file. */ 
void fill_file(Prog *p, char *name)
{
  unsigned int j ; 
  FILE *save = NULL ; 
  
  if((save = fopen(name, "w")) == NULL){
    free_program_memory(&p) ; 
    CODE_ERROR(SCANF, Scanf) ;
  }
  
  if(p->totalStrs == 0){
    (p->totalStrs)++ ; 
  }
  
  /* Write string to file, followed by a space. */   
  for(j = 0 ; j < p->totalStrs ; j++){  
    fprintf(save, "%s ", p->program[j]) ; 
    
    file_formatting(save, p, j) ;     
  }
            
  if(fclose(save) == EOF){
    free_program_memory(&p) ; 
    CODE_ERROR(NOT_CLOSED, NotClosed) ; 
  }

  return ; 
}

/* Format program in file - new lines and spaces. */ 
void file_formatting(FILE *save, Prog *p, \
unsigned int place)
{
  unsigned int i ; 
  char *newLineSet[NUM_NEW_LINE_CHARS] = NEW_LINE_SET ; 
  char *moves[NUM_OF_MOVES] = MOVES ; 

  if(place >= 1){
    for(i = 0 ; i < NUM_OF_MOVES ; i++){
      if(str_same(p->program[place - 1], moves[i])){
        fprintf(save, SINGLE_NEW_LINE_AND_SPACE) ;
      }
    }
  }
  
  for(i = 0 ; i < NUM_NEW_LINE_CHARS ; i++){
    if(str_same(p->program[place], newLineSet[i])){
      fprintf(save, DOUBLE_NEW_LINE_AND_SPACE) ;
    }
  }    
  
  if(PENULTIMATE(place, p->totalStrs)){
    fseek(save, END_FORMAT_STEP_BACK, SEEK_CUR) ; 
    fprintf(save, END_FORMAT) ; 
  }
  
  return ; 
}

