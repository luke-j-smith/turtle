/* Header file for turtle.c, which contains main(). */ 
#ifndef TURTLE_H
#define TURTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "turtle_errors.h"

/* Expecting an executable file and txt Turtle file. */ 
#define EXPECTED_NUMBER_OF_COMMAND_LINE_ARGS 2

/* Return values used in functions that determine type. */
enum returnValue {False, True, Variable, Number} ; 
typedef enum returnValue ReturnValue ;

enum boolean {Failure, Success} ; 
typedef enum boolean Boolean ; 

/* Holds all information needed for parsing a Turtle prog.*/
struct prog{
  char **program ;  
  unsigned int totalStrs ;
  unsigned int place ; 
} ;
typedef struct prog Prog ;

#endif 
/* TURTLE_H */ 
