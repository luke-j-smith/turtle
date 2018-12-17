/* Header file for test_turtle.c - CUnit Turtle testing. */
#include "CUnit/Basic.h"  
#include "CUnit/Automated.h"
#include "CUnit/Console.h" 
#include "test_turtle_parser_setup.h"
#include "test_turtle_parser.h"

/* Initiate and clean suite functions for CUnit. */ 
int init_suite(void) ; 
int clean_suite(void) ; 

/* Function containing all of the Test Suites. */ 
void test_parser_suites(CU_pSuite pSuite) ;

/* Every Test Suite for each individual function. */ 
int str_same_suite(CU_pSuite pSuite) ;
int is_op_suite(CU_pSuite pSuite) ; 
int a_variable_name_suite(CU_pSuite pSuite) ; 
int is_var_suite(CU_pSuite pSuite) ; 
int is_negative_suite(CU_pSuite pSuite) ;
int more_than_one_decimal_or_neg_suite(CU_pSuite pSuite) ; 
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
int initialise_Prog_suite(CU_pSuite pSuite) ;
int read_in_strings_return_suite(CU_pSuite pSuite) ;
int free_program_memory_suite(CU_pSuite pSuite) ;
int set_up_program_suite(CU_pSuite pSuite) ; 
int is_move_suite(CU_pSuite pSuite) ; 
int mock_parsing_error_suite(CU_pSuite pSuite) ; 
int mock_check_within_program_bounds_suite(CU_pSuite \
pSuite) ;  
int mock_polish_suite(CU_pSuite pSuite) ; 
int mock_set_suite(CU_pSuite pSuite) ; 
int mock_do_to_from_suite(CU_pSuite pSuite) ; 
int mock_instruction_suite(CU_pSuite pSuite) ; 
int mock_instruction_list_suite(CU_pSuite pSuite) ; 
int mock_parser_program_main_suite(CU_pSuite pSuite) ; 
