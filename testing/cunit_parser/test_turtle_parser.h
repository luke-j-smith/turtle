/* Header file for test_turtle_parser.c */ 
#include "CUnit/CUnit.h"
#include "test_turtle_parser_setup.h"
#include "turtle_parser.h"

/* 
 * The return values used in mock functions. Used to check 
 * the coverage of each function and to replace any ERRORS
 * that would normally result in an EXIT. 
 */
enum mockRouteReturnValue {FailureBuffer, SuccessBuffer, \
OutOfBounds, MockNoSetStart, MockNoSetVar, MockNoSetDefine,\
DoStartFail, DoVarFail, DoFromFail, DoVarNum1Fail, \
DoToFail, DoVarNum2Fail, DoEndFail, InstrctMoveFail, \
InstrctDo, InstrctSet, InstrctMove} ; 
typedef enum mockRouteReturnValue MockRouteReturnValue ; 

/* Used in Suite 1 to test str_same() return value. */  
#define STR_NOT_EQUAL "Not Equal."
#define STR_EQUAL "Equal."

/* 
 * Str to test whether a str that is too long is flagged. 
 * Used in Suites 2, 4 and 8.
 */
#define STR_TOO_LONG "Long."

/* Used in Suite 2 to test is_op() - flag as incorrect. */ 
#define OP_INCOR1 "."
#define OP_INCOR2 "}"
#define OP_INCOR3 "3"
#define OP_INCOR4 " "
#define OP_INCOR5 "A"

/* 
 * All possible variable names and their string length. 
 * Used in Suites 3, 4 and 20. 
 */ 
#define VAR_NAMES {"A", "B", "C", "D", "E", "F", "G", \
 "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", \
 "S", "T", "U", "V", "W", "X", "Y", "Z"} ;
#define NUMBER_OF_VARS 26
#define VAR_NAME_LEN 2

/* 
 * Strings to test #define a_variable_name - should flag as   
 * incorrect. Used in Suites 3 and 5.  
 */ 
#define NAME_INCOR1 "a"
#define NAME_INCOR2 "z"
#define NAME_INCOR3 "."
#define NAME_INCOR4 " -"
#define NAME_INCOR5 "+"

/* Used in Suites 4 and 8test is_var() - flag incorrect. */ 
#define VAR_INCOR1 "a"
#define VAR_INCOR2 "!"
#define VAR_INCOR3 "B "
#define VAR_INCOR4 "CD"
#define VAR_INCOR5 "A."

/* 
 * Used in Suite 6. Input combinations to test return of 
 * more_than_one_decimal_or_negative().
 */
#define TWO_INPUTS 2
#define TYPE_NUM_NON_NEG_INT {0, 0}
#define TYPE_NUM_NEG_INT {1, 0}
#define TYPE_NUM_NON_NEG_FLOAT {0, 1}
#define TYPE_NUM_NEG_FLOAT {1, 1} 
#define TYPE_NUM_INCOR1 {0, 2}
#define TYPE_NUM_INCOR2 {2, 0}
#define TYPE_NUM_INCOR3 {1, 2}
#define TYPE_NUM_INCOR4 {2, 1}
#define TYPE_NUM_INCOR5 {2, 2}

/* 
 * Strings to test in Suites 7 and 8. Should flag as being
 * incorrect and not a valid number. 
 */ 
#define NUM_INCOR1 "9-820."
#define NUM_INCOR2 "8a3"
#define NUM_INCOR3 "17.2.01"
#define NUM_INCOR4 "--01"
#define NUM_INCOR5 NEGATIVE_SYMBOL_STR

/* 
 * Strings to test in Suites 7 and 8. Should flag as being
 * correct and return Number.
 */ 
#define NUM_NON_NI "9"
#define NUM_NI "-101"
#define NUM_NON_NF "94.102"
#define NUM_NF1 "-99.109"
#define NUM_NF2 "-.0782"

/* #define MOCK_PASSING_ERROR (turtle_errors.h) - Suite 22*/
#define MOCK_PARSING_ERROR(message, type, p, check) \
{fprintf(stderr, message, type, (p->place + 1)) ; check = \
(p->place + 1) ; free_program_memory(&p) ; p = NULL ; }
#define MK_PAR_MSSGE "\nParsing Error: %d - Test " \
"to see if the #define PARSING_ERROR exit function behaves"\
" correctly.\nNO ACTUAL ERROR - Print one: %d.\n\n"
#define MOCK_PAR_TYPE 0

/* Suite 27 - Checks number steps taken through program. */
enum placeMovement {NoMove, OneStep, TwoSteps, ThreeSteps, \
FourSteps} ; 
typedef enum placeMovement PlaceMovement ; 


/* Suite 1 Tests - #define str_same (turtle_parser.h) */
void test_str_same_not_equal(void) ; 
void test_str_same_equal(void) ; 

/* Suite 2 Tests - is_op (turtle_parser.c) */ 
void test_is_op_incorrect_length(void) ; 
void test_is_op_incorrect1(void) ; 
void test_is_op_incorrect2(void) ; 
void test_is_op_incorrect3(void) ; 
void test_is_op_incorrect4(void) ; 
void test_is_op_incorrect5(void) ; 
void test_is_op_correct(void) ; 

/* 
 * Suite 3 Tests - 
 * #define a_variable_name (turtle_parser.h) 
 */
void test_a_variable_name_flags_incorrect_name1(void) ;
void test_a_variable_name_flags_incorrect_name2(void) ;
void test_a_variable_name_flags_incorrect_name3(void) ;
void test_a_variable_name_flags_incorrect_name4(void) ;
void test_a_variable_name_flags_incorrect_name5(void) ;
void test_a_variable_name_return_correct_names(void) ;

/* Suite 4 Tests - is_var (turtle_parser.c) */ 
void test_is_var_incorrect_length(void) ; 
void test_is_var_incorrect_name1(void) ; 
void test_is_var_incorrect_name2(void) ; 
void test_is_var_incorrect_name3(void) ; 
void test_is_var_incorrect_name4(void) ; 
void test_is_var_incorrect_name5(void) ; 
void test_is_var_correct_name(void) ; 

/* 
 * Suite 5 Tests - 
 * #define is_negative (turtle_parser.h) 
 */
void test_is_negative_return_value_false1(void) ;
void test_is_negative_return_value_false2(void) ;
void test_is_negative_return_value_false3(void) ;
void test_is_negative_return_value_false4(void) ;
void test_is_negative_return_value_false5(void) ;
void test_is_negative_return_value_true(void) ;

/* 
 * Suite 6 Tests - #define more_than_one_decimal_or_negative
 * (turtle_parser.h)
 */
void test_more_than_one_decimal_or_negative_true1(void) ; 
void test_more_than_one_decimal_or_negative_true2(void) ; 
void test_more_than_one_decimal_or_negative_true3(void) ; 
void test_more_than_one_decimal_or_negative_true4(void) ; 
void test_more_than_one_decimal_or_negative_true5(void) ; 
void test_more_than_one_decimal_or_negative_false1(void) ; 
void test_more_than_one_decimal_or_negative_false2(void) ; 
void test_more_than_one_decimal_or_negative_false3(void) ; 
void test_more_than_one_decimal_or_negative_false4(void) ;

/* Suite 7 Tests - is_num (turtle_parser.c) */ 
void test_is_num_incorrect1(void) ;
void test_is_num_incorrect2(void) ;
void test_is_num_incorrect3(void) ;
void test_is_num_incorrect4(void) ;
void test_is_num_incorrect5(void) ;
void test_is_num_cor_non_negative_integer(void) ; 
void test_is_num_cor_negative_integer(void) ; 
void test_is_num_cor_non_negative_floating(void) ; 
void test_is_num_cor_negative_floating1(void) ; 
void test_is_num_cor_negative_floating2(void) ; 

/* Suite 8 Tests - is_var_or_num (turtle_parser.c) */ 
void test_is_var_or_num_not_number1(void) ; 
void test_is_var_or_num_not_number2(void) ; 
void test_is_var_or_num_not_number3(void) ; 
void test_is_var_or_num_not_number4(void) ; 
void test_is_var_or_num_too_long(void) ; 
void test_is_var_or_num_not_variable1(void) ; 
void test_is_var_or_num_not_variable2(void) ; 
void test_is_var_or_num_not_variable3(void) ; 
void test_is_var_or_num_not_variable4(void) ; 
void test_is_var_or_num_correct_variables(void) ; 
void test_is_var_or_num_cor_non_negative_integer(void) ; 
void test_is_var_or_num_cor_negative_integer(void) ; 
void test_is_var_or_num_cor_non_negative_floating(void) ; 
void test_is_var_or_num_cor_negative_floating1(void) ; 
void test_is_var_or_num_cor_negative_floating2(void) ;

/* Suite 21 Tests - is_move (turtle_parser.c) */
void test_is_move_fail1(void) ;
void test_is_move_fail2(void) ;
void test_is_move_fail3(void) ;
void test_is_move_pass1(void) ;
void test_is_move_pass2(void) ;
void test_is_move_pass3(void) ;

/* 
 * Suite Tests - 22
 * #define MOCK_PASSING_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
void test_mock_parsing_error(void) ; 

/* 
 * Suite 23 Tests - 
 * mock_check_within_bounds (turtle_parser.c) 
 */
unsigned int mock_check_within_program_bounds(Prog *p) ; 
void test_mock_check_within_program_bounds_fail1(void) ; 
void test_mock_check_within_program_bounds_fail2(void) ; 
void test_mock_check_within_program_bounds_pass(void) ; 

/* Suite 24 Tests - mock_polish (turtle_parser.c) */
unsigned int mock_polish(Prog *p) ; 
void test_mock_polish_no_end_character(void) ; 
void test_mock_polish_incor1(void) ; 
void test_mock_polish_incor2(void) ; 
void test_mock_polish_incor3(void) ;
void test_mock_polish_incor4(void) ;
void test_mock_polish_cor1(void) ; 
void test_mock_polish_cor2(void) ;
void test_mock_polish_cor3(void) ;
void test_mock_polish_cor4(void) ;
void test_mock_polish_cor5(void) ;

/* Suite 25 Tests - mock_set (turtle_parser.c) */
unsigned int mock_set(Prog *p) ; 
void test_mock_set_incor1(void) ; 
void test_mock_set_incor2(void) ; 
void test_mock_set_incor3(void) ;
void test_mock_set_incor4(void) ;
void test_mock_set_incor5(void) ;
void test_mock_set_cor1(void) ; 
void test_mock_set_cor2(void) ;
void test_mock_set_cor3(void) ;
void test_mock_set_cor4(void) ;
void test_mock_set_cor5(void) ;

/* Suite 26 Tests - mock_do_from_to (turtle_parser.c) */
unsigned int mock_do_from_to(Prog *p) ;
void test_mock_do_from_to_fail1(void) ;
void test_mock_do_from_to_fail2(void) ;
void test_mock_do_from_to_fail3(void) ;
void test_mock_do_from_to_fail4(void) ;
void test_mock_do_from_to_fail5(void) ;
void test_mock_do_from_to_fail6(void) ;
void test_mock_do_from_to_fail7(void) ;
void test_mock_do_from_to_pass1(void) ;
void test_mock_do_from_to_pass2(void) ;
void test_mock_do_from_to_pass3(void) ;
void test_mock_do_from_to_pass4(void) ;

/* Suite 27 Tests - mock_instruction (turtle_parser.c) */
unsigned int mock_instruction(Prog *p) ; 
void test_mock_instruction_fail1(void) ; 
void test_mock_instruction_fail2(void) ;
void test_mock_instruction_fail3(void) ;
void test_mock_instruction_pass_fd(void) ;
void test_mock_instruction_pass_lt(void) ;
void test_mock_instruction_pass_rt(void) ;
void test_mock_instruction_pass_do(void) ;
void test_mock_instruction_pass_set(void) ;

/* 
 * Suite 28 Tests -
 * mock_instruction_list (turtle_parser.c) 
 */
unsigned int mock_instruction_list(Prog *p) ;
void test_mock_instruction_list_fail1(void) ;
void test_mock_instruction_list_fail2(void) ; 
void test_mock_instruction_list_fail3(void) ;
void test_mock_instruction_list_empty(void) ;
void test_mock_instruction_list_pass1(void) ;
void test_mock_instruction_list_pass2(void) ;
void test_mock_instruction_list_pass3(void) ;

/* 
 * Suite 29 Tests - 
 * mock_parser_program_main (turtle_parser.c) 
 */
unsigned int mock_parser_program_main(Prog *p) ;
void test_mock_parser_program_main_incor1(void) ;
void test_mock_parser_program_main_incor2(void) ;
void test_mock_parser_program_main_incor3(void) ;
void test_mock_parser_program_main_incor_empty_file(void) ; 
void test_mock_parser_program_main_pass(void) ;


