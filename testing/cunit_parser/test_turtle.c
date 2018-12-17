/*
 * CUnit registry used for running unit tests on all of the
 * functions in turtle_parser.c and turtle_parser_setup.c
 */
#include "test_turtle.h"


int main(void)
{
  CU_pSuite pSuite = NULL ;

  /* Used to initialise the CUnit test registry. */
  if(CUE_SUCCESS != CU_initialize_registry()){
    return CU_get_error() ;
  }
  
  test_parser_suites(pSuite) ; 
      
  /* Used to run all testing using the basic interface. */ 
  CU_basic_set_mode(CU_BRM_VERBOSE) ;
  CU_basic_run_tests() ;
  printf("\n") ;
  CU_basic_show_failures(CU_get_failure_list()) ;
  printf("\n\n") ;

  /* Run all testing using the automated interface. */ 
  CU_automated_run_tests() ;
  CU_list_tests_to_file() ;
  
  /* Used to run all testing using the console interface. */ 
  CU_console_run_tests() ;

  /* Used to clean up the CUnit registry and return. */ 
  CU_cleanup_registry() ;
  return CU_get_error() ;
}

/* Test Suite initialise function - return 0 for success. */  
int init_suite(void) 
{ 
  return 0 ; 
}

/* Test Suite clean up function - return 0 for success. */
int clean_suite(void) 
{
  return 0 ; 
}

/* Function containing all of the Test Suites. */ 
void test_parser_suites(CU_pSuite pSuite)
{
  str_same_suite(pSuite) ;
  is_op_suite(pSuite) ;  
  a_variable_name_suite(pSuite) ;
  is_var_suite(pSuite) ; 
  is_negative_suite(pSuite) ; 
  more_than_one_decimal_or_neg_suite(pSuite) ; 
  is_num_suite(pSuite) ; 
  is_var_or_num_suite(pSuite) ; 
  is_pointer_null_suite(pSuite) ; 
  memory_for_Prog_suite(pSuite) ; 
  memory_for_string_suite(pSuite) ;
  memory_for_program_suite(pSuite) ; 
  open_file_suite(pSuite) ; 
  close_file_suite(pSuite) ; 
  string_length_too_long_suite(pSuite) ; 
  number_of_strings_in_file_suite(pSuite) ;
  initialise_Prog_suite(pSuite) ;  
  read_in_strings_return_suite(pSuite) ; 
  free_program_memory_suite(pSuite) ; 
  set_up_program_suite(pSuite) ; 
  is_move_suite(pSuite) ; 
  mock_parsing_error_suite(pSuite) ; 
  mock_check_within_program_bounds_suite(pSuite) ; 
  mock_polish_suite(pSuite) ; 
  mock_set_suite(pSuite) ; 
  mock_do_to_from_suite(pSuite) ; 
  mock_instruction_suite(pSuite) ;
  mock_instruction_list_suite(pSuite) ; 
  mock_parser_program_main_suite(pSuite) ;  

  return ; 
}

/* Test Suite 1: #define str_same (turtle_parser.h) */ 
int str_same_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("1 - #define str_same " \
  "(turtle_parser.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "the return value when strings are not the same (ie, " \
  "should be False).", test_str_same_not_equal)) ||
  (NULL == CU_add_test(pSuite, \
  "the return value when strings are the same (ie, should" \
  " be True).", test_str_same_equal))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 2: is_op (turtle_parser.c) */ 
int is_op_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("2 - is_op (turtle_parser.c)", \
  init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "test False returned when operation is too long (ie, " \
  "when length > 1).", test_is_op_incorrect_length)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when operation is incorrect - v1.", \
  test_is_op_incorrect1)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when operation is incorrect - v2.", \
  test_is_op_incorrect2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when operation is incorrect - v3.", \
  test_is_op_incorrect3)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when operation is incorrect - v4.", \
  test_is_op_incorrect4)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when operation is incorrect - v5.", \
  test_is_op_incorrect5)) ||
  (NULL == CU_add_test(pSuite, \
  "test True returned for all possible (ie, defined by " \
  "grammar) operations.", test_is_op_correct))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ;
}

/* Test Suite 3: a_variable_name (turtle_parser.h) */ 
int a_variable_name_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("3 - a_variable_name " \
  " (turtle_parser.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "test zero returned when operation is incorrect - v1.", \
  test_a_variable_name_flags_incorrect_name1)) ||
  (NULL == CU_add_test(pSuite, \
  "test zero returned when operation is incorrect - v2.", \
  test_a_variable_name_flags_incorrect_name2)) ||
  (NULL == CU_add_test(pSuite, \
  "test zero returned when operation is incorrect - v3.", \
  test_a_variable_name_flags_incorrect_name3)) ||
  (NULL == CU_add_test(pSuite, \
  "test zero returned when operation is incorrect - v4.", \
  test_a_variable_name_flags_incorrect_name4)) ||
  (NULL == CU_add_test(pSuite, \
  "test zero returned when operation is incorrect - v5.", \
  test_a_variable_name_flags_incorrect_name5)) ||
  (NULL == CU_add_test(pSuite, \
  "test one returned for all correct (ie, set by grammar" \
  ") names.",test_a_variable_name_return_correct_names))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ;
}

/* Test Suite 4: is_var (turtle_parser.c) */ 
int is_var_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("4 - is_var (turtle_parser.c)", \
  init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test false returned when operation is too long (ie, " \
  "when length > 1).", test_is_var_incorrect_length)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v1.", test_is_var_incorrect_name1)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v2.", test_is_var_incorrect_name2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v3.", test_is_var_incorrect_name3)) || 
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v4.", test_is_var_incorrect_name4)) || 
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v5.", test_is_var_incorrect_name5))||
  (NULL == CU_add_test(pSuite, \
  "test true returned for all possible and correct " \
  "variable names.", test_is_var_correct_name))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 5 - #define is_negative (turtle_parser.h) */
int is_negative_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("5 - is_negative " \
  "(turtle_parser.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v1.", test_is_negative_return_value_false1)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v2.", test_is_negative_return_value_false2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v3.", test_is_negative_return_value_false3)) || 
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v4.", test_is_negative_return_value_false4)) || 
  (NULL == CU_add_test(pSuite, \
  "test False returned when variable name is incorrect " \
  "- v5.", test_is_negative_return_value_false5))||
  (NULL == CU_add_test(pSuite, \
  "test true returned for all possible and correct " \
  "variable names.", test_is_negative_return_value_true))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 6: #define more_than_one_decimal_or_negative
 * (turtle_parser.h)
 */
int more_than_one_decimal_or_neg_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("6 - #define more_than_one_decimal"\
  "_or_negative (turtle_parser.h)", \
  init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test True returned for invalid combination - v1.", \
  test_more_than_one_decimal_or_negative_true1)) ||  
  (NULL == CU_add_test(pSuite, \
  "test True returned for invalid combination - v2.", \
  test_more_than_one_decimal_or_negative_true2)) ||  
  (NULL == CU_add_test(pSuite, \
  "test True returned for invalid combination - v3.", \
  test_more_than_one_decimal_or_negative_true3)) ||  
  (NULL == CU_add_test(pSuite, \
  "test True returned for invalid combination - v4.", \
  test_more_than_one_decimal_or_negative_true4)) ||  
  (NULL == CU_add_test(pSuite, \
  "test True returned for invalid combination - v5.", \
  test_more_than_one_decimal_or_negative_true5)) ||  
  (NULL == CU_add_test(pSuite, \
  "test False returned for valid combination - type 1.", \
  test_more_than_one_decimal_or_negative_false1)) ||  
  (NULL == CU_add_test(pSuite, \
  "test False returned for valid combination - type 2.", \
  test_more_than_one_decimal_or_negative_false2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned for valid combination - type 3.", \
  test_more_than_one_decimal_or_negative_false3)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned for valid combination - type 4.", \
  test_more_than_one_decimal_or_negative_false4))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 7: is_num (turtle_parser.c) */ 
int is_num_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("7 - is_num (turtle_parser.c)", \
  init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number - v1.", \
  test_is_num_incorrect1)) ||  
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number - v2.", \
  test_is_num_incorrect2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number - v3.", \
  test_is_num_incorrect3)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number - v4.", \
  test_is_num_incorrect4)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number - v5.", \
  test_is_num_incorrect5)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned when string is a number an " \
  "integer.", test_is_num_cor_non_negative_integer)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned value when string is a negative " \
  "integer.", test_is_num_cor_negative_integer)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned value when string non-negati" \
  "ve decimal.", test_is_num_cor_non_negative_floating)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned when string is a negative floati"\
  "ng point - v1.", test_is_num_cor_negative_floating1)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned when string is a negative floati"\
  "ng point - v2.", test_is_num_cor_negative_floating2))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 8: is_var_or_num (turtle_parser.c) */ 
int is_var_or_num_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("8 - is_var_or_num "\
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number (1).", \
  test_is_var_or_num_not_number1)) ||  
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number (2).", \
  test_is_var_or_num_not_number2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number (3).", \
  test_is_var_or_num_not_number3)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a number (4).", \
  test_is_var_or_num_not_number4)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when number is negative.", \
  test_is_var_or_num_too_long)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a variable (1).",\
  test_is_var_or_num_not_variable1)) ||  
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a variable (2).",\
  test_is_var_or_num_not_variable2)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a variable (3).",\
  test_is_var_or_num_not_variable3)) ||
  (NULL == CU_add_test(pSuite, \
  "test False returned when string is not a variable (4).",\
  test_is_var_or_num_not_variable4)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned for a non-negative integer.", \
  test_is_var_or_num_cor_non_negative_integer)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned for a negative integer.", \
  test_is_var_or_num_cor_negative_integer)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned for a non-negative floating " \
  "point.", test_is_var_or_num_cor_non_negative_floating))||
  (NULL == CU_add_test(pSuite, \
  "test Number returned for a negative floating point -" \
  " v1.", test_is_var_or_num_cor_negative_floating1)) ||
  (NULL == CU_add_test(pSuite, \
  "test Number returned for a negative floating point -" \
  " v2.", test_is_var_or_num_cor_negative_floating2)) ||
  (NULL == CU_add_test(pSuite, \
  "test Variable returned for all possible variable " \
  "names.", test_is_var_or_num_correct_variables))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 9: pointer_is_null (turtle_parser_setup.c) */ 
int is_pointer_null_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("9 - is_pointer_null " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "for pointers of type: " \
  "void.", test_pointer_is_null_for_void)) || 
  (NULL == CU_add_test(pSuite, "for pointers of type: " \
  "int.", test_pointer_is_null_for_int)) || 
  (NULL == CU_add_test(pSuite, "for pointers of type: " \
  "unsigned int.",test_pointer_is_null_for_unsigned_int)) || 
  (NULL == CU_add_test(pSuite, "for pointers of type: " \
  "char.", test_pointer_is_null_for_char)) || 
  (NULL == CU_add_test(pSuite, "for pointers of type: " \
  "char *.", test_pointer_is_null_for_char_pointer)) || 
  (NULL == CU_add_test(pSuite, "for pointers of type: " \
  "Prog.", test_pointer_is_null_for_Prog))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 10: memory_for_Prog (turtle_parser_setup.c) */ 
int memory_for_Prog_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("10 - memory_for_Prog " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that returned pointer is not null.", \
  test_memory_for_Prog_not_null)) || 
  (NULL == CU_add_test(pSuite, \
  "returned pointer has correct size.", \
  test_memory_for_Prog_size))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 11: memory_for_string (turtle_parser_setup.c)
 */ 
int memory_for_string_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("11 - memory_for_string " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that returned pointer is not null.", \
  test_memory_for_string_not_null)) || 
  (NULL == CU_add_test(pSuite, \
  "returned pointer has correct size.", \
  test_memory_for_string_size)) || 
  (NULL == CU_add_test(pSuite, \
  "that calloc worked correctly.", \
  test_memory_for_string_calloc_worked)) || 
  (NULL == CU_add_test(pSuite, \
  "that pointer of correct type (can store string).", \
  test_memory_for_string_can_store_string))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 12: 
 * memory_for_program (turtle_parser_setup.c) 
 */ 
int memory_for_program_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("12 - memory_for_program " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that returned pointer is not null.", \
  test_memory_for_program_not_null)) || 
  (NULL == CU_add_test(pSuite, \
  "returned pointer has correct size.", \
  test_memory_for_program_size)) || 
  (NULL == CU_add_test(pSuite, \
  "that calloc worked correctly.", \
  test_memory_for_program_calloc_worked)) || 
  (NULL == CU_add_test(pSuite, \
  "that variable can store correct amount of strings).", \
  test_memory_for_program_strings_stored))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 13: open_file (turtle_parser_setup.c) */ 
int open_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("13 - open_file " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function flags when null pointer returned.", \
  test_open_file_null_flagged_and_returned)) ||
  (NULL == CU_add_test(pSuite, \
  "that function returns correct value when file " \
  "successfully opened.", test_open_file_return_value)) ||
  (NULL == CU_add_test(pSuite, \
  "that function returns a non-null pointer when file " \
  "successfully opened.", \
  test_open_file_pointer_not_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that file is readable and behaves appropriately.", \
  test_open_file_file_readable)) ||
  (NULL == CU_add_test(pSuite, \
  "that file is not writable.", \
  test_open_file_file_not_writable))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 14: close_file (turtle_parser_setup.c) */ 
int close_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("14 - close_file " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function returns correct value when file " \
  "successfully closed.", test_close_file_return_value)) ||
  (NULL == CU_add_test(pSuite, "that file is actually " \
  "closed (when function doesn't that it isn't).", \
  test_close_file_file_shut_and_null_ptr))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Suite 15 Tests - 
 * string_length_too_long (turtle_parser_setup.c) 
 */
 int string_length_too_long_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("15 - string_length_too_long" \
  " (turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function returns False when string within bounds.",\
  test_string_length_too_long_not_too_long)) ||
  (NULL == CU_add_test(pSuite, \
  "that function returns True when string out of bounds.",\
  test_string_length_too_long_too_long))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 16: number_strings_in_file 
 * (turtle_parser_setup.c) 
 */
int number_of_strings_in_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("16 - number_of_strings_in_file " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function returns zero for an empty file.", \
  test_number_strings_in_file_empty)) ||
  (NULL == CU_add_test(pSuite, \
  "correct amount returned for for non-empty file.", \
  test_number_strings_in_file_test_file))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 17: initialise_Prog (turtle_parser_setup.c) */
int initialise_Prog_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("17 - initialise_Prog" \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function does not "\
  "return null char ** pointerand p->totalStrs is " \
  "not changed.", test_initialise_Prog_program)) ||
  (NULL == CU_add_test(pSuite, "that function sets p->" \
  "place to correct starting value and p->totalStrs is " \
  "not changed.", test_initialise_Prog_place_value))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 18: read_in_strings (turtle_parser_setup.c) */
int read_in_strings_return_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("18 - read_in_strings " \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function returns zero for an empty file.", \
  test_read_in_strings_return_value_empty)) ||
  (NULL == CU_add_test(pSuite, \
  "correct amount returned for for non-empty file.", \
  test_read_in_strings_return_value_not_empty)) ||
  (NULL == CU_add_test(pSuite, \
  "that function read in strings correctly.", \
  test_read_in_strings_strings_correct))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 19: 
 * free_program_memory (turtle_parser_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
int free_program_memory_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("19 - free_program_memory" \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function correctly"\
  "free any allocated memory in Prog ptr and sets all ptrs"\
  "to null.", test_free_program_memory_Prog_ptr_null))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 20: set_up_program (turtle_parser_setup.c) */
int set_up_program_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("20 - set_up_program" \
  "(turtle_parser_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function does not return null Prog * pointer.", \
  test_set_up_program_program_Prog_ptr_not_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that function does not return null char ** pointer.", \
  test_set_up_program_program_program_ptr_not_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that function determines the num. of strings in file.", \
  test_set_up_program_program_totalStrs_correct)) ||
  (NULL == CU_add_test(pSuite, \
  "that function does not return null char * pointers.", \
  test_set_up_program_program_ptrs_not_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly copies in strings from file.", \
  test_set_up_program_program_strs_correct)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly set place in file (0).", \
  test_set_up_program_place_correct)) ||
  (NULL == CU_add_test(pSuite, "that the function shuts " \
  "the file and the file pointer to null.", \
  test_set_up_program_file_shut))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 21: is_move (turtle_parser.c) */
int is_move_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("21 - is_move (turtle_parser.c)", \
  init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that returns correct " \
  "values when not a valid move v1", test_is_move_fail1)) ||
  (NULL == CU_add_test(pSuite, "that returns correct " \
  "values when not a valid move v2", test_is_move_fail2)) ||
  (NULL == CU_add_test(pSuite, "that returns correct " \
  "values when not a valid move v3", test_is_move_fail3)) ||
  (NULL == CU_add_test(pSuite, "that returns True for the" \
  "valid move of FD.", test_is_move_pass1)) ||
  (NULL == CU_add_test(pSuite, "that returns True for the" \
  "valid move of LT.", test_is_move_pass2)) ||
  (NULL == CU_add_test(pSuite, "that returns True for the" \
  "valid move of RT.", test_is_move_pass3))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 22: 
 * #define MOCK_PASSING_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
int mock_parsing_error_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("22 - #define MOCK_PASSING_ERROR " \
  "(turtle_errors.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly exits is parsing error and " \
  "leaves no alloced memory", test_mock_parsing_error))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 23:
 * mock_check_within_program_bounds (turtle_parser.c) 
 */
int mock_check_within_program_bounds_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("23 - mock_check_within_bounds" \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function flags in place counter = number strings.",\
  test_mock_check_within_program_bounds_fail1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags in place counter > number strings.",\
  test_mock_check_within_program_bounds_fail2)) ||
  (NULL == CU_add_test(pSuite, \
  "that return value when place counter < number strings.",\
  test_mock_check_within_program_bounds_pass))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 24: mock_polish (turtle_parser.c) */
int mock_polish_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("24 - mock_polish" \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function gives parsing error when no terminating " \
  "char (ie, ';').", test_mock_polish_no_end_character)) ||
  (NULL == CU_add_test(pSuite, \
  "test that sequence of strings not matching grammar is " \
  "flagged by mock (1).", test_mock_polish_incor1)) ||
  (NULL == CU_add_test(pSuite, \
  "test that sequence of strings not matching grammar is " \
  "flagged by mock (2).", test_mock_polish_incor2)) || 
  (NULL == CU_add_test(pSuite, \
  "test that sequence of strings not matching grammar is " \
  "flagged by mock (3).", test_mock_polish_incor3)) ||
  (NULL == CU_add_test(pSuite, \
  "test that sequence of strings not matching grammar is " \
  "flagged by mock (4).", test_mock_polish_incor4)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock function for" \
  " correct grammar (1).", test_mock_polish_cor1)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock function for" \
  " correct grammar (2).", test_mock_polish_cor2)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock function for" \
  " correct grammar (3).", test_mock_polish_cor3)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock function for" \
  " correct grammar (4).", test_mock_polish_cor4)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock function for" \
  " correct grammar (5).", test_mock_polish_cor5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 25: mock_set (turtle_parser.c) */
int mock_set_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("25 - mock_set" \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "that function gives parsing error when no starting " \
  "character (ie, \"SET\").", test_mock_set_incor1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function gives parsing error when no variable " \
  "character (ie, var in [A-Z]).", test_mock_set_incor2)) || 
  (NULL == CU_add_test(pSuite, \
  "that function gives parsing error when no defining " \
  "character (ie, \":=\").", test_mock_set_incor3)) ||
  (NULL == CU_add_test(pSuite, \
  "that function gives parsing error when no polish " \
  "terminating char (ie, \";\").", test_mock_set_incor4)) ||
  (NULL == CU_add_test(pSuite, \
  "that function gives parsing error when the polish " \
  "grammar incorrect.", test_mock_set_incor5)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock_set function "\
  "for correct grammar (1).", test_mock_set_cor1)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock_set function "\
  "for correct grammar (2).", test_mock_set_cor2)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock_set function "\
  "for correct grammar (3).", test_mock_set_cor3)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock_set function "\
  "for correct grammar (4).", test_mock_set_cor4)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and exit of mock_set function "\
  "for correct grammar (5).", test_mock_set_cor5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 26: mock_do_to_from (turtle_parser.c) */
int mock_do_to_from_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("26 - mock_do_to_from " \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (1) for DO", test_mock_do_from_to_fail1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (2) for DO", test_mock_do_from_to_fail2)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (3) for DO", test_mock_do_from_to_fail3)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (4) for DO", test_mock_do_from_to_fail4)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (5) for DO", test_mock_do_from_to_fail5)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (6) for DO", test_mock_do_from_to_fail6)) |
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (7) for DO", test_mock_do_from_to_fail7)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (1)", \
  test_mock_do_from_to_pass1)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (2)", \
  test_mock_do_from_to_pass2)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (3)", \
  test_mock_do_from_to_pass3)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (3)", \
  test_mock_do_from_to_pass4))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 27: mock_instruction (turtle_parser.c) */
int mock_instruction_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("27 - mock_instruction " \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly flags when no valid " \
  "instruction is input 1", test_mock_instruction_fail1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags when no valid " \
  "instruction is input 2", test_mock_instruction_fail2)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags when no valid " \
  "instruction is input 3", test_mock_instruction_fail3)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid instruction (FD)", \
  test_mock_instruction_pass_fd)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid instruction (LT)", \
  test_mock_instruction_pass_lt)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid instruction (RT)", \
  test_mock_instruction_pass_rt)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid instruction (DO)", \
  test_mock_instruction_pass_do)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid instruction (SET)", \
  test_mock_instruction_pass_set))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 28:
 * mock_instruction_list (turtle_parser.c) 
 */
int mock_instruction_list_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("28 - mock_instruction_list " \
  "(turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (1)", test_mock_instruction_list_fail1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (2)", test_mock_instruction_list_fail2)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings (3)", test_mock_instruction_list_fail3)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags an empty file", \
  test_mock_instruction_list_empty)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (1)", \
  test_mock_instruction_list_pass1)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (2)", \
  test_mock_instruction_list_pass2)) ||
  (NULL == CU_add_test(pSuite, \
  "that behaves correctly for valid set of strings (3)", \
  test_mock_instruction_list_pass3))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 29: mock_parser_program_main - 
 * (turtle_parser.c).
 */
int mock_parser_program_main_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("29 - mock_parser_program_" \
  "main (turtle_parser.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function flags incorrect start symbol (ie, \"{\")" \
  " (1).", test_mock_parser_program_main_incor1)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags incorrect start symbol (ie, \"{\")" \
  " (2).", test_mock_parser_program_main_incor2)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags incorrect start symbol (ie, \"{\")" \
  " (3).", test_mock_parser_program_main_incor3)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags when the input file is empty.", \
  test_mock_parser_program_main_incor_empty_file)) ||
  (NULL == CU_add_test(pSuite, "that function continues " \
  "correctly when start symbol (ie, \"{\") is first str.", \
  test_mock_parser_program_main_pass))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

