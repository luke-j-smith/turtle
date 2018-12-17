/* Header file for turtle.c, which contains main(). */ 
#ifndef TURTLE_H
#define TURTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "turtle_errors.h"
#include "neillsdl2.h"

/* Returns the value 1 if two strings are the same. */ 
#define str_same(a, b) (strcmp(a, b) == 0) 

/* Expecting an executable file and txt Turtle file. */ 
#define EXPECTED_NUMBER_OF_COMMAND_LINE_ARGS 2

/* 
 * If the absolute difference between two floating point 
 * number is less than FLOAT_DIF, consider them equal. 
 */
#define FLOAT_DIF 0.000001

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

/* Total number of possible variables. */ 
#define NUMBER_OF_VARS (LAST_VAR - FIRST_VAR + 1) 

/* 
 * Variety of return values used functions that determine 
 * string type. Thus, can specifically identify string type. 
 */
enum returnValue {False, True, Variable, NonNegInt, NegInt,\
NonNegFloat, NegFloat} ; 
typedef enum returnValue ReturnValue ; 

/* Add to ReturnValue to get to first Number type (ie, 3+)*/
#define RTN_NUM_OFFSET 3

enum boolean {Failure, Success} ; 
typedef enum boolean Boolean ; 

/* Variables are defined as having a value of type double.*/
struct varValue{
  double value ; 
} ; 
typedef struct varValue VarValue ; 

/* The coordinates of the Turtle on the SDL screen. */ 
struct coordinates{
  double x ; 
  double y ; 
} ; 
typedef struct coordinates Coordinates ; 

/* Stores information about Turtles position on screen. */
struct turtlePosition{
  Coordinates current ; 
  Coordinates previous ; 
  double theta ; 
} ; 
typedef struct turtlePosition TurtlePos ; 

/* Stack structure used to calculate polish expressions. */
struct polishStack{
  VarValue *stack ; 
  unsigned int size ; 
  unsigned int top ; 
} ; 
typedef struct polishStack PolishStack ; 

/* Contains all information needed for Turtle program. */ 
struct prog{
  char **program ;  
  unsigned int totalStrs ;
  unsigned int place ;  
  VarValue temp ;
  VarValue *var[NUMBER_OF_VARS] ; 
  PolishStack s ; 
  int currentMove ;
  TurtlePos turtle ;  
  SDL_Simplewin sw ; 
} ;
typedef struct prog Prog ;

/* Used to store relevant values for a DO loop. */ 
struct doValues{
  int from ; 
  int to ; 
  unsigned int startPlace ; 
  unsigned int varPlace ; 
} ; 
typedef struct doValues DoValues ; 

#endif 
/* TURTLE_H */
