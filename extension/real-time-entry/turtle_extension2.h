/* Header file for Turtle extension - turtle_extension2.c */
#include "turtle_interp_setup2.h"

/* Used to determine when current program is at capacity. */
#define at_capacity(a, b) ((b - a) < ENOUGH_SPACE_LEFT)
#define ENOUGH_SPACE_LEFT 5

/* Used to define how much larger the new program is. */ 
#define CAPACITY_INCREASE 1.5
#define new_capacity(size) (size * CAPACITY_INCREASE) 

/* Defines users wants to end program (and maybe save). */ 
#define END_SQUENCE "END"
#define SAVE_FILE_SEQUENCE "SAVE"

/* If saving, append the file name with a file type. */ 
#define FILE_TYPE ".txt"

/* Used to determine when certain file formatting. */ 
#define MOVES {"FD", "RT", "LT"}
#define NUM_OF_MOVES 3
#define NEW_LINE_SET {"{", "}", ";"}
#define NUM_NEW_LINE_CHARS 3

/* File formatting - new lines and indentation. */ 
#define SINGLE_NEW_LINE_AND_SPACE "\n  "
#define DOUBLE_NEW_LINE_AND_SPACE "\n\n  "
#define PENULTIMATE(place, total) (place == total - 2) 
#define END_FORMAT_STEP_BACK -2
#define END_FORMAT "\n"


unsigned int read_in_string_from_command(Prog *p) ; 
void check_if_end_sequence(char str[MAX_STR_LEN], Prog *p) ;
void add_string_to_program(char str[MAX_STR_LEN], Prog *p) ;
void check_program_capacity(Prog *p) ;
void create_new_program_array(Prog *p) ;
void transfer_words(char **new, char **old, Prog *p) ;
void create_and_save_file(Prog *p) ; 
void fill_file(Prog *p, char *name) ; 
void file_formatting(FILE *save, Prog *p, \
unsigned int place) ; 
