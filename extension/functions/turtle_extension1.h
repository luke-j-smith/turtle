/* Header file for Turtle extension - turtle_extension1.c */
#include "turtle_interp1.h"

/* Used to identify the start for the main() function. */ 
#define PROG_MAIN "MAIN"

/* Used to define start of a function definition. */
#define DEFINE_FUNCTION "FUNC_DEF"

/* Symbols used to group and determine function inputs. */
#define FUNC_INPUT_START "("
#define FUNC_INPUT_END ")"
#define NUM_INPUT_BRACKS 2

/* Hash table must grow to be large enough for all funcs. */
#define multiply_by(current_size) (SIZE_INC * current_size)
#define SIZE_INC 2

/* Every number divisible by 1, so start search at 2. */ 
#define PRIME_CHECK_START 2 

#define no_remainder(a, b) ((a % b) == 0)

/* Prime if and only if divisible by 1 and itself. */ 
#define prime(divisible) (divisible == 2)

#define NOT_PRIME 1 
#define IS_PRIME 0

/* The forbidden strings that are defined in the grammar. */
#define FORBIDDEN_CHARS {PROG_MAIN, DEFINE_FUNCTION, \
FUNC_INPUT_START, FUNC_INPUT_END, EXPRESSION_TERM_CHAR, \
NEGATIVE_SYMBOL_STR, OPENING_CHAR, TERMINATING_CHAR, \
DO_START, DO_FROM, DO_TO, SET_START, SET_DEFINE, \
FUNCTION_START, "FD", "RT", "LT", "*", "/", "+"}
#define NUM_FORBIDDEN_CHARS 20
#define CHAR_LEN 9

/* Used to determine the function operation required. */ 
#define SET 1
#define CALL 2
#define RETURN 3

/*
 * Values used in the primary and secondary hash functions. 
 * Taken from: http://www.cse.yorku.ca/~oz/hash.html
 */
#define DJB2_START 5381
#define DJB2_BITWISE 5
#define SDBM_BITWISE1 6
#define SDBM_BITWISE2 16


void set_up_functions(Prog *p) ;
void locate_main_place(Prog *p) ;
void set_up_function_table(Prog *p) ; 
void count_number_functions_defined(Prog *p) ;
void create_function_hash_table(Prog *p) ;
unsigned int next_largest_prime(unsigned int current_size) ;
unsigned int next_prime(unsigned int current_number) ;
Func **memory_for_function_table(unsigned int size) ;
void contstruct_program_function_table(Prog *p) ;
void define_specific_function(Prog *p, unsigned int i) ;
void check_function_name(char *name, Prog *p) ;
unsigned int is_forbidden_char(char *name) ;
unsigned int find_table_index(char *name, Prog *p) ;
unsigned int double_hash(unsigned int index, \
unsigned int probe, Prog *p) ;
unsigned int primary_hash_function(char *str) ;
unsigned int secondary_hash_function(char *str) ;
Func *memory_for_function(void) ;
void set_function_name(unsigned int i, unsigned int index, \
Prog *p) ;
void determine_inputs(unsigned int i, unsigned int index, \
Prog *p);
unsigned int number_of_inputs(unsigned int i, Prog *p) ;
InputName **memory_for_inputs(unsigned int size) ;
void define_inputs(unsigned int input, unsigned int index, \
Prog *p, unsigned int choice) ;
InputName *memory_for_input(void) ; 
void check_input_name(char *name, Prog *p, \
unsigned int choice) ; 
void determine_function_end_place(unsigned int index, \
Prog *p) ;
unsigned int get_function_index(Prog *p) ; 
unsigned int keep_looking_for_function(unsigned int index, \
unsigned int probe, Prog *p) ; 
void call_function(Prog *p, unsigned int index) ; 
void replace_inputs(Prog *p, unsigned int index, \
unsigned int choice) ; 
void check_if_same(Prog *p, unsigned int index, \
unsigned int place, unsigned int choice) ; 
void swap(char **current, char **replace) ;
