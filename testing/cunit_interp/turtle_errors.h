/* 
 * Header file contains the #defines for exiting when there
 * is an error, including messages and error types. 
 */ 

/* CODE_ERROR used for issues with the underlying C code. */ 
#define CODE_ERROR(message, type) {fprintf(stderr, message,\
type) ; exit(type) ; }

/* CODE_ERROR types to allow for error identification. */ 
enum codeError {NoCodeError, Argc, ProgMem, NotOpened, \
StrLong, FSeek, ProgContMem, NoStrMem, FileSize, NotClosed,\
StackMem, StackFull, StackFree, VarReadIncor, NoVarOrNum, \
NotValidNum, VarSetIncor, UpdateStkType, NoOp, \
InvalidOpType, UnexpectedMove} ; 
typedef enum codeError CodeError ; 

/* CODE_ERROR messages to be printed with respective type.*/
#define ARGC "\nERROR: %d - Expecting two arguments on " \
"command line.\nPrecisely, an executable followed by file" \
" (containing a Turtle program) is required.\n\n" 
#define PROG_MEM "\nERROR: %d - Unable to allocate " \
"enough memory for a Prog pointer *p (type Prog **).\n\n"
#define NOT_OPENED "\nERROR: %d - Unable to open file.\n\n" 
#define STR_LONG "\nERROR: %d - File contains a string " \
"that is longer than the maximum assumed length of 100 " \
"used when checking how many strings are in the file.\n" \
"Please either check file, or increase MAX_STR_LEN.\n\n"
#define FSEEK "\nERROR: %d - Unable to return file " \
"file position of the stream to beginning of the file.\n\n"
#define PROG_CONT_MEM "\nERROR: %d - Unable to allocate " \
"enough memory for a p->program (type char **) ptr.\n\n"
#define NO_STR_MEM "\nERROR: %d - Unable to allocate " \
"enough memory for a string (type char *).\n\n"
#define FILE_SIZE "\nERROR: %d - The program size (ie, " \
"the number of strings in file does not match the number " \
"of strings being read into p->program.\n\n"
#define NOT_CLOSED "\nERROR: %d - Unable to close file.\n\n"
#define STACK_MEM "\nERROR: %d - Unable to allocate " \
"enough memory for a s->stack ptr (type VarValue *).\n\n"
#define STACK_FULL "\nERROR: %d - Trying to push onto a " \
"full stack (ie, s.top < s.size).\n\n"
#define STACK_FREE "\nERROR: %d - Unable to set stack " \
"pointer, s->stack, to NULL in free_stack().\n\n"
#define VAR_READ_INCOR "\nERROR: %d - Variable name " \
"for the variable attempting to be read in " \
"read_var_value() is incorrect.\nThis is should have been" \
"flagged as an incorrect name before this point.\n\n"
#define NO_VAR_OR_NUM "\nERROR: %d - Expecting string to " \
"either be a variable or valid number, however, it is not."\
"\nThis should have been flagged a as a parsing error " \
"before reaching this point.\n\n"
#define NOT_VALID_NUM "\nERROR: %d - String that is " \
"attempting to be read as a number, does not represent a " \
"a valid number.\nThis should have been flagged as a " \
"parsing error before reaching this point.\n\n"
#define VAR_SET_INCOR "\nERROR: %d - Variable name " \
"for the variable attempting to be set in " \
"set_var_value() is incorrect.\nThis is should have been" \
"flagged as an incorrect name before this point.\n\n"
#define UPDATE_STK_TYPE "\nERROR: %d - Unexpected type " \
"of operation to be performed by update_stack().\n\n"
#define NO_OP "\nERROR: %d - String being checked is not" \
" an operation.\nString should not have been passed to " \
"to the calculation() function.\n\n"
#define INVALID_OP_TYPE "\nERROR: %d - Unexpected " \
"operation type set in calculation() function.\n\n"
#define UNEXPECTED_MOVE "\nERROR: %d - Unexpected type of" \
" move in calculate_turn_amount().\nShould either be LT" \
" or RT.\n\n"

/* 
 * INTERP_ERROR used when Turtle grammar or semantics are 
 * not obeyed. Frees memory, display error type and advice. 
 */
#define INTERP_ERROR(message, type, p) \
{fprintf(stderr, message, type, (p->place + 1)) ; \
free_program_memory(&p) ; p = NULL ; exit(type) ; }

/* INTERP_ERROR types to allow for error identification. */ 
enum interpreterError {InterpOk, FileEmpty, NoStartSym, \
NoEndChar, InstrnLst, NoDoStart, NoDoVar, NoDoFrom, \
NoDoVarNum, NoDoTo, NoDoOpenExp, NoSetStart, NoSetVar, \
NoSetDefine, NotPolish, InstrnVarNum, DoFloat, VarNotSet, \
DoLargerFirst, DivisionByZero, TooManyOps, TooFewOps, \
OffRightScreen, OffLeftScreen, OffBottomScreen, \
OffTopScreen} ; 
typedef enum interpreterError InterpreterError ;

/* INTERP_ERROR messages details issue and gives advice. */ 
#define FILE_EMPTY "\nParsing Error: %d - File appears to" \
" be empty.\nError occurred at string: %d.\n\n"
#define NO_START_SYM "\nParsing Error: %d - Expecting " \
"the start of program symbol \"{\".\n Error occurred at " \
"string: %d.\n\n"
#define NO_END_CHAR "\nParsing Error: %d - Trying to parse"\
" a string that does not exist - ie, a terminating symbol" \
"(\"}\") is expected.\nInsert } in position: %d.\n\n"
#define INSTRN_LST "\nParsing Error: %d - Expecting " \
"either an instruction (ie, \"FD\", \"LT\", \"RT\", \"DO\""\
", or \"SET\") or the terminating character (ie, \";\").\n"\
"Error occurred at string: %d.\n\n"
#define NO_DO_START "\nParsing Error: %d - Expecting the "\
"string \"DO\" to begin a DO expression.\n Error " \
"occurred at string: %d.\n\n"
#define NO_DO_VAR "\nParsing Error: %d - Expecting a " \
"variable [A-Z] to be the subject of a DO expression - " \
"need variable to set.\nError occurred at string: %d.\n\n"
#define NO_DO_FROM "\nParsing Error: %d - Expecting the "\
"string \"FROM\" to construct a DO expression.\n Error " \
"occurred at string: %d.\n\n"
#define NO_DO_VARNUM "\nParsing Error: %d - Expecting a " \
"variable [A-Z] or an integer to be one of the " \
"subjects of a DO expression - need variable or number to" \
" DO from or to.\nError occurred at string: %d.\n\n"
#define NO_DO_TO "\nParsing Error: %d - Expecting the "\
"string \"TO\" to construct a DO expression.\n Error " \
"occurred at string: %d.\n\n"
#define NO_DO_OPEN_EXP "\nParsing Error: %d - Expecting " \
"an \"{\" to open an expression after a DO statement.\n" \
"Error occurred at string: %d.\n\n"
#define NO_SET_START "\nParsing Error: %d - Expecting the "\
"string \"SET\" to begin a SET expression.\n Error " \
"occurred at string: %d.\n\n"
#define NO_SET_VAR "\nParsing Error: %d - Expecting a " \
"variable [A-Z] to be the subject of a SET expression - " \
"need variable to set.\nError occurred at string: %d.\n\n"
#define NO_SET_DEFINE "\nParsing Error: %d - Expecting the"\
"define symbol  \":=\" to define a variable in SET " \
"expression.\n Error occurred at string: %d.\n\n"
#define NOT_POLISH "\nParsing Error: %d - Expecting a " \
"Reverse Polish expression.\n Either: (i) an operation; " \
"(ii) a variable; or (iii) the terminating character " \
"(ie, ';') is expected.\n Error occurred at string: %d.\n\n"
#define IN_VAR_NUM "\nParsing Error: %d - Expecting either"\
" a variable (ie, [A-Z]) or a non-negative number to " \
"follow after move instruction (ie, after a \"FD\", " \
"\"LT\", \"RT\"). Error occurred at string: %d\n\n"
#define DO_FLOAT "\nInterpreter Error: %d - Expecting an " \
"integer (or variable) to be one of the subjects of a DO " \
"expression.\nCannot accept a floating point number.\n" \
"Error occurred at string: %d.\n\n"
#define VAR_NOT_SET "\nInterpreter Error: %d - Variable " \
"has not been set/defined before being used in an " \
"expression.\nError occurred at string: %d.\n\n"
#define DO_LARGER_FIRST "\nInterpreter Error: %d - In the "\
"DO expression: DO 'A' FROM 'X' TO 'Y' {, 'Y' must be " \
"greater than or equal to 'X'.\nIn your expression 'Y' < " \
"'X'. Please correct this.\nError occurred at string: " \
"%d.\n\n"
#define DIVISION_BY_ZERO "\nInterpreter Error: %d - " \
"Attempting to divide by zero!\nThis is not possible, " \
"please correct your code.\nError occurred at string: " \
"%d.\n\n"
#define TOO_MANY_OPS "\nInterpreter Error: %d - Not enough"\
" variables or numbers in the current expression trying to"\
" be evaluated.\nThe expression needs to be balanced.\n" \
"Error occurred at string: %d.\n\n"
#define TOO_FEW_OPS "\nInterpreter Error: %d - Not enough "\
"operations in the current expression trying to be " \
"evaluated.\nThe expression needs to be balanced.\nError " \
"occurred at string: %d.\n\n"
#define OFF_RIGHT_SCREEN "\nInterpreter Error: %d - The " \
"Turtle will be going off the right of the screen!\nPlease"\
" reduce the x value.\nError occurred at string: %d.\n\n"
#define OFF_LEFT_SCREEN "\nInterpreter Error: %d - The " \
"Turtle will be going off the left of the screen!\nPlease" \
" increase the x value.\nError occurred at string: %d.\n\n"
#define OFF_BOTTOM_SCREEN "\nInterpreter Error: %d - The " \
"Turtle will be going off the bottom of the screen!\n" \
"Please reduce the y value.\nError occurred at string: " \
"%d.\n\n"
#define OFF_TOP_SCREEN "\nInterpreter Error: %d - The " \
"Turtle will be going off the top of the screen!\nPlease "\
"increase the y value.\nError occurred at string: %d.\n\n"
