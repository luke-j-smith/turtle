/* File containing all tests for turtle_interp_setup.c */ 
#include "test_turtle_interp_setup.h"

/* 
 * Suite 11 Tests - pointer_is_null (turtle_interp_setup.c)
 */
void test_pointer_is_null_for_void(void)
{ 
  void *p_null = NULL ; 

  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  return ; 
}

void test_pointer_is_null_for_int(void)
{ 
  int *p_null = NULL ; 
  int not_null, *p_not_null = NULL ; 
  
  p_not_null = &not_null ; 
  
  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p_not_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_not_null), False) ; 

  return ; 
}

void test_pointer_is_null_for_unsigned_int(void)
{ 
  unsigned int *p_null = NULL ; 
  unsigned int not_null, *p_not_null = NULL ; 
  
  p_not_null = &not_null ; 
  
  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p_not_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_not_null), False) ; 

  return ; 
}

void test_pointer_is_null_for_char(void)
{ 
  char *p_null = NULL ; 
  char not_null, *p_not_null = NULL ; 
  
  p_not_null = &not_null ; 
  
  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p_not_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_not_null), False) ; 

  return ; 
}

void test_pointer_is_null_for_char_pointer(void)
{ 
  char **p_null = NULL ; 
  char *not_null = NULL, **p_not_null = NULL ; 
  
  p_not_null = &not_null ; 
  
  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p_not_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_not_null), False) ; 

  return ; 
}


void test_pointer_is_null_for_Prog(void)
{ 
  Prog *p_null = NULL ; 
  Prog not_null, *p_not_null = NULL ; 
  
  p_not_null = &not_null ; 
  
  CU_ASSERT_PTR_NULL(p_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_null), True) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p_not_null) ; 
  
  CU_ASSERT_EQUAL(pointer_is_null(p_not_null), False) ; 

  return ; 
}

/* 
 * Suite 12 Tests - memory_for_Prog (turtle_interp_setup.c)
 */
void test_memory_for_Prog_not_null(void)
{
  Prog *p = NULL ; 

  p = memory_for_Prog() ;
  
  if(p != NULL){
    CU_ASSERT_PTR_NOT_NULL(p) ;
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
}

void test_memory_for_Prog_size(void)
{
  Prog *p = NULL ; 

  p = memory_for_Prog() ;
  
  if(p != NULL){
    CU_ASSERT_EQUAL(sizeof(p), sizeof(Prog *)) ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
  
  free(p) ; 
  p = NULL ; 

  return ; 
}

/* 
 * Suite 13 Tests - 
 * memory_for_string (turtle_interp_setup.c)
 */
void test_memory_for_string_not_null(void)
{
  char *string = NULL ; 

  string = memory_for_string(TEST_STR_LEN) ;
  
  if(string != NULL){
    CU_ASSERT_PTR_NOT_NULL(string) ;
  }
  else{
    TEST_ERROR(TE_STR_MEM, ErrStrMem) ; 
  }

  free(string) ; 
  string = NULL ; 

  return ; 
}

void test_memory_for_string_size(void)
{
  char *string = NULL ; 
  
  string = memory_for_string(TEST_STR_LEN) ;

  if(string != NULL){  
    CU_ASSERT_EQUAL(sizeof(string), sizeof(char *)) ;
  }
  else{
    TEST_ERROR(TE_STR_MEM, ErrStrMem) ; 
  } 
  
  free(string) ; 
  
  string = NULL ; 

  return ; 
}

void test_memory_for_string_calloc_worked(void)
{
  char *string = NULL ; 
  
  string = memory_for_string(TEST_STR_LEN) ;
  
  if(string != NULL){
    CU_ASSERT_EQUAL(*string, 0) ; 
  }
  else{
    TEST_ERROR(TE_STR_MEM, ErrStrMem) ; 
  }
   
  free(string) ;
  string = NULL ; 
  
  return ; 
}

void test_memory_for_string_can_store_string(void)
{
  char *string = NULL ;
  char test[] = STR_FOR_TEST ; 
  
  string = memory_for_string(TEST_STR_LEN) ;
  
  if(string != NULL){
    strcpy(string, test) ; 
  
    CU_ASSERT_STRING_EQUAL(string, test) ; 
  
    CU_ASSERT_STRING_EQUAL(string, STR_FOR_TEST) ;
  }
  else{
    TEST_ERROR(TE_STR_MEM, ErrStrMem) ; 
  } 
  
  free(string) ;
  string = NULL ; 

  return ; 
}

/* 
 * Suite 14 Tests -  
 * memory_for_program (turtle_interp_setup.c)
 */
void test_memory_for_program_not_null(void)
{
  unsigned int size = TEST_SIZE ; 
  char **list = NULL ; 

  list = memory_for_program(size) ;
  
  if(list != NULL){
    CU_ASSERT_PTR_NOT_NULL(list) ;
  }
  else{
    TEST_ERROR(TE_CONTENT_MEM, ErrContentMem) ; 
  }

  free(list) ; 

  list = NULL ; 

  return ; 
}

void test_memory_for_program_size(void)
{
  unsigned int size = TEST_SIZE ; 
  char **list = NULL ; 

  list = memory_for_program(size) ;
  
  if(list != NULL){
    CU_ASSERT_EQUAL(sizeof(list), sizeof(char **)) ;
  }
  else{
    TEST_ERROR(TE_CONTENT_MEM, ErrContentMem) ; 
  }
  
  free(list) ; 
  list = NULL ; 

  return ; 
}

void test_memory_for_program_calloc_worked(void)
{
  unsigned int i, size = TEST_SIZE ; 
  char **list = NULL ; 

  list = memory_for_program(size) ;
  
  if(list != NULL){    
    for(i = 0 ; i < TEST_SIZE ; i++){
      CU_ASSERT_EQUAL(list[i], 0) ; 
    }
  }
  else{
    TEST_ERROR(TE_CONTENT_MEM, ErrContentMem) ; 
  }
  
  free(list) ; 
  list = NULL ; 

  return ; 
}


void test_memory_for_program_strings_stored(void)
{
  unsigned int i, size = TEST_SIZE ; 
  char **list = NULL, test[] = STR_FOR_TEST ; 

  list = memory_for_program(size) ;
  
  if(list != NULL){    
    for(i = 0 ; i < TEST_SIZE ; i++){        
      list[i] = memory_for_string(TEST_STR_LEN) ; 
      
      strcpy(list[i], test) ;
      
      CU_ASSERT_STRING_EQUAL(list[i], test) ; 
  
      CU_ASSERT_STRING_EQUAL(list[i], STR_FOR_TEST) ;
      
      free(list[i]) ; 
    }
  }
  else{
    TEST_ERROR(TE_CONTENT_MEM, ErrContentMem) ; 
  }
  
  free(list) ; 
  list = NULL ; 

  return ; 
}

/* Suite 15 Tests - open_file (turtle_interp_setup.c) */
void test_open_file_null_flagged_and_returned(void) 
{
  FILE *temp = NULL ; 

  CU_ASSERT_EQUAL(open_file(&temp, "not_a_file"), Failure) ; 
  
  CU_ASSERT_PTR_NULL(temp) ; 

  return ; 
}

void test_open_file_return_value(void)
{
  FILE *temp = NULL ; 

  CU_ASSERT_EQUAL(open_file(&temp, TEST_FILE), Success) ; 
    
  fclose(temp) ; 

  return ; 
}

void test_open_file_pointer_not_null(void)
{
  FILE *temp = NULL ; 
  
  if(open_file(&temp, TEST_FILE) == Success){
    CU_ASSERT_PTR_NOT_NULL(temp) ;
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  fclose(temp) ; 
  
  return ; 
}

void test_open_file_file_readable(void)
{
  FILE *temp = NULL ;
  char testStr[TEST_STR_LEN] ; 
  
  if(open_file(&temp, TEST_FILE) == Success){
    CU_ASSERT_EQUAL(fscanf(temp, "%s", testStr), 1) ; 
  
    CU_ASSERT_EQUAL(fseek(temp, SEEK_JUMP, SEEK_CUR), 0) ; 

    CU_ASSERT_EQUAL(fgetc(temp), TEST_CHAR1) ; 
  
    CU_ASSERT_NOT_EQUAL(fgetc(temp), TEST_CHAR1) ; 
    
    CU_ASSERT_EQUAL(ftell(temp), TEST_FILE_POS) ;  
    
    CU_ASSERT_EQUAL(fgetc(temp), TEST_CHAR2) ; 
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  fclose(temp) ; 
  
  return ; 
}

void test_open_file_file_not_writable(void)
{
  FILE *temp = NULL ; 
  
  if(open_file(&temp, TEST_FILE) == Success){
    CU_ASSERT_EQUAL(fputc(TEST_CHAR_TO_WRITE, temp), EOF) ;  
      
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  
  fclose(temp) ; 
  
  return ; 
}

/* Suite 16 Tests - close_file (turtle_interp_setup.c) */
void test_close_file_return_value(void)
{
  FILE *temp = NULL ; 
  
  temp = fopen(TEST_FILE, "r+") ;  

  if(temp != NULL){
    CU_ASSERT_EQUAL(close_file(&temp), Success) ; 
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }  

  return ; 
}

void test_close_file_file_shut_and_null_ptr(void)
{
  FILE *temp = NULL ; 

  temp = fopen(TEST_FILE, "r+") ;  

  if(temp != NULL){
    if(close_file(&temp) == Success){
      CU_ASSERT_PTR_NULL(temp) ;     
    }
    else{
      fclose(temp) ; 
      TEST_ERROR(TE_CLOSE, ErrClose) ; 
    }  
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  } 

  return ; 
}

/* 
 * Suite 17 Tests - 
 * string_length_too_long (turtle_interp_setup.c) 
 */
void test_string_length_too_long_not_too_long(void) 
{
  unsigned int i ; 
  char random, str[MAX_STR_LEN] ; 
  
  srand(time(NULL)) ; 
  
  for(i = 0 ; i < MAX_STR_LEN - 1; i++){
    random = RANDOM_LOWER_LETTER ;  
    str[i] = random ; 
  }

  str[MAX_STR_LEN - 1] = '\0' ; 
  
  CU_ASSERT_EQUAL(string_length_too_long(str), False) ; 
  
  return ; 
}
 
void test_string_length_too_long_too_long(void)
{
  unsigned int i ; 
  char random, str[MAX_STR_LEN] ; 
  
  srand(time(NULL)) ; 
  
  for(i = 0 ; i < MAX_STR_LEN ; i++){
    random = RANDOM_LOWER_LETTER ; 
    str[i] = random ; 
  }
  
  CU_ASSERT_EQUAL(string_length_too_long(str), True) ; 
  
  return ; 
}

/* 
 * Suite 18 Tests - number_strings_in_file
 * (turtle_interp_setup.c) 
 */
void test_number_strings_in_file_empty(void)
{
  FILE *temp = NULL ; 
  
  temp = fopen(EMPTY_FILE, "r") ;  

  if(temp != NULL){
    CU_ASSERT_EQUAL(number_strings_in_file(temp), 0) ; 
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }  
  
  fclose(temp) ; 

  return ; 
}

void test_number_strings_in_file_test_file(void)
{
  FILE *temp = NULL ; 
  
  temp = fopen(TEST_FILE, "r") ;  

  if(temp != NULL){
    CU_ASSERT_EQUAL(number_strings_in_file(temp), \
    TEST_FILE_STRS) ; 
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }  
  
  fclose(temp) ; 

  return ; 
}

/* 
 * Suite 19 Tests - 
 * initialise_turtle_position (turtle_interp_setup.c)  
 */
void test_initialise_turtle_position_current_x(void) 
{
  TurtlePos turtle ; 
  
  initialise_turtle_position(&turtle) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(turtle.current.x, \
  TURTLE_STARTING_X, FLOAT_DIF) ; 
  
  return ; 
}
 
void test_initialise_turtle_position_current_y(void)  
{
  TurtlePos turtle ; 
  
  initialise_turtle_position(&turtle) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(turtle.current.y, \
  TURTLE_STARTING_Y, FLOAT_DIF) ; 
  
  return ; 
}

void test_initialise_turtle_position_previous_x(void) 
{
  TurtlePos turtle ; 
  
  initialise_turtle_position(&turtle) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(turtle.previous.x, \
  TURTLE_STARTING_X, FLOAT_DIF) ; 
  
  return ; 
}

void test_initialise_turtle_position_previous_y(void)  
{
  TurtlePos turtle ; 
  
  initialise_turtle_position(&turtle) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(turtle.previous.y, \
  TURTLE_STARTING_Y, FLOAT_DIF) ; 
  
  return ; 
}

void test_initialise_turtle_position_theta(void)
{
  TurtlePos turtle ; 
  
  initialise_turtle_position(&turtle) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(turtle.theta, 0.0, FLOAT_DIF) ; 

  return ; 
} 

/* 
 * Suite 20 Tests - initialise_Prog (turtle_interp_setup.c)  
 */
void test_initialise_Prog_program(void)  
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
    
  if(p != NULL){
    p->totalStrs = TEST_TOTAL_STR_NUM ; 

    initialise_Prog(p, testFile) ; 

    CU_ASSERT_PTR_NOT_NULL(p->program) ;
    
    CU_ASSERT_EQUAL(p->totalStrs , TEST_TOTAL_STR_NUM) ; 
    
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
}

void test_initialise_Prog_place_value(void)
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    p->totalStrs = TEST_TOTAL_STR_NUM ; 
  
    initialise_Prog(p, testFile) ; 
    
    CU_ASSERT_EQUAL(p->place, 0) ;
    
    CU_ASSERT_EQUAL(p->totalStrs , TEST_TOTAL_STR_NUM) ; 
    
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
}

void test_initialise_Prog_temp_value(void)
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(p->temp.value, 0, FLOAT_DIF) ;
    
    free(p->program) ; 
    p->program = NULL ; 
  }
    
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
}

void test_initialise_Prog_var_set_to_null(void)
{
  unsigned int i ; 
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
    
    for(i = 0 ; i < NUMBER_OF_VARS ; i++){
      CU_ASSERT_PTR_NULL(p->var[i]) ;
    }
        
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_currentMove(void) 
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_EQUAL(p->currentMove, NO_MOVE) ;
    
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_turtle_position_current_x(void) 
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.current.x, \
    TURTLE_STARTING_X, FLOAT_DIF) ; 
        
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_turtle_position_current_y(void) 
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.current.y, \
    TURTLE_STARTING_Y, FLOAT_DIF) ; 
        
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_turtle_position_previous_x(void) 
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.previous.x, \
    TURTLE_STARTING_X, FLOAT_DIF) ; 
            
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_turtle_position_previous_y(void) 
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.previous.y, \
    TURTLE_STARTING_Y, FLOAT_DIF) ; 
        
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

void test_initialise_Prog_turtle_position_theta(void)
{
  FILE *testFile = NULL ; 
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ;
  
  if(p != NULL){
    initialise_Prog(p, testFile) ; 
   
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, 0.0, FLOAT_DIF); 
        
    free(p->program) ; 
    p->program = NULL ; 
  }
  else{
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  free(p) ; 
  p = NULL ; 

  return ; 
} 

/* 
 * Suite 21 Tests - read_in_strings (turtle_interp_setup.c)
 */
void test_read_in_strings_return_value_empty(void) 
{ 
  Prog *p = NULL ;
  FILE *temp = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  temp = fopen(EMPTY_FILE, "r") ;

  if(temp != NULL){
    initialise_Prog(p, temp) ; 
  
    CU_ASSERT_EQUAL(read_in_strings(temp, p), 0) ;
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  
  fclose(temp) ; 

  free(p->program) ; 
  
  free(p) ; 
  p = NULL ;

  return ; 
}

void test_read_in_strings_return_value_not_empty(void)
{
  Prog *p = NULL ;
  FILE *temp = NULL ; 
  int i ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  temp = fopen(TEST_FILE, "r") ;  
  
  if(temp != NULL){
    p->totalStrs = TEST_FILE_STRS ; 
  
    initialise_Prog(p, temp) ; 
      
    CU_ASSERT_EQUAL(read_in_strings(temp, p), \
    TEST_FILE_STRS) ; 
        
    for(i = 0 ; i < TEST_FILE_STRS ; i++){
      free(p->program[i]) ; 
      
      p->program[i] = NULL ; 
    }
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  
  fclose(temp) ; 

  free(p->program) ; 
  p->program = NULL ;

  free(p) ; 
  p = NULL ; 

  return ; 
}
 
void test_read_in_strings_strings_correct(void) 
{
  Prog *p = NULL ; 
  FILE *temp = NULL ; 
  int i ; 
  char tempStr[MAX_STR_LEN] ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  temp = fopen(TEST_FILE, "r") ;  

  if(temp != NULL){
    p->totalStrs = TEST_FILE_STRS ; 
    
    initialise_Prog(p, temp) ; 
  
    CU_ASSERT_EQUAL(read_in_strings(temp, p), \
    TEST_FILE_STRS) ;
    
    rewind(temp) ; 
  
    for(i = 0 ; i < TEST_FILE_STRS ; i++){
      if(fscanf(temp, "%s", tempStr) != 1){
        TEST_ERROR(TE_FSCANF, ErrFscanf) ; 
      } 
      CU_ASSERT_STRING_EQUAL(p->program[i], tempStr) ; 
        
      free(p->program[i]) ; 
      
      p->program[i] = NULL ; 
    }
  }
  else{
    TEST_ERROR(TE_OPEN, ErrOpen) ; 
  }
  
  fclose(temp) ; 

  free(p->program) ; 
  p->program = NULL ; 

  free(p) ; 
  p = NULL ; 

  return ; 
}

/* 
 * Suite 22 Tests - initialise_stack (turtle_interp_setup.c)
 */
void test_initialise_stack_ptr_not_null(void)
{
  Prog *p ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
      
  initialise_stack(p, STACK_TEST_SIZE) ; 

  CU_ASSERT_PTR_NOT_NULL(p->s.stack) ;
  
  free(p->s.stack) ;
  
  free(p) ; 
  p = NULL ; 

  return ; 
}

void test_initialise_stack_ptr_correct_size(void)
{
  Prog *p ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
          
  initialise_stack(p, STACK_TEST_SIZE) ; 

  CU_ASSERT_EQUAL(sizeof(p->s.stack), sizeof(VarValue *)) ;
  
  free(p->s.stack) ; 
  
  free(p) ;  
  p = NULL ; 


  return ; 
}

void test_initialise_stack_correct_stack_size(void) 
{
  Prog *p ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
          
  initialise_stack(p, STACK_TEST_SIZE) ; 

  CU_ASSERT_EQUAL(p->s.size, STACK_TEST_SIZE) ; 
  
  free(p->s.stack) ; 
  
  free(p) ; 
  p = NULL ; 


  return ; 
}

void test_initialise_stack_top_value(void)
{
  Prog *p ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
          
  initialise_stack(p, STACK_TEST_SIZE) ; 

  CU_ASSERT_EQUAL(p->s.top, STACK_TOP_START_VALUE) ; 
  
  free(p->s.stack) ; 
  
  free(p) ; 
  p = NULL ; 

  return ; 
}

/* 
 * Suite 23 Tests - free_stack (turtle_interp_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
void test_free_stack_all_freed(void)
{
  Prog *p ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
      
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  free_stack(&(p->s)) ; 
  
  CU_ASSERT_PTR_NULL(p->s.stack) ; 
  
  free(p) ; 
  p = NULL ; 

  return ; 
}

/* 
 * Suite 24 Tests - 
 * free_program_memory (turtle_interp_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
void test_free_program_memory_Prog_ptr_null(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;   
  
  free_program_memory(&p) ; 
          
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* Suite 25 Tests - set_up_program (turtle_interp_setup.c)*/
void test_set_up_program_program_Prog_ptr_not_null(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 

  CU_ASSERT_PTR_NOT_NULL(p) ; 
      
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ;  

  return ; 
}

void test_set_up_program_program_program_ptr_not_null(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_PTR_NOT_NULL(p->program) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ;  

  return ; 
}

void test_set_up_program_program_totalStrs_correct(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_EQUAL(p->totalStrs, TEST_FILE_STRS) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_program_ptrs_not_null(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    CU_ASSERT_PTR_NOT_NULL(p->program[i]) ; 
  }
    
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_program_strs_correct(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_STRING_EQUAL(p->program[0], \
  TEST_FILE_STRING1) ; 
  
  CU_ASSERT_STRING_EQUAL(p->program[1], \
  TEST_FILE_STRING2) ; 
    
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_place_correct(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_EQUAL(p->place, 0) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_temp_value(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, 0, FLOAT_DIF) ;
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_var_set_to_null(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_PTR_NULL(p->var[i]) ;
  }
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_currentMove(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_EQUAL(p->currentMove, NO_MOVE) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_turtle_position_current_x(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.current.x, \
  TURTLE_STARTING_X, FLOAT_DIF) ;  
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}
 
void test_set_up_program_turtle_position_current_y(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.current.y, \
  TURTLE_STARTING_Y, FLOAT_DIF) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}
 
void test_set_up_program_turtle_position_previous_x(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.previous.x, \
  TURTLE_STARTING_X, FLOAT_DIF) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}
 
void test_set_up_program_turtle_position_previous_y(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.previous.y, \
  TURTLE_STARTING_Y, FLOAT_DIF) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}
 
void test_set_up_program_turtle_position_theta(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, 0.0, FLOAT_DIF); 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

void test_set_up_program_file_shut(void) 
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  CU_ASSERT_PTR_NULL(tempFile) ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    free(p->program[i]) ; 
    p->program[i] = NULL ; 
  }
  
  free(p->program) ;
  p->program = NULL ;  
  
  free(p) ;
  p = NULL ; 

  return ; 
}

/* 
 * Suite 26 Tests - 
 * within_expression_and_file (turtle_interp_setup.c) 
 */ 
void test_within_expression_and_file_false_place(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_TERM_FILE) ;  
  
  (p->place)++ ;  
  
  (p->place)++ ;  
  
  CU_ASSERT_EQUAL(within_expression_and_file(p->place, p), \
  False) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 
 
void test_within_expression_and_file_false_term_char(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_TERM_FILE) ;  
          
  CU_ASSERT_EQUAL(within_expression_and_file(p->place, p), \
  False) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
}

void test_within_expression_and_file_true(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;  
    
  CU_ASSERT_EQUAL(within_expression_and_file(p->place, p), \
  True) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

/* 
 * Suite 27 Tests - 
 * estimate_polish_length (turtle_interp_setup.c) 
 */
void test_estimate_polish_length_empty(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, EMPTY_FILE) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), 0) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

void test_estimate_polish_length1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_LEN_FILE1) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), POL_LEN1) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

void test_estimate_polish_length2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_LEN_FILE2) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), POL_LEN2) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

void test_estimate_polish_length3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_LEN_FILE3) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), POL_LEN3) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

void test_estimate_polish_length4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_LEN_FILE4) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), POL_LEN4) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

void test_estimate_polish_length5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POL_LEN_FILE5) ;  
    
  CU_ASSERT_EQUAL(estimate_polish_length(p), POL_LEN5) ; 
  
  free_program_memory(&p) ; 
          
  return ; 
} 

/* Suite 31 Tests - mock_push (turtle_interp_setup.c) */
unsigned int mock_push(Prog *p, double value)
{
  if(p->s.top >= p->s.size){
    return Failure ;  
  }

  p->s.stack[p->s.top].value = value ; 
  
  p->s.top += 1 ; 

  return Success ; 
}

void test_mock_push_full_flag(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    CU_ASSERT_EQUAL(mock_push(p, value), Success) ; 
  }

  CU_ASSERT_EQUAL(mock_push(p, value), Failure) ; 
  
  free_program_memory(&p) ; 

  return ; 
}

void test_mock_push_top_value(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
      
  for(i = 0 ; i < p->s.size ; i++){
    CU_ASSERT_EQUAL(mock_push(p, value), Success) ; 
    
    CU_ASSERT_EQUAL(p->s.top, (i + 1)) ; 
  }

  free_program_memory(&p) ; 

  return ; 
}

void test_mock_push_value_stored(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  } 
    
  initialise_stack(p, STACK_TEST_SIZE) ;  
  
  for(i = 0 ; i < p->s.size ; i++){
    CU_ASSERT_EQUAL(mock_push(p, (value * i)), Success) ;     
  }
  
  for(i = 0 ; i < p->s.size ; i++){        
    CU_ASSERT_DOUBLE_EQUAL(p->s.stack[i].value, \
    (value * i), FLOAT_DIF) ;
  }

  free_program_memory(&p) ; 

  return ; 
}

/* 
 * Suite 42 Tests - 
 * degrees_to_radians (turtle_interp_setup.c) 
 */
void test_degrees_to_radians_north(void) 
{
  CU_ASSERT_DOUBLE_EQUAL(degrees_to_radians(NTH_D), NTH_R, \
  FLOAT_DIF) ; 

  return ; 
}

void test_degrees_to_radians_south(void) 
{
  CU_ASSERT_DOUBLE_EQUAL(degrees_to_radians(STH_D), STH_R, \
  FLOAT_DIF) ; 

  return ; 
}

void test_degrees_to_radians_east(void) 
{
  CU_ASSERT_DOUBLE_EQUAL(degrees_to_radians(EST_D), EST_R, \
  FLOAT_DIF) ; 

  return ; 
}

void test_degrees_to_radians_west(void) 
{
  CU_ASSERT_DOUBLE_EQUAL(degrees_to_radians(WST_D), WST_R, \
  FLOAT_DIF) ; 

  return ; 
}

void test_degrees_to_radians_range_neg_and_pos(void) 
{
  unsigned int i ; 
  double degrees, radians ; 
  
  srand(time(NULL)) ; 
  
  for(i = 0 ; i < NUM_TEST_DEG_TO_RAD ; i++){
    degrees = (rand() % DEGREES_IN_CIRCLE) ; 
    
    if((i % 2) == 0){
      degrees *= -1 ; 
    }
  
    radians = (degrees * (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
    
    CU_ASSERT_DOUBLE_EQUAL(degrees_to_radians(degrees), \
    radians, FLOAT_DIF) ; 
  }

  return ; 
}


