/* Header file for turtle_parser.c for parsing Turtle. */
#include "turtle.h"
#include "turtle_parser_setup.h"

/* Returns the value 1 (True) if two strings are the same.*/ 
#define str_same(a, b) (strcmp(a, b) == 0) 

/* Open and close expressions chars defined by grammar. */ 
#define OPENING_CHAR "{"
#define TERMINATING_CHAR "}"

/* Variable must be only on character (ie, length 1). */ 
#define VAR_LENGTH 1 

/* If correct length, check it belongs to {A, ..., Z}. */ 
#define a_variable_name(str) \
((strcmp(str, FIRST_VAR_STR) >= 0) && \
(strcmp(str, LAST_VAR_STR) <= 0))

/* First and last variable names - in char and str form. */
#define FIRST_VAR 'A'
#define FIRST_VAR_STR "A"
#define LAST_VAR 'Z'
#define LAST_VAR_STR "Z"

/* Strings used in a DO expression as defined by grammar. */ 
#define DO_START "DO"
#define DO_FROM "FROM"
#define DO_TO "TO"

/* Strings used in a SET expression as defined by grammar.*/ 
#define SET_START "SET"
#define SET_DEFINE ":="

/* String used to end a reverse polish expression. */ 
#define POLISH_TERM_CHAR ";"

/* The possible arithmetic operations and number of them. */
#define NUMBER_OF_OPS 4 
#define OP_SET {"+", "-", "*", "/"}

/* Possible moves defined by grammar and number of them. */
#define NUMBER_OF_MOVES 3 
#define MOVE_SET {"FD", "LT", "RT"}

/* Used to check if string represents negative a number. */
#define is_negative(str) (str[0] == NEGATIVE_SYMBOL)
#define NEGATIVE_SYMBOL '-'
#define NEGATIVE_SYMBOL_STR "-"

#define DECIMAL_POINT '.'

/* If amount of decimals or negatives > 1, then not a num.*/
#define more_than_one_decimal_or_negative(n, d) \
((n > 1) || (d > 1)) 


void parser_program_main(Prog *p) ; 
void instruction_list(Prog *p) ; 
void check_within_program_bounds(Prog *p) ; 
unsigned int instruction(Prog *p) ;
void do_from_to(Prog *p) ;
unsigned int is_var(char *variable) ; 
unsigned int is_var_or_num(char *string) ;
unsigned int is_num(char *string) ;
void set(Prog *p) ;
void polish(Prog *p) ;
unsigned int is_op(char *string) ;
unsigned int is_move(Prog *p) ;
