/* File containing all tests for turtle_parser.c */ 
#include "test_turtle_parser.h"


/* Suite 1 Tests - #define str_same (turtle_parser.h) */
void test_str_same_not_equal(void)
{
  char *not_equal = STR_NOT_EQUAL ; 
  char *equal = STR_EQUAL ; 
  
  CU_ASSERT_EQUAL(str_same(equal, not_equal), False) ; 
  
  return ; 
}

void test_str_same_equal(void)
{
  char *equal1 = STR_EQUAL ; 
  char *equal2 = STR_EQUAL ; 
  
  CU_ASSERT_EQUAL(str_same(equal1, equal2), True) ; 
  
  return ; 
}

/* Suite 2 Tests - is_op (turtle_parser.c) */ 
void test_is_op_incorrect_length(void)
{  
  CU_ASSERT_EQUAL(is_op(STR_TOO_LONG), False) ; 
  
  return ; 
}

void test_is_op_incorrect1(void)
{  
  CU_ASSERT_EQUAL(is_op(OP_INCOR1), False) ; 
  
  return ; 
}

void test_is_op_incorrect2(void)
{  
  CU_ASSERT_EQUAL(is_op(OP_INCOR2), False) ; 
  
  return ; 
}

void test_is_op_incorrect3(void)
{  
  CU_ASSERT_EQUAL(is_op(OP_INCOR3), False) ; 
  
  return ; 
}

void test_is_op_incorrect4(void)
{  
  CU_ASSERT_EQUAL(is_op(OP_INCOR4), False) ; 
  
  return ; 
}

void test_is_op_incorrect5(void)
{  
  CU_ASSERT_EQUAL(is_op(OP_INCOR5), False) ; 
  
  return ; 
}

void test_is_op_correct(void)
{
  int i ; 
  char *operationSet[NUMBER_OF_OPS] = OP_SET ; 
  
  for(i = 0 ; i < NUMBER_OF_OPS ; i++){
    CU_ASSERT_EQUAL(is_op(operationSet[i]), True) ; 
  }
  
  return ; 
}

/* 
 * Suite 3 Tests - 
 * #define a_variable_name (turtle_parser.h) 
 */
void test_a_variable_name_flags_incorrect_name1(void)
{  
  CU_ASSERT_EQUAL(a_variable_name(NAME_INCOR1), False) ; 
  
  return ; 
}

void test_a_variable_name_flags_incorrect_name2(void)
{  
  CU_ASSERT_EQUAL(a_variable_name(NAME_INCOR2), False) ; 
  
  return ; 
}

void test_a_variable_name_flags_incorrect_name3(void)
{  
  CU_ASSERT_EQUAL(a_variable_name(NAME_INCOR3), False) ; 
  
  return ; 
}

void test_a_variable_name_flags_incorrect_name4(void)
{  
  CU_ASSERT_EQUAL(a_variable_name(NAME_INCOR4), False) ; 
  
  return ; 
}

void test_a_variable_name_flags_incorrect_name5(void)
{  
  CU_ASSERT_EQUAL(a_variable_name(NAME_INCOR5), False) ; 
  
  return ; 
}

void test_a_variable_name_return_correct_names(void)
{
  int i ; 
  char corNames[NUMBER_OF_VARS][VAR_NAME_LEN] = VAR_NAMES ; 
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_EQUAL(a_variable_name(corNames[i]), True) ; 
  }
  
  return ; 
}

/* Suite 4 Tests - is_var (turtle_parser.c) */ 
void test_is_var_incorrect_length(void)
{  
  CU_ASSERT_EQUAL(is_var(STR_TOO_LONG), False) ; 
  
  return ; 
}

void test_is_var_incorrect_name1(void)
{  
  CU_ASSERT_EQUAL(is_var(VAR_INCOR1), False) ; 
  
  return ; 
}

void test_is_var_incorrect_name2(void)
{  
  CU_ASSERT_EQUAL(is_var(VAR_INCOR2), False) ; 
  
  return ; 
}

void test_is_var_incorrect_name3(void)
{  
  CU_ASSERT_EQUAL(is_var(VAR_INCOR3), False) ; 
  
  return ; 
}

void test_is_var_incorrect_name4(void)
{  
  CU_ASSERT_EQUAL(is_var(VAR_INCOR4), False) ; 
  
  return ; 
}

void test_is_var_incorrect_name5(void)
{  
  CU_ASSERT_EQUAL(is_var(VAR_INCOR5), False) ; 
  
  return ; 
}

void test_is_var_correct_name(void)
{
  int i ; 
  char corNames[NUMBER_OF_VARS][VAR_NAME_LEN] = VAR_NAMES ; 
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_EQUAL(is_var(corNames[i]), True) ; 
  }
  
  return ; 
}

/* 
 * Suite 5 Tests - 
 * #define is_negative (turtle_parser.h) 
 */
void test_is_negative_return_value_false1(void)
{  
  CU_ASSERT_EQUAL(is_negative(NAME_INCOR1), False) ; 
  
  return ; 
}

void test_is_negative_return_value_false2(void)
{  
  CU_ASSERT_EQUAL(is_negative(NAME_INCOR2), False) ; 
  
  return ; 
}

void test_is_negative_return_value_false3(void)
{  
  CU_ASSERT_EQUAL(is_negative(NAME_INCOR3), False) ; 
  
  return ; 
}

void test_is_negative_return_value_false4(void)
{  
  CU_ASSERT_EQUAL(is_negative(NAME_INCOR4), False) ; 
  
  return ; 
}

void test_is_negative_return_value_false5(void)
{  
  CU_ASSERT_EQUAL(is_negative(NAME_INCOR5), False) ; 
  
  return ; 
}

void test_is_negative_return_value_true(void)
{  
  CU_ASSERT_EQUAL(is_negative(NEGATIVE_SYMBOL_STR), True) ; 
  
  return ; 
}

/* 
 * Suite 6 Tests - #define more_than_one_decimal_or_negative
 * (turtle_parser.h)
 */
void test_more_than_one_decimal_or_negative_true1(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR1 ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), True) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_true2(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR2 ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), True) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_true3(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR3 ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), True) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_true4(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR4 ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), True) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_true5(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR5 ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), True) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_false1(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NON_NEG_INT ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), False) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_false2(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NEG_INT ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), False) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_false3(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NON_NEG_FLOAT ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), False) ; 

  return ; 
}

void test_more_than_one_decimal_or_negative_false4(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NEG_FLOAT ; 

  CU_ASSERT_EQUAL(more_than_one_decimal_or_negative(n[0], \
  n[1]), False) ; 

  return ; 
}

/* Suite 7 Tests - is_num (turtle_parser.c) */ 
void test_is_num_incorrect1(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_INCOR1), False) ; 
  
  return ; 
}

void test_is_num_incorrect2(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_INCOR2), False) ; 
  
  return ; 
}

void test_is_num_incorrect3(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_INCOR3), False) ; 
  
  return ; 
}

void test_is_num_incorrect4(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_INCOR4), False) ; 
  
  return ; 
}

void test_is_num_incorrect5(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_INCOR5), False) ; 
  
  return ; 
}

void test_is_num_cor_non_negative_integer(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NON_NI), Number) ; 
  
  return ; 
}

void test_is_num_cor_negative_integer(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NI), Number) ; 
  
  return ; 
}

void test_is_num_cor_non_negative_floating(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NON_NF), Number) ; 
  
  return ; 
}

void test_is_num_cor_negative_floating1(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NF1), Number) ; 
  
  return ; 
}

void test_is_num_cor_negative_floating2(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NF2), Number) ; 
  
  return ; 
}

/* Suite 8 Tests - is_var_or_num (turtle_parser.c) */ 
void test_is_var_or_num_not_number1(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_INCOR1), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_number2(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_INCOR2), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_number3(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_INCOR3), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_number4(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_INCOR4), False) ; 
  
  return ; 
}

void test_is_var_or_num_too_long(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(STR_TOO_LONG), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_variable1(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(VAR_INCOR1), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_variable2(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(VAR_INCOR2), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_variable3(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(VAR_INCOR3), False) ; 
  
  return ; 
}

void test_is_var_or_num_not_variable4(void)
{  
  CU_ASSERT_EQUAL(is_var_or_num(VAR_INCOR4), False) ; 
  
  return ; 
}

void test_is_var_or_num_cor_non_negative_integer(void)  
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NON_NI), Number) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_integer(void)  
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NI), Number) ; 
  
  return ; 
}

void test_is_var_or_num_cor_non_negative_floating(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NON_NF), Number) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_floating1(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NF1), Number) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_floating2(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NF2), Number) ; 
  
  return ; 
}

void test_is_var_or_num_correct_variables(void)
{
  int i ; 
  char corNames[NUMBER_OF_VARS][VAR_LENGTH + 1] = \
  VAR_NAMES ; 
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_EQUAL(is_var_or_num(corNames[i]), Variable) ; 
  }
  
  return ; 
}

/* Suite 21 Tests - is_move (turtle_parser.c) */
void test_is_move_fail1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_INCOR1) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Failure) ; 
        
  CU_ASSERT_EQUAL(p->place, Failure) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_is_move_fail2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_INCOR2) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Failure) ; 
        
  CU_ASSERT_EQUAL(p->place, Failure) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_is_move_fail3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_INCOR3) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Failure) ; 
        
  CU_ASSERT_EQUAL(p->place, Failure) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_is_move_pass1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_COR1) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, Success) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
     
  return ; 
}

void test_is_move_pass2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_COR2) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, Success) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_is_move_pass3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MOVE_COR3) ; 
    
  CU_ASSERT_EQUAL(is_move(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, Success) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite Tests - 22
 * #define MOCK_PASSING_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
void test_mock_parsing_error(void)
{
  unsigned int check = 0 ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
    
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  MOCK_PARSING_ERROR(MK_PAR_MSSGE, MOCK_PAR_TYPE, p, check); 
       
  CU_ASSERT_EQUAL(check, Success) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  CU_ASSERT_PTR_NULL(tempFile) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 23 Tests - 
 * mock_check_within_program_bounds (turtle_parser.c) 
 */
unsigned int mock_check_within_program_bounds(Prog *p)
{
  unsigned int check ; 
  
  check = 0 ; 

  (p->place >= p->totalStrs) ? \
  (check = True) : (check = False) ; 
  
  
  if(check == True){
    return True ; 
  }

  return False ; 
}

void test_mock_check_within_program_bounds_fail1(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, EMPTY_FILE) ;   
    
  CU_ASSERT_EQUAL(mock_check_within_program_bounds(p), \
  True) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_within_program_bounds_fail2(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;   
  
  p->place = TEST_FILE_STRS + 1 ; 
    
  CU_ASSERT_EQUAL(mock_check_within_program_bounds(p), \
  True) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_within_program_bounds_pass(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;   
      
  CU_ASSERT_EQUAL(mock_check_within_program_bounds(p), \
  False) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* Suite 24 Tests - mock_polish (turtle_parser.c) */
unsigned int mock_polish(Prog *p)
{
  unsigned int mockReturnValue, check ;  
  
  mockReturnValue = check = 0 ; 
  
  (p->place)++ ; 
    
  if(mock_check_within_program_bounds(p)){
    return OutOfBounds ; 
  } 
      
  if(str_same(p->program[p->place], POLISH_TERM_CHAR)){
    return Success ; 
  }

  if(is_op(p->program[p->place])){
    check++ ;
    mockReturnValue = mock_polish(p) ; 
    return mockReturnValue ; 
  }
  
  if(is_var_or_num(p->program[p->place])){
    check++ ; 
    mockReturnValue = mock_polish(p) ; 
    return mockReturnValue ; 
  }

  if(check == 0){
    return Failure ; 
  }
  
  return mockReturnValue ; 
}

void test_mock_polish_no_end_character(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NO_END) ;   
    
  CU_ASSERT_EQUAL(mock_polish(p), OutOfBounds) ;
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_incor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_INCOR1) ; 
        
  CU_ASSERT_EQUAL(mock_polish(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_incor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_INCOR2) ;   
    
  CU_ASSERT_EQUAL(mock_polish(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_incor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_INCOR3) ;   
    
  CU_ASSERT_EQUAL(mock_polish(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_incor4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_INCOR4) ;   
    
  CU_ASSERT_EQUAL(mock_polish(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_cor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_COR1) ;   
    
  CU_ASSERT_EQUAL(mock_polish(p), Success) ; 
  
  CU_ASSERT_EQUAL(p->place, POL_COR_PASS_1) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_cor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_COR2) ;   
  
  CU_ASSERT_EQUAL(mock_polish(p), Success) ; 
  
  CU_ASSERT_EQUAL(p->place, POL_COR_PASS_2) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_cor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_COR3) ;   
  
  CU_ASSERT_EQUAL(mock_polish(p), Success) ; 
  
  CU_ASSERT_EQUAL(p->place, POL_COR_PASS_3) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_cor4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_COR4) ;   
  
  CU_ASSERT_EQUAL(mock_polish(p), Success) ; 
  
  CU_ASSERT_EQUAL(p->place, POL_COR_PASS_4) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_polish_cor5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_COR5) ;   
  
  CU_ASSERT_EQUAL(mock_polish(p), Success) ; 
  
  CU_ASSERT_EQUAL(p->place, POL_COR_PASS_5) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* Suite 25 Tests - mock_set (turtle_parser.c) */
unsigned int mock_set(Prog *p) 
{
  if(mock_check_within_program_bounds(p)){
    return OutOfBounds ; 
  } 
  
  if(!str_same(p->program[p->place], SET_START)){
    return MockNoSetStart ; 
  } 
  
  (p->place)++ ; 

  if(!is_var(p->program[p->place])){
    return MockNoSetVar ;
  }

  (p->place)++ ; 

  if(!str_same(p->program[p->place], SET_DEFINE)){
    return MockNoSetDefine ;
  } 
      
  return mock_polish(p) ; 
}

void test_mock_set_incor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_INCOR1) ; 
        
  CU_ASSERT_EQUAL(mock_set(p), MockNoSetStart) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_incor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_INCOR2) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), MockNoSetVar
) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_incor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_INCOR3) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), MockNoSetDefine) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_incor4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_INCOR4) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), OutOfBounds) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_incor5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_INCOR5) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Failure) ;  
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_cor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_COR1) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Success) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_1) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_cor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
    
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_COR2) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Success) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_2) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_cor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
    
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_COR3) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Success) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_3) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_cor4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
    
  p = memory_for_Prog() ;  
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_COR4) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Success) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_4) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_cor5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, SET_COR5) ;   
  
  CU_ASSERT_EQUAL(mock_set(p), Success) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_5) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* Suite 26 Tests - mock_do_from_to (turtle_parser.c) */
unsigned int mock_do_from_to(Prog *p)
{
  check_within_program_bounds(p) ; 
  
  if(!str_same(p->program[(p->place)++], DO_START)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoStartFail ; 
  } 
  
  if(!is_var(p->program[(p->place)++])){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoVarFail ; 
  }
  
  if(!str_same(p->program[(p->place)++], DO_FROM)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoVarFail ; 
  }
    
  if(!is_var_or_num(p->program[(p->place)++])){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoVarNum1Fail ; 
  }
  
  if(!str_same(p->program[(p->place)++], DO_TO)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoToFail ; 
  }
  
  if(!is_var_or_num(p->program[(p->place)++])){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoVarNum2Fail ; 
  }
  
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoEndFail ; 
  }
  /* 
   * Assume instruction_list works and input is correct - 
   * instruction_list(p) ; 
   */
  return Success ; 
}

void test_mock_do_from_to_fail1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR1) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoStartFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL1_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_do_from_to_fail2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR2) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoVarFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL2_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_do_from_to_fail3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR3) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoVarFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL3_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_fail4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR4) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoVarNum1Fail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL4_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_do_from_to_fail5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR5) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoToFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL5_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_fail6(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR6) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoVarNum2Fail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL6_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_fail7(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR7) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoEndFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL7_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR1) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR2) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR3) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR4) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
    
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* Suite 27 Tests - mock_instruction (turtle_parser.c) */
unsigned int mock_instruction(Prog *p) 
{
  if(str_same(p->program[p->place], DO_START)){
    /* Assume function do() works correctly and input ok. */
    return InstrctDo ; 
  }
  
  if(str_same(p->program[p->place], SET_START)){
    /* Assume function set() works correctly and input ok.*/
    return InstrctSet ; 
  }
  
  if(is_move(p)){
    if(!is_var_or_num(p->program[p->place])){
      /* PARSING_ERROR - simulate this by returning 0. */ 
      return InstrctMoveFail ; 
    }
    else{
      return InstrctMove ; 
    }
  }
  
  return Failure ; 
}

void test_mock_instruction_fail1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_INCOR1) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), Failure) ;
  
  CU_ASSERT_EQUAL(p->place, NoMove) ;  
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_fail2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_INCOR2) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), \
  InstrctMoveFail) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_fail3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_INCOR3) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), \
  InstrctMoveFail) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_pass_fd(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_COR_FD) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), InstrctMove) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_pass_lt(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_COR_LT) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), InstrctMove) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_pass_rt(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_COR_RT) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), InstrctMove) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_pass_do(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_COR_DO) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), InstrctDo) ; 
        
  CU_ASSERT_EQUAL(p->place, NoMove) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_pass_set(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, INST_COR_SE) ; 
    
  CU_ASSERT_EQUAL(mock_instruction(p), InstrctSet) ; 
        
  CU_ASSERT_EQUAL(p->place, NoMove) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 28 Tests - 
 * mock_instruction_list (turtle_parser.c) 
 */
unsigned int mock_instruction_list(Prog *p)
{  
  unsigned int check = Failure ; 
  
  (p->place)++ ;

  if(mock_check_within_program_bounds(p)){
    return OutOfBounds ; 
  } 
    
  if(str_same(p->program[p->place], TERMINATING_CHAR)){ 
    return Success ; 
  }
  
  else if(mock_instruction(p)){
    check = mock_instruction_list(p) ; 
  } 
  
  else{
    return Failure ;
  }
     
  return check ; 
}

void test_mock_instruction_list_fail1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_INCOR1) ; 
        
  CU_ASSERT_EQUAL(mock_instruction_list(p), OutOfBounds) ;
  
  CU_ASSERT_EQUAL(p->place, ThreeSteps) ;  
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_fail2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_INCOR2) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), OutOfBounds) ;
  
  CU_ASSERT_EQUAL(p->place, FourSteps) ;  
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_fail3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_INCOR3) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), Failure) ;
  
  CU_ASSERT_EQUAL(p->place, OneStep) ;  
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_empty(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, EMPTY_FILE) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), OutOfBounds) ;
  
  CU_ASSERT_EQUAL(p->place, OneStep) ;  
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_pass1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_COR1) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, OneStep) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_pass2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_COR2) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, ThreeSteps) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_instruction_list_pass3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, LIST_COR3) ; 
    
  CU_ASSERT_EQUAL(mock_instruction_list(p), Success) ; 
        
  CU_ASSERT_EQUAL(p->place, TwoSteps) ; 
      
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 29 Tests - 
 * mock_parser_program_main (turtle_parser.c) 
 */
unsigned int mock_parser_program_main(Prog *p) 
{
  if(p->totalStrs == 0){
    return OutOfBounds ; 
  }

  if(!str_same(p->program[p->place], OPENING_CHAR)){
    return Failure ; 
  }
  /* 
   * Assume instruction_list works and input is correct - 
   * instruction_list(p) ; 
   */
  return Success ; 
}

void test_mock_parser_program_main_incor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR1) ; 
      
  CU_ASSERT_EQUAL(mock_parser_program_main(p), Failure) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_parser_program_main_incor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR2) ; 
      
  CU_ASSERT_EQUAL(mock_parser_program_main(p), Failure) ;  
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_parser_program_main_incor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR3) ; 
      
  CU_ASSERT_EQUAL(mock_parser_program_main(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_parser_program_main_incor_empty_file(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, EMPTY_FILE) ; 
      
  CU_ASSERT_EQUAL(mock_parser_program_main(p), \
  OutOfBounds) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_parser_program_main_pass(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_COR) ; 
      
  CU_ASSERT_EQUAL(mock_parser_program_main(p), Success) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}


