/*  
 * Header file for turtle_interp_setup.h - contains function
 * top lines and any #defines. 
 */ 
#include "turtle.h"

/* Define Pi */ 
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
/* M_PI */ 

/* 
 * Defines width and height of the SDL window. Note that 
 * WWIDTH and WHEIGHT take from neillsdl2.h 
 */ 
#define SDL_WIDTH 800
#define SDL_HEIGHT 600

/* Define the delay for SDL window to update. */ 
#define MILLISECONDDELAY 10

/* Determines how long each move should stay on screen. */ 
#define SDL_SCREEN_ITERATIONS 2

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
void set_up_program(Prog *p, FILE *progFile, char *argv1) ;
unsigned int open_file(FILE **progFile, char *argv1) ;
unsigned int number_strings_in_file(FILE *progFile) ;
unsigned int string_length_too_long(char str[MAX_STR_LEN]) ;
void initialise_Prog(Prog *p, FILE *progFile) ;
void initialise_turtle_position(TurtlePos *turtle) ;
char **memory_for_program(unsigned int size) ;
unsigned int read_in_strings(FILE *progFile, Prog *p) ;
char *memory_for_string(unsigned int strLen) ;
void free_program_memory(Prog **p) ;
unsigned int close_file(FILE **progFile) ;
unsigned int estimate_polish_length(Prog *p) ;
unsigned int within_expression_and_file(unsigned int place,\
Prog *p) ;
void initialise_stack(Prog *p, unsigned int length) ;
void push(Prog *p, double value) ;
void free_stack(PolishStack *s) ;
double degrees_to_radians(double degrees) ;
