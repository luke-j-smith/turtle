/* All function definitions used to interpret Turtle file.*/
#include "turtle_interp.h"

/* First interpreting function, starts recursive interp. */ 
void interpreter_for_program_main(Prog *p) 
{
  /* If file is empty, then report this. */ 
  if(p->totalStrs == 0){
    INTERP_ERROR(FILE_EMPTY, FileEmpty, p) ;   
  }

  /* If the first character is not correct, report this. */
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    INTERP_ERROR(NO_START_SYM, NoStartSym, p) ;   
  }
     
  /* Otherwise, continue parsing Turtle program. */  
  instruction_list(p) ; 
  
  /* 
   * REMOVE SDL FOR TESTING.
   * keep_sdl_until_finished(p->sw) ;  
   */

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
  
  else if(instruction(p)){
    /* After instruction, call again - recursive interp. */
    instruction_list(p) ; 
  } 
  
  else{
    INTERP_ERROR(INSTRN_LST, InstrnLst, p) ;
  }
     
  return ; 
}

/* Ensures we are not going beyond the program length. */
void check_within_program_bounds(Prog *p)
{
  unsigned int check ; 
  
  check = 0 ; 

  (p->place >= p->totalStrs) ? \
  (check = True) : (check = False) ; 

  if(check == True){
    INTERP_ERROR(NO_END_CHAR, NoEndChar, p) ; 
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
    if(is_var_or_num(p->program[p->place])){
      /* Interpret and make move as we parse. */
      make_move(p) ; 
      
      return Success ;  
    }
    else{
      INTERP_ERROR(IN_VAR_NUM, InstrnVarNum, p) ; 
    }
  }
  
  return Failure ; 
}

/* Ensures DO instruction has the correct structure. */ 
void do_from_to(Prog *p)
{
  DoValues current ; 

  check_within_program_bounds(p) ; 
    
  if(!str_same(p->program[(p->place)++], DO_START)){
    INTERP_ERROR(NO_DO_START, NoDoStart, p) ; 
  }
  
  /* Store the place of the variable in DO expression. */
  current.varPlace = check_do_var_and_return_place(p) ;
    
  if(!str_same(p->program[(p->place)++], DO_FROM)){
    INTERP_ERROR(NO_DO_FROM, NoDoFrom, p) ; 
  } 
  
  /* Store the integer value we are DO'ing FROM. */
  current.from = check_and_set_do_var_or_num(p) ; 
  
  (p->place)++ ; 
    
  if(!str_same(p->program[(p->place)++], DO_TO)){
    INTERP_ERROR(NO_DO_TO, NoDoTo, p) ; 
  }
  
  /* Store the integer value we are DO'ing TO. */
  current.to = check_and_set_do_var_or_num(p) ;    
  
  (p->place)++ ;   
  
  /* Ensure that TO integer >= FROM integer. */ 
  check_to_is_larger_than_from(p, current) ; 
    
  if(!str_same(p->program[p->place], OPENING_CHAR)){
    INTERP_ERROR(NO_DO_OPEN_EXP, NoDoOpenExp, p) ; 
  }  
    
  /* Interpret and carry out DO loop as we parse. */
  do_loop(p, current) ; 
    
  return ; 
}

/* Checks whether var. subject of DO and returns place. */
unsigned int check_do_var_and_return_place(Prog *p)
{
  if(!is_var(p->program[p->place])){
    INTERP_ERROR(NO_DO_VAR, NoDoVar, p) ; 
  }

  return (p->place)++ ; 
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

/* Checks DO TO and FROM is an integer and returns value. */
int check_and_set_do_var_or_num(Prog *p) 
{
  if(is_var_or_num(p->program[(p->place)])){
    /* If it is a variable or number, check it is an int. */
    check_do_var_or_num_valid(p) ;    
  } 
  else{
    INTERP_ERROR(NO_DO_VARNUM, NoDoVarNum, p) ; 
  }
  
  /* Return the integer value of variable or number. */
  return (int) value_of_var_or_num(p) ; 
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
    return type_of_number(negative, decimals) ;  
  }
  
  return False ; 
}

/* Determines what kind of number the string represents. */ 
unsigned int type_of_number(unsigned int n, unsigned int d)
{
  unsigned int type ; 
  
  /* Check that amount of decimals or negatives <= 1. */ 
  if(more_than_one_decimal_or_negative(n, d)){
    return False ;
  }
  
  /* 
   * determine_type_two_inputs() maps two values to one and 
   * RTN_NUM_OFFSET offsets result in line with ReturnType. 
   */
  type = determine_type_two_inputs(n, d) + RTN_NUM_OFFSET ;
  
  /* If a number, return the type. If not, return False. */
  switch(type){
    case NonNegInt : 
      return NonNegInt ; 
      
    case NegInt : 
      return NegInt ; 
      
    case NonNegFloat : 
      return NonNegFloat ; 
      
    case NegFloat : 
      return NegFloat ; 
      
    default : 
      return False ; 
  }

  return False ; 
}

/* Used to check that DO FROM and TO are integers. */ 
void check_do_var_or_num_valid(Prog *p)
{
  unsigned int strType ;
  double fraction, integer ; 
  
  /* Determine what string represents. */       
  strType = is_var_or_num(p->program[p->place]) ; 
  
  switch(strType){
    case Variable : 
      /* If variable is subject, check it is an int. */
      fraction = modf(read_var_value(p->program[p->place], \
      p), &integer) ; 
      check_if_integer(fraction, p) ;  
      break ; 
      
    /* If value is an integer then okay. */ 
    case NonNegInt :
    case NegInt :
      break ; 
      
    /* If value is not an integer then INTERP_ERROR. */ 
    case NonNegFloat :
    case NegFloat : 
      INTERP_ERROR(DO_FLOAT, DoFloat, p) ; 
      break ; 
      
    default : 
      INTERP_ERROR(NO_DO_VARNUM, NoDoVarNum, p) ; 
  }
  
  return ; 
}

/* Reads and returns value that of a defined variable. */
double read_var_value(char *str, Prog *p)
{
  unsigned int index ; 
  
  /* 
   * If string not variable name, then give code error as 
   * should have been flagged earlier as a parsing error. 
   */
  if(is_var(str) == False){
    free_program_memory(&p) ; 
    CODE_ERROR(VAR_READ_INCOR, VarReadIncor) ; 
  }
    
  /* Calculate correct index for p->var[] array for str. */
  index = determine_var_index(str[0]) ; 
    
  /* If ptr is null, parsing error as variable not set. */
  if(p->var[index] == NULL){
    INTERP_ERROR(VAR_NOT_SET, VarNotSet, p) ; 
  }

  return p->var[index]->value ; 
}

/* If decimal part of a number is >= FLOAT_DIF, not int. */
void check_if_integer(double fraction, Prog *p)
{
  if((fabs(fraction) - FLOAT_DIF >= 0)){
    INTERP_ERROR(DO_FLOAT, DoFloat, p) ; 
  }

  return ; 
}

/* For str that is a var. or num., determine its value. */
double value_of_var_or_num(Prog *p)
{
  double value = 0 ; 

  if(is_var(p->program[p->place])){
    value = read_var_value(p->program[p->place], p) ; 
  }

  else if(is_num(p->program[p->place])){
    value = read_number_value(p->program[p->place], p) ; 
  }
  
  else{
    free_program_memory(&p) ;
    CODE_ERROR(NO_VAR_OR_NUM, NoVarOrNum) ; 
  }

  return value ; 
}

/* If string is a number, quantify its value. */ 
double read_number_value(char *string, Prog *p) 
{
  double value ; 
  unsigned int length ; 
  char *strCopy = NULL, *end = NULL ; 
  
  if(is_num(string) == False){
    free_program_memory(&p) ;
    CODE_ERROR(NOT_VALID_NUM, NotValidNum) ; 
  }
  
  /* Create a copy of string as strtod destroys string. */ 
  length = strlen(string) + 1 ; 
  
  strCopy = memory_for_string(length) ; 
  
  if(pointer_is_null(strCopy)){
    free_program_memory(&p) ;
    CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
  }
  
  strcpy(strCopy, string) ; 
  
  value = strtod(strCopy, &end) ; 
  
  free(strCopy) ; 
  
  strCopy = NULL ; 
  
  return value ;  
}

/* Check that DO TO is greater than or equal to DO TO. */
void check_to_is_larger_than_from(Prog *p, DoValues current)
{
  if(current.from > current.to){
    INTERP_ERROR(DO_LARGER_FIRST, DoLargerFirst, p) ;
  }

  return ; 
}

/* Function used to carry out a DO loop. */
void do_loop(Prog *p, DoValues current)
{
  int i ; 
  
  current.startPlace = p->place ; 
  
  for(i = current.from ; i <= current.to ; i++){
    /* Update variables value each iteration. */
    set_var_value(p->program[current.varPlace], i, p) ;
    
    /* Return p->place to start of DO loop. */
    p->place = current.startPlace ;
    
    /* Carry out body of DO loop. */ 
    instruction_list(p) ;  
  }

  return ; 
}

/* Function used to define the value of a variable. */ 
void set_var_value(char *str, double value, Prog *p)
{
  unsigned int index ; 
    
  if(is_var(str) == False){
    free_program_memory(&p) ;
    CODE_ERROR(VAR_SET_INCOR, VarSetIncor) ; 
  }

  index = determine_var_index(str[0]) ; 
  
  /* If variable not previously set, allocate space. */ 
  if(p->var[index] == NULL){
    p->var[index] = (VarValue *)calloc(1, sizeof(VarValue));
  }

  p->var[index]->value = value ; 

  return ; 
}

/* Ensure SET has correct structure and perform operation.*/ 
void set(Prog *p) 
{
  unsigned int varPlace ;

  check_within_program_bounds(p) ; 
  
  if(!str_same(p->program[p->place], SET_START)){
    INTERP_ERROR(NO_SET_START, NoSetStart, p) ; 
  } 
  
  varPlace = ++(p->place) ; 

  if(!is_var(p->program[(p->place)++])){
    INTERP_ERROR(NO_SET_VAR, NoSetVar, p) ; 
  }

  if(!str_same(p->program[p->place], SET_DEFINE)){
    INTERP_ERROR(NO_SET_DEFINE, NoSetDefine, p) ; 
  } 
    
  set_up_stack_and_calculate_expression(p, varPlace) ; 
    
  return ; 
}

/* 
 * Creates the stack used to calculate a reverse polish 
 * expression and then calculates/sets the final value. 
 */
void set_up_stack_and_calculate_expression(Prog *p, \
unsigned int varPlace)
{
  unsigned int polishLength ; 

  polishLength = estimate_polish_length(p) ; 
  
  initialise_stack(p, polishLength) ; 

  polish(p) ; 
  
  get_final_value_from_stack(p) ; 
  
  set_var_value(p->program[varPlace], p->temp.value, p) ; 
  
  free_stack(&(p->s)) ; 
  
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
    /* If string is an operation, perform calculation. */ 
    update_stack(p, CALCULATION) ;
    check++ ; 
    polish(p) ; 
    return ; 
  }
  
  else if(is_var_or_num(p->program[p->place])){
    /* If string has a value, push onto stack. */ 
    update_stack(p, PUSH_ONLY) ; 
    check++ ; 
    polish(p) ; 
    return ; 
  }

  if(check == 0){
    INTERP_ERROR(NOT_POLISH, NotPolish, p) ;   
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

/* 
 * Used to updated the stack - either push a single value
 * or pop two, carry out calculation, and push result on. 
 */ 
void update_stack(Prog *p, int type)
{
  double tempValue ; 
  
  tempValue = 0.0 ; 
    
  switch(type){
    case CALCULATION : 
      tempValue = calculation(p, pop(p), pop(p)) ;
      break ; 
      
    case PUSH_ONLY :
      tempValue = value_of_var_or_num(p) ; 
      break ; 
      
    default : 
      free_program_memory(&p) ; 
      CODE_ERROR(UPDATE_STK_TYPE, UpdateStkType) ; 
  }

  push(p, tempValue) ;

  return ; 
}

/* Used to carry out the appropriate calculation. */ 
double calculation(Prog *p, double value1, double value2) 
{
  unsigned int i, operationType ; 
  double calc ; 
  char *operations[NUMBER_OF_OPS] = OP_SET ; 
  
  operationType = NoOperation ; 

  /* Determine the type of operation to be performed. */ 
  for(i = 0 ; i < NUMBER_OF_OPS ; i++){
    if(str_same(p->program[p->place], operations[i])){
      operationType = i ; 
    }
  }

  switch(operationType){
    case Addition : 
      calc = (value1 + value2) ; 
      break ; 
      
    case Subtraction : 
      calc = (value1 - value2) ; 
      break ;
       
    case Multiplication : 
      calc = (value1 * value2) ; 
      break ; 
      
    case Division : 
      check_if_division_by_zero(value2, p) ; 
      calc = (value1 / value2) ; 
      break ; 
      
    case NoOperation : 
      free_program_memory(&p) ;
      CODE_ERROR(NO_OP, NoOp) ; 
      break ; 
      
    default : 
      free_program_memory(&p) ;
      CODE_ERROR(INVALID_OP_TYPE, InvalidOpType) ; 
  }

  return calc ; 
}

/* Used to ensure that user is not trying to divide by 0. */
void check_if_division_by_zero(double divisor, Prog *p)
{
  if((fabs(divisor) - FLOAT_DIF) < 0){
    INTERP_ERROR(DIVISION_BY_ZERO, DivisionByZero, p) ; 
  }

  return ; 
}

/* Pops value off the stack and updates ToS values. */ 
double pop(Prog *p)
{
  /* If no values on stack, then too many operations. */
  if(p->s.top <= 0){
    INTERP_ERROR(TOO_MANY_OPS, TooManyOps, p) ;  
  }

  p->s.top = p->s.top - 1 ; 

  return p->s.stack[p->s.top].value ; 
}

/* Checks only one value in stack, if so, returns it. */ 
void get_final_value_from_stack(Prog *p)
{ 
  if(p->s.top == 1){
    p->temp.value = pop(p) ; 
  }
  else if(p->s.top > 1){
    /* If > 1 value on stack, then too few operations. */
    INTERP_ERROR(TOO_FEW_OPS, TooFewOps, p) ; 
  }
  else{
    INTERP_ERROR(TOO_MANY_OPS, TooManyOps, p) ;  
  }
  
  free_stack(&(p->s)) ; 

  return ; 
} 

/* Determines if string is a valid move. */ 
unsigned int is_move(Prog *p)
{
  int i ; 
  char *moves[NUMBER_OF_MOVES] = MOVE_SET ; 
  
  for(i = 0 ; i < NUMBER_OF_MOVES ; i++){
    if(str_same(p->program[p->place], moves[i])){  
      /* If set currentMove type and return True. */ 
      p->currentMove = i ;     
      
      (p->place)++ ; 
      
      return True ; 
    }
  }
  
  return False ; 
}

/* Used to calculate move variables and then make move. */
void make_move(Prog *p)
{
  double moveValue ; 
  
  moveValue = value_of_var_or_num(p) ; 

  if(p->currentMove == FD){
    /* If forward move, calculate the new Turtle position.*/ 
    calculate_next_position(&(p->turtle), moveValue) ;
    
    check_still_on_screen(p) ; 
    
    /*
     * update_sdl(p) ; - REMOVE SDL FOR CUNIT TESTING. 
     */
  }
  
  /* If not forward move, move must be a turn. */ 
  else{
    calculate_turn_amount(p, moveValue) ; 
  }

  return ; 
}

/* For a forward move, calculate new pos. and save prev. */
void calculate_next_position(TurtlePos *turtle, double dis)
{
  turtle->previous.x = turtle->current.x ; 
  
  turtle->previous.y = turtle->current.y ; 
  
  /* South and East is an increase in (x, y) coordinates. */
  turtle->current.x += (dis * sin(turtle->theta)) ; 
  
  turtle->current.y -= (dis * cos(turtle->theta)) ; 
  
  return ; 
}

/* Ensure that Turtle is still within the SDL window. */
void check_still_on_screen(Prog *p)
{
  /* INTERP_ERROR if gone off the right of the screen. */ 
  if(p->turtle.current.x > SDL_WIDTH){
    INTERP_ERROR(OFF_RIGHT_SCREEN, OffRightScreen, p) ; 
  }
  
  /* INTERP_ERROR if gone off the left of the screen. */ 
  if(p->turtle.current.x < 0){
    INTERP_ERROR(OFF_LEFT_SCREEN, OffLeftScreen, p) ; 
  }
  
  /* INTERP_ERROR if gone off the bottom of the screen. */ 
  if(p->turtle.current.y > SDL_HEIGHT){
    INTERP_ERROR(OFF_BOTTOM_SCREEN, OffBottomScreen, p) ; 
  }
  
  /* INTERP_ERROR if gone off the top of the screen. */ 
  if(p->turtle.current.y < 0){
    INTERP_ERROR(OFF_TOP_SCREEN, OffTopScreen, p) ; 
  }

  return ; 
}

/* Used to calculate turn amount and change direction. */ 
void calculate_turn_amount(Prog *p, double turnBy)
{
  double radians ; 
  
  switch(p->currentMove){
    case LT : 
      turnBy *= LEFT_TURN ; 
      radians = degrees_to_radians(turnBy) ; 
      break ; 
      
    case RT : 
      radians = degrees_to_radians(turnBy) ; 
      break ; 
      
    default : 
      free_program_memory(&p) ; 
      CODE_ERROR(UNEXPECTED_MOVE, UnexpectedMove) ; 
  }

  /* Update the current direction by making the turn. */ 
  p->turtle.theta += radians ; 

  return ; 
}

/* 
 * REMOVE SDL FROM CUNIT TESTING. 
void update_sdl(Prog *p)
{
  Neill_SDL_Events(&(p->sw)) ;
  
  if(!(p->sw.finished)){
    display_move_on_sdl(p->sw, p) ; 
  }

  return ; 
}


void display_move_on_sdl(SDL_Simplewin sw, Prog *p) 
{
  unsigned int i, xOld, yOld, xNew, yNew ; 

  xOld = (unsigned int) p->turtle.previous.x ; 
  yOld = (unsigned int) p->turtle.previous.y ; 
  xNew = (unsigned int) p->turtle.current.x ; 
  yNew = (unsigned int) p->turtle.current.y ; 

  i = 0 ; 
  
  do{
    SDL_Delay(MILLISECONDDELAY);

    Neill_SDL_SetDrawColour(&sw, SDL_R, SDL_G, SDL_B) ;
    
    SDL_RenderDrawLine(sw.renderer, xOld, yOld, xNew, yNew);
  
    SDL_RenderPresent(sw.renderer);
    
    SDL_UpdateWindowSurface(sw.win); 

    i++ ;
  } while(i < SDL_SCREEN_ITERATIONS) ;

  return ;
}

void keep_sdl_until_finished(SDL_Simplewin sw) 
{
  do{
    SDL_Delay(MILLISECONDDELAY);

    SDL_RenderPresent(sw.renderer);
    SDL_UpdateWindowSurface(sw.win); 
      
    Neill_SDL_Events(&sw);

  } while(!sw.finished) ;

   
  return ;
}
 * REMOVE SDL FROM CUNIT TESTING. 
 */
