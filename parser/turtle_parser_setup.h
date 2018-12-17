/*  
 * Header file for turtle_parser_setup.h - contains function
 * top lines and any #defines. 
 */ 
#include "turtle.h"

/* Assumed maximum length of string in file. */
#define MAX_STR_LEN 101

/* Set parsing starting position - string to parse first. */ 
#define STARTING_PLACE 0 

Prog *memory_for_Prog(void) ;
unsigned int pointer_is_null(void *pointer) ;
void set_up_program(Prog *p, FILE *progFile, char *argv1) ;
unsigned int open_file(FILE **progFile, char *argv1) ; 
unsigned int number_strings_in_file(FILE *progFile) ;
unsigned int string_length_too_long(char str[MAX_STR_LEN]) ; 
void initialise_Prog(Prog *p, FILE *progFile) ; 
char **memory_for_program(unsigned int size) ; 
unsigned int read_in_strings(FILE *progFile, Prog *p) ; 
char *memory_for_string(unsigned int strLen) ; 
void free_program_memory(Prog **p) ; 
unsigned int close_file(FILE **progFile) ; 
