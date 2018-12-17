/*
 * Header file containing the location of all files used to 
 * test functions in parser.c and parser_setup.c 
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

/* File that contains nothing at all. */ 
#define EMPTY_FILE "./test_files/empty_file.txt"

/* Files used in Suite 21 to test if string is a move. */ 
#define MOVE_INCOR1 "./test_files/move/is_move_incor1.txt"
#define MOVE_INCOR2 "./test_files/move/is_move_incor2.txt"
#define MOVE_INCOR3 "./test_files/move/is_move_incor3.txt"
#define MOVE_COR1 "./test_files/move/is_move_cor1.txt"
#define MOVE_COR2 "./test_files/move/is_move_cor2.txt"
#define MOVE_COR3 "./test_files/move/is_move_cor3.txt"

/* Files used in Suite 24 to test if polish(). */ 
#define POLISH_NO_END "./test_files/polish/pol_no_end.txt"
#define POLISH_INCOR1 "./test_files/polish/pol_incor1.txt"
#define POLISH_INCOR2 "./test_files/polish/pol_incor2.txt"
#define POLISH_INCOR3 "./test_files/polish/pol_incor3.txt"
#define POLISH_INCOR4 "./test_files/polish/pol_incor4.txt"
#define POLISH_COR1 "./test_files/polish/pol_cor1.txt"
#define POLISH_COR2 "./test_files/polish/pol_cor2.txt"
#define POLISH_COR3 "./test_files/polish/pol_cor3.txt"
#define POLISH_COR4 "./test_files/polish/pol_cor4.txt"
#define POLISH_COR5 "./test_files/polish/pol_cor5.txt"
#define POL_COR_PASS_1 1
#define POL_COR_PASS_2 2 
#define POL_COR_PASS_3 3 
#define POL_COR_PASS_4 4 
#define POL_COR_PASS_5 5 

/* Files used in Suite 25 to test if set(). */ 
#define SET_INCOR1 "./test_files/set/set_incor1.txt"
#define SET_INCOR2 "./test_files/set/set_incor2.txt"
#define SET_INCOR3 "./test_files/set/set_incor3.txt"
#define SET_INCOR4 "./test_files/set/set_incor4.txt"
#define SET_INCOR5 "./test_files/set/set_incor5.txt"
#define SET_COR1 "./test_files/set/set_cor1.txt"
#define SET_COR2 "./test_files/set/set_cor2.txt"
#define SET_COR3 "./test_files/set/set_cor3.txt"
#define SET_COR4 "./test_files/set/set_cor4.txt"
#define SET_COR5 "./test_files/set/set_cor5.txt"
#define SET_COR_PASS_1 4
#define SET_COR_PASS_2 6
#define SET_COR_PASS_3 4 
#define SET_COR_PASS_4 6 
#define SET_COR_PASS_5 13

/* Files used in Suite 26 to test if do_to_from(). */ 
#define DO_INCOR1 "./test_files/do/do_incor1.txt"
#define DO_INCOR2 "./test_files/do/do_incor2.txt"
#define DO_INCOR3 "./test_files/do/do_incor3.txt"
#define DO_INCOR4 "./test_files/do/do_incor4.txt"
#define DO_INCOR5 "./test_files/do/do_incor5.txt"
#define DO_INCOR6 "./test_files/do/do_incor6.txt"
#define DO_INCOR7 "./test_files/do/do_incor7.txt"
#define DO_COR1 "./test_files/do/do_cor1.txt"
#define DO_COR2 "./test_files/do/do_cor2.txt"
#define DO_COR3 "./test_files/do/do_cor3.txt"
#define DO_COR4 "./test_files/do/do_cor4.txt"
#define DO_NUM_STRS 7
#define DO_FAIL1_PLACE (DO_NUM_STRS - 6)
#define DO_FAIL2_PLACE (DO_NUM_STRS - 5)
#define DO_FAIL3_PLACE (DO_NUM_STRS - 4)
#define DO_FAIL4_PLACE (DO_NUM_STRS - 3)
#define DO_FAIL5_PLACE (DO_NUM_STRS - 2)
#define DO_FAIL6_PLACE (DO_NUM_STRS - 1)
#define DO_FAIL7_PLACE (DO_NUM_STRS - 1)

/* Files used in Suite 27 to test if instruction(). */ 
#define INST_INCOR1 "./test_files/instrn/instrn_incor1.txt"
#define INST_INCOR2 "./test_files/instrn/instrn_incor2.txt"
#define INST_INCOR3 "./test_files/instrn/instrn_incor3.txt"
#define INST_COR_FD "./test_files/instrn/instrn_cor_fd.txt"
#define INST_COR_LT "./test_files/instrn/instrn_cor_lt.txt"
#define INST_COR_RT "./test_files/instrn/instrn_cor_rt.txt"
#define INST_COR_DO "./test_files/instrn/instrn_cor_do.txt"
#define INST_COR_SE "./test_files/instrn/instrn_cor_set.txt"

/* Files used in Suite 28 to test if instruction_list(). */ 
#define LIST_INCOR1 "./test_files/list/list_incor1.txt"
#define LIST_INCOR2 "./test_files/list/list_incor2.txt"
#define LIST_INCOR3 "./test_files/list/list_incor3.txt"
#define LIST_COR1 "./test_files/list/list_cor1.txt"
#define LIST_COR2 "./test_files/list/list_cor2.txt"
#define LIST_COR3 "./test_files/list/list_cor3.txt"

/* Files used in Suite 29 to test if parser_program_main. */ 
#define MAIN_INCOR1 "./test_files/main/main_incor1.txt"
#define MAIN_INCOR2 "./test_files/main/main_incor2.txt"
#define MAIN_INCOR3 "./test_files/main/main_incor3.txt"
#define MAIN_COR "./test_files/main/main_cor.txt"

