/*
 * Header file containing the location of all files used to 
 * test functions in interp.c and interp_setup.c 
 */


/* File to test the behaviour in multiple Suites. */
#define TEST_FILE "./test_files/open_close_test_file.txt"
/* Used with file above to test behaviour of opened file. */
#define SEEK_JUMP 8
#define TEST_CHAR1 't'
/* Test the character two positions after the first. */
#define TEST_FILE_POS 14 
#define TEST_CHAR2 's' 
#define TEST_CHAR_TO_WRITE 'c'
/* First and second strings in the test file above. */ 
#define TEST_FILE_STRING1 "This"
#define TEST_FILE_STRING2 "is"
#define TEST_FILE_STRS 12

/* Used in Suites 18, 21, 27, 30 and 58. A blank file. */ 
#define EMPTY_FILE "./test_files/empty_file.txt"

/* Used in Suite 26 to test within_expression_and_file */ 
#define POL_TERM_FILE "./test_files/within_file_and_term/" \
"polish_terminating_character.txt"

/* Used in Suite 27 to test estimate_polish_length */ 
#define POL_LEN_FILE1 "./test_files/pol_len/pol_len1.txt"
#define POL_LEN_FILE2 "./test_files/pol_len/pol_len2.txt"
#define POL_LEN_FILE3 "./test_files/pol_len/pol_len3.txt"
#define POL_LEN_FILE4 "./test_files/pol_len/pol_len4.txt"
#define POL_LEN_FILE5 "./test_files/pol_len/pol_len5.txt"
#define POL_LEN1 2
#define POL_LEN2 5
#define POL_LEN3 7
#define POL_LEN4 9
#define POL_LEN5 11

/* Files used in Suite 28 to test if string is a move. */ 
#define MOVE_INCOR1 "./test_files/move/is_move_incor1.txt"
#define MOVE_INCOR2 "./test_files/move/is_move_incor2.txt"
#define MOVE_INCOR3 "./test_files/move/is_move_incor3.txt"
#define MOVE_COR1 "./test_files/move/is_move_cor1.txt"
#define MOVE_COR2 "./test_files/move/is_move_cor2.txt"
#define MOVE_COR3 "./test_files/move/is_move_cor3.txt"

/* Used in Suite 38 and 52 to test value_of_var_or_num */ 
#define VARNUM_INCOR1 \
"./test_files/varnum_value/varnum_incor1.txt"
#define VARNUM_INCOR2 \
"./test_files/varnum_value/varnum_incor2.txt"
#define VARNUM_INCOR3 \
"./test_files/varnum_value/varnum_incor3.txt"
#define VARNUM_INCOR4 \
"./test_files/varnum_value/varnum_incor4.txt"
#define VARNUM_INCOR5 \
"./test_files/varnum_value/varnum_incor5.txt"
#define VARNUM_VAR_COR \
"./test_files/varnum_value/varnum_var_cor.txt"
#define VARNUM_NUM_COR1 \
"./test_files/varnum_value/varnum_num_cor1.txt"
#define VARNUM_NUM_COR2 \
"./test_files/varnum_value/varnum_num_cor2.txt"
#define VARNUM_NUM_COR3 \
"./test_files/varnum_value/varnum_num_cor3.txt"
#define VARNUM_NUM_COR4 \
"./test_files/varnum_value/varnum_num_cor4.txt"
#define VARNUM_NUM_COR5 \
"./test_files/varnum_value/varnum_num_cor5.txt"
#define VARNUM_NUM_COR_VALUE1 81
#define VARNUM_NUM_COR_VALUE2 -90231
#define VARNUM_NUM_COR_VALUE3 013.7821
#define VARNUM_NUM_COR_VALUE4 -9102.2
#define VARNUM_NUM_COR_VALUE5 -.001

/* Used in Suite 40 to test calculation */ 
#define CALC_ADD "./test_files/calc/calc_add.txt"
#define CALC_SUB "./test_files/calc/calc_sub.txt"
#define CALC_MUL "./test_files/calc/calc_mul.txt"
#define CALC_DIV "./test_files/calc/calc_div.txt"

/* Files used in Suite 46 to test set_and_make_move(). */ 
#define SET_MAKE_TURN_FILE1 \
"./test_files/set_make_move/turn_file1.txt"
#define SET_MAKE_TURN_FILE2 \
"./test_files/set_make_move/turn_file2.txt"
#define SET_MAKE_TURN_FILE3 \
"./test_files/set_make_move/turn_file3.txt"
#define SET_MAKE_TURN_VAL1 78
#define SET_MAKE_TURN_VAL2 -33
#define SET_MAKE_TURN_VAL3 1045
#define SET_FWD_OFF_FILE \
"./test_files/set_make_move/fd_off.txt"
#define SET_FWD_ON_FILE \
"./test_files/set_make_move/fd_on.txt"

#define VAR_NAME_A "A"
#define VAR_NAME_B "B"
#define VAR_NAME_C "C"

/* 
 * Files used in Suite 47 and 48 to test polish() and 
 * set_up_stack_and_calculate_expression(), respectively. 
 */ 
#define POLISH_NUMS_ONLY_FILE1 \
"./test_files/polish/nums_only1.txt"
#define POLISH_NUMS_ONLY_CHARS1 6
#define POLISH_NUMS_ONLY_TOP1 1
#define POLISH_NUMS_ONLY_VAL1 25
#define POLISH_NUMS_ONLY_FILE2 \
"./test_files/polish/nums_only2.txt"
#define POLISH_NUMS_ONLY_CHARS2 4
#define POLISH_NUMS_ONLY_TOP2 1
#define POLISH_NUMS_ONLY_VAL2 2.5
#define POLISH_NUMS_ONLY_FILE3 \
"./test_files/polish/nums_only3.txt"
#define POLISH_NUMS_ONLY_CHARS3 5
#define POLISH_NUMS_ONLY_TOP3 2
#define POLISH_NUMS_ONLY_VAL3 10

#define POLISH_VARS_ONLY_FILE1 \
"./test_files/polish/vars_only1.txt"
#define POLISH_VARS_ONLY1_A 6
#define POLISH_VARS_ONLY1_B -13
#define POLISH_VARS_ONLY_CHARS1 4
#define POLISH_VARS_ONLY_TOP1 1
#define POLISH_VARS_ONLY_VAL1 -7
#define POLISH_VARS_ONLY_FILE2 \
"./test_files/polish/vars_only2.txt"
#define POLISH_VARS_ONLY2_A 1
#define POLISH_VARS_ONLY2_B 2
#define POLISH_VARS_ONLY_CHARS2 6
#define POLISH_VARS_ONLY_TOP2 1
#define POLISH_VARS_ONLY_VAL2 0
#define POLISH_VARS_ONLY_FILE3 \
"./test_files/polish/vars_only3.txt"
#define POLISH_VARS_ONLY3_C 100
#define POLISH_VARS_ONLY_CHARS3 5
#define POLISH_VARS_ONLY_TOP3 2
#define POLISH_VARS_ONLY_VAL3 200

#define POLISH_NUMS_VARS_FILE1 \
"./test_files/polish/num_vars1.txt"
#define POLISH_NUMS_VARS_A1 -1.5
#define POLISH_NUMS_VARS_CHARS1 4
#define POLISH_NUMS_VARS_TOP1 1
#define POLISH_NUMS_VARS_VAL1 -10.5
#define POLISH_NUMS_VARS_FILE2 \
"./test_files/polish/num_vars2.txt"
#define POLISH_NUMS_VARS_A2 0
#define POLISH_NUMS_VARS_CHARS2 4
#define POLISH_NUMS_VARS_TOP2 1
#define POLISH_NUMS_VARS_VAL2 0
#define POLISH_NUMS_VARS_FILE3 \
"./test_files/polish/num_vars3.txt"
#define POLISH_NUMS_VARS_A3 22
#define POLISH_NUMS_VARS_B3 -13
#define POLISH_NUMS_VARS_CHARS3 6
#define POLISH_NUMS_VARS_TOP3 1
#define POLISH_NUMS_VARS_VAL3 81
#define POLISH_NUMS_VARS_FILE4 \
"./test_files/polish/num_vars4.txt"
#define POLISH_NUMS_VARS_A4 1
#define POLISH_NUMS_VARS_B4 1
#define POLISH_NUMS_VARS_CHARS4 7
#define POLISH_NUMS_VARS_TOP4 2
#define POLISH_NUMS_VARS_VAL4 90

/* For defining and checking a var. in Suites 48 and 49. */ 
#define SET_UP_AND_CHECK_VAR "Z"

/* Files used in Suite 49 to test if set(). */ 
#define SET_INCOR1 "./test_files/set/set_incor1.txt"
#define SET_INCOR2 "./test_files/set/set_incor2.txt"
#define SET_INCOR3 "./test_files/set/set_incor3.txt"
#define SET_INCOR4 "./test_files/set/set_incor4.txt"
#define SET_INCOR5 "./test_files/set/set_incor5.txt"
#define SET_COR1 "./test_files/set/set_cor1.txt"
#define SET_COR_PASS_1 4
#define SET_COR_VAL_1 15
#define SET_COR2 "./test_files/set/set_cor2.txt"
#define SET_COR_PASS_2 6
#define SET_COR_VAL_2 -45
#define SET_COR3 "./test_files/set/set_cor3.txt"
#define SET_COR_PASS_3 8
#define SET_COR_VAL_3 1.25
#define SET_COR4 "./test_files/set/set_cor4.txt"
#define SET_COR_PASS_4 10
#define SET_COR_VAL_4 50.5
#define SET_COR5 "./test_files/set/set_cor5.txt"
#define SET_COR_PASS_5 10
#define SET_COR_VAL_5 -0.875

/* Used in Suite 51 to test check_do_var_and_return_place */ 
#define DO_VAR_RTN_PLACE_INCOR1 \
"./test_files/check_do_var_and_rtn/check_do_var_incor1.txt"
#define DO_VAR_RTN_PLACE_INCOR2 \
"./test_files/check_do_var_and_rtn/check_do_var_incor2.txt"
#define DO_VAR_RTN_PLACE_INCOR3 \
"./test_files/check_do_var_and_rtn/check_do_var_incor3.txt"
#define DO_VAR_RTN_PLACE_INCOR4 \
"./test_files/check_do_var_and_rtn/check_do_var_incor4.txt"
#define DO_VAR_RTN_PLACE_INCOR5 \
"./test_files/check_do_var_and_rtn/check_do_var_incor5.txt"
#define DO_VAR_RTN_PLACE_COR1 \
"./test_files/check_do_var_and_rtn/check_do_var_cor1.txt"
#define DO_VAR_RTN_PLACE_COR2 \
"./test_files/check_do_var_and_rtn/check_do_var_cor2.txt"
#define DO_VAR_RTN_PLACE_COR3 \
"./test_files/check_do_var_and_rtn/check_do_var_cor3.txt"
#define DO_VAR_RTN_PLACE_COR4 \
"./test_files/check_do_var_and_rtn/check_do_var_cor4.txt"
#define DO_VAR_RTN_PLACE_COR5 \
"./test_files/check_do_var_and_rtn/check_do_var_cor5.txt"
#define BUFFER1 1
#define BUFFER2 2
#define BUFFER3 3
#define BUFFER4 4
#define BUFFER5 5

/* Used in Suite 53 to test check_do_var_or_num_valid(). */ 
#define INTEGER_FILE1 \
"./test_files/check_do_var_num_valid/int1.txt"
#define INTEGER_VALUE1 0
#define INTEGER_FILE2 \
"./test_files/check_do_var_num_valid/int2.txt"
#define INTEGER_VALUE2 -101
#define INTEGER_FILE3 \
"./test_files/check_do_var_num_valid/int3.txt"
#define INTEGER_VALUE3 10902
#define INTEGER_FILE4 \
"./test_files/check_do_var_num_valid/int4.txt"
#define INTEGER_VALUE4 -9204
#define INTEGER_FILE5 \
"./test_files/check_do_var_num_valid/int5.txt"
#define INTEGER_VALUE5 76
#define NOT_INTEGER_FILE1 \
"./test_files/check_do_var_num_valid/not_int1.txt"
#define NOT_INTEGER_FILE2 \
"./test_files/check_do_var_num_valid/not_int2.txt"
#define NOT_INTEGER_FILE3 \
"./test_files/check_do_var_num_valid/not_int3.txt"
#define NOT_INTEGER_FILE4 \
"./test_files/check_do_var_num_valid/not_int4.txt"
#define NOT_INTEGER_FILE5 \
"./test_files/check_do_var_num_valid/not_int5.txt"
#define VARIABLE_NAME_A_FILE \
"./test_files/check_do_var_num_valid/variable_name.txt"
#define VAR_INT1 0
#define VAR_INT2 -99
#define VAR_INT3 1023
#define VAR_NOT_INT1 0.092
#define VAR_NOT_INT2 -9.2973
#define VAR_NOT_INT3 0.528

/* Files used in Suite ?? to test if do_to_from(). */ 
#define DO_INCOR1 "./test_files/do/do_incor1.txt"
#define DO_INCOR2 "./test_files/do/do_incor2.txt"
#define DO_INCOR3 "./test_files/do/do_incor3.txt"
#define DO_INCOR4 "./test_files/do/do_incor4.txt"
#define DO_INCOR5 "./test_files/do/do_incor5.txt"
#define DO_INCOR6 "./test_files/do/do_incor6.txt"
#define DO_INCOR7 "./test_files/do/do_incor7.txt"
#define DO_INCOR8 "./test_files/do/do_incor8.txt"
#define DO_INCOR9 "./test_files/do/do_incor9.txt"
#define DO_COR1 "./test_files/do/do_cor1.txt"
#define DO_COR2 "./test_files/do/do_cor2.txt"
#define DO_COR3 "./test_files/do/do_cor3.txt"
#define DO_COR4 "./test_files/do/do_cor4.txt"
#define DO_NUM_STRS 7
#define DO_FAIL1_PLACE (DO_NUM_STRS - 6)
#define DO_FAIL2_PLACE (DO_NUM_STRS - 6)
#define DO_FAIL3_PLACE (DO_NUM_STRS - 4)
#define DO_FAIL4_PLACE (DO_NUM_STRS - 4)
#define DO_FAIL5_PLACE (DO_NUM_STRS - 2)
#define DO_FAIL6_PLACE (DO_NUM_STRS - 2)
#define DO_FAIL7_PLACE (DO_NUM_STRS - 2)
#define DO_FAIL8_PLACE (DO_NUM_STRS - 1)
#define DO_FAIL9_PLACE (DO_NUM_STRS - 1)

#define DO_SET_CHAR1 "U"
#define DO_SET_CHAR1_VAL 60
#define DO_SET_CHAR2 "K"
#define DO_SET_CHAR2_VAL 101
#define DO_SET_CHAR3 "Z"
#define DO_SET_CHAR3_VAL 0
#define DO_SET_CHAR4 "O"
#define DO_SET_CHAR4_VAL 1

/* Files used in Suite 56 to test if instruction(). */ 
#define INST_INCOR1 "./test_files/instrn/instrn_incor1.txt"
#define INST_INCOR2 "./test_files/instrn/instrn_incor2.txt"
#define INST_INCOR3 "./test_files/instrn/instrn_incor3.txt"
#define INST_COR_FD "./test_files/instrn/instrn_cor_fd.txt"
#define INST_COR_LT "./test_files/instrn/instrn_cor_lt.txt"
#define INST_COR_RT "./test_files/instrn/instrn_cor_rt.txt"
#define INST_COR_DO "./test_files/instrn/instrn_cor_do.txt"
#define INST_COR_SE "./test_files/instrn/instrn_cor_set.txt"

/* Files used in Suite 58 to test if instruction_list(). */ 
#define LIST_INCOR1 "./test_files/list/list_incor1.txt"
#define LIST_INCOR2 "./test_files/list/list_incor2.txt"
#define LIST_INCOR3 "./test_files/list/list_incor3.txt"
#define LIST_COR1 "./test_files/list/list_cor1.txt"
#define LIST_COR2 "./test_files/list/list_cor2.txt"
#define LIST_COR3 "./test_files/list/list_cor3.txt"

/* Files used in Suite 59 to test if parser_program_main. */ 
#define MAIN_INCOR1 "./test_files/main/main_incor1.txt"
#define MAIN_INCOR2 "./test_files/main/main_incor2.txt"
#define MAIN_INCOR3 "./test_files/main/main_incor3.txt"
#define MAIN_COR "./test_files/main/main_cor.txt"

