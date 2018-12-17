/* Header file for test_turtle_interp.c */ 
#include "CUnit/CUnit.h"
#include "test_turtle_interp_setup.h"
#include "turtle_interp.h"

/* 
 * The return values used in mock functions. Used to check 
 * the coverage of each function and to replace any ERRORS
 * that would normally result in an EXIT. 
 */
enum mockRouteReturnValue {FailureBuffer, SuccessBuffer, \
StackMore1, StackLess1, MockSetVarFail, \
MockVarReadNameFail, MockVarReadNullFail, OutOfBounds, \
OffRight, OffLeft, OffBottom, OffTop, \
MockNoSetStart, MockNoSetVar, MockNoSetDefine, \
MockDoNotVar, MockNotInt, MockCheckAndSetFalse, MockInt, \
MockDoInt, MockDoFloat, \
DoStartFail, DoVarFail, DoFromFail, DoVarNum1Fail, \
DoToFail, DoVarNum2Fail, DoFromLarger, DoEndFail, \
InstrctMoveFail, InstrctDo, \
InstrctSet, InstrctMove} ; 
typedef enum mockRouteReturnValue MockRouteReturnValue ; 

/* Used in Suite 1 to test str_same() return value. */  
#define STR_NOT_EQUAL "Not Equal."
#define STR_EQUAL "Equal."

/* Used in Suites 2, 4 and 10. Should str too long. */
#define STR_TOO_LONG "Long."

/* Used in Suite 2 to test is_op() - flag as incorrect. */ 
#define OP_INCOR1 "."
#define OP_INCOR2 "}"
#define OP_INCOR3 "3"
#define OP_INCOR4 " "
#define OP_INCOR5 "A"

/* 
 * Used in Suites 3, 4, 35, 36 and 37. 
 * All possible variable names and their string length. 
 */ 
#define VAR_NAMES {"A", "B", "C", "D", "E", "F", "G", \
 "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", \
 "S", "T", "U", "V", "W", "X", "Y", "Z"} ;
#define VAR_NAME_LEN 2

/* 
 * Used in Suites 3 and 5 to test #define a_variable_name -  
 * Flag as incorrect. Assume correct length is okay. . 
 */ 
#define NAME_INCOR1 "a"
#define NAME_INCOR2 "z"
#define NAME_INCOR3 "."
#define NAME_INCOR4 " -"
#define NAME_INCOR5 "+"

/* Used in Suites 4 and 10 - should flag as incorrect. */ 
#define VAR_INCOR1 "a"
#define VAR_INCOR2 "!"
#define VAR_INCOR3 "B "
#define VAR_INCOR4 "CD"
#define VAR_INCOR5 "A."

/* Used in Suite 7. Inputs for determine_type_two_inputs. */ 
#define TEST_DETERMINE_TYPE_START -101
#define TEST_DETERMINE_TYPE_END 101

/* 
 * Used in Suite 8. Input combinations to test return of 
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
 * Used in Suites 8, 9, 10, 34 and 53. Should flag as being
 * incorrect and not a valid number. 
 */ 
#define NUM_INCOR1 "9-820."
#define NUM_INCOR2 "8a3"
#define NUM_INCOR3 "17.2.01"
#define NUM_INCOR4 "--01"
#define NUM_INCOR5 NEGATIVE_SYMBOL_STR

/* 
 * Strings to test in Suites 9, 10, 34 and 54. Should flag
 * as being correct and return correct type of number.
 */ 
#define NUM_NON_NI "9"
#define NUM_NI "-101"
#define NUM_NON_NF "94.102"
#define NUM_NF1 "-99.109"
#define NUM_NF2 "-.0782"
#define NUM_NON_NI_VALUE 9
#define NUM_NI_VALUE -101
#define NUM_NON_NF_VALUE 94.102
#define NUM_NF1_VALUE -99.109
#define NUM_NF2_VALUE -.0782

/* #define MOCK_INTERP_ERROR (turtle_errors.h) - Suite 29 */
#define MOCK_INTERP_ERROR(message, type, p, check) \
{fprintf(stderr, message, type, (p->place + 1)) ; check = \
(p->place + 1) ; free_program_memory(&p) ; p = NULL ; }
#define MK_PAR_MSSGE "\nParsing Error: %d - Test " \
"to see if the #define PARSING_ERROR exit function behaves"\
" correctly.\nNO ACTUAL ERROR - Print one: %d.\n\n"
#define MOCK_PAR_TYPE 0

/* A correct variable name used in Suite 37. */ 
#define COR_VAR_NAME "A"

/* Used in Suite 45 to test check_still_on_screen(). */ 
#define OFF_SCREEN_NEG -FLOAT_DIF
#define OFF_SCREEN_X_POS (SDL_WIDTH + FLOAT_DIF)
#define OFF_SCREEN_Y_POS (SDL_HEIGHT + FLOAT_DIF)

/* Used in Suite 50 to test check_if_integer(). */ 
#define NT_INT1 0.9999
#define NT_INT2 0.01
#define NT_INT3 0.0001
#define NT_INT4 0.00001
#define NT_INT5 0.000001
#define INT1 0.0000001
#define INT2 0.00000009
#define INT3 0.000000099
#define INT4 0.0000000999
#define INT5 0.00000009999

/* Used in Suite 55 to generate a random starting place. */
#define RANDOM_PLACE 101

/* Used in Suite 57 - Check number steps taken in program.*/
enum placeMovement {NoMove, OneStep, TwoSteps, ThreeSteps, \
FourSteps} ; 
typedef enum placeMovement PlaceMovement ; 


/* Suite 1 Tests - #define str_same (turtle_interp.h) */
void test_str_same_not_equal(void) ; 
void test_str_same_equal(void) ; 

/* Suite 2 Tests - is_op (turtle_interp.c) */ 
void test_is_op_incorrect_length(void) ; 
void test_is_op_incorrect1(void) ; 
void test_is_op_incorrect2(void) ; 
void test_is_op_incorrect3(void) ; 
void test_is_op_incorrect4(void) ; 
void test_is_op_incorrect5(void) ; 
void test_is_op_correct(void) ; 

/* 
 * Suite 3 Tests - 
 * #define a_variable_name (turtle_interp.h) 
 */
void test_a_variable_name_flags_incorrect_name1(void) ;
void test_a_variable_name_flags_incorrect_name2(void) ;
void test_a_variable_name_flags_incorrect_name3(void) ;
void test_a_variable_name_flags_incorrect_name4(void) ;
void test_a_variable_name_flags_incorrect_name5(void) ;
void test_a_variable_name_return_correct_names(void) ;

/* Suite 4 Tests - is_var (turtle_interp.c) */ 
void test_is_var_incorrect_length(void) ; 
void test_is_var_incorrect_name1(void) ; 
void test_is_var_incorrect_name2(void) ; 
void test_is_var_incorrect_name3(void) ; 
void test_is_var_incorrect_name4(void) ; 
void test_is_var_incorrect_name5(void) ; 
void test_is_var_correct_name(void) ; 

/* Suite 5 Tests -  #define is_negative (turtle_interp.h) */
void test_is_negative_return_value_false1(void) ;
void test_is_negative_return_value_false2(void) ;
void test_is_negative_return_value_false3(void) ;
void test_is_negative_return_value_false4(void) ;
void test_is_negative_return_value_false5(void) ;
void test_is_negative_return_value_true(void) ;

/* 
 * Suite 6 Tests - #define more_than_one_decimal_or_negative
 * (turtle_interp.h)
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

/* 
 * Suite 7 Tests - 
 * #define determine_type_two_inputs (turtle_interp.h) 
 */ 
void test_determine_type_two_inputs_test_zero(void) ; 
void test_determine_type_two_inputs_test_range(void) ;

/* Suite 8 Tests - type_of_number (turtle_interp.c) */
void test_type_of_number_return_false1(void) ;
void test_type_of_number_return_false2(void) ;
void test_type_of_number_return_false3(void) ;
void test_type_of_number_return_false4(void) ;
void test_type_of_number_return_false5(void) ;
void test_type_of_number_return_NonNegInt(void) ;
void test_type_of_number_return_NegInt(void) ;
void test_type_of_number_return_NonNegFloat(void) ;
void test_type_of_number_return_NegFloat(void) ;

/* Suite 9 Tests - is_num (turtle_interp.c) */ 
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

/* Suite 10 Tests - is_var_or_num (turtle_interp.c) */ 
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

/* Suite 28 Tests - is_move (turtle_interp.c) */
void test_is_move_fail1(void) ;
void test_is_move_fail2(void) ;
void test_is_move_fail3(void) ;
void test_is_move_pass1(void) ;
void test_is_move_pass2(void) ;
void test_is_move_pass3(void) ;

/* 
 * Suite Tests 29 -
 * #define MOCK_INTERP_ERROR (turtle_errors.h) 
 * Test if exit function works correctly (using Valgrind)
 */
void test_MOCK_INTERP_ERROR(void) ; 

/* 
 * Suite 30 Tests - 
 * mock_check_within_bounds (turtle_interp.c) 
 */
unsigned int mock_check_within_program_bounds(Prog *p) ; 
void test_mock_check_within_program_bounds_fail1(void) ; 
void test_mock_check_within_program_bounds_fail2(void) ; 
void test_mock_check_within_program_bounds_pass(void) ; 

/* Suite 32 Tests - mock_pop (turtle_interp.c) */
double mock_pop(Prog *p) ;
void test_mock_pop_flag_empty(void) ; 
void test_mock_pop_top_value(void) ; 
void test_mock_pop_popped_value(void) ; 

/* 
 * Suite 33 Tests - 
 * mock_get_final_value_from_stack (turtle_interp.c) 
 */
double mock_get_final_value_from_stack(Prog *p) ;
void mock_get_final_value_from_stack_more_than_one(void) ;
void mock_get_final_value_from_stack_less_than_one(void) ;
void mock_get_final_value_from_stack_correct_value(void) ;

/* 
 * Suite 34 Tests - 
 * mock_read_number_value (turtle_interp.c) 
 */
double mock_read_number_value(char *string) ; 
void test_mock_read_number_value_incor_num_flagged1(void) ; 
void test_mock_read_number_value_incor_num_flagged2(void) ; 
void test_mock_read_number_value_incor_num_flagged3(void) ; 
void test_mock_read_number_value_incor_num_flagged4(void) ;
void test_mock_read_number_value_incor_num_flagged5(void) ;
void test_mock_read_number_value_correct_num1(void) ;
void test_mock_read_number_value_correct_num2(void) ;
void test_mock_read_number_value_correct_num3(void) ;
void test_mock_read_number_value_correct_num4(void) ;
void test_mock_read_number_value_correct_num5(void) ;

/* 
 * Suite 35 Tests - 
 * #define determine_var_index (turtle_interp.h) 
 */
void test_determine_var_index_correct_value(void) ; 

/* Suite 36 Tests - mock_set_var_value (turtle_interp.c) */
double mock_set_var_value(char *str, double value, Prog *p);
void test_mock_set_var_value_fail_name_length(void) ;
void test_mock_set_var_value_fail_name_wrong(void) ;
void test_mock_set_var_value_correct_not_defined(void) ;
void test_mock_set_var_value_correct_when_defined(void) ;

/* Suite 37 Tests - mock_read_var_value (turtle_interp.c) */
double mock_read_var_value(char *str, Prog *p) ; 
void test_mock_read_var_value_fail_name_length(void) ;
void test_mock_read_var_value_fail_name_wrong(void) ; 
void test_mock_read_var_value_fail_null(void) ; 
void test_mock_read_var_correct_var_values(void) ; 

/* 
 * Suite 38 Tests - 
 * mock_value_of_var_or_num (turtle_interp.c) 
 */
double mock_value_of_var_or_num(Prog *p) ;
void test_mock_value_of_var_or_num_fail1(void) ;
void test_mock_value_of_var_or_num_fail2(void) ;
void test_mock_value_of_var_or_num_fail3(void) ;
void test_mock_value_of_var_or_num_fail4(void) ;
void test_mock_value_of_var_or_num_fail5(void) ;
void test_mock_value_of_var_or_num_vars_cor(void) ;
void test_mock_value_of_var_or_num_num_cor1(void) ;
void test_mock_value_of_var_or_num_num_cor2(void) ;
void test_mock_value_of_var_or_num_num_cor3(void) ;
void test_mock_value_of_var_or_num_num_cor4(void) ;
void test_mock_value_of_var_or_num_num_cor5(void) ;

/* 
 * Suite 39 Tests - 
 * mock_check_if_division_by_zero (turtle_interp.h) 
 */
unsigned int mock_check_if_division_by_zero(double divisor);
void test_mock_check_if_division_by_zero_true(void) ; 
void test_mock_check_if_division_by_zero_false(void) ; 

/* Suite 40 Tests - mock_calculation (turtle_interp.c) */
double mock_calculation(Prog *p, double value1, \
double value2) ; 
void test_mock_calculation_no_operation(void) ;
void test_mock_calculation_divide_by_zero_flag(void) ;
void test_mock_calculation_addition_correct(void) ;
void test_mock_calculation_subtraction_correct(void) ;
void test_mock_calculation_multiplication_correct(void) ;
void test_mock_calculation_division_correct(void) ;

/* Suite 41 Tests - update_stack (turtle_interp.c) */
void test_update_stack_calc_addition(void) ;
void test_update_stack_calc_subtraction(void) ;
void test_update_stack_calc_multiplication(void) ;
void test_update_stack_calc_division(void) ;
void test_update_stack_push_only1(void) ;
void test_update_stack_push_only2(void) ;
void test_update_stack_push_only3(void) ;
void test_update_stack_push_only4(void) ;
void test_update_stack_push_only5(void) ;

/* 
 * Suite 43 Tests - 
 * mock_calculate_turn_amount (turtle_interp.c) 
 */
int mock_calculate_turn_amount(Prog *p, double turnBy) ;
void test_mock_calculate_turn_amount_incor_move_type(void) ;
void test_mock_calculate_turn_amount_LT(void) ;
void test_mock_calculate_turn_amount_RT(void) ;

/* 
 * Suite 44 Tests - 
 * calculate_next_position (turtle_interp.c) 
 */
void test_calculat_next_position(void) ; 

/* 
 * Suite 45 Tests - 
 * mock_still_on_screen (turtle_interp.c) 
 */
unsigned int mock_check_still_on_screen(Prog *p) ;
void test_mock_check_still_on_screen_flags_right(void) ;
void test_mock_check_still_on_screen_flags_left(void) ;
void test_mock_check_still_on_screen_flags_bottom(void) ;
void test_mock_check_still_on_screen_flags_top(void) ;
void test_mock_check_still_on_screen_passes_okay(void) ;

/* 
 * Suite 46 Tests - 
 * mock_set_up_and_make_move (turtle_interp.c) 
 */
unsigned int mock_set_up_and_make_move(Prog *p) ;
void test_mock_set_up_and_make_move_left_turn1(void) ;
void test_mock_set_up_and_make_move_left_turn2(void) ;
void test_mock_set_up_and_make_move_left_turn3(void) ;
void test_mock_set_up_and_make_move_right_turn1(void) ;
void test_mock_set_up_and_make_move_right_turn2(void) ;
void test_mock_set_up_and_make_move_right_turn3(void) ;
void test_mock_set_up_and_make_move_fd_off_right(void) ;
void test_mock_set_up_and_make_move_fd_off_left(void) ;
void test_mock_set_up_and_make_move_fd_off_bottom(void) ;
void test_mock_set_up_and_make_move_fd_off_top(void) ;
void test_mock_set_up_and_make_move_on_screen(void) ;

/* Suite 47 Tests - polish (turtle_interp.c) */
void test_polish_nums_only1(void) ; 
void test_polish_nums_only2(void) ; 
void test_polish_nums_only3(void) ; 
void test_polish_vars_only1(void) ; 
void test_polish_vars_only2(void) ;
void test_polish_vars_only3(void) ; 
void test_polish_nums_and_vars1(void) ;
void test_polish_nums_and_vars2(void) ;
void test_polish_nums_and_vars3(void) ;
void test_polish_nums_and_vars4(void) ;

/* 
 * Suite 48 Tests - 
 * mock_set_up_stack_and_calculate_expression 
 * (turtle_interp.c) 
 */
double mock_set_up_stack_and_calculate_expression(\
Prog *p, unsigned int varPlace) ; 
void test_mock_set_up_stack_and_cal_nums_only1(void) ; 
void test_mock_set_up_stack_and_cal_nums_only2(void) ; 
void test_mock_set_up_stack_and_cal_nums_only3(void) ; 
void test_mock_set_up_stack_and_cal_vars_only1(void) ; 
void test_mock_set_up_stack_and_cal_vars_only2(void) ; 
void test_mock_set_up_stack_and_cal_vars_only3(void) ; 
void test_mock_set_up_stack_and_cal_num_and_vars1(void) ; 
void test_mock_set_up_stack_and_cal_num_and_vars2(void) ; 
void test_mock_set_up_stack_and_cal_num_and_vars3(void) ; 
void test_mock_set_up_stack_and_cal_num_and_vars4(void) ; 

/* Suite 49 Tests - mock_set (turtle_interp.c) */
double mock_set(Prog *p) ;
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

/* 
 * Suite 50 Tests - 
 * mock_check_if_integer (turtle_interp.c) 
 */
unsigned int mock_check_if_integer(double fraction) ;
void test_mock_if_integer_False1(void) ;
void test_mock_if_integer_False2(void) ;
void test_mock_if_integer_False3(void) ;
void test_mock_if_integer_False4(void) ;
void test_mock_if_integer_False5(void) ;
void test_mock_if_integer_True1(void) ;
void test_mock_if_integer_True2(void) ;
void test_mock_if_integer_True3(void) ;
void test_mock_if_integer_True4(void) ;
void test_mock_if_integer_True5(void) ;

/* 
 * Suite 51 Tests - 
 * mock_check_do_var_and_return_place (turtle_interp.c) 
 */
unsigned int mock_check_do_var_and_return_place(Prog *p) ; 
void test_mock_check_do_var_and_return_place_incor1(void) ;
void test_mock_check_do_var_and_return_place_incor2(void) ;
void test_mock_check_do_var_and_return_place_incor3(void) ;
void test_mock_check_do_var_and_return_place_incor4(void) ;
void test_mock_check_do_var_and_return_place_incor5(void) ;
void test_mock_check_do_var_and_return_place_cor1(void) ;
void test_mock_check_do_var_and_return_place_cor2(void) ;
void test_mock_check_do_var_and_return_place_cor3(void) ;
void test_mock_check_do_var_and_return_place_cor4(void) ;
void test_mock_check_do_var_and_return_place_cor5(void) ;

/* 
 * Suite 52 Tests - 
 * mock_check_do_var_or_num_valid (turtle_interp.c) 
 */
unsigned int mock_check_do_var_or_num_valid(Prog *p) ; 
void test_mock_check_do_var_and_return_False1(void) ; 
void test_mock_check_do_var_and_return_False2(void) ; 
void test_mock_check_do_var_and_return_False3(void) ; 
void test_mock_check_do_var_and_return_False4(void) ; 
void test_mock_check_do_var_and_return_False5(void) ; 
void test_mock_check_do_var_and_return_integer1(void) ;
void test_mock_check_do_var_and_return_integer2(void) ;
void test_mock_check_do_var_and_return_integer3(void) ;
void test_mock_check_do_var_and_return_integer4(void) ;
void test_mock_check_do_var_and_return_integer5(void) ;
void test_mock_check_do_var_and_return_not_integer1(void) ;
void test_mock_check_do_var_and_return_not_integer2(void) ;
void test_mock_check_do_var_and_return_not_integer3(void) ;
void test_mock_check_do_var_and_return_not_integer4(void) ;
void test_mock_check_do_var_and_return_not_integer5(void) ;
void test_mock_check_do_var_and_return_var_int1(void) ;
void test_mock_check_do_var_and_return_var_int2(void) ;
void test_mock_check_do_var_and_return_var_int3(void) ;
void test_mock_check_do_var_and_return_var_not_int1(void) ;
void test_mock_check_do_var_and_return_var_not_int2(void) ;
void test_mock_check_do_var_and_return_var_not_int3(void) ;

/* 
 * Suite 53 Tests - 
 * mock_check_and_set_do_var_or_num (turtle_interp.c) 
 */
int mock_check_and_set_do_var_or_num(Prog *p) ;
void test_mock_check_and_set_do_var_or_num_False1(void) ;
void test_mock_check_and_set_do_var_or_num_False2(void) ;
void test_mock_check_and_set_do_var_or_num_False3(void) ;
void test_mock_check_and_set_do_var_or_num_False4(void) ;
void test_mock_check_and_set_do_var_or_num_False5(void) ;
void test_mock_check_and_set_do_var_or_num_integer1(void) ;
void test_mock_check_and_set_do_var_or_num_integer2(void) ;
void test_mock_check_and_set_do_var_or_num_integer3(void) ;
void test_mock_check_and_set_do_var_or_num_integer4(void) ;
void test_mock_check_and_set_do_var_or_num_integer5(void) ;
void test_mock_check_and_set_do_var_or_num_var_int1(void) ;
void test_mock_check_and_set_do_var_or_num_var_int2(void) ;
void test_mock_check_and_set_do_var_or_num_var_int3(void) ;

/* 
 * Suite 54 Tests - 
 * mock_check_to_is_larger_than_from (turtle_interp.c) 
 */
int mock_check_to_is_larger_than_from(DoValues current) ; 
void test_mock_check_to_is_larger_than_from_False(void) ;
void test_mock_check_to_is_larger_than_from_True(void) ;

/* Suite 55 Tests - mock_do_loop (turtle_interp.c) */
void mock_do_loop(Prog *p, DoValues current) ; 
void test_mock_do_loop(void) ; 

/* Suite 56 Tests - mock_do_from_to (turtle_interp.c) */
unsigned int mock_do_from_to(Prog *p) ;
void test_mock_do_from_to_fail1(void) ;
void test_mock_do_from_to_fail2(void) ;
void test_mock_do_from_to_fail3(void) ;
void test_mock_do_from_to_fail4(void) ;
void test_mock_do_from_to_fail5(void) ;
void test_mock_do_from_to_fail6(void) ;
void test_mock_do_from_to_fail7(void) ;
void test_mock_do_from_to_fail8(void) ; 
void test_mock_do_from_to_fail9(void) ; 
void test_mock_do_from_to_pass1(void) ;
void test_mock_do_from_to_pass2(void) ;
void test_mock_do_from_to_pass3(void) ;
void test_mock_do_from_to_pass4(void) ;

/* Suite 57 Tests - mock_instruction (turtle_interp.c) */
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
 * Suite 58 Tests -
 * mock_instruction_list (turtle_interp.c) 
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
 * Suite 59 Tests - 
 * mock_interpreter_for_program_main (turtle_interp.c) 
 */
unsigned int mock_interpreter_for_program_main(Prog *p) ;
void test_mock_interpreter_for_program_main_incor1(void) ;
void test_mock_interpreter_for_program_main_incor2(void) ;
void test_mock_interpreter_for_program_main_incor3(void) ;
void test_mock_interpreter_for_program_main_empty_fle(void); 
void test_mock_interpreter_for_program_main_pass(void) ;
