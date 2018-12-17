/*  
 * Header file for turtle_interp_setup.h - contains function
 * top lines and any #defines. 
 */ 
#include "turtle2.h"

/* 
 * Defines width and height of the SDL window. Note that 
 * WWIDTH and WHEIGHT take from neillsdl2.h 
 */ 
#define SDL_WIDTH WWIDTH
#define SDL_HEIGHT WHEIGHT

/* Define the delay for SDL window to update. */ 
#define MILLISECONDDELAY 10

/* Determines how long each move should stay on screen. */ 
#define SDL_SCREEN_ITERATIONS 2

#define INITIAL_PROGRAM_SIZE 3

/* Used to define Turtle colour. Currently white. */ 
#define SDL_R 255
#define SDL_G 255
#define SDL_B 255

/* Assumed maximum length of string in file. */
#define MAX_STR_LEN 101

/* Set parsing starting position - string to interp first.*/ 
#define STARTING_PLACE 0 

/* Set the starting value of the p->temp.value. */ 
#define STARTING_TEMP_VALUE 0

/* Set the starting move as no move (ie, none processed). */ 
#define NO_MOVE -1

/* Set the Turtle's starting position as centre of window.*/
#define TURTLE_STARTING_X (SDL_WIDTH / 2)
#define TURTLE_STARTING_Y (SDL_HEIGHT / 2)

/* Set the Turtle's starting direction as north. */
#define POINT_NORTH 0 

/* Set the stacks' s.top starting value. */ 
#define STACK_TOP_START_VALUE 0

/* Character used to signal end of an expression. */ 
#define EXPRESSION_TERM_CHAR ";"

#define DEGREES_IN_CIRCLE 360
#define HALF_DEGREES_IN_CIRCLE (DEGREES_IN_CIRCLE / 2)


Prog *memory_for_Prog(void) ;
unsigned int pointer_is_null(void *pointer) ;
void initialise_Prog(Prog *p) ; 
void initialise_turtle_position(TurtlePos *turtle) ;
char **memory_for_program(unsigned int size) ;
char *memory_for_string(unsigned int strLen) ;
unsigned int string_length_too_long(char str[MAX_STR_LEN]) ;
void free_program_memory(Prog **p) ;
void initialise_stack(Prog *p, unsigned int length) ;
void push(Prog *p, double value) ;
void free_stack(PolishStack *s) ;
double degrees_to_radians(double degrees) ;
