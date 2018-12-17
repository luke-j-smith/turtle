/* File containing all tests for turtle_interp.c */ 
#include "test_turtle_interp.h"


/* Suite 1 Tests - #define str_same (turtle_interp.h) */
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

/* Suite 2 Tests - is_op (turtle_interp.c) */ 
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
 * #define a_variable_name (turtle_interp.h) 
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

/* Suite 4 Tests - is_var (turtle_interp.c) */ 
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

/* Suite 5 Tests - #define is_negative (turtle_interp.h) */
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
 * (turtle_interp.h)
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

/* 
 * Suite 7 Tests - 
 * #define determine_type_two_inputs (turtle_interp.h) 
 */ 
void test_determine_type_two_inputs_test_zero(void)
{   
  CU_ASSERT_EQUAL(determine_type_two_inputs(0, 0), 0) ; 

  return ; 
}
 
void test_determine_type_two_inputs_test_range(void)
{
  int i, j, calc ;
  
  i = TEST_DETERMINE_TYPE_START ;
  j = TEST_DETERMINE_TYPE_END ; 
  
  while(i < TEST_DETERMINE_TYPE_END){
    calc = ((i * 1) + (j * 2)) ; 
    
    CU_ASSERT_EQUAL(determine_type_two_inputs(i, j), calc) ; 
  
    i++ ; 
    j-- ; 
  }
    
  return ; 
}

/* Suite 8 Tests - type_of_number (turtle_interp.c) */
void test_type_of_number_return_false1(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR1 ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), False) ; 

  return ; 
}

void test_type_of_number_return_false2(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR2 ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), False) ; 

  return ; 
}

void test_type_of_number_return_false3(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR3 ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), False) ; 

  return ; 
}

void test_type_of_number_return_false4(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR4 ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), False) ; 

  return ; 
}

void test_type_of_number_return_false5(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_INCOR5 ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), False) ; 

  return ; 
}

void test_type_of_number_return_NonNegInt(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NON_NEG_INT ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), NonNegInt) ; 

  return ; 
}

void test_type_of_number_return_NegInt(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NEG_INT ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), NegInt) ; 

  return ; 
}

void test_type_of_number_return_NonNegFloat(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NON_NEG_FLOAT ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), NonNegFloat) ; 

  return ; 
}

void test_type_of_number_return_NegFloat(void)
{
  unsigned int n[TWO_INPUTS] = TYPE_NUM_NEG_FLOAT ; 

  CU_ASSERT_EQUAL(type_of_number(n[0], n[1]), NegFloat) ; 

  return ; 
}

/* Suite 9 Tests - is_num (turtle_interp.c) */ 
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
  CU_ASSERT_EQUAL(is_num(NUM_NON_NI), NonNegInt) ; 
  
  return ; 
}

void test_is_num_cor_negative_integer(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NI), NegInt) ; 
  
  return ; 
}

void test_is_num_cor_non_negative_floating(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NON_NF), NonNegFloat) ; 
  
  return ; 
}

void test_is_num_cor_negative_floating1(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NF1), NegFloat) ; 
  
  return ; 
}

void test_is_num_cor_negative_floating2(void)
{  
  CU_ASSERT_EQUAL(is_num(NUM_NF2), NegFloat) ; 
  
  return ; 
}

/* Suite 10 Tests - is_var_or_num (turtle_interp.c) */ 
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
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NON_NI), NonNegInt) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_integer(void)  
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NI), NegInt) ; 
  
  return ; 
}

void test_is_var_or_num_cor_non_negative_floating(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NON_NF), NonNegFloat) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_floating1(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NF1), NegFloat) ; 
  
  return ; 
}

void test_is_var_or_num_cor_negative_floating2(void) 
{  
  CU_ASSERT_EQUAL(is_var_or_num(NUM_NF2), NegFloat) ; 
  
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

/* Suite 28 Tests - is_move (turtle_interp.c) */
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
 * Suite Tests - 29
 * #define MOCK_INTERP_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
void test_MOCK_INTERP_ERROR(void)
{
  unsigned int check = 0 ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
    
  set_up_program(p, tempFile, TEST_FILE) ; 
  
  MOCK_INTERP_ERROR(MK_PAR_MSSGE, MOCK_PAR_TYPE, p, check); 
       
  CU_ASSERT_EQUAL(check, Success) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  CU_ASSERT_PTR_NULL(tempFile) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 30 Tests - 
 * mock_check_within_program_bounds (turtle_interp.c) 
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

/* Suite 32 Tests - mock_pop (turtle_interp_setup.c) */
double mock_pop(Prog *p)
{
  if(p->s.top <= 0){
    free_program_memory(&p) ; 
    return Failure ;  
  }

  p->s.top = p->s.top - 1 ; 

  return p->s.stack[p->s.top].value ; 
}

void test_mock_pop_flag_empty(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }    
  
  initialise_stack(p, STACK_TEST_SIZE) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(mock_pop(p), Failure, FLOAT_DIF) ;
      
  return ; 
}

void test_mock_pop_top_value(void)
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
    push(p, value) ; 
  }
  
  for(i = 0 ; i < p->s.size ; i++){
    mock_pop(p) ; 
    
    CU_ASSERT_EQUAL(p->s.top, (p->s.size - (i + 1))) ;  
  }
  
  free_program_memory(&p) ; 

  return ; 
}

void test_mock_pop_popped_value(void)
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
    push(p, (i * value)) ; 
  }
  
  for(i = 0 ; i < p->s.size ; i++){    
    CU_ASSERT_DOUBLE_EQUAL(mock_pop(p), \
    ((p->s.size - (1 + i)) * value), FLOAT_DIF) ;  
  }
  
  free_program_memory(&p) ; 

  return ; 
}

/* 
 * Suite 33 Tests - 
 * mock_get_final_value_from_stack (turtle_interp.c) 
 */
double mock_get_final_value_from_stack(Prog *p)
{
  double finalValue ; 
    
  if(p->s.top == 1){
    finalValue = mock_pop(p) ; 
    p->temp.value = finalValue ; 
  }
  else if(p->s.top > 1){
    free_program_memory(&p) ; 
    return StackMore1 ; 
  }
  else{
    free_program_memory(&p) ; 
    return StackLess1 ; 
  }
    
  free_stack(&(p->s)) ; 

  return finalValue ; 
} 

void mock_get_final_value_from_stack_more_than_one(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }    
  
  initialise_stack(p, STACK_TEST_SIZE) ; ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    push(p, (i * value)) ; 
  }
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_get_final_value_from_stack(p), StackMore1,FLOAT_DIF); 
    
  return ; 
}

void mock_get_final_value_from_stack_less_than_one(void)
{
  Prog *p = NULL ; 

  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }    
  
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_get_final_value_from_stack(p), StackLess1,FLOAT_DIF); 
    
  return ; 
}


void mock_get_final_value_from_stack_correct_value(void)
{
  Prog *p = NULL ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }    
  
  initialise_stack(p, STACK_TEST_SIZE) ;  
  
  push(p, value) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_get_final_value_from_stack(p), value, FLOAT_DIF) ; 
  
  CU_ASSERT_PTR_NULL(p->s.stack) ;  
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* 
 * Suite 34 Tests - 
 * mock_read_number_value (turtle_interp.c) 
 */
double mock_read_number_value(char *string) 
{
  double value ; 
  unsigned int length ; 
  char *strCopy = NULL, *end = NULL ; 
  
  if(is_num(string) == False){
    return False ;  
  }
  
  length = strlen(string) + 1 ; 
  
  strCopy = memory_for_string(length) ; 
  
  if(pointer_is_null(strCopy)){
    CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
  }
  
  strcpy(strCopy, string) ; 
  
  value = strtod(strCopy, &end) ; 
  
  free(strCopy) ; 
  
  strCopy = NULL ; 
  
  return value ;  
}

void test_mock_read_number_value_incor_num_flagged1(void) 
{
  char *notNumber = NUM_INCOR1 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(notNumber),\
  False, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(notNumber, NUM_INCOR1) ; 

  return ; 
}

void test_mock_read_number_value_incor_num_flagged2(void) 
{
  char *notNumber = NUM_INCOR2 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(notNumber),\
  False, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(notNumber, NUM_INCOR2) ; 

  return ; 
}

void test_mock_read_number_value_incor_num_flagged3(void) 
{
  char *notNumber = NUM_INCOR3 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(notNumber),\
  False, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(notNumber, NUM_INCOR3) ; 

  return ; 
}

void test_mock_read_number_value_incor_num_flagged4(void) 
{
  char *notNumber = NUM_INCOR4 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(notNumber),\
  False, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(notNumber, NUM_INCOR4) ; 

  return ; 
}

void test_mock_read_number_value_incor_num_flagged5(void) 
{
  char *notNumber = NUM_INCOR5 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(notNumber),\
  False, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(notNumber, NUM_INCOR5) ; 

  return ; 
}

void test_mock_read_number_value_correct_num1(void) 
{
  char *number = NUM_NON_NI ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(number),\
  NUM_NON_NI_VALUE, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(number, NUM_NON_NI) ; 

  return ; 
}

void test_mock_read_number_value_correct_num2(void) 
{
  char *number = NUM_NI ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(number),\
  NUM_NI_VALUE, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(number, NUM_NI) ; 

  return ; 
}

void test_mock_read_number_value_correct_num3(void) 
{
  char *number = NUM_NON_NF ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(number),\
  NUM_NON_NF_VALUE, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(number, NUM_NON_NF) ; 

  return ; 
}

void test_mock_read_number_value_correct_num4(void) 
{
  char *number = NUM_NF1 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(number),\
  NUM_NF1_VALUE, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(number, NUM_NF1) ; 

  return ; 
}

void test_mock_read_number_value_correct_num5(void) 
{
  char *number = NUM_NF2 ; 

  CU_ASSERT_DOUBLE_EQUAL(mock_read_number_value(number),\
  NUM_NF2_VALUE, FLOAT_DIF) ; 

  CU_ASSERT_STRING_EQUAL(number, NUM_NF2) ; 

  return ; 
}

/* 
 * Suite 35 Tests - 
 * #define determine_var_index (turtle_interp.h) 
 */
void test_determine_var_index_correct_value(void)
{
  unsigned int i, index ; 
  char corNames[NUMBER_OF_VARS][VAR_LENGTH + 1] = \
  VAR_NAMES ; 
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    index = (unsigned int) \
    determine_var_index(corNames[i][0]) ; 
      
    CU_ASSERT_EQUAL(index, i); 
  }

  return ; 
}

/* Suite 36 Tests - mock_set_var_value (turtle_interp.c) */
double mock_set_var_value(char *str, double value, Prog *p)
{
  unsigned int index ; 
  
  if(is_var(str) == False){
    /* In mock, return error value, rather than exiting. */
    return MockSetVarFail ; 
  }

  index = determine_var_index(str[0]) ; 
  
  if(p->var[index] == NULL){
    p->var[index] = (VarValue *)calloc(1, sizeof(VarValue));
  }

  p->var[index]->value = value ; 

  return p->var[index]->value ; 
}

void test_mock_set_var_value_fail_name_length(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set_var_value(VAR_INCOR4, 0, \
  p), MockSetVarFail, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_set_var_value_fail_name_wrong(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set_var_value(VAR_INCOR1, 0, \
  p), MockSetVarFail, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_set_var_value_correct_not_defined(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  char str[NUMBER_OF_VARS][VAR_NAME_LEN] = VAR_NAMES ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_PTR_NULL(p->var[i]) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(mock_set_var_value(str[i], i,p),\
    i, FLOAT_DIF) ;
      
    CU_ASSERT_PTR_NOT_NULL(p->var[i]) ; 
  }
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_set_var_value_correct_when_defined(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  char str[NUMBER_OF_VARS][VAR_NAME_LEN] = VAR_NAMES ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    CU_ASSERT_PTR_NULL(p->var[i]) ; 
    
    p->var[i] = (VarValue *)calloc(1, sizeof(VarValue)) ; 
    
    p->var[i]->value = ((i*i) + 1) ; 
    
    CU_ASSERT_PTR_NOT_NULL(p->var[i]) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(mock_set_var_value(str[i], i,p),\
    i, FLOAT_DIF) ;
      
    CU_ASSERT_PTR_NOT_NULL(p->var[i]) ; 
  }
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* Suite 37 Tests - mock_read_var_value (turtle_interp.c) */
double mock_read_var_value(char *str, Prog *p)
{
  unsigned int index ; 
     
  if(is_var(str) == False){
   return MockVarReadNameFail ; 
  }
  
  index = determine_var_index(str[0]) ; 
  
  if(p->var[index] == NULL){
   return MockVarReadNullFail ; 
  }

  return p->var[index]->value ; 
}

void test_mock_read_var_value_fail_name_length(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_read_var_value(VAR_INCOR4, \
  p), MockVarReadNameFail, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_read_var_value_fail_name_wrong(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_read_var_value(VAR_INCOR1, \
  p), MockVarReadNameFail, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_read_var_value_fail_null(void)
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
    CU_ASSERT_DOUBLE_EQUAL(mock_read_var_value(\
    COR_VAR_NAME, p), MockVarReadNullFail, FLOAT_DIF) ;  
  }
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_read_var_correct_var_values(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  char str[NUMBER_OF_VARS][VAR_NAME_LEN] = VAR_NAMES ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    p->var[i] = (VarValue *)calloc(1, sizeof(VarValue)) ; 
    
    p->var[i]->value = i ; 
    
    CU_ASSERT_DOUBLE_EQUAL(mock_read_var_value(str[i], p), \
    i, FLOAT_DIF) ;  
  }
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* 
 * Suite 38 Tests - 
 * mock_value_of_var_or_num (turtle_interp.c) 
 */
double mock_value_of_var_or_num(Prog *p)
{
  double value = 0 ; 

  if(is_var(p->program[p->place])){
    value = read_var_value(p->program[p->place], p) ; 
  }

  else if(is_num(p->program[p->place])){
    value = read_number_value(p->program[p->place], p) ; 
  }
  
  else{
    return False ; 
  }

  return value ; 
}

void test_mock_value_of_var_or_num_fail1(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_INCOR1) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, False, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_fail2(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_INCOR2) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, False, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_fail3(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_INCOR3) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, False, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_fail4(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_INCOR4) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, False, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_fail5(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_INCOR5) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, False, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_vars_cor(void)
{
  double returnValue ; 
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_VAR_COR) ;
  
  for(i = 0 ; i < NUMBER_OF_VARS ; i++){
    p->var[i] = (VarValue *)calloc(1, sizeof(VarValue)) ; 
    
    p->var[i]->value = i ; 
    
    p->place = i ; 
    
    returnValue = mock_value_of_var_or_num(p) ; 
  
    CU_ASSERT_DOUBLE_EQUAL(returnValue, i, FLOAT_DIF) ; 
  }
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_num_cor1(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR1) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, \
  VARNUM_NUM_COR_VALUE1, FLOAT_DIF) ;
      
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_num_cor2(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR2) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, \
  VARNUM_NUM_COR_VALUE2, FLOAT_DIF) ;    
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_num_cor3(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR3) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, \
  VARNUM_NUM_COR_VALUE3, FLOAT_DIF) ;    
  
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_num_cor4(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR4) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, \
  VARNUM_NUM_COR_VALUE4, FLOAT_DIF) ;   
   
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_value_of_var_or_num_num_cor5(void)
{
  double returnValue ; 
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR5) ;
  
  returnValue = mock_value_of_var_or_num(p) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(returnValue, \
  VARNUM_NUM_COR_VALUE5, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* 
 * Suite 39 Tests - 
 * mock_check_if_division_by_zero (turtle_interp.c) 
 */
unsigned int mock_check_if_division_by_zero(double divisor)
{
  if((fabs(divisor) - FLOAT_DIF) < 0){
    return True ; 
  }

  return False ; 
}
 
void test_mock_check_if_division_by_zero_true(void)
{
  double zero = 0.0 ; 
  
  CU_ASSERT_EQUAL(mock_check_if_division_by_zero(zero), \
  True) ; 

  return ; 
}

void test_mock_check_if_division_by_zero_false(void)
{
  double notZero = 1.0 ; 
  
  CU_ASSERT_EQUAL(mock_check_if_division_by_zero(notZero), \
  False) ; 

  return ; 
}

/* Suite 40 Tests - mock_calculation (turtle_interp.c) */
double mock_calculation(Prog *p, double value1, \
double value2) 
{
  unsigned int i, operationType ; 
  double calc ; 
  char *operations[NUMBER_OF_OPS] = OP_SET ; 
  
  operationType = NoOperation ; 

  for(i = 0 ; i < NUMBER_OF_OPS ; i++){
    if(str_same(p->program[p->place], operations[i])){
      operationType = i ; 
    }
  }

  switch(operationType){
    case Addition : calc = (value1 + value2) ; break ; 
    case Subtraction : calc = (value1 - value2) ; break ; 
    case Multiplication : calc = (value1 * value2) ; break ; 
    case Division : 
      if(mock_check_if_division_by_zero(value2)){
        return DivisionByZero ; 
      } 
      calc = (value1 / value2) ; break ; 
    case NoOperation : return NoOp ;  
    default : return False ; 
  }

  return calc ; 
}

void test_mock_calculation_no_operation(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  val1 = val2 = 0 ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, TEST_FILE) ;
    
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  NoOp, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculation_divide_by_zero_flag(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  srand(time(NULL)) ; 
  
  val1 = rand() ; 
  val2 = 0 ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_DIV) ;
    
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  DivisionByZero, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculation_addition_correct(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  srand(time(NULL)) ; 
  
  val1 = rand() ; 
  val2 = rand() ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_ADD) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  (val1 + val2), FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculation_subtraction_correct(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  srand(time(NULL)) ; 
  
  val1 = rand() ; 
  val2 = rand() ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_SUB) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  (val1 - val2), FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculation_multiplication_correct(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  srand(time(NULL)) ; 
  
  val1 = rand() ; 
  val2 = rand() ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_MUL) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  (val1 * val2), FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculation_division_correct(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  double val1, val2 ; 
  
  srand(time(NULL)) ; 
  
  val1 = rand() ; 
  val2 = rand() ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_DIV) ;
  
  CU_ASSERT_DOUBLE_EQUAL(mock_calculation(p, val1, val2), \
  (val1 / val2), FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* Suite 41 Tests - update_stack (turtle_interp.c) */
void test_update_stack_calc_addition(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_ADD) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, CALCULATION) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size - 1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  (value + value), FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_calc_subtraction(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_SUB) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, CALCULATION) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size - 1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  (value - value), FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_calc_multiplication(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_MUL) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, CALCULATION) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size - 1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  (value * value), FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_calc_division(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, CALC_DIV) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < p->s.size ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, CALCULATION) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size - 1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  (value / value), FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_push_only1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR1) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < (p->s.size - 1) ; i++){
    push(p, value) ; 
  }
    
  update_stack(p, PUSH_ONLY) ; 
    
  CU_ASSERT_EQUAL(p->s.top, p->s.size) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  VARNUM_NUM_COR_VALUE1, FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_push_only2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR2) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < (p->s.size - 1) ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, PUSH_ONLY) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  VARNUM_NUM_COR_VALUE2, FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_push_only3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR3) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < (p->s.size - 1) ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, PUSH_ONLY) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  VARNUM_NUM_COR_VALUE3, FLOAT_DIF) ;  
  
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_push_only4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR4) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < (p->s.size - 1) ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, PUSH_ONLY) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  VARNUM_NUM_COR_VALUE4, FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

void test_update_stack_push_only5(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int i ; 
  double value = STACK_TEST_VAL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, VARNUM_NUM_COR5) ;
    
  initialise_stack(p, STACK_TEST_SIZE) ; 
  
  for(i = 0 ; i < (p->s.size - 1) ; i++){
    push(p, value) ; 
  }
  
  update_stack(p, PUSH_ONLY) ; 
  
  CU_ASSERT_EQUAL(p->s.top, p->s.size) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  VARNUM_NUM_COR_VALUE5, FLOAT_DIF) ;  
    
  free_program_memory(&p) ; 

  return ; 
}

/* 
 * Suite 43 Tests - 
 * mock_calculate_turn_amount (turtle_interp.c) 
 */
int mock_calculate_turn_amount(Prog *p, double turnBy)
{
  double radians ; 
  
  switch(p->currentMove){
    case LT : turnBy *= LEFT_TURN ; 
      radians = degrees_to_radians(turnBy) ; break ; 
    case RT : radians = degrees_to_radians(turnBy) ; break ; 
    default : free_program_memory(&p) ; 
      return Failure ;  
  }

  p->turtle.theta += radians ; 

  return Success ; 
}

void test_mock_calculate_turn_amount_incor_move_type(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  p->currentMove = FD ; 
  
  CU_ASSERT_EQUAL(mock_calculate_turn_amount(p, 0), \
  Failure)
    
  return ; 
}

void test_mock_calculate_turn_amount_LT(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double degrees, radians ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  srand(time(NULL)) ; 
  
  p->currentMove = LT ; 
  
  for(i = 0 ; i < NUM_TEST_DEG_TO_RAD ; i++){
    p->turtle.theta = 0.0 ; 
  
    degrees = (rand() % DEGREES_IN_CIRCLE) ; 
    
    if((i % 2) == 0){
      degrees = -degrees ; 
    }
    
    CU_ASSERT_EQUAL(mock_calculate_turn_amount(p, degrees),\
    Success)
  
    radians = (degrees * (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
    
    radians *= LEFT_TURN ; 
    
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, radians, \
    FLOAT_DIF) ; 
  }
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_calculate_turn_amount_RT(void)
{
  Prog *p = NULL ; 
  unsigned int i ; 
  double degrees, radians ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  srand(time(NULL)) ; 
  
  p->currentMove = RT ; 
  
  for(i = 0 ; i < NUM_TEST_DEG_TO_RAD ; i++){
    p->turtle.theta = 0.0 ; 
  
    degrees = (rand() % DEGREES_IN_CIRCLE) ; 
    
    if((i % 2) == 0){
      degrees = -degrees ; 
    }
    
    CU_ASSERT_EQUAL(mock_calculate_turn_amount(p, degrees),\
    Success)
  
    radians = (degrees * (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
        
    CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, radians, \
    FLOAT_DIF) ; 
  }
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* 
 * Suite 44 Tests - 
 * calculate_next_position (turtle_interp.c) 
 */
void test_calculat_next_position(void)
{
  TurtlePos turtle ; 
  unsigned int i ; 
  double distance, xOld, yOld, xNew, yNew ; 
  
  srand(time(NULL)) ; 
    
  turtle.theta = 0.0 ;
  
  turtle.current.x = 0.0 ; 
  
  turtle.current.y = 0.0 ; 
  
  for(i = 0 ; i < NUM_TEST_DEG_TO_RAD ; i++){
    
    turtle.theta = (double) (rand() / (2 * M_PI)) ; 
    distance = rand() ; 

    if((i % 2) == 0){
      distance = -distance ; 
    }
    
    xOld = turtle.current.x ; 
    
    yOld = turtle.current.y ; 
    
    xNew = xOld + (distance * sin(turtle.theta)) ; 
    
    yNew = yOld - (distance * cos(turtle.theta)) ; 
    
    calculate_next_position(&turtle, distance) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(turtle.current.x, xNew, \
    FLOAT_DIF) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(turtle.current.y, yNew, \
    FLOAT_DIF) ; 
    
    CU_ASSERT_DOUBLE_EQUAL(turtle.previous.x, xOld, \
    FLOAT_DIF);
    
    CU_ASSERT_DOUBLE_EQUAL(turtle.previous.y, yOld, \
    FLOAT_DIF);
  }
  
  return ; 
}

/* 
 * Suite 45 Tests - 
 * mock_still_on_screen (turtle_interp.c) 
 */
unsigned int mock_check_still_on_screen(Prog *p)
{
  /* If gone off the right of the screen. */ 
  if(p->turtle.current.x > SDL_WIDTH){
    return OffRight ;  
  }
  /* Gone off the left of the screen. */ 
  if(p->turtle.current.x < 0){
    return OffLeft ;  
  }
  /* Gone off the bottom of the screen. */ 
  if(p->turtle.current.y > SDL_HEIGHT){
    return OffBottom ;  
  }
  /* Gone off the top of the screen. */ 
  if(p->turtle.current.y < 0){
    return OffTop ;  
  }

  return Success ; 
}

void test_mock_check_still_on_screen_flags_right(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }  
  
  p->turtle.current.x = OFF_SCREEN_X_POS ; 
  
  p->turtle.current.y = TURTLE_STARTING_Y ; 
  
  CU_ASSERT_EQUAL(mock_check_still_on_screen(p), OffRight) ;
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_still_on_screen_flags_left(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }  
  
  p->turtle.current.x = OFF_SCREEN_NEG ; 
  
  p->turtle.current.y = TURTLE_STARTING_Y ; 
  
  CU_ASSERT_EQUAL(mock_check_still_on_screen(p), OffLeft) ;
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_still_on_screen_flags_bottom(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }  
  
  p->turtle.current.x = TURTLE_STARTING_X ; 
  
  p->turtle.current.y = OFF_SCREEN_Y_POS ; 
  
  CU_ASSERT_EQUAL(mock_check_still_on_screen(p), OffBottom);
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_still_on_screen_flags_top(void)
{
  Prog *p = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }  
  
  p->turtle.current.x = TURTLE_STARTING_X ; 
  
  p->turtle.current.y = OFF_SCREEN_NEG ; 
  
  CU_ASSERT_EQUAL(mock_check_still_on_screen(p), OffTop) ;
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ;  

  return ; 
}

void test_mock_check_still_on_screen_passes_okay(void)
{
  Prog *p = NULL ; 
  unsigned int i, j ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }  
  
  for(i = 0 ; i < SDL_WIDTH ; i++){
    p->turtle.current.x = i ; 
  
    for(j = 0 ; j < SDL_HEIGHT ; j++){
      p->turtle.current.y = j ; 
      
      CU_ASSERT_EQUAL(mock_check_still_on_screen(p), \
      Success) ; 
    }
  } 

  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* 
 * Suite 46 Tests - 
 * mock_set_up_and_make_move (turtle_interp.c) 
 */
unsigned int mock_set_up_and_make_move(Prog *p)
{
  double moveValue ; 
  
  moveValue = value_of_var_or_num(p) ; 

  if(p->currentMove == FD){
    calculate_next_position(&(p->turtle), moveValue) ;
    return mock_check_still_on_screen(p) ; 
  }
  else{
    calculate_turn_amount(p, moveValue) ; 
  }

  return Success ; 
}

void test_mock_set_up_and_make_move_left_turn1(void)
{
  Prog *p = NULL ; 
  double turnAmount ;
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE1) ; 
  
  p->currentMove = LT ; 
    
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
  
  turnAmount = (SET_MAKE_TURN_VAL1 * \
  (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
    
  turnAmount *= LEFT_TURN ; 
      
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
    
  free_program_memory(&p) ; 

  return ;  
}

void test_mock_set_up_and_make_move_left_turn2(void)
{
  Prog *p = NULL ; 
  double turnAmount ; 
  FILE *testFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE2) ; 
  
  p->currentMove = LT ; 
      
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
      
  turnAmount = degrees_to_radians(SET_MAKE_TURN_VAL2) ; 
  
  turnAmount *= LEFT_TURN ; 
          
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
    
  free_program_memory(&p) ; 

  return ;  
}

void test_mock_set_up_and_make_move_left_turn3(void)
{
  Prog *p = NULL ; 
  double turnAmount ;  
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE3) ; 
  
  p->currentMove = LT ; 
    
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
  
  turnAmount = degrees_to_radians(SET_MAKE_TURN_VAL3) ;
    
  turnAmount *= LEFT_TURN ; 
      
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
      
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ;  
}

void test_mock_set_up_and_make_move_right_turn1(void)
{
  Prog *p = NULL ; 
  double turnAmount ;
  FILE *testFile = NULL ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE1) ; 
  
  p->currentMove = RT ; 
    
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
  
  turnAmount = (SET_MAKE_TURN_VAL1 * \
  (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
          
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
    
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ;  
}

void test_mock_set_up_and_make_move_right_turn2(void)
{
  Prog *p = NULL ; 
  double turnAmount ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE2) ; 
  
  p->currentMove = RT ; 
    
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
  
  turnAmount = (SET_MAKE_TURN_VAL2 * \
  (M_PI / HALF_DEGREES_IN_CIRCLE)) ;
          
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
    
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ;  
}

void test_mock_set_up_and_make_move_right_turn3(void)
{
  Prog *p = NULL ; 
  double turnAmount ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_MAKE_TURN_FILE3) ; 
  
  p->currentMove = RT ; 
    
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ; 
  
  turnAmount = degrees_to_radians(SET_MAKE_TURN_VAL3) ;
          
  CU_ASSERT_DOUBLE_EQUAL(p->turtle.theta, turnAmount, \
  FLOAT_DIF) ; 
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ;  
}

void test_mock_set_up_and_make_move_fd_off_right(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_FWD_OFF_FILE) ; 
  
  p->currentMove = FD ; 
  
  p->turtle.theta = EST_R ; 
  
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), OffRight) ; 
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
              
  return ;  
}

void test_mock_set_up_and_make_move_fd_off_left(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_FWD_OFF_FILE) ; 
  
  p->currentMove = FD ; 
  
  p->turtle.theta = WST_R ; 
  
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), OffLeft) ; 
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
              
  return ;  
}

void test_mock_set_up_and_make_move_fd_off_bottom(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_FWD_OFF_FILE) ; 
  
  p->currentMove = FD ; 
  
  p->turtle.theta = STH_R ; 
  
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), OffBottom) ;
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
              
  return ;  
}

void test_mock_set_up_and_make_move_fd_off_top(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, SET_FWD_OFF_FILE) ; 
  
  p->currentMove = FD ; 
  
  p->turtle.theta = NTH_R ; 
  
  CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), OffTop) ;
  
  free_program_memory(&p) ;  
  
  CU_ASSERT_PTR_NULL(p) ; 
            
  return ;  
}

void test_mock_set_up_and_make_move_on_screen(void)
{
  unsigned int i ; 
  Prog *p = NULL ; 
  FILE *testFile = NULL ;
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  srand(time(NULL)) ; 
  
  set_up_program(p, testFile, SET_FWD_ON_FILE) ; 
  
  p->currentMove = FD ; 
  
  for(i = 0 ; i < NUM_TEST_DEG_TO_RAD ; i++){
    p->turtle.current.x = TURTLE_STARTING_X ; 
    
    p->turtle.current.y = TURTLE_STARTING_Y ; 
  
    p->turtle.theta = rand() ; 
        
    CU_ASSERT_EQUAL(mock_set_up_and_make_move(p), Success) ;   
  }
  
  free_program_memory(&p) ; 
            
  CU_ASSERT_PTR_NULL(p) ; 

  return ;  
}

/* Suite 47 Tests - polish (turtle_interp.c) */
void test_polish_nums_only1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE1) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_ONLY_CHARS1) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_ONLY_TOP1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_ONLY_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_only2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE2) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_ONLY_CHARS2) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_ONLY_TOP2) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_ONLY_VAL2, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_only3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE3) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_ONLY_CHARS3) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_ONLY_TOP3) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_ONLY_VAL3, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_vars_only1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE1) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_VARS_ONLY1_A, p) ; 

  set_var_value(VAR_NAME_B, POLISH_VARS_ONLY1_B, p) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_VARS_ONLY_CHARS1) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_VARS_ONLY_TOP1) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_VARS_ONLY_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_vars_only2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE2) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_VARS_ONLY2_A, p) ; 

  set_var_value(VAR_NAME_B, POLISH_VARS_ONLY2_B, p) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_VARS_ONLY_CHARS2) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_VARS_ONLY_TOP2) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_VARS_ONLY_VAL2, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_vars_only3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE3) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_C, POLISH_VARS_ONLY3_C, p) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_VARS_ONLY_CHARS3) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_VARS_ONLY_TOP3) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_VARS_ONLY_VAL3, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_and_vars1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE1) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A1, p) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS1) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_VARS_TOP1) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_VARS_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_and_vars2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE2) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A2, p) ; 
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS2) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_VARS_TOP2) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_VARS_VAL2, FLOAT_DIF) ;
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_and_vars3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE3) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A3, p) ;
  
  set_var_value(VAR_NAME_B, POLISH_NUMS_VARS_B3, p) ;  
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS3) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_VARS_TOP3) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top -1].value, \
  POLISH_NUMS_VARS_VAL3, FLOAT_DIF) ;
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_polish_nums_and_vars4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int polishLength ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE4) ; 
  
  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A4, p) ;
  
  set_var_value(VAR_NAME_B, POLISH_NUMS_VARS_B4, p) ;  
    
  polish(p) ;  
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS4) ; 
  
  CU_ASSERT_EQUAL(p->s.top, POLISH_NUMS_VARS_TOP4) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->s.stack[p->s.top - 1].value, \
  POLISH_NUMS_VARS_VAL4, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 48 Tests - 
 * mock_set_up_stack_and_calculate_expression 
 * (turtle_interp.c) 
 */
double mock_set_up_stack_and_calculate_expression(\
Prog *p, unsigned int varPlace)
{
  double check ; 
  unsigned int polishLength ; 

  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 

  polish(p) ; 
      
  check = mock_get_final_value_from_stack(p) ; 
    
  if(fabs(check - StackMore1) < FLOAT_DIF){
    return check ; 
  }
        
  set_var_value(p->program[varPlace], p->temp.value, p) ;
  
  free_stack(&(p->s)) ; 
  
  return check ; 
}

void test_mock_set_up_stack_and_cal_nums_only1(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE1) ; 
    
  varPlace = POLISH_NUMS_ONLY_CHARS1 + 1 ; 
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_NUMS_ONLY_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_ONLY_CHARS1) ; 
      
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_NUMS_ONLY_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_NUMS_ONLY_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_nums_only2(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE2) ; 
  
  varPlace = POLISH_NUMS_ONLY_CHARS2 + 1 ; 
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_NUMS_ONLY_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_ONLY_CHARS2) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_NUMS_ONLY_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_NUMS_ONLY_VAL2, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_nums_only3(void) 
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_ONLY_FILE3) ; 
  
  varPlace = POLISH_NUMS_ONLY_CHARS3 + 1 ; 
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  StackMore1, FLOAT_DIF) ; 
      
  return ; 
}

void test_mock_set_up_stack_and_cal_vars_only1(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE1) ;
  
  set_var_value(VAR_NAME_A, POLISH_VARS_ONLY1_A, p) ; 

  set_var_value(VAR_NAME_B, POLISH_VARS_ONLY1_B, p) ;  
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
  
  varPlace = POLISH_VARS_ONLY_CHARS1 + 1 ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_VARS_ONLY_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_VARS_ONLY_CHARS1) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_VARS_ONLY_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_VARS_ONLY_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_vars_only2(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE2) ; 
  
  set_var_value(VAR_NAME_A, POLISH_VARS_ONLY2_A, p) ; 

  set_var_value(VAR_NAME_B, POLISH_VARS_ONLY2_B, p) ;  
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
  
  varPlace = POLISH_VARS_ONLY_CHARS2 + 1 ; 
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_VARS_ONLY_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_VARS_ONLY_CHARS2) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_VARS_ONLY_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_VARS_ONLY_VAL2, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_vars_only3(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_VARS_ONLY_FILE3) ; 
  
  set_var_value(VAR_NAME_C, POLISH_VARS_ONLY3_C, p) ; 
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
  
  varPlace = POLISH_VARS_ONLY_CHARS3 + 1 ; 
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  StackMore1, FLOAT_DIF) ; 
        
  return ; 
}

void test_mock_set_up_stack_and_cal_num_and_vars1(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE1) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A1, p) ; 
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;  
    
  varPlace = POLISH_NUMS_VARS_CHARS1 + 1 ; 
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_NUMS_VARS_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS1) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_NUMS_VARS_VAL1, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_NUMS_VARS_VAL1, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_num_and_vars2(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE2) ;

  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A2, p) ; 
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;
  
  varPlace = POLISH_NUMS_VARS_CHARS2 + 1 ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_NUMS_VARS_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS2) ; 
    
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_NUMS_VARS_VAL2, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_NUMS_VARS_VAL2, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_set_up_stack_and_cal_num_and_vars3(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE3) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A3, p) ;
  
  set_var_value(VAR_NAME_B, POLISH_NUMS_VARS_B3, p) ;  
  
  set_var_value(SET_UP_AND_CHECK_VAR, 0, p) ;
  
  varPlace = POLISH_NUMS_VARS_CHARS3 + 1 ; 
    
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  POLISH_NUMS_VARS_VAL3, FLOAT_DIF) ; 
    
  CU_ASSERT_EQUAL(p->place, POLISH_NUMS_VARS_CHARS3) ;
  
  CU_ASSERT_DOUBLE_EQUAL(p->temp.value, \
  POLISH_NUMS_VARS_VAL3, FLOAT_DIF) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), \
  POLISH_NUMS_VARS_VAL3, FLOAT_DIF) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ;  
  
  return ; 
}

void test_mock_set_up_stack_and_cal_num_and_vars4(void)  
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int varPlace ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, POLISH_NUMS_VARS_FILE4) ; 
  
  set_var_value(VAR_NAME_A, POLISH_NUMS_VARS_A3, p) ;
  
  set_var_value(VAR_NAME_B, POLISH_NUMS_VARS_B3, p) ;  
    
  varPlace = POLISH_NUMS_VARS_CHARS4 + 1 ; 
  
  CU_ASSERT_DOUBLE_EQUAL(\
  mock_set_up_stack_and_calculate_expression(p, varPlace), \
  StackMore1, FLOAT_DIF) ; 
      
  return ; 
}

/* Suite 49 Tests - mock_set (turtle_interp.c) */
double mock_set(Prog *p) 
{
  unsigned int varPlace ;

  if(mock_check_within_program_bounds(p)){
    return OutOfBounds ; 
  } 
  
  if(!str_same(p->program[p->place], SET_START)){
    return MockNoSetStart ; 
  } 
  
  varPlace = ++(p->place) ; 

  if(!is_var(p->program[(p->place)++])){
    return MockNoSetVar ;
  }

  if(!str_same(p->program[p->place], SET_DEFINE)){
    return MockNoSetDefine ;
  } 
        
  return \
  mock_set_up_stack_and_calculate_expression(p, varPlace) ;
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
        
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), MockNoSetStart, \
  FLOAT_DIF) ; 
  
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

        
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), MockNoSetVar, \
  FLOAT_DIF) ;  

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
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), MockNoSetDefine, \
  FLOAT_DIF) ;  
      
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
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), StackMore1, \
  FLOAT_DIF) ;   

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

  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), StackMore1, \
  FLOAT_DIF) ;
      
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
    
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), SET_COR_VAL_1, \
  FLOAT_DIF) ;  
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), SET_COR_VAL_1, \
  FLOAT_DIF) ;  
  
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
    
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), -45, \
  FLOAT_DIF) ;  
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), SET_COR_VAL_2, \
  FLOAT_DIF) ;  
  
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
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), SET_COR_VAL_3, \
  FLOAT_DIF) ;  
    
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), SET_COR_VAL_3, \
  FLOAT_DIF) ;  
  
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
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), SET_COR_VAL_4, \
  FLOAT_DIF) ;  
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), SET_COR_VAL_4, \
  FLOAT_DIF) ;  
  
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
  
  CU_ASSERT_DOUBLE_EQUAL(mock_set(p), SET_COR_VAL_5, \
  FLOAT_DIF) ;  
  
  CU_ASSERT_DOUBLE_EQUAL(\
  read_var_value(SET_UP_AND_CHECK_VAR, p), SET_COR_VAL_5, \
  FLOAT_DIF) ;  
  
  CU_ASSERT_EQUAL(p->place, SET_COR_PASS_5) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 50 Tests - 
 * mock_check_if_integer (turtle_interp.c) 
 */
unsigned int mock_check_if_integer(double fraction) 
{
  if((fabs(fraction) - FLOAT_DIF) >= 0){
    return MockNotInt ; 
  }

  return MockInt ; 
}

void test_mock_if_integer_False1(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(NT_INT1), \
  MockNotInt) ;

  return ; 
}

void test_mock_if_integer_False2(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(NT_INT2), \
  MockNotInt) ;

  return ; 
}

void test_mock_if_integer_False3(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(NT_INT3), \
  MockNotInt) ;

  return ; 
}

void test_mock_if_integer_False4(void)
{
  CU_ASSERT_EQUAL(mock_check_if_integer(NT_INT4), \
  MockNotInt) ;

  return ; 
}

void test_mock_if_integer_False5(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(NT_INT5), \
  MockNotInt) ;

  return ; 
}

void test_mock_if_integer_True1(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(INT1), MockInt) ;

  return ; 
}

void test_mock_if_integer_True2(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(INT2), MockInt) ;

  return ; 
}

void test_mock_if_integer_True3(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(INT3), MockInt) ;

  return ; 
}

void test_mock_if_integer_True4(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(INT4), MockInt) ;

  return ; 
}

void test_mock_if_integer_True5(void)
{  
  CU_ASSERT_EQUAL(mock_check_if_integer(INT5), MockInt) ;

  return ; 
}

/* 
 * Suite 51 Tests - 
 * mock_check_do_var_and_return_place (turtle_interp.c) 
 */
unsigned int mock_check_do_var_and_return_place(Prog *p)
{
  if(!is_var(p->program[p->place])){
    return MockDoNotVar ; 
  }

  return (p->place)++ ; 
}

void test_mock_check_do_var_and_return_place_incor1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_INCOR1) ;
  
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  MockDoNotVar) ; 
  
  CU_ASSERT_EQUAL(p->place, 0) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_incor2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_INCOR2) ;
  
  p->place = BUFFER1 ; 
  
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  MockDoNotVar) ; 
  
  CU_ASSERT_EQUAL(p->place, BUFFER1) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}


void test_mock_check_do_var_and_return_place_incor3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_INCOR3) ;
  
  p->place = BUFFER2 ; 
  
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  MockDoNotVar) ; 
  
  CU_ASSERT_EQUAL(p->place, BUFFER2) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}


void test_mock_check_do_var_and_return_place_incor4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_INCOR4) ;
  
  p->place = BUFFER2 ; 
  
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  MockDoNotVar) ; 
  
  CU_ASSERT_EQUAL(p->place, BUFFER2) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}


void test_mock_check_do_var_and_return_place_incor5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_INCOR5) ;
  
  p->place = BUFFER4 ; 
  
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  MockDoNotVar) ; 
  
  CU_ASSERT_EQUAL(p->place, BUFFER4) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_cor1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_COR1) ;
    
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), 0); 
  
  CU_ASSERT_EQUAL(p->place, BUFFER1) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_cor2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_COR2) ;
  
  p->place = BUFFER1 ; 
    
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  BUFFER1); 
  
  CU_ASSERT_EQUAL(p->place, BUFFER2) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_cor3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_COR3) ;
  
  p->place = BUFFER2 ; 
    
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  BUFFER2); 
  
  CU_ASSERT_EQUAL(p->place, BUFFER3) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_cor4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_COR4) ;
  
  p->place = BUFFER3 ; 
    
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  BUFFER3); 
  
  CU_ASSERT_EQUAL(p->place, BUFFER4) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_place_cor5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, DO_VAR_RTN_PLACE_COR5) ;
  
  p->place = BUFFER4 ; 
    
  CU_ASSERT_EQUAL(mock_check_do_var_and_return_place(p), \
  BUFFER4); 
  
  CU_ASSERT_EQUAL(p->place, BUFFER5) ; 
  
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 52 Tests - 
 * mock_check_do_var_or_num_valid (turtle_interp.c) 
 */
unsigned int mock_check_do_var_or_num_valid(Prog *p)
{
  unsigned int strType ;
  double fraction, integer ; 
          
  strType = is_var_or_num(p->program[p->place]) ; 
    
  switch(strType){
    case Variable : 
      fraction = modf(read_var_value(p->program[p->place], \
      p), &integer) ;       
      return mock_check_if_integer(fraction) ;  break ; 
    case NonNegInt :
    case NegInt : return MockDoInt ; break ; 
    case NonNegFloat :
    case NegFloat : return MockDoFloat ; break ; 
      break ; 
    default : return False ; 
  }
  
  return False ; 
}

void test_mock_check_do_var_and_return_False1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR1) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), False); 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_False2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR2) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), False); 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_False3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR3) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), False); 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_False4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR4) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), False); 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_False5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR5) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), False); 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_integer1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE1) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_integer2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE2) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_integer3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE3) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_integer4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE4) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_integer5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE5) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_not_integer1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, NOT_INTEGER_FILE1) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoFloat) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_not_integer2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, NOT_INTEGER_FILE2) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoFloat) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_not_integer3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, NOT_INTEGER_FILE3) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoFloat) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_not_integer4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, NOT_INTEGER_FILE4) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoFloat) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_not_integer5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, NOT_INTEGER_FILE5) ;
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockDoFloat) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_int1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT1, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_int2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT2, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_int3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT3, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_not_int1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_NOT_INT1, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockNotInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_not_int2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_NOT_INT2, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockNotInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_do_var_and_return_var_not_int3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_NOT_INT3, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_do_var_or_num_valid(p), \
  MockNotInt) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 53 Tests - 
 * mock_check_and_set_do_var_or_num (turtle_interp.c) 
 */
int mock_check_and_set_do_var_or_num(Prog *p) 
{
  if(is_var_or_num(p->program[(p->place)])){
    check_do_var_or_num_valid(p) ;    
  } 
  else{  
    return MockCheckAndSetFalse ;  
  }
    
  return (int) value_of_var_or_num(p) ; 
}

void test_mock_check_and_set_do_var_or_num_False1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR1) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  MockCheckAndSetFalse) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_False2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR2) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  MockCheckAndSetFalse) ; 
      
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_False3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR3) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  MockCheckAndSetFalse) ; 
      
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_False4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR4) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  MockCheckAndSetFalse) ; 
      
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_False5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARNUM_INCOR5) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  MockCheckAndSetFalse) ; 
      
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_integer1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE1) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  INTEGER_VALUE1) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_integer2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE2) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  INTEGER_VALUE2) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_integer3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE3) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  INTEGER_VALUE3) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_integer4(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE4) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  INTEGER_VALUE4) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_integer5(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, INTEGER_FILE5) ;
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  INTEGER_VALUE5) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_var_int1(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT1, p) ; 
        
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  VAR_INT1) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_var_int2(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT2, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  VAR_INT2) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_check_and_set_do_var_or_num_var_int3(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;
  
  set_var_value(VAR_NAME_A, VAR_INT3, p) ; 
      
  CU_ASSERT_EQUAL(mock_check_and_set_do_var_or_num(p), \
  VAR_INT3) ; 
    
  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

/* 
 * Suite 54 Tests - 
 * mock_check_to_is_larger_than_from (turtle_interp.c) 
 */
int mock_check_to_is_larger_than_from(DoValues current)
{
  if(current.from > current.to){
    return False ; 
  }

  return True ; 
}

void test_mock_check_to_is_larger_than_from_False(void)
{
  DoValues curr ;
  int random ; 
  
  srand(time(NULL)) ; 
  
  curr.from = rand() ; 
  
  random = rand() ; 
  
  if(random < curr.from){
    curr.to = random ; 
  }
  else{
    curr.to = curr.from ; 
    curr.from = random ; 
  }
  
  CU_ASSERT_EQUAL(mock_check_to_is_larger_than_from(curr), \
  False) ; 

  return ; 
}

void test_mock_check_to_is_larger_than_from_True(void)
{
  DoValues curr ;
  int random ; 
  
  srand(time(NULL)) ; 
  
  curr.from = rand() ; 
  
  random = rand() ; 
  
  if(random >= curr.from){
    curr.to = random ; 
  }
  else{
    curr.to = curr.from ; 
    curr.from = random ; 
  }
  
  CU_ASSERT_EQUAL(mock_check_to_is_larger_than_from(curr), \
  True) ; 

  return ; 
}

/* Suite 55 Tests - mock_do_loop (turtle_interp.c) */
void mock_do_loop(Prog *p, DoValues current)
{
  int i ; 
  
  current.startPlace = p->place ; 
  
  for(i = current.from ; i <= current.to ; i++){
    set_var_value(p->program[current.varPlace], i, p) ;
    
    p->place = current.startPlace ;
    
    /*
     * Assume that the function instruction_list() works.
     * instruction_list(p) ;  
     */
  }

  return ; 
}

void test_mock_do_loop(void)
{
  Prog *p = NULL ; 
  FILE *testFile = NULL ; 
  DoValues current ;
  int random ; 
  unsigned int randomPlace ;   
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, testFile, VARIABLE_NAME_A_FILE) ;

  current.varPlace = 0 ; 

  srand(time(NULL)) ; 
  
  p->place = randomPlace = (rand() % RANDOM_PLACE) ; 
  
  current.from = (rand() % RANDOM_PLACE) ; 
  
  random = (rand() % RANDOM_PLACE) ; 
  
  if(random >= current.from){
    current.to = random ; 
  }
  else{
    current.to = current.from ; 
    current.from = random ; 
  }
  
  mock_do_loop(p, current) ;  
  
  CU_ASSERT_EQUAL(p->place, randomPlace) ;
  
  CU_ASSERT_DOUBLE_EQUAL(p->var[0]->value, current.to, \
  FLOAT_DIF) ;  

  free_program_memory(&p) ; 
  
  CU_ASSERT_PTR_NULL(p) ; 
}

/* Suite 56 Tests - mock_do_from_to (turtle_interp.c) */
unsigned int mock_do_from_to(Prog *p)
{
  int check ; 
  DoValues current ; 

  check_within_program_bounds(p) ; 
    
  if(!str_same(p->program[(p->place)++], DO_START)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoStartFail ; 
  } 

  check = mock_check_do_var_and_return_place(p) ;
  
  if(check == MockDoNotVar){
    return MockDoNotVar ; 
  }
  else{
    current.varPlace = check ; 
  }
      
  if(!str_same(p->program[(p->place)++], DO_FROM)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoFromFail ; 
  }
        
  check = mock_check_and_set_do_var_or_num(p) ; 
  
  if(check == MockCheckAndSetFalse){
    return DoVarNum1Fail ; 
  }
  else{
    current.from = check ; 
  }
    
  (p->place)++ ; 
    
  if(!str_same(p->program[(p->place)++], DO_TO)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoToFail ; 
  }
      
  check = mock_check_and_set_do_var_or_num(p) ; 
    
  if(check == MockCheckAndSetFalse){
    return DoVarNum2Fail ; 
  }
  else{
    current.to = check ; 
  }
    
  (p->place)++ ;   
    
  if(mock_check_to_is_larger_than_from(current) == False){
    return DoFromLarger ; 
  }
    
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    /* PARSING ERROR - return Failure in mock for testing.*/
    return DoEndFail ; 
  }
    
  mock_do_loop(p, current) ; 
    
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
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), MockDoNotVar) ;
  
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
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoFromFail) ;
  
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
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
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
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoVarNum2Fail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL7_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_fail8(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR8) ; 
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoFromLarger) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL8_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_fail9(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_INCOR9) ; 
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), DoEndFail) ;
  
  CU_ASSERT_EQUAL(p->place, DO_FAIL9_PLACE) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int index ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR1) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
  
  index = determine_var_index(DO_SET_CHAR1[0]) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->var[index]->value, \
  DO_SET_CHAR1_VAL, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ;
  unsigned int index ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR2) ; 
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
  
  index = determine_var_index(DO_SET_CHAR2[0]) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->var[index]->value, \
  DO_SET_CHAR2_VAL, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int index ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR3) ;
  
  set_var_value(VAR_NAME_A, 0, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
  
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
  
  index = determine_var_index(DO_SET_CHAR3[0]) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->var[index]->value, \
  DO_SET_CHAR3_VAL, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

void test_mock_do_from_to_pass4(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  unsigned int index ;  
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, DO_COR4) ; 
  
  set_var_value(VAR_NAME_A, 0, p) ; 

  set_var_value(VAR_NAME_B, 1, p) ; 
    
  CU_ASSERT_EQUAL(mock_do_from_to(p), Success) ;
    
  CU_ASSERT_EQUAL(p->place, (DO_NUM_STRS - 1)) ;  
    
  CU_ASSERT_EQUAL(p->totalStrs, DO_NUM_STRS) ;  
  
  index = determine_var_index(DO_SET_CHAR4[0]) ; 
  
  CU_ASSERT_DOUBLE_EQUAL(p->var[index]->value, \
  DO_SET_CHAR4_VAL, FLOAT_DIF) ;  
    
  free_program_memory(&p) ;

  CU_ASSERT_PTR_NULL(p) ; 
  
  return ; 
}

/* Suite 57 Tests - mock_instruction (turtle_interp.c) */
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
 * Suite 58 Tests - 
 * mock_instruction_list (turtle_interp.c) 
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
 * Suite 59 Tests - 
 * mock_interpreter_for_program_main (turtle_interp.c) 
 */
unsigned int mock_interpreter_for_program_main(Prog *p) 
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

void test_mock_interpreter_for_program_main_incor1(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR1) ; 
      
  CU_ASSERT_EQUAL(mock_interpreter_for_program_main(p), Failure) ; 
    
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_interpreter_for_program_main_incor2(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR2) ; 
      
  CU_ASSERT_EQUAL(mock_interpreter_for_program_main(p), Failure) ;  
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_interpreter_for_program_main_incor3(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_INCOR3) ; 
      
  CU_ASSERT_EQUAL(mock_interpreter_for_program_main(p), Failure) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_interpreter_for_program_main_empty_fle(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, EMPTY_FILE) ; 
      
  CU_ASSERT_EQUAL(mock_interpreter_for_program_main(p), \
  OutOfBounds) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}

void test_mock_interpreter_for_program_main_pass(void)
{
  Prog *p = NULL ; 
  FILE *tempFile = NULL ; 
  
  p = memory_for_Prog() ; 
  
  if(p == NULL){
    TEST_ERROR(TE_PROG_MEM, ErrProgMem) ; 
  }
  
  set_up_program(p, tempFile, MAIN_COR) ; 
      
  CU_ASSERT_EQUAL(mock_interpreter_for_program_main(p), Success) ; 
  
  free_program_memory(&p) ;
  
  CU_ASSERT_PTR_NULL(p) ; 

  return ; 
}


