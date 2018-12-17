/* Header file for test_turtle.c - CUnit Turtle testing. */
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h" 
#include "test_turtle_interp_setup.h"
#include "test_turtle_interp.h"  


/* Initiate and clean suite functions for CUnit. */ 
int init_suite(void) ;  
int clean_suite(void) ; 

/* Function containing all of the Test Suites. */ 
void test_interpreter_suites(CU_pSuite pSuite) ;

/* Every Test Suite for each individual function. */ 
int str_same_suite(CU_pSuite pSuite) ;
int is_op_suite(CU_pSuite pSuite) ; 
int a_variable_name_suite(CU_pSuite pSuite) ; 
int is_var_suite(CU_pSuite pSuite) ; 
int is_negative_suite(CU_pSuite pSuite) ;
int more_than_one_decimal_or_neg_suite(CU_pSuite pSuite) ;
int determine_type_two_inputs_suite(CU_pSuite pSuite) ; 
int type_of_number_suite(CU_pSuite pSuite) ; 
int is_num_suite(CU_pSuite pSuite) ; 
int is_var_or_num_suite(CU_pSuite pSuite) ;
int is_pointer_null_suite(CU_pSuite pSuite) ; 
int memory_for_Prog_suite(CU_pSuite pSuite) ; 
int memory_for_string_suite(CU_pSuite pSuite) ; 
int memory_for_program_suite(CU_pSuite pSuite) ;
int open_file_suite(CU_pSuite pSuite) ;
int close_file_suite(CU_pSuite pSuite) ;
int string_length_too_long_suite(CU_pSuite pSuite) ; 
int number_of_strings_in_file_suite(CU_pSuite pSuite) ;
int initialise_turtle_position_suite(CU_pSuite pSuite) ;
int initialise_Prog_suite(CU_pSuite pSuite) ;
int read_in_strings_return_suite(CU_pSuite pSuite) ;
int initialise_stack_suite(CU_pSuite pSuite) ;
int free_stack_suite(CU_pSuite pSuite) ; 
int free_program_memory_suite(CU_pSuite pSuite) ;
int set_up_program_suite(CU_pSuite pSuite) ; 
int within_expression_and_file_suite(CU_pSuite pSuite) ; 
int estimate_polish_length_suite(CU_pSuite pSuite) ;
int is_move_suite(CU_pSuite pSuite) ; 
int MOCK_INTERP_ERROR_suite(CU_pSuite pSuite) ; 
int mock_check_within_program_bounds_suite(CU_pSuite \
pSuite) ; 
int mock_push_suite(CU_pSuite pSuite) ; 
int mock_pop_suite(CU_pSuite pSuite) ; 
int mock_get_final_value_from_stack_suite(CU_pSuite pSuite);
int mock_read_number_value_suite(CU_pSuite pSuite) ; 
int determine_var_index_suite(CU_pSuite pSuite) ; 
int mock_set_var_value_suite(CU_pSuite pSuite) ; 
int mock_read_var_value_suite(CU_pSuite pSuite) ; 
int mock_value_of_var_or_num_suite(CU_pSuite pSuite) ; 
int mock_check_if_division_by_zero_Suite(CU_pSuite pSuite) ; 
int mock_calculation_suite(CU_pSuite pSuite) ; 
int update_stack_suite(CU_pSuite pSuite) ; 
int degrees_to_radians_suite(CU_pSuite pSuite) ;
int mock_calculate_turn_amount_suite(CU_pSuite pSuite) ; 
int calculate_next_position_suite(CU_pSuite pSuite) ; 
int mock_still_on_screen_suite(CU_pSuite pSuite) ; 
int mock_set_up_and_make_move_suite(CU_pSuite pSuite) ; 
int polish_suite(CU_pSuite pSuite) ; 
int mock_set_up_stack_and_calc_suite(CU_pSuite pSuite) ; 
int mock_set_suite(CU_pSuite pSuite) ; 
int mock_check_if_integer_suite(CU_pSuite pSuite) ;
int mock_check_do_var_and_rtn_place_suite(CU_pSuite pSuite);
int mock_check_do_var_or_num_valid_suite(CU_pSuite pSuite) ;
int mock_check_and_set_do_var_or_nm_suite(CU_pSuite pSuite);
int mock_check_to_is_larger_thn_frm_suite(CU_pSuite pSuite);
int mock_do_loop_suite(CU_pSuite pSuite) ;  
int mock_do_to_from_suite(CU_pSuite pSuite) ; 
int mock_instruction_suite(CU_pSuite pSuite) ; 
int mock_instruction_list_suite(CU_pSuite pSuite) ; 
int mock_interpreter_for_program_main_suite(CU_pSuite \
pSuite) ; 
