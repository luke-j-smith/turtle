/* 
 * Extension to the Turtle grammar - allows for functions to
 * be defined (with inputs passed by reference) and used. 
 */
#include "turtle_extension1.h"

/* 
 * Checks to see if any functions declared, if so defines 
 * them in a hash table. 
 */
void set_up_functions(Prog *p)
{
  locate_main_place(p) ; 

  count_number_functions_defined(p) ; 
  
  /* If there are any functions, define them in a table. */
  if(p->totalFuncs > 0){
    create_function_hash_table(p) ; 
  }
  
  return ; 
} 

/* Locate the start of main, ie the string "MAIN". */ 
void locate_main_place(Prog *p)
{
  unsigned int i, check ; 
  
  check = False ; 
  
  for(i = 0 ; i < p->totalStrs ; i++){
    if(str_same(p->program[i], PROG_MAIN)){
      p->mainStart = i + 1 ; 
      
      check++ ; 
    }
  }

  /* If "MAIN"s in file is not exactly one, then error. */
  if(check == False){
    INTERP_ERROR(NO_MAIN, NoMain, p) ;  
  }
  else if(check > True){
    INTERP_ERROR(TOO_MANY_MAINS, TooManyMains, p) ;  
  }

  return ; 
}

/* Count the number of functions defined. */ 
void count_number_functions_defined(Prog *p) 
{
  unsigned int i ; 
   
  for(i = 0 ; i < p->totalStrs ; i++){
    if(str_same(p->program[i], DEFINE_FUNCTION)){
      (p->totalFuncs)++ ; 
    }
  }

  return ; 
}

/* Create a hash table to store each defined function. */
void create_function_hash_table(Prog *p) 
{  
  p->tableSize = next_largest_prime(p->totalFuncs) ; 

  p->funcTable = memory_for_function_table(p->tableSize) ;
  
  if(pointer_is_null(p->funcTable)){
    free_program_memory(&p) ; 
    CODE_ERROR(FUNC_TABLE_MEM, FuncTableMem) ; 
  }
    
  contstruct_program_function_table(p) ; 
  
  return ; 
}

/* Finds the next appropriate prime number for table size.*/ 
unsigned int next_largest_prime(unsigned int current_size)
{
  unsigned int prime = current_size ; 

  /* Check each subsequent prime, until large enough. */ 
  while(prime < multiply_by(current_size)){
    prime = next_prime(prime) ; 
  }
  
  return prime ; 
}

/* Finds the subsequent prime for any inputted number. */ 
unsigned int next_prime(unsigned int current_number)
{
  unsigned int i, divisible, check ; 
  
  check = NOT_PRIME ; 
  
  /* Check each subsequent number until a prime is found. */ 
  while(check == NOT_PRIME){
    current_number++ ; 
    /* All numbers divisible by 1, so set divisible = 1. */ 
    divisible = 1 ;
    /* Then start search from i = 2. */ 
    for(i = PRIME_CHECK_START ; i <= current_number ; i++){
      /* If there is no remainder, then divisible by i. */ 
      if(no_remainder(current_number, i)){
        divisible++ ; 
      }
    }
    
    /* Prime iff divisible by 1 and itself (divisible =2).*/
    if(prime(divisible)){
      check = IS_PRIME ; 
    }
  }
  
  return current_number ; 
}

/* Allocate space for a function table (with prime size). */
Func **memory_for_function_table(unsigned int size) 
{
  Func **funcTable = NULL ; 
  
  funcTable = (Func **)calloc(size, sizeof(Func *)) ; 
  
  return funcTable ; 
}

void contstruct_program_function_table(Prog *p) 
{
  unsigned int i ; 

  for(i = 0 ; i < p->totalStrs ; i++){  
    /* Locate each function definition in file. */
    if(str_same(p->program[i], DEFINE_FUNCTION)){
      define_specific_function(p, i) ; 
    }
  }
  
  return ; 
}

/* For each function, define it in the hash table. */
void define_specific_function(Prog *p, unsigned int i) 
{
  unsigned int index ; 
    
  check_function_name(p->program[++i], p) ; 
    
  index = find_table_index(p->program[i], p) ;

  p->funcTable[index] = memory_for_function() ; 
  
  if(pointer_is_null(p->funcTable[index])){
    free_program_memory(&p) ; 
    CODE_ERROR(FUNC_MEM, FuncMem) ; 
  }
  
  set_function_name(i, index, p) ; 
    
  determine_inputs(i++, index, p) ; 
      
  p->funcTable[index]->start = \
  i + p->funcTable[index]->totalInputs + NUM_INPUT_BRACKS ;
  
  determine_function_end_place(index, p) ; 
  
  return ; 
}

/* Ensure function has an acceptable name. */ 
void check_function_name(char *name, Prog *p) 
{
  /* Name cannot be a variable name or a number. */ 
  if(is_var_or_num(name)){
    INTERP_ERROR(FUNC_NAME_VARNUM, FuncNameVarNum, p) ; 
  }
  
  /* Name cannot be a string used elsewhere in the grammar*/ 
  if(is_forbidden_char(name)){
    INTERP_ERROR(FUNC_NAME_FORBID, FuncNameForbid, p) ; 
  }

  return ; 
}

/* 
 * Check if the function name is forbidden - not allowed
 * to be any string that is already defined in the grammar. 
 */ 
unsigned int is_forbidden_char(char *name)
{
  unsigned int i ; 
  char forbid[NUM_FORBIDDEN_CHARS][CHAR_LEN] = \
  FORBIDDEN_CHARS ; 

  for(i = 0 ; i < NUM_FORBIDDEN_CHARS ; i++){
    if(str_same(name, forbid[i])){
      return True ; 
    }
  }

  if(is_op(name)){
    return True ;  
  }

  return False ; 
}

/* Determine the hash table index based on functions name.*/
unsigned int find_table_index(char *name, Prog *p) 
{
  unsigned int index, probe ;
  
  index = (primary_hash_function(name) % p->tableSize) ;

  /* If element already exists, use a double hash. */ 
  if(p->funcTable[index] != NULL){
    probe = (secondary_hash_function(name) % p->tableSize) ;
    
    index = double_hash(index, probe, p) ; 
  }

  return index ; 
}

unsigned int double_hash(unsigned int index, \
unsigned int probe, Prog *p)
{
  int newIndex ; 
  
  newIndex = index ; 
  
  /* Ensure that the probe is not zero! */ 
  if(probe == 0){
    probe = 1 ; 
  }
  
  do{
    newIndex -= probe ; 
    
    if(newIndex < 0){
      newIndex += p->tableSize ; 
    }
    
  /* Keep looking until space in table is found. */   
  } while(p->funcTable[newIndex] != NULL) ; 

  return (unsigned int) newIndex ; 
}


/*
 * The djb2 hash function. Taken from the following website:
 * http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int primary_hash_function(char *str)
{
  unsigned int hash = DJB2_START ;
  int i, n = strlen(str) ;

  for(i = 0 ; i < n ; i++){
    hash = ((hash << DJB2_BITWISE) + hash) + str[i] ; 
  }

  /* Return value will need to be modded with table size.*/
  return hash ;
}

/*
 * The sdbm hash function. Taken from the following website:
 * http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int secondary_hash_function(char *str)
{
  unsigned int hash = 0 ; 
  int i, n = strlen(str) ; 

  for(i = 0 ; i < n ; i++){
    hash = str[i] + (hash << SDBM_BITWISE1) + \
    (hash << SDBM_BITWISE2) - hash;
  }

  /* Ensure that probe size is not zero. */ 
  if(hash == 0){
    return 1 ; 
  }

  /* Return value will need to be modded with table size.*/
  return hash ; 
}

/* Allocate memory for the defined function in hash table.*/
Func *memory_for_function(void)
{
  Func *function = NULL ; 
  
  function = (Func *)calloc(1, sizeof(Func)) ; 
  
  return function ; 
}

/* Define the functions name in the hash table. */
void set_function_name(unsigned int i, unsigned int index, \
Prog *p) 
{
  unsigned int nameLen ; 
  
  nameLen = strlen(p->program[i]) + 1 ; 

  p->funcTable[index]->name = memory_for_string(nameLen) ; 
  
  if(pointer_is_null(p->funcTable[index])){
    free_program_memory(&p) ; 
    CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
  }

  strcpy(p->funcTable[index]->name, p->program[i]) ; 

  return ; 
}

/* Identify number of inputs and their identifiers. */ 
void determine_inputs(unsigned int i, unsigned int index, \
Prog *p)
{
  unsigned numIns ; 

  if(!str_same(p->program[++i], FUNC_INPUT_START)){
    INTERP_ERROR(FUNC_INPUT_OPEN, FuncInputOpen, p) ; 
  }
    
  numIns = number_of_inputs(i++, p) ; 
    
  p->funcTable[index]->totalInputs = numIns ; 
  
  p->funcTable[index]->inputs = memory_for_inputs(numIns) ;
  
  if(pointer_is_null(p->funcTable[index]->inputs)){
    free_program_memory(&p) ; 
    CODE_ERROR(FUNC_INPUTS_MEM, FuncInputsMem) ; 
  }
      
  define_inputs(i, index, p, SET) ; 
  
  i += p->funcTable[index]->totalInputs ; 
    
  if(!str_same(p->program[i], FUNC_INPUT_END)){
    INTERP_ERROR(FUNC_INPUT_CLOSE, FuncInputClose, p) ; 
  }
  
  return ; 
} 

/* Determine the number of inputs. */ 
unsigned int number_of_inputs(unsigned int i, Prog *p) 
{
  unsigned int inputs ; 
  
  inputs = 0 ; 
  
  /* Keep looking while in file and stop at ")". */ 
  while((!str_same(p->program[++i], FUNC_INPUT_END)) && \
  (i < p->totalStrs)){  
    inputs++ ; 
  }
  
  return inputs ; 
}

/* Allocate memory for an array of inputs. */ 
InputName **memory_for_inputs(unsigned int size) 
{
  InputName **inputs = NULL ; 
  
  inputs = (InputName **)calloc(size, sizeof(InputName *)) ;
  
  return inputs ; 
}

void define_inputs(unsigned int input, unsigned int index, \
Prog *p, unsigned int choice) 
{
  unsigned int place, startPlace, endPlace, inputLen, i ; 
  
  startPlace = input ; 
  
  endPlace = startPlace + p->funcTable[index]->totalInputs ;
  
  i = 0 ; 
  
  /* For each input, either: */ 
  for(place = startPlace ; place < endPlace ; place++){ 
    inputLen = strlen(p->program[place]) + 1 ; 
        
    switch(choice){
      /* Set its defined name and allocate space for it. */ 
      case SET : 
        p->funcTable[index]->inputs[i] = memory_for_input();
        
        if(pointer_is_null(p->funcTable[index]->inputs[i])){
          free_program_memory(&p) ; 
          CODE_ERROR(INPUT_MEM, InputMem) ; 
        }

        check_input_name(p->program[place], p, SET) ; 

        p->funcTable[index]->inputs[i]->name = \
        memory_for_string(inputLen) ; 
        
        if(pointer_is_null(\
        p->funcTable[index]->inputs[i]->name)){
          free_program_memory(&p) ; 
          CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
        }
            
        strcpy(p->funcTable[index]->inputs[i]->name, \
        p->program[place]) ; 
        
        break ; 
      
      /* Or, define the input to function when called. */ 
      case CALL: 
        check_input_name(p->program[place], p, CALL) ; 

        p->funcTable[index]->inputs[i]->temp = \
        memory_for_string(inputLen) ; 
        
        if(pointer_is_null(\
        p->funcTable[index]->inputs[i]->temp)){
          free_program_memory(&p) ; 
          CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
        }
    
        strcpy(p->funcTable[index]->inputs[i]->temp, \
        p->program[place]) ; 
        
        break ; 
    
      default:
        free_program_memory(&p) ;
        CODE_ERROR(UNEXPECTED_INPUT, UnexpectedInput) ;  
    }
    
    i++ ; 
  }

  return ; 
}

/* Allocate memory for an input. */ 
InputName *memory_for_input(void) 
{
  InputName *input = NULL ; 
  
  input = (InputName *)calloc(1, sizeof(InputName)) ;
  
  return input ; 
}

/* Ensure functions inputs do not have a forbidden name. */  
void check_input_name(char *name, Prog *p, \
unsigned int choice)
{
  if(is_forbidden_char(name)){
    INTERP_ERROR(VAR_NAME_FORBID, VarNameForbid, p) ; 
  }
  
  if(choice == SET){
    if(is_var(name)){
      INTERP_ERROR(VAR_SET_VAR, VarSetVar, p) ; 
    }
  }

  return ; 
}

/* Defines the place in program where the function ends. */
void determine_function_end_place(unsigned int index, \
Prog *p) 
{
  unsigned int holdPlace ; 
  
  holdPlace = p->place ; 
  
  p->place = p->funcTable[index]->start ; 
  
  check_within_program_bounds(p) ; 
    
  if(!str_same(p->program[(p->place)++], OPENING_CHAR)){
    INTERP_ERROR(NO_START_SYM, NoStartSym, p) ; 
  }
  
  check_within_program_bounds(p) ; 
    
  while((!str_same(p->program[p->place], TERMINATING_CHAR) \
  && (p->place < p->totalStrs))){
    (p->place)++ ; 
  }
  
  check_within_program_bounds(p) ; 
    
  if(!str_same(p->program[p->place], TERMINATING_CHAR)){
    INTERP_ERROR(NO_END_CHAR, NoEndChar, p) ; 
  }
  
  p->funcTable[index]->end = p->place ; 
  
  p->place = holdPlace ;  
  
  return ; 
}

/* Ensures that the structure of function call is correct.*/ 
void function(Prog *p)
{
  unsigned int funcIndex, numInputs ; 
  
  if(!str_same(p->program[(p->place)++], FUNCTION_START)){
    INTERP_ERROR(NO_FUNC_START, NoFuncStart, p) ; 
  }
      
  check_function_name(p->program[p->place], p) ; 
    
  funcIndex = get_function_index(p) ; 
    
  (p->place)++ ; 

  if(!str_same(p->program[(p->place)], FUNC_INPUT_START)){
    INTERP_ERROR(FUNC_INPUT_OPEN, FuncInputOpen, p) ; 
  }
  
  numInputs = number_of_inputs((p->place)++, p) ;  
  
  /* Ensure that the correct number of inputs entered! */ 
  if(numInputs != p->funcTable[funcIndex]->totalInputs){
    INTERP_ERROR(INCOR_NUM_INPUTS, IncorNumInputs, p) ; 
  }
      
  define_inputs((p->place), funcIndex, p, CALL) ; 
  
  p->place += numInputs ; 
        
  if(!str_same(p->program[(p->place)++], FUNC_INPUT_END)){
    INTERP_ERROR(FUNC_INPUT_CLOSE, FuncInputClose, p) ; 
  }
    
  if(!str_same(p->program[(p->place)], POLISH_TERM_CHAR)){
    INTERP_ERROR(NO_FUNC_CALL_END, NoFuncCallEnd, p) ; 
  }
    
  call_function(p, funcIndex) ; 
  
  return ; 
}

/* When calling a function, find its hash table index. */ 
unsigned int get_function_index(Prog *p) 
{
  unsigned int index, probe ;
    
  index = (primary_hash_function(p->program[p->place]) % \
  p->tableSize) ;
   
  /* If not found immediately, then double hash and probe.*/  
  if(!str_same(p->program[p->place], \
  p->funcTable[index]->name)){
    
    probe = (secondary_hash_function(p->program[p->place]) \
    % p->tableSize) ;

    index = keep_looking_for_function(index, probe, p) ; 
  }

  return index ; 
}

unsigned int keep_looking_for_function(unsigned int index, \
unsigned int probe, Prog *p)
{
  int newIndex ; 
  
  newIndex = index ; 
  
  if(probe == 0){
    probe = 1 ; 
  }
  
  do{
    newIndex -= probe ; 
  
    if(newIndex < 0){
      newIndex += p->tableSize ; 
    }
    
    /* If element is empty, then function doesn't exist. */ 
    if(p->funcTable[newIndex] == NULL){
      INTERP_ERROR(FUNC_NOT_DEFINED, FuncNotDefined, p) ;  
    }
  
  /* Keep looking until function found in table. */ 
  } while(!str_same(p->program[p->place], \
  p->funcTable[newIndex]->name)) ; 

  return (unsigned int) newIndex ; 
}

/* Used when function called from within another function.*/
void call_function(Prog *p, unsigned int index)
{
  unsigned int currentPlace ; 
  
  /* Store the current place in program when called. */ 
  currentPlace = p->place ; 
  
  /* Go to the start position of function in memory. */ 
  p->place = p->funcTable[index]->start ; 

  /* Replace input identifiers with the actual inputs. */ 
  replace_inputs(p, index, CALL) ;  
  
  /* Carry out function instructions. */  
  interpreter_for_program_main(p) ; 
  
  /* Replace the actual inputs with input identifiers. */ 
  replace_inputs(p, index, RETURN) ;   
  
  /* Return to correct place in program memory after call.*/
  p->place = currentPlace ; 

  return ; 
}

/* Swap input identifiers with actual inputs & vice versa.*/ 
void replace_inputs(Prog *p, unsigned int index, \
unsigned int choice) 
{
  unsigned int place, start, end ; 
  
  /* Go from function start place in memory... */ 
  start = p->funcTable[index]->start ; 
  
  /* Until end place in memory of function. */ 
  end = p->funcTable[index]->end ; 
  
  /* Replace any input identifier, with actual input. */
  for(place = start ; place <= end ; place++){
    check_if_same(p, index, place, choice) ; 
  }
  
  return ; 
}

/* Check if input name is within the function definition. */
void check_if_same(Prog *p, unsigned int index, \
unsigned int place, unsigned int choice)
{
  unsigned int i ; 
  
  /* If so, ... */ 
  for(i = 0 ; i < p->funcTable[index]->totalInputs ; i++){
    switch(choice){
      /* When calling, replace identifier with input. */ 
      case CALL :         
        if(str_same(p->program[place], \
        p->funcTable[index]->inputs[i]->name)){
                
          swap(&(p->program[place]), \
          &(p->funcTable[index]->inputs[i]->temp)) ; 
            
        }
        break ; 
        
      /* When returning, replace input with identifier. */ 
      case RETURN :
        if(str_same(p->program[place], \
        p->funcTable[index]->inputs[i]->temp)){
        
          swap(&(p->program[place]), \
          &(p->funcTable[index]->inputs[i]->name)) ;
          
        } 
        break ; 
        
      default : 
        free_program_memory(&p) ; 
        CODE_ERROR(UNEXPECTED_CALL, UnexpectedCall) ; 
    }
  }
  
  return ; 
}

/* Swap two strings. */ 
void swap(char **current, char **replace)
{
  unsigned int replaceStrLen ; 
      
  replaceStrLen = strlen(*replace) + 1 ; 
  
  free(*current) ; 
  
  *current = memory_for_string(replaceStrLen) ; 
  
  if(pointer_is_null(current)){
    CODE_ERROR(NO_STR_MEM, NoStrMem) ; 
  }
  
  strcpy(*current, *replace) ;  
  
  return ; 
}


