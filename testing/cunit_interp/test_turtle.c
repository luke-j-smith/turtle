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
  
  /* Run all of the Test Suite - one for each function. */
  test_interpreter_suites(pSuite) ; 
      
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
void test_interpreter_suites(CU_pSuite pSuite)
{
  str_same_suite(pSuite) ;
  is_op_suite(pSuite) ;  
  a_variable_name_suite(pSuite) ;
  is_var_suite(pSuite) ; 
  is_negative_suite(pSuite) ; 
  more_than_one_decimal_or_neg_suite(pSuite) ; 
  determine_type_two_inputs_suite(pSuite) ; 
  type_of_number_suite(pSuite) ; 
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
  initialise_turtle_position_suite(pSuite) ; 
  initialise_Prog_suite(pSuite) ;  
  read_in_strings_return_suite(pSuite) ; 
  initialise_stack_suite(pSuite) ; 
  free_stack_suite(pSuite) ; 
  free_program_memory_suite(pSuite) ; 
  set_up_program_suite(pSuite) ; 
  within_expression_and_file_suite(pSuite) ; 
  estimate_polish_length_suite(pSuite) ;  
  is_move_suite(pSuite) ; 
  MOCK_INTERP_ERROR_suite(pSuite) ; 
  mock_check_within_program_bounds_suite(pSuite) ; 
  mock_push_suite(pSuite) ; 
  mock_pop_suite(pSuite) ; 
  mock_get_final_value_from_stack_suite(pSuite) ; 
  mock_read_number_value_suite(pSuite) ; 
  determine_var_index_suite(pSuite) ; 
  mock_set_var_value_suite(pSuite) ; 
  mock_read_var_value_suite(pSuite) ; 
  mock_value_of_var_or_num_suite(pSuite) ; 
  mock_check_if_division_by_zero_Suite(pSuite) ; 
  mock_calculation_suite(pSuite) ; 
  update_stack_suite(pSuite) ;
  degrees_to_radians_suite(pSuite) ; 
  mock_calculate_turn_amount_suite(pSuite) ; 
  calculate_next_position_suite(pSuite) ; 
  mock_still_on_screen_suite(pSuite) ; 
  mock_set_up_and_make_move_suite(pSuite) ; 
  polish_suite(pSuite) ; 
  mock_set_up_stack_and_calc_suite(pSuite) ; 
  mock_set_suite(pSuite) ;
  mock_check_if_integer_suite(pSuite) ; 
  mock_check_do_var_and_rtn_place_suite(pSuite) ; 
  mock_check_do_var_or_num_valid_suite(pSuite) ; 
  mock_check_and_set_do_var_or_nm_suite(pSuite) ;
  mock_check_to_is_larger_thn_frm_suite(pSuite) ; 
  mock_do_loop_suite(pSuite) ;  
  mock_do_to_from_suite(pSuite) ; 
  mock_instruction_suite(pSuite) ; 
  mock_instruction_list_suite(pSuite) ; 
  mock_interpreter_for_program_main_suite(pSuite) ;

  return ; 
}

/* Test Suite 1: #define str_same (turtle_interp.h) */ 
int str_same_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("1 - #define str_same " \
  "(turtle_interp.h)", init_suite, clean_suite) ;
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

/* Test Suite 2: is_op (turtle_interp.c) */ 
int is_op_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("2 - is_op (turtle_interp.c)", \
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

/* Test Suite 3: a_variable_name (turtle_interp.h) */ 
int a_variable_name_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("3 - a_variable_name " \
  " (turtle_interp.h)", init_suite, clean_suite) ;
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

/* Test Suite 4: is_var (turtle_interp.c) */ 
int is_var_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("4 - is_var (turtle_interp.c)", \
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

/* 
 * Test Suite 5 - 
 * #define is_negative (turtle_interp.h) 
 */
int is_negative_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("5 - is_negative " \
  "(turtle_interp.h)", init_suite, clean_suite) ;
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
 * (turtle_interp.h)
 */
int more_than_one_decimal_or_neg_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("6 - #define more_than_one_decimal"\
  "_or_negative (turtle_interp.h)", \
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

/* 
 * Test Suite 7: 
 * #define determine_type_two_inputs (turtle_interp.h) 
 */
int determine_type_two_inputs_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("7 - #define determine_type_two_" \
  "inputs (turtle_interp.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "the that zero is returned when both input are zero.", \
  test_determine_type_two_inputs_test_zero)) ||
  (NULL == CU_add_test(pSuite, \
  "the return value for a range of inputs - negative to " \
  "positive.", test_determine_type_two_inputs_test_range))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 8: type_of_number (turtle_interp.c) */ 
int type_of_number_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("8 - type_of_number "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, \
  "test False returned input does not relate to a valid " \
  "combination - v1.", test_type_of_number_return_false1))||  
  (NULL == CU_add_test(pSuite, \
  "test False returned input does not relate to a valid " \
  "combination - v2.", test_type_of_number_return_false2))||
  (NULL == CU_add_test(pSuite, \
  "test False returned input does not relate to a valid " \
  "combination - v3.", test_type_of_number_return_false3))||
  (NULL == CU_add_test(pSuite, \
  "test False returned input does not relate to a valid " \
  "combination - v4.", test_type_of_number_return_false4))||
  (NULL == CU_add_test(pSuite, \
  "test False returned input does not relate to a valid " \
  "combination - v5.", test_type_of_number_return_false5))||
  (NULL == CU_add_test(pSuite, \
  "test NonNegInt returned when string is a non-negative "\
  "integer.", test_type_of_number_return_NonNegInt)) ||
  (NULL == CU_add_test(pSuite, \
  "test NegInt returned value when string is a negative " \
  "integer.", test_type_of_number_return_NegInt)) ||
  (NULL == CU_add_test(pSuite, \
  "test NonNegFloat returned value when string non-negati" \
  "ve decimal.", test_type_of_number_return_NonNegFloat)) ||
  (NULL == CU_add_test(pSuite, \
  "test NegFloat returned when string is a negative floati"\
  "ng point.", test_type_of_number_return_NegFloat))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 9: is_num (turtle_interp.c) */ 
int is_num_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("9 - is_num (turtle_interp.c)", \
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

/* Test Suite 10: is_var_or_num (turtle_interp.c) */ 
int is_var_or_num_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("10 - is_var_or_num "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
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

/* Test Suite 11: pointer_is_null (turtle_interp_setup.c) */ 
int is_pointer_null_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("11 - is_pointer_null " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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


/* Test Suite 12: memory_for_Prog (turtle_interp_setup.c) */ 
int memory_for_Prog_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("12 - memory_for_Prog " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* Test Suite 13: memory_for_string (turtle_interp_setup.c) */ 
int memory_for_string_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("13 - memory_for_string " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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
 * Test Suite 14: 
 * memory_for_program (turtle_interp_setup.c) 
 */ 
int memory_for_program_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("14 - memory_for_program " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* Test Suite 15: open_file (turtle_interp_setup.c) */ 
int open_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("15 - open_file " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* Test Suite 16: close_file (turtle_interp_setup.c) */ 
int close_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("16 - close_file " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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
 * Suite 17 Tests: 
 * string_length_too_long (turtle_interp_setup.c) 
 */
 int string_length_too_long_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("17 - string_length_too_long" \
  " (turtle_interp_setup.c)", init_suite, clean_suite) ;
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
 * Test Suite 18: number_strings_in_file 
 * (turtle_interp_setup.c) 
 */
int number_of_strings_in_file_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("18 - number_of_strings_in_file " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* 
 * Test Suite 19:
 * initialise_turtle_position (turtle_interp_setup.c)  
 */
int initialise_turtle_position_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("19 - initialise_turtle_position" \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.x.", \
  test_initialise_turtle_position_current_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.y.", \
  test_initialise_turtle_position_current_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_initialise_turtle_position_previous_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_initialise_turtle_position_previous_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.theta.", \
  test_initialise_turtle_position_theta))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 20: initialise_Prog (turtle_interp_setup.c) */
int initialise_Prog_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("20 - initialise_Prog" \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function does not "\
  "return null char ** pointerand p->totalStrs is " \
  "not changed.", test_initialise_Prog_program)) ||
  (NULL == CU_add_test(pSuite, "that function sets p->" \
  "place to correct starting value and p->totalStrs is " \
  "not changed.", test_initialise_Prog_place_value)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets the initial temporary value (for " \
  "calcs) to 0.", test_initialise_Prog_temp_value)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets all initial var pointers to null.", \
  test_initialise_Prog_var_set_to_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets currentMove to NO_MOVE (-1).", \
  test_initialise_Prog_currentMove)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.x.", \
  test_initialise_Prog_turtle_position_current_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.y.", \
  test_initialise_Prog_turtle_position_current_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_initialise_Prog_turtle_position_previous_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_initialise_Prog_turtle_position_previous_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.theta.", \
  test_initialise_Prog_turtle_position_theta))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 21: read_in_strings (turtle_interp_setup.c) */
int read_in_strings_return_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("21 - read_in_strings " \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* Test Suite 22: initialise_stack (turtle_interp_setup.c) */
int initialise_stack_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("22 - initialise_stack "\
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function returns a stack pointer that is not " \
  "null.", test_initialise_stack_ptr_not_null)) ||
  (NULL == CU_add_test(pSuite, "that function returns a " \
  "stack pointer that is the correct and expected size", \
  test_initialise_stack_ptr_correct_size)) ||
  (NULL == CU_add_test(pSuite, "that function sets the " \
  "stack stack size (ie, s.size) to correct starting " \
  "value.", test_initialise_stack_correct_stack_size)) ||
  (NULL == CU_add_test(pSuite, \
  "that function returns a stack top value of zero.", \
  test_initialise_stack_top_value))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 23: free_stack (turtle_interp_setup.c) */
int free_stack_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("23 - free_stack "\
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function frees the memory allocated for the stack" \
  " and returns NULL pointer.",test_free_stack_all_freed))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 24: 
 * free_program_memory (turtle_interp_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
int free_program_memory_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("24 - free_program_memory" \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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

/* Test Suite 25: set_up_program (turtle_interp_setup.c) */
int set_up_program_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("25 - set_up_program" \
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
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
  (NULL == CU_add_test(pSuite, \
  "that function sets the initial temporary value (for " \
  "calcs) to 0.", test_set_up_program_temp_value)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets all initial var pointers to null.", \
  test_set_up_program_var_set_to_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets currentMove to NO_MOVE (-1).", \
  test_set_up_program_currentMove)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.x.", \
  test_set_up_program_turtle_position_current_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.current.y.", \
  test_set_up_program_turtle_position_current_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_set_up_program_turtle_position_previous_x)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.previous.y.", \
  test_set_up_program_turtle_position_previous_y)) ||
  (NULL == CU_add_test(pSuite, "that the function sets" \
  " the correct value for TurtlePos turtle.theta.", \
  test_set_up_program_turtle_position_theta)) ||
  (NULL == CU_add_test(pSuite, "that the function shuts " \
  "the file and the file pointer to null.", \
  test_set_up_program_file_shut))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 26: 
 * within_expression_and_file (turtle_interp_setup.c) 
 */ 
int within_expression_and_file_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("26 - within_expression_" \
  "and_file (turtle_interp_setup.c)", init_suite, clean_suite);
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that False is returned" \
  "when place in file is beyond the total file length.", \
  test_within_expression_and_file_false_place)) ||
  (NULL == CU_add_test(pSuite, "that False is returned" \
  "when current character is terminating char (\";\").", \
  test_within_expression_and_file_false_term_char)) ||
  (NULL == CU_add_test(pSuite, "that True returned when " \
  "within file length and current character is not " \
  "\";\" char.", test_within_expression_and_file_true))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 27: 
 * estimate_polish_length (turtle_interp_setup.c) 
 */ 
int estimate_polish_length_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("27 - estimate_polish_length " \
  "(turtle_interp_setup.c)", init_suite, clean_suite);
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an empty file.", \
  test_estimate_polish_length_empty)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an polish expression" \
  " - v1.", test_estimate_polish_length1)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an polish expression" \
  " - v2.", test_estimate_polish_length2)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an polish expression" \
  " - v3.", test_estimate_polish_length3)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an polish expression" \
  " - v4.", test_estimate_polish_length4)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "the correct expression length for an polish expression" \
  " - v5.", test_estimate_polish_length5)) ){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 28: is_move (turtle_interp.c) */
int is_move_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("28 - is_move (turtle_interp.c)", \
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
 * Test Suite 29: 
 * #define MOCK_INTERP_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
int MOCK_INTERP_ERROR_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("29 - #define MOCK_INTERP_ERROR " \
  "(turtle_errors.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly exits is parsing error and " \
  "leaves no alloced memory", test_MOCK_INTERP_ERROR))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 30:
 * mock_check_within_program_bounds (turtle_interp.c) 
 */
int mock_check_within_program_bounds_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("30 - mock_check_within_bounds" \
  "(turtle_interp.c)", init_suite, clean_suite) ;
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

/* Test Suite 31: mock_push (turtle_interp_setup.c) */
int mock_push_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("31 - mock_push "\
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function flags " \
  "when pushing onto a full stack.", \
  test_mock_push_full_flag)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "updates stack top value.", test_mock_push_top_value)) ||
  (NULL == CU_add_test(pSuite, "that function correctly "\
  "stores/pushes the inputed value.", \
  test_mock_push_value_stored))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 32: mock_pop (turtle_interp.c) */
int mock_pop_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("32 - mock_pop "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function flags " \
  "when popping off an empty stack.", \
  test_mock_pop_flag_empty)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "updates stack top value.", test_mock_pop_top_value)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "pops/loads the correct stack value.", \
  test_mock_pop_popped_value))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 33: 
 * mock_get_final_value_from_stack (turtle_interp.c) 
 */
int mock_get_final_value_from_stack_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("33 - mock_get_final_value_from_" \
  "stack (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function flags " \
  "when stack has more than one element in it.", \
  mock_get_final_value_from_stack_more_than_one)) ||
  (NULL == CU_add_test(pSuite, "that function flags " \
  "when stack has less than one element in it.", \
  mock_get_final_value_from_stack_less_than_one)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "pops/loads the correct stack value when one element.", \
  mock_get_final_value_from_stack_correct_value))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Suite 34 Tests:
 * mock_read_number_value (turtle_interp.c) 
 */
int mock_read_number_value_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("34 - mock_read_number_value " \
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a number and str unchanged - v1.", \
  test_mock_read_number_value_incor_num_flagged1)) ||  
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a number and str unchanged - v2.", \
  test_mock_read_number_value_incor_num_flagged2)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a number and str unchanged - v3.", \
  test_mock_read_number_value_incor_num_flagged3)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a number and str unchanged - v4.", \
  test_mock_read_number_value_incor_num_flagged4)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a number and str unchanged - v5.", \
  test_mock_read_number_value_incor_num_flagged5)) ||
  (NULL == CU_add_test(pSuite, "test correct value " \
  "returned when string is a non-neg. integer and str is " \
  "unchanged.", test_mock_read_number_value_correct_num1))||
  (NULL == CU_add_test(pSuite, "test correct value " \
  "returned when string is a negative integer and str is " \
  "unchanged.", test_mock_read_number_value_correct_num2))||
  (NULL == CU_add_test(pSuite, "test correct value " \
  "returned when string non-neg. float and str is " \
  "unchanged.", test_mock_read_number_value_correct_num3))||
  (NULL == CU_add_test(pSuite, "test correct value " \
  "returned when string is a neg. float and str is same " \
  " - v1.", test_mock_read_number_value_correct_num4)) ||
  (NULL == CU_add_test(pSuite, "test correct value " \
  "returned when string is a neg. float and str is same " \
  " - v2.", test_mock_read_number_value_correct_num5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Suite 35 Tests:
 * #define determine_var_index (turtle_interp.h) 
 */
 int determine_var_index_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("35 - #define determine_var_index" \
  " (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that returns correct " \
  "index for each possible variable name.", \
  test_determine_var_index_correct_value))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Suite 36 Tests: mock_read_var_value (turtle_interp.c) */
int mock_set_var_value_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("36 - mock_set_var_value "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function flags when variable name is too long.", \
  test_mock_set_var_value_fail_name_length)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags when variable name is incorrect.", \
  test_mock_set_var_value_fail_name_wrong)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets correct value when not set before.", \
  test_mock_set_var_value_correct_not_defined)) ||
  (NULL == CU_add_test(pSuite, \
  "that function sets correct value when set before.", \
  test_mock_set_var_value_correct_when_defined))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Suite 37 Tests: mock_read_var_value (turtle_interp.c) */
int mock_read_var_value_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("37 - mock_read_var_value "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function flags when variable name is too long.", \
  test_mock_read_var_value_fail_name_length)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags when variable name is incorrect.", \
  test_mock_read_var_value_fail_name_wrong)) ||
  (NULL == CU_add_test(pSuite, \
  "that function flags when variable has not been set.", \
  test_mock_read_var_value_fail_null)) ||
  (NULL == CU_add_test(pSuite, \
  "that returns correct value for each variable.", \
  test_mock_read_var_correct_var_values))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Suite 38 Tests:
 * mock_value_of_var_or_num (turtle_interp.c) 
 */
int mock_value_of_var_or_num_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("38 - mock_value_of_var_or_num "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a variable or number - v1.", \
  test_mock_value_of_var_or_num_fail1)) ||  
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a variable or number - v2.", \
  test_mock_value_of_var_or_num_fail2)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a variable or number - v3.", \
  test_mock_value_of_var_or_num_fail3)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a variable or number - v4.", \
  test_mock_value_of_var_or_num_fail4)) ||
  (NULL == CU_add_test(pSuite, "test False returned " \
  "when string is not a variable or number - v5.", \
  test_mock_value_of_var_or_num_fail5)) ||
  (NULL == CU_add_test(pSuite, "test correct value is " \
  "returned for predefined variable, for each possible " \
  "name.", test_mock_value_of_var_or_num_vars_cor)) ||  
  (NULL == CU_add_test(pSuite, "test correct returned " \
  "when string is a valid number - v1.", \
  test_mock_value_of_var_or_num_num_cor1)) ||  
  (NULL == CU_add_test(pSuite, "test correct returned " \
  "when string is a valid number - v2.", \
  test_mock_value_of_var_or_num_num_cor2)) || 
  (NULL == CU_add_test(pSuite, "test correct returned " \
  "when string is a valid number - v3.", \
  test_mock_value_of_var_or_num_num_cor3)) || 
  (NULL == CU_add_test(pSuite, "test correct returned " \
  "when string is a valid number - v4.", \
  test_mock_value_of_var_or_num_num_cor4)) || 
  (NULL == CU_add_test(pSuite, "test correct returned " \
  "when string is a valid number - v5.", \
  test_mock_value_of_var_or_num_num_cor5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 39:
 * mock_check_if_division_by_zero (turtle_interp.c) 
 */
int mock_check_if_division_by_zero_Suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("39 - mock_check_if_division_by_" \
  "zero (turtle_interp.h)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function returns " \
  "True when zero is input.", \
  test_mock_check_if_division_by_zero_true)) ||
  (NULL == CU_add_test(pSuite, "that function returns " \
  "True when zero is input.", \
  test_mock_check_if_division_by_zero_false))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
} 

/* Test Suite 40: mock_calculation (turtle_interp.c) */
int mock_calculation_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("40 - mock_calculation "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function flags when string passed to function is " \
  "not an operation.",test_mock_calculation_no_operation))||
  (NULL == CU_add_test(pSuite, \
  "that function flags when trying to divide by zero.", \
  test_mock_calculation_divide_by_zero_flag)) ||
  (NULL == CU_add_test(pSuite, \
  "that function return correct value for addition.", \
  test_mock_calculation_addition_correct)) ||
  (NULL == CU_add_test(pSuite, \
  "that function return correct value for subtraction.", \
  test_mock_calculation_subtraction_correct)) ||
  (NULL == CU_add_test(pSuite, \
  "that function return correct value for multiplication.",\
  test_mock_calculation_multiplication_correct)) ||
  (NULL == CU_add_test(pSuite, \
  "that function return correct value for division.", \
  test_mock_calculation_division_correct))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 41: update_stack (turtle_interp.c) */
int update_stack_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("41 - update_stack "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " performs calculation and pushes result onto the stack" \
  " - addition.", test_update_stack_calc_addition)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly"\
  " performs calculation and pushes result onto the stack" \
  " - subtraction.", test_update_stack_calc_subtraction)) || 
  (NULL == CU_add_test(pSuite, "test function correctly "\
  "performs calculation and pushes result onto the stack -"\
  " mult.", test_update_stack_calc_multiplication)) || 
  (NULL == CU_add_test(pSuite, "test function correctly"\
  " performs calculation and pushes result onto the stack" \
  " - division.", test_update_stack_calc_division)) || 
  (NULL == CU_add_test(pSuite, "test function correctly  " \
  "pushes a valid number onto the stack - v1.", \
  test_update_stack_push_only1)) ||
  (NULL == CU_add_test(pSuite, "test function correctly  " \
  "pushes a valid number onto the stack - v2.", \
  test_update_stack_push_only2)) ||
  (NULL == CU_add_test(pSuite, "test function correctly  " \
  "pushes a valid number onto the stack - v3.", \
  test_update_stack_push_only3)) ||
  (NULL == CU_add_test(pSuite, "test function correctly  " \
  "pushes a valid number onto the stack - v4.", \
  test_update_stack_push_only4)) ||
  (NULL == CU_add_test(pSuite, "test function correctly  " \
  "pushes a valid number onto the stack - v5.", \
  test_update_stack_push_only5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 42: degrees_to_radians (turtle_interp_setup.c)
 */
int degrees_to_radians_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("42 - degrees_to_radians "\
  "(turtle_interp_setup.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " converts degrees to radians - direction: North.", \
  test_degrees_to_radians_north)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " converts degrees to radians - direction: South.", \
  test_degrees_to_radians_south)) || 
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " converts degrees to radians - direction: East.", \
  test_degrees_to_radians_east)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " converts degrees to radians - direction: West.", \
  test_degrees_to_radians_west)) || 
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " converts degrees to radians - direction: random input" \
  "number.", test_degrees_to_radians_range_neg_and_pos))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 43: 
 * mock_calculate_turn_amount (turtle_interp.c)  
 */
int mock_calculate_turn_amount_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("43 - mock_calculate_turn_amount "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " flags when current move is not a turn.", \
  test_mock_calculate_turn_amount_incor_move_type)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " calculates angle to turn for left turn.", \
  test_mock_calculate_turn_amount_LT)) || 
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " calculates angle to turn for left turn.", \
  test_mock_calculate_turn_amount_RT))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 44: 
 * calculate_next_position (turtle_interp.c)   
 */
int calculate_next_position_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("44 - calculate_next_position "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " calculates next position and updates previous " \
  "position.", test_calculat_next_position))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 45: mock_still_on_screen (turtle_interp.c) */
int mock_still_on_screen_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("45 - mock_still_on_screen "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " flags when turtle goes off the right of the screen.", \
  test_mock_check_still_on_screen_flags_right)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " flags when turtle goes off the left of the screen.", \
  test_mock_check_still_on_screen_flags_left)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " flags when turtle goes off the bottom of the screen.", \
  test_mock_check_still_on_screen_flags_bottom)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " flags when turtle goes off the top of the screen.", \
  test_mock_check_still_on_screen_flags_top)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " identifies when turtle on screen for all correct posi" \
  "tions.", test_mock_check_still_on_screen_passes_okay))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* 
 * Test Suite 46:
 * mock_set_up_and_make_move (turtle_interp.c)
 */
int mock_set_up_and_make_move_suite(CU_pSuite pSuite)
{
  pSuite = CU_add_suite("46 - mock_set_up_and_make_move "\
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "test function correctly"\
  " makes a left turn - v1.", \
  test_mock_set_up_and_make_move_left_turn1)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " makes a left turn - v2.", \
  test_mock_set_up_and_make_move_left_turn2)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " makes a left turn - v3.", \
  test_mock_set_up_and_make_move_left_turn3)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " makes a right turn - v1.", \
  test_mock_set_up_and_make_move_right_turn1)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " makes a right turn - v2.", \
  test_mock_set_up_and_make_move_right_turn2)) ||
  (NULL == CU_add_test(pSuite, "test function correctly" \
  " makes a right turn - v3.", \
  test_mock_set_up_and_make_move_right_turn3)) ||
  (NULL == CU_add_test(pSuite, "test function correctly " \
  "flags when forward moves leaves right of the screen.", \
  test_mock_set_up_and_make_move_fd_off_right)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly " \
  "flags when forward moves leaves left of the screen.", \
  test_mock_set_up_and_make_move_fd_off_left)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly " \
  "flags when forward moves leaves bottom of the screen.", \
  test_mock_set_up_and_make_move_fd_off_bottom)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly " \
  "flags when forward moves leaves top of the screen.", \
  test_mock_set_up_and_make_move_fd_off_top)) ||  
  (NULL == CU_add_test(pSuite, "test function correctly " \
  "makes a forward move when position on screen.", \
  test_mock_set_up_and_make_move_fd_off_top))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  return 0 ; 
}

/* Test Suite 47: mock_polish (turtle_interp.c) */
int polish_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("47 - polish" \
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v1.", \
  test_polish_nums_only1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v2.", \
  test_polish_nums_only2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v3.", \
  test_polish_nums_only3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v1.", \
  test_polish_vars_only1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v2.", \
  test_polish_vars_only2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v3.", \
  test_polish_vars_only3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v1.", test_polish_nums_and_vars1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v2.", test_polish_nums_and_vars2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v3.", test_polish_nums_and_vars3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v4.", test_polish_nums_and_vars4))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 48: 
 * mock_set_up_stack_and_calculate_expression 
 * (turtle_interp.c) 
 */
int mock_set_up_stack_and_calc_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("48 - mock_set_up_stack_and_" \
  "calculate_expression (turtle_interp.c)", init_suite, \
  clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v1.", \
  test_mock_set_up_stack_and_cal_nums_only1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v2.", \
  test_mock_set_up_stack_and_cal_nums_only2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using numbers - v3.", \
  test_mock_set_up_stack_and_cal_nums_only3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v1.", \
  test_mock_set_up_stack_and_cal_vars_only1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v2.", \
  test_mock_set_up_stack_and_cal_vars_only2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when only using set variables - v3.", \
  test_mock_set_up_stack_and_cal_vars_only3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v1.", \
  test_mock_set_up_stack_and_cal_num_and_vars1)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v2.", \
  test_mock_set_up_stack_and_cal_num_and_vars2)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v3.", \
  test_mock_set_up_stack_and_cal_num_and_vars3)) ||
  (NULL == CU_add_test(pSuite, "that function behaves " \
  "the correctly when using mix of numbers and set " \
  "variables - v4.", \
  test_mock_set_up_stack_and_cal_num_and_vars4))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
} 

/* Test Suite 49: mock_set (turtle_interp.c) */
int mock_set_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("49 - mock_set" \
  "(turtle_interp.c)", init_suite, clean_suite) ;
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
  "that function gives parsing error when there are too " \
  "many operations - v1.", test_mock_set_incor4)) ||
  (NULL == CU_add_test(pSuite, \
  "that function gives parsing error when there are too " \
  "many operations - v2.", test_mock_set_incor5)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and that variable is set "\
  "for correct grammar (1).", test_mock_set_cor1)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and that variable is set "\
  "for correct grammar (2).", test_mock_set_cor2)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and that variable is set "\
  "for correct grammar (3).", test_mock_set_cor3)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and that variable is set "\
  "for correct grammar (4).", test_mock_set_cor4)) ||
  (NULL == CU_add_test(pSuite, \
  "test recursive behaviour and that variable is set "\
  "for correct grammar (5).", test_mock_set_cor5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 50: mock_check_if_integer (turtle_interp.c) */
int mock_check_if_integer_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("50 - mock_check_if_integer" \
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v1.", test_mock_if_integer_False1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v2.", test_mock_if_integer_False2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v3.", test_mock_if_integer_False3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v4.", test_mock_if_integer_False4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v5.", test_mock_if_integer_False5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when decimal part of number >=" \
  " FLOAT_DIF - v5.", test_mock_if_integer_False5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True when decimal part of number <" \
  " FLOAT_DIF - v1.", test_mock_if_integer_True1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True when decimal part of number <" \
  " FLOAT_DIF - v2.", test_mock_if_integer_True2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True when decimal part of number <" \
  " FLOAT_DIF - v3.", test_mock_if_integer_True3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True when decimal part of number <" \
  " FLOAT_DIF - v4.", test_mock_if_integer_True4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True when decimal part of number <" \
  " FLOAT_DIF - v5.", test_mock_if_integer_True5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 51: 
 * mock_check_do_var_and_return_place (turtle_interp.c) 
 */
int mock_check_do_var_and_rtn_place_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("51 - mock_check_do_var_and_return"\
  "_place (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not a variable - v1.",
  test_mock_check_do_var_and_return_place_incor1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not a variable - v2.",
  test_mock_check_do_var_and_return_place_incor2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not a variable - v3.",
  test_mock_check_do_var_and_return_place_incor3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not a variable - v4.",
  test_mock_check_do_var_and_return_place_incor4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not a variable - v5.",
  test_mock_check_do_var_and_return_place_incor5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v1.",
  test_mock_check_do_var_and_return_place_cor1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v1.",
  test_mock_check_do_var_and_return_place_cor1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v2.",
  test_mock_check_do_var_and_return_place_cor2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v3.",
  test_mock_check_do_var_and_return_place_cor3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v4.",
  test_mock_check_do_var_and_return_place_cor4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is a possible var. - v5.",
  test_mock_check_do_var_and_return_place_cor5))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 52: 
 * mock_check_do_var_or_num_valid (turtle_interp.c) 
 */
int mock_check_do_var_or_num_valid_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("52 - mock_check_do_var_or_num_" \
  "valid (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v1.",
  test_mock_check_do_var_and_return_False1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v2.",
  test_mock_check_do_var_and_return_False2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v3.",
  test_mock_check_do_var_and_return_False3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v4.",
  test_mock_check_do_var_and_return_False4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v5.",
  test_mock_check_do_var_and_return_False5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is an immediate integer " \
  "- v1.", test_mock_check_do_var_and_return_integer1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is an immediate integer " \
  "- v2.", test_mock_check_do_var_and_return_integer2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is an immediate integer " \
  "- v3.", test_mock_check_do_var_and_return_integer3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is an immediate integer " \
  "- v4.", test_mock_check_do_var_and_return_integer4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is an immediate integer " \
  "- v5.", test_mock_check_do_var_and_return_integer5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not immediate integer - "\
  "v1.", test_mock_check_do_var_and_return_not_integer1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not immediate integer - "\
  "v2.", test_mock_check_do_var_and_return_not_integer2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not immediate integer - "\
  "v3.", test_mock_check_do_var_and_return_not_integer3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not immediate integer - "\
  "v4.", test_mock_check_do_var_and_return_not_integer4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string is not immediate integer - "\
  "v5.", test_mock_check_do_var_and_return_not_integer5)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to integer - "\
  "v1.", test_mock_check_do_var_and_return_var_int1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to integer - "\
  "v2.", test_mock_check_do_var_and_return_var_int2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to integer - "\
  "v3.", test_mock_check_do_var_and_return_var_int3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to not int. - "\
  "v1.", test_mock_check_do_var_and_return_var_not_int1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to not int. - "\
  "v2.", test_mock_check_do_var_and_return_var_not_int2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly flags when string var. and set to not int. - "\
  "v3.", test_mock_check_do_var_and_return_var_not_int3))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 53: 
 * mock_check_and_set_do_var_or_num (turtle_interp.c) 
 */
int mock_check_and_set_do_var_or_nm_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("53 - mock_check_and_set_do_var_" \
  "or_num (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v1.",
  test_mock_check_and_set_do_var_or_num_False1)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v2.",
  test_mock_check_and_set_do_var_or_num_False2)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v3.",
  test_mock_check_and_set_do_var_or_num_False3)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v4.",
  test_mock_check_and_set_do_var_or_num_False4)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False when not a var. or num. - v5.",
  test_mock_check_and_set_do_var_or_num_False5)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is an immediate integer - " \
  "v1.", test_mock_check_and_set_do_var_or_num_integer1)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is an immediate integer - " \
  "v2.", test_mock_check_and_set_do_var_or_num_integer2)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is an immediate integer - " \
  "v3.", test_mock_check_and_set_do_var_or_num_integer3)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is an immediate integer - " \
  "v4.", test_mock_check_and_set_do_var_or_num_integer4)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is an immediate integer - " \
  "v5.", test_mock_check_and_set_do_var_or_num_integer5)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is a defined variable - " \
  "v1.", test_mock_check_and_set_do_var_or_num_var_int1)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is a defined variable - " \
  "v2.", test_mock_check_and_set_do_var_or_num_var_int2)) ||
  (NULL == CU_add_test(pSuite, "that function returns the" \
  " correct value when string is a defined variable - " \
  "v3.", test_mock_check_and_set_do_var_or_num_var_int3))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* 
 * Test Suite 54: 
 * mock_check_to_is_larger_than_from (turtle_interp.c) 
 */
int mock_check_to_is_larger_thn_frm_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("54 - mock_check_to_is_larger_than"\
  "_from (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function " \
  "correctly returns False DO FROM is > than DO TO.",
  test_mock_check_to_is_larger_than_from_False)) ||
  (NULL == CU_add_test(pSuite, "that function " \
  "correctly returns True DO FROM is <= than DO TO.",
  test_mock_check_to_is_larger_than_from_True))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 55: mock_do_loop (turtle_interp.c) */
int mock_do_loop_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("55 - mock_do_loop"\
  "_from (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  if((NULL == CU_add_test(pSuite, "that function loops cor"\
  "rect amount of times and that p->place have the correct"\
  "value on exit of function - v1.", test_mock_do_loop)) ||
  (NULL == CU_add_test(pSuite, "that function loops cor"\
  "rect amount of times and that p->place have the correct"\
  "value on exit of function - v2.", test_mock_do_loop)) ||
  (NULL == CU_add_test(pSuite, "that function loops cor"\
  "rect amount of times and that p->place have the correct"\
  "value on exit of function - v3.", test_mock_do_loop)) ||
  (NULL == CU_add_test(pSuite, "that function loops cor"\
  "rect amount of times and that p->place have the correct"\
  "value on exit of function - v4.", test_mock_do_loop)) ||
  (NULL == CU_add_test(pSuite, "that function loops cor"\
  "rect amount of times and that p->place have the correct"\
  "value on exit of function - v5.", test_mock_do_loop))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 56: mock_do_to_from (turtle_interp.c) */
int mock_do_to_from_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("56 - mock_do_to_from " \
  "(turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings - no \"DO\".", test_mock_do_from_to_fail1)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "flags invalid arrangement of strings - no variable as " \
  "subject of DO function.", test_mock_do_from_to_fail2)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings - no \"FROM\".", test_mock_do_from_to_fail3)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "flags invalid arrangement of strings - no var. or num " \
  "in after \"FROM\".", test_mock_do_from_to_fail4)) ||
  (NULL == CU_add_test(pSuite, \
  "that function correctly flags invalid arrangement of " \
  "strings - no \"TO\".", test_mock_do_from_to_fail5)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "flags invalid arrangement of strings - no var. or num " \
  "in after \"TO\" - v1.", test_mock_do_from_to_fail6)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "flags invalid arrangement of strings - no var. or num " \
  "in after \"TO\" - v2.", test_mock_do_from_to_fail7)) ||
  (NULL == CU_add_test(pSuite, "that function correctly " \
  "flags invalid arrangement of strings when the FROM > " \
  "the TO.", test_mock_do_from_to_fail8)) ||
  (NULL == CU_add_test(pSuite, "that function correctly "\
  "flags when DO does not end correctly, ie, there is " \
  "no \"{\".", test_mock_do_from_to_fail9)) ||
  (NULL == CU_add_test(pSuite, "that behaves correctly " \
  "FROM immediate number TO immediate number.", \
  test_mock_do_from_to_pass1)) ||
  (NULL == CU_add_test(pSuite, "that behaves correctly " \
  "FROM a defined variable TO immediate number.", \
  test_mock_do_from_to_pass1)) ||
  (NULL == CU_add_test(pSuite, "that behaves correctly " \
  "FROM immediate number TO a defined variable.", \
  test_mock_do_from_to_pass1)) ||
  (NULL == CU_add_test(pSuite, "that behaves correctly " \
  "FROM a defined variable TO a defined variable.", \
  test_mock_do_from_to_pass1))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

/* Test Suite 57: mock_instruction (turtle_interp.c) */
int mock_instruction_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("57 - mock_instruction " \
  "(turtle_interp.c)", init_suite, clean_suite) ;
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

/* Test Suite 58: mock_instruction_list (turtle_interp.c) */
int mock_instruction_list_suite(CU_pSuite pSuite) 
{
  pSuite = CU_add_suite("58 - mock_instruction_list " \
  "(turtle_interp.c)", init_suite, clean_suite) ;
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
 * Test Suite 59: 
 * mock_interpreter_for_program_main - (turtle_interp.c)
 */
int mock_interpreter_for_program_main_suite(CU_pSuite \
pSuite) 
{
  pSuite = CU_add_suite("59 - mock_interpreter_program_" \
  "main (turtle_interp.c)", init_suite, clean_suite) ;
  if(NULL == pSuite){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }
  
  if((NULL == CU_add_test(pSuite, "that function flags " \
  "incorrect start symbol (ie, \"{\") (1).", \
   test_mock_interpreter_for_program_main_incor1)) ||
  (NULL == CU_add_test(pSuite, "that function flags " \
  "incorrect start symbol (ie, \"{\") (2).", \
  test_mock_interpreter_for_program_main_incor2)) ||
  (NULL == CU_add_test(pSuite, "that function flags " \
  "incorrect start symbol (ie, \"{\") (3).", \
  test_mock_interpreter_for_program_main_incor3)) ||
  (NULL == CU_add_test(pSuite, "that function flags " \
  "when the input file is empty.", \
  test_mock_interpreter_for_program_main_empty_fle)) ||
  (NULL == CU_add_test(pSuite, "that function continues " \
  "correctly when start symbol (ie, \"{\") is first str.", \
  test_mock_interpreter_for_program_main_pass))){
    CU_cleanup_registry() ;
    return CU_get_error() ;
  }

  return 0 ; 
}

