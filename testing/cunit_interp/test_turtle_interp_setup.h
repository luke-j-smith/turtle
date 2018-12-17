/* Header file for test_turtle_interp_setup.c */ 
#include <time.h>
#include "CUnit/CUnit.h"
#include "test_turtle_test_files.h"
#include "test_turtle_errors.h"
#include "turtle_interp_setup.h"

/* Used in as a test string in Suites 13 and 14. */ 
#define STR_FOR_TEST "Test for string!"
#define TEST_STR_LEN 17

/* Used to set the size of *char[] structure in Suite 14. */ 
#define TEST_SIZE 10

/* Generates random lower case character for Suite 17. */ 
#define RANDOM_LOWER_LETTER ((rand() % 26) + 'a')

/* Used in Suite 20 to ensure p->totalStrs not changed. */ 
#define TEST_TOTAL_STR_NUM 19

/* Used in Suites 22, 23 and 31 for testing stack fnctns. */ 
#define STACK_TEST_SIZE 3

/* Used Suite 31 to test push(). */ 
#define STACK_TEST_VAL 13.479

/* Used to test degrees_to_radians() in Suite 42. */ 
#define NTH_D 0
#define EST_D 90
#define STH_D 180
#define WST_D 270
#define NTH_R (0 * M_PI)
#define EST_R (0.5 * M_PI)
#define STH_R (1 * M_PI)
#define WST_R (1.5 * M_PI)

/* Number of random numbers to test with in Suite 42. */ 
#define NUM_TEST_DEG_TO_RAD 101


/* 
 * Suite 11 Tests - pointer_is_null (turtle_interp_setup.c)
 */
void test_pointer_is_null_for_void(void) ; 
void test_pointer_is_null_for_int(void) ; 
void test_pointer_is_null_for_unsigned_int(void) ; 
void test_pointer_is_null_for_char(void) ;
void test_pointer_is_null_for_char_pointer(void) ; 
void test_pointer_is_null_for_Prog(void) ; 

/* 
 * Suite 12 Tests - memory_for_Prog (turtle_interp_setup.c)
 */
void test_memory_for_Prog_not_null(void) ;
void test_memory_for_Prog_size(void) ;

/* 
 * Suite 13 Tests - 
 * memory_for_string (turtle_interp_setup.c)
 */
void test_memory_for_string_not_null(void) ; 
void test_memory_for_string_size(void) ; 
void test_memory_for_string_calloc_worked(void) ; 
void test_memory_for_string_can_store_string(void) ;

/* 
 * Suite 14 Tests -  
 * memory_for_program (turtle_interp_setup.c)
 */
void test_memory_for_program_not_null(void) ; 
void test_memory_for_program_size(void) ; 
void test_memory_for_program_calloc_worked(void) ; 
void test_memory_for_program_strings_stored(void) ; 

/* Suite 15 Tests - open_file (turtle_interp_setup.c) */
void test_open_file_null_flagged_and_returned(void) ; 
void test_open_file_return_value(void) ;
void test_open_file_pointer_not_null(void) ; 
void test_open_file_file_readable(void) ; 
void test_open_file_file_not_writable(void) ; 

/* Suite 16 Tests - close_file (turtle_interp_setup.c) */ 
void test_close_file_return_value(void) ; 
void test_close_file_file_shut_and_null_ptr(void) ; 

/* 
 * Suite 17 Tests - 
 * string_length_too_long (turtle_interp_setup.c) 
 */
void test_string_length_too_long_not_too_long(void) ; 
void test_string_length_too_long_too_long(void) ; 

/* 
 * Suite 18 Tests - 
 * number_strings_in_file (turtle_interp_setup.c) 
 */
void test_number_strings_in_file_empty(void) ; 
void test_number_strings_in_file_test_file(void) ; 

/* 
 * Suite 19 Tests - 
 * initialise_turtle_position (turtle_interp_setup.c)  
 */
void test_initialise_turtle_position_current_x(void) ; 
void test_initialise_turtle_position_current_y(void) ; 
void test_initialise_turtle_position_previous_x(void) ; 
void test_initialise_turtle_position_previous_y(void) ; 
void test_initialise_turtle_position_theta(void) ; 

/* 
 * Suite 20 Tests - initialise_Prog (turtle_interp_setup.c)  
 */
void test_initialise_Prog_program(void) ; 
void test_initialise_Prog_place_value(void) ; 
void test_initialise_Prog_temp_value(void) ;
void test_initialise_Prog_var_set_to_null(void) ;
void test_initialise_Prog_currentMove(void) ; 
void test_initialise_Prog_turtle_position_current_x(void) ; 
void test_initialise_Prog_turtle_position_current_y(void) ; 
void test_initialise_Prog_turtle_position_previous_x(void) ; 
void test_initialise_Prog_turtle_position_previous_y(void) ; 
void test_initialise_Prog_turtle_position_theta(void) ;

/* 
 * Suite 21 Tests - 
 * read_in_strings (turtle_interp_setup.c) 
 */
void test_read_in_strings_return_value_empty(void) ;
void test_read_in_strings_return_value_not_empty(void) ;
void test_read_in_strings_strings_correct(void) ;

/* 
 * Suite 22 Tests - initialise_stack (turtle_interp_setup.c)
 */
void test_initialise_stack_ptr_not_null(void) ;
void test_initialise_stack_ptr_correct_size(void) ;
void test_initialise_stack_correct_stack_size(void) ;
void test_initialise_stack_top_value(void) ; 

/* 
 * Suite 23 Tests - free_stack (turtle_interp_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
void test_free_stack_all_freed(void) ; 

/* 
 * Suite 24 Tests - 
 * free_program_memory (turtle_interp_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
void test_free_program_memory_Prog_ptr_null(void) ;

/* Suite 25 Tests - set_up_program (turtle_interp_setup.c)*/
void test_set_up_program_program_Prog_ptr_not_null(void) ;
void test_set_up_program_program_program_ptr_not_null(void); 
void test_set_up_program_program_totalStrs_correct(void) ;
void test_set_up_program_program_ptrs_not_null(void) ;
void test_set_up_program_program_strs_correct(void) ;
void test_set_up_program_place_correct(void) ;
void test_set_up_program_temp_value(void) ;
void test_set_up_program_var_set_to_null(void) ;
void test_set_up_program_currentMove(void) ; 
void test_set_up_program_turtle_position_current_x(void) ; 
void test_set_up_program_turtle_position_current_y(void) ; 
void test_set_up_program_turtle_position_previous_x(void) ; 
void test_set_up_program_turtle_position_previous_y(void) ; 
void test_set_up_program_turtle_position_theta(void) ;
void test_set_up_program_file_shut(void) ; 

/* 
 * Suite 26 Tests - 
 * within_expression_and_file (turtle_interp_setup.c) 
 */ 
void test_within_expression_and_file_false_place(void) ;
void test_within_expression_and_file_false_term_char(void) ;
void test_within_expression_and_file_true(void) ; 

/* 
 * Suite 27 Tests - 
 * estimate_polish_length (turtle_interp_setup.c) 
 */
void test_estimate_polish_length_empty(void) ;
void test_estimate_polish_length1(void) ;
void test_estimate_polish_length2(void) ;
void test_estimate_polish_length3(void) ;
void test_estimate_polish_length4(void) ;
void test_estimate_polish_length5(void) ;

/* Suite 31 Tests - mock_push (turtle_interp_setup.c) */
unsigned int mock_push(Prog *p, double value) ; 
void test_mock_push_full_flag(void) ; 
void test_mock_push_top_value(void) ; 
void test_mock_push_value_stored(void) ;

/* 
 * Suite 42 Tests - 
 * degrees_to_radian (turtle_interp_setup.c) 
 */
void test_degrees_to_radians_north(void) ;
void test_degrees_to_radians_south(void) ;
void test_degrees_to_radians_east(void) ;
void test_degrees_to_radians_west(void) ;
void test_degrees_to_radians_range_neg_and_pos(void) ;

