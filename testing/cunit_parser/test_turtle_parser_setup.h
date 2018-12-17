/* Header file for test_turtle_parser_setup.c */ 
#include <time.h>
#include "CUnit/CUnit.h"
#include "test_turtle_test_files.h"
#include "test_turtle_errors.h"
#include "turtle_parser_setup.h"

/* Used in as a test string in Suites 11 and 12. */ 
#define STR_FOR_TEST "Test for string!"
#define TEST_STR_LEN 17

/* Used to set the size of *char[] structure in Suite 12. */ 
#define TEST_SIZE 10

/* Generates random lower case character for Suite 15. */ 
#define RANDOM_LOWER_LETTER ((rand() % 26) + 'a')

/* Used in Suite 17 to ensure p->totalStrs not changed. */ 
#define TEST_TOTAL_STR_NUM 19


/* 
 * Suite 9 Tests - 
 * pointer_is_null (turtle_parser_setup.c) 
 */
void test_pointer_is_null_for_void(void) ; 
void test_pointer_is_null_for_int(void) ; 
void test_pointer_is_null_for_unsigned_int(void) ; 
void test_pointer_is_null_for_char(void) ;
void test_pointer_is_null_for_char_pointer(void) ; 
void test_pointer_is_null_for_Prog(void) ; 

/* 
 * Suite 10 Tests - 
 * memory_for_Prog (turtle_parser_setup.c) 
 */
void test_memory_for_Prog_not_null(void) ;
void test_memory_for_Prog_size(void) ;

/* 
 * Suite 11 Tests - 
 * memory_for_string (turtle_parser_setup.c) 
 */
void test_memory_for_string_not_null(void) ; 
void test_memory_for_string_size(void) ; 
void test_memory_for_string_calloc_worked(void) ; 
void test_memory_for_string_can_store_string(void) ;

/* 
 * Suite 12 Tests -  
 * memory_for_program (turtle_parser_setup.c)
 */
void test_memory_for_program_not_null(void) ; 
void test_memory_for_program_size(void) ; 
void test_memory_for_program_calloc_worked(void) ; 
void test_memory_for_program_strings_stored(void) ; 

/* Suite 13 Tests - open_file (turtle_parser_setup.c) */
void test_open_file_null_flagged_and_returned(void) ; 
void test_open_file_return_value(void) ;
void test_open_file_pointer_not_null(void) ; 
void test_open_file_file_readable(void) ; 
void test_open_file_file_not_writable(void) ; 

/* Suite 14 Tests - close_file (turtle_parser_setup.c) */ 
void test_close_file_return_value(void) ; 
void test_close_file_file_shut_and_null_ptr(void) ; 

/* 
 * Suite 15 Tests - 
 * string_length_too_long (turtle_parser_setup.c) 
 */
void test_string_length_too_long_not_too_long(void) ; 
void test_string_length_too_long_too_long(void) ; 

/* 
 * Suite 16 Tests - 
 * number_strings_in_file (turtle_parser_setup.c) 
 */
void test_number_strings_in_file_empty(void) ; 
void test_number_strings_in_file_test_file(void) ; 

/* 
 * Suite 17 Tests - 
 * initialise_program (turtle_parser_setup.c)  
 */
void test_initialise_Prog_program(void) ; 
void test_initialise_Prog_place_value(void) ; 


/* 
 * Suite 18 Tests - 
 * read_in_strings (turtle_parser_setup.c)
 */
void test_read_in_strings_return_value_empty(void) ;
void test_read_in_strings_return_value_not_empty(void) ;
void test_read_in_strings_strings_correct(void) ;

/* 
 * Suite 19 Tests - 
 * free_program_memory (turtle_parser_setup.c) 
 * Test if all alloced memory freed using Valgrind.
 */
void test_free_program_memory_Prog_ptr_null(void) ;

/* Suite 20 Tests - set_up_program (turtle_parser_setup.c)*/
void test_set_up_program_program_Prog_ptr_not_null(void) ;
void test_set_up_program_program_program_ptr_not_null(void); 
void test_set_up_program_program_totalStrs_correct(void) ;
void test_set_up_program_program_ptrs_not_null(void) ;
void test_set_up_program_program_strs_correct(void) ;
void test_set_up_program_place_correct(void) ;
void test_set_up_program_file_shut(void) ; 

