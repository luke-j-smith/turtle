/* File containing all tests for turtle_parser_setup.c */ 
#include "test_turtle_parser_setup.h"

/* Suite 9 Tests - pointer_is_null (turtle_parser_setup.c)*/
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
 * Suite 10 Tests - memory_for_Prog (turtle_parser_setup.c) 
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
 * Suite 11 Tests - 
 * memory_for_string (turtle_parser_setup.c)
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
 * Suite 12 Tests -  
 * memory_for_program (turtle_parser_setup.c)
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

/* Suite 13 Tests - open_file (turtle_parser_setup.c) */
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

/* Suite 14 Tests - close_file (turtle_parser_setup.c) */
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
 * Suite 15 Tests - 
 * string_length_too_long (turtle_parser_setup.c) 
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
 * Suite 16 Tests - number_strings_in_file
 * (turtle_parser_setup.c) 
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
 * Suite 17 Tests - 
 * initialise_program (turtle_parser_setup.c)  
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

/* 
 * Suite 18 Tests - read_in_strings (turtle_parser_setup.c)
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
 * Suite 19 Tests - 
 * free_program_memory (turtle_parser_setup.c) 
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

/* 
 * Suite 20 Tests - set_up_program (turtle_parser_setup.c)
 */
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

