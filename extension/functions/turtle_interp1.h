#include "turtle_interp_setup1.h"


/* Open and close expressions chars defined by grammar. */ 
#define OPENING_CHAR "{"
#define TERMINATING_CHAR "}"

/* Strings used in a DO expression as defined by grammar. */ 
#define DO_START "DO"
#define DO_FROM "FROM"
#define DO_TO "TO"
/* Set containing the strings used to define DO structure.*/
#define DO_STRCT {DO_START, DO_FROM, DO_TO, \
OPENING_CHAR}
#define NUM_DO_STRCT DoStructFine
#define STRCT_STR_LEN 5

/* Strings used in a SET expression as defined by grammar.*/ 
#define SET_START "SET"
#define SET_DEFINE ":="

/* String used to end a reverse polish expression. */ 
#define POLISH_TERM_CHAR ";"

/* Used to define when calling a function from MAIN. */ 
#define FUNCTION_START "FUNC"

/* The defined operations (for Polish) and number of them.*/
#define NUMBER_OF_OPS 4 
#define OP_SET {"+", "-", "*", "/"}

/* Return values used to identify the type of operation. */
enum opType {Addition, Subtraction, Multiplication, \
Division, NoOperation} ; 
typedef enum opType OpType ;

/* Possible moves defined by grammar and number of them. */
#define NUMBER_OF_MOVES 3 
#define MOVE_SET {"FD", "LT", "RT"}

/* Return values used to identify the type of move. */
enum moveValue {FD, LT, RT} ; 
typedef enum moveValue MoveValue ; 

/* Used to check if string represents negative a number. */
#define is_negative(str) (str[0] == NEGATIVE_SYMBOL)
#define NEGATIVE_SYMBOL '-'
#define NEGATIVE_SYMBOL_STR "-"

#define DECIMAL_POINT '.'

/* If amount of decimals or negatives > 1, then not a num.*/
#define more_than_one_decimal_or_negative(n, d) \
((n > 1) || (d > 1)) 

/* Formula used to produce single value from two inputs. */ 
#define determine_type_two_inputs(x, y) ((x * 1) + (y * 2))

/* Used to calculate the correct index for variable array.*/
#define determine_var_index(c) (c - FIRST_VAR)

/* Used to determine  type of stack operation to perform. */
#define CALCULATION 2
#define PUSH_ONLY 3

/* Left turn is anti-clockwise, so need to multiple by -1.*/
#define LEFT_TURN -1 


void interpreter_for_program_main(Prog *p) ; 
void instruction_list(Prog *p) ; 
void check_within_program_bounds(Prog *p) ; 
unsigned int instruction(Prog *p) ;
void do_from_to(Prog *p) ; 
unsigned int check_do_var_and_return_place(Prog *p) ; 
unsigned int is_var(char *variable) ; 
int check_and_set_do_var_or_num(Prog *p) ; 
unsigned int is_var_or_num(char *string) ; 
unsigned int is_num(char *string) ; 
unsigned int type_of_number(unsigned int n, unsigned int d);
void check_do_var_or_num_valid(Prog *p) ; 
double read_var_value(char *str, Prog *p) ; 
void check_if_integer(double fraction, Prog *p) ; 
double value_of_var_or_num(Prog *p) ;
double read_var_value(char *str, Prog *p) ;
double read_number_value(char *string, Prog *p) ;
void check_to_is_larger_than_from(Prog *p, DoValues cur) ;
void do_loop(Prog *p, DoValues current) ;
void set_var_value(char *str, double value, Prog *p) ;
void set(Prog *p) ;
void set_up_stack_and_calculate_expression(Prog *p, \
unsigned int varPlace) ;
void polish(Prog *p) ;
void function(Prog *p) ; 
unsigned int is_op(char *string) ;
void update_stack(Prog *p, int type) ;
double calculation(Prog *p, double value2, double value1) ;
void check_if_division_by_zero(double divisor, Prog *p) ;
double pop(Prog *p) ;
void get_final_value_from_stack(Prog *p) ;
unsigned int is_move(Prog *p) ;
void make_move(Prog *p) ;
void calculate_next_position(TurtlePos *turtle, double dis);
void check_still_on_screen(Prog *p) ;
void update_sdl(Prog *p) ; 
void display_move_on_sdl(SDL_Simplewin sw, Prog *p) ;
void calculate_turn_amount(Prog *p, double turnBy) ;
void keep_sdl_until_finished(SDL_Simplewin sw) ;
