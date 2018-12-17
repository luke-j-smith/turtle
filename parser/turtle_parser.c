/* All function definitions used to parse Turtle file. */
#include "turtle_parser.h"


/* First parsing function, starts recursive parsing. */ 
void parser_program_main(Prog *p) 
{
  /* If file is empty, then report this. */ 
  if(p->totalStrs == 0){
    PARSING_ERROR(FILE_EMPTY, FileEmpty, p) ;   
  }

  /* If the first character is not correct, report this. */
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    PARSING_ERROR(NO_START_SYM, NoStartSym, p) ;   
  }
  
  /* Otherwise, continue parsing Turtle program. */ 
  instruction_list(p) ; 

  return ; 
}

/* Recursively check main body of a Turtle program. */ 
void instruction_list(Prog *p)
{
  (p->place)++ ;
  
  check_within_program_bounds(p) ; 
  
  /* If closing character, then return straight away. */ 
  if(str_same(p->program[p->place], TERMINATING_CHAR)){ 
    return ; 
  }
  
  /* Check is current string represents an instruction. */ 
  else if(instruction(p)){
    /* After instruction, call again - recursive parser. */
    instruction_list(p) ; 
  } 
  
  /* If not closing char. or an instruction, then report. */
  else{
    PARSING_ERROR(INSTRN_LST, InstrnLst, p) ;
  }
     
  return ; 
}

/* Ensures we are not going beyond the length of program. */
void check_within_program_bounds(Prog *p)
{
  unsigned int check ; 
  
  check = 0 ; 

  (p->place >= p->totalStrs) ? \
  (check = True) : (check = False) ; 

  if(check == True){
    PARSING_ERROR(NO_END_CHAR, NoEndChar, p) ; 
  }

  return ; 
}

/* 
 * Determines if string is a valid instruction and then  
 * takes the appropriate path for instruction. 
 */ 
unsigned int instruction(Prog *p) 
{
  if(str_same(p->program[p->place], DO_START)){
    do_from_to(p) ;  
     
    return Success ; 
  }
  
  if(str_same(p->program[p->place], SET_START)){
    set(p) ; 
    
    return Success ; 
  }
  
  if(is_move(p)){
    if(!is_var_or_num(p->program[p->place])){
      PARSING_ERROR(IN_VAR_NUM, InstrnVarNum, p) ; 
    }
    else{
      return Success ; 
    }
  }
  
  return Failure ; 
}

/* Ensures DO instruction has the correct structure. */ 
void do_from_to(Prog *p)
{
  check_within_program_bounds(p) ; 
  
  if(!str_same(p->program[(p->place)++], DO_START)){
    PARSING_ERROR(NO_DO_START, NoDoStart, p) ; 
  } 
  
  if(!is_var(p->program[(p->place)++])){
    PARSING_ERROR(NO_DO_VAR, NoDoVar, p) ; 
  }
  
  if(!str_same(p->program[(p->place)++], DO_FROM)){
    PARSING_ERROR(NO_DO_FROM, NoDoFrom, p) ; 
  } 
    
  if(!is_var_or_num(p->program[(p->place)++])){
    PARSING_ERROR(NO_DO_VARNUM, NoDoVarNum, p) ; 
  }  
  
  if(!str_same(p->program[(p->place)++], DO_TO)){
    PARSING_ERROR(NO_DO_TO, NoDoTo, p) ; 
  }
    
  if(!is_var_or_num(p->program[(p->place)++])){
    PARSING_ERROR(NO_DO_VARNUM, NoDoVarNum, p) ; 
  } 
    
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    PARSING_ERROR(NO_DO_OPEN_EXP, NoDoOpenExp, p) ; 
  }  
  
  instruction_list(p) ;  
    
  return ; 
}

/* Determines whether string is a possible variable. */ 
unsigned int is_var(char *variable)
{
  /* If string is not correct length, then not variable. */ 
  if(strlen(variable) != VAR_LENGTH){
    return False ; 
  }

  /* Check if string belongs to set of variable names. */ 
  if(a_variable_name(variable)){
    return True ; 
  }

  /* If not, then string is not a correct variable name. */ 
  return False ; 
}

/* Determines if string is either a variable or number. */ 
unsigned int is_var_or_num(char *string)
{
  if(is_var(string)){
    return Variable ; 
  }
  
  return is_num(string) ; 
}

/* Determines whether string is a valid number number. */ 
unsigned int is_num(char *string) 
{
  unsigned int i, length, digits, decimals, negative ;
  
  digits = decimals = negative = 0 ; 
  length = strlen(string) ; 
  
  /* Check to see if string starts with negative symbol. */
  if(is_negative(string)){
    negative++ ; 
  }
  
  for(i = negative ; i < length ; i++){
    /* Count the number of digits (ie, '0'-'9') in string.*/ 
    if(isdigit(string[i])){
      digits++ ; 
    }
    /* Count the number of decimal points in string. */ 
    else if(string[i] == DECIMAL_POINT){
      decimals++ ; 
    }
  }
  
  /* If string only negative symbol (ie, "-"), not valid. */ 
  if(length == negative){
    return False ; 
  }

  /* 
   * A valid number iff string length is equal to the total
   * amount of negative, decimal and digit characters. 
   */ 
  if(length == (negative + decimals + digits)){
    /* Check that amount of decimals or negatives <= 1. */ 
    if(!more_than_one_decimal_or_negative(negative, \
    decimals)){
      return Number ;
    }
  }
  
  return False ; 
}

/* Ensures SET instruction has the correct structure. */ 
void set(Prog *p) 
{
  check_within_program_bounds(p) ; 
  
  if(!str_same(p->program[p->place], SET_START)){
    PARSING_ERROR(NO_SET_START, NoSetStart, p) ; 
  } 
  
  (p->place)++ ; 

  if(!is_var(p->program[p->place])){
    PARSING_ERROR(NO_SET_VAR, NoSetVar, p) ; 
  }

  (p->place)++ ; 

  if(!str_same(p->program[p->place], SET_DEFINE)){
    PARSING_ERROR(NO_SET_DEFINE, NoSetDefine, p) ; 
  } 
  
  polish(p) ; 
  
  return ; 
}

/* 
 * Ensures POLISH instruction has the correct structure
 * in recursive manner, as defined by grammar. 
 */ 
void polish(Prog *p)
{
  unsigned int check ;  
  
  /* Used to check current string is expected in polish. */ 
  check = 0 ; 
  
  (p->place)++ ; 
  
  check_within_program_bounds(p) ; 
      
  if(str_same(p->program[p->place], POLISH_TERM_CHAR)){
    return ; 
  }

  else if(is_op(p->program[p->place])){
    check++ ; 
    polish(p) ; 
    return ; 
  }
  
  else if(is_var_or_num(p->program[p->place])){
    check++ ; 
    polish(p) ; 
    return ; 
  }

  if(check == 0){
    PARSING_ERROR(NOT_POLISH, NotPolish, p) ;   
  }

  return ; 
}

/* Determines whether sting is a possible operation.*/
unsigned int is_op(char *string)
{
  int i ; 
  char *operationSet[NUMBER_OF_OPS] = OP_SET ; 

  /* Go through each possible operation and check is same.*/
  for(i = 0 ; i < NUMBER_OF_OPS ; i++){
    if(str_same(string, operationSet[i])){
      /* If match then return 1 as string is an operation.*/ 
      return True ; 
    }
  }
  
  /* Otherwise, the string not a possible operation. */ 
  return False ;
}

/* Determines if string is a valid move. */ 
unsigned int is_move(Prog *p)
{
  int i ; 
  char *moves[NUMBER_OF_MOVES] = MOVE_SET ; 
  
  for(i = 0 ; i < NUMBER_OF_MOVES ; i++){
    if(str_same(p->program[p->place], moves[i])){      
      (p->place)++ ; 
      
      /* If match then return 1 as string is a move. */ 
      return True ; 
    }
  }
  
  return False ; 
}
