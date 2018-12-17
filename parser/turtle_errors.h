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
DoExpression} ; 
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
#define DO_EXPRESSION "\nERROR: %d - Unexpected input " \
"into switch(check) in check_do_set_up_structure().\n" \
"Please check turtle_parsing.c and turtle_parsing.h\n\n"

/* 
 * PARSING_ERROR used when Turtle grammar is not obeyed.
 * Frees all memory and displays error type and advice. 
 */
#define PARSING_ERROR(message, type, p) \
{fprintf(stderr, message, type, (p->place + 1)) ; \
free_program_memory(&p) ; p = NULL ; exit(type) ; }

/* PARSING_ERROR types to allow for error identification. */ 
enum parsingError {ParsedOk, FileEmpty, NoStartSym, \
NoEndChar, InstrnLst, NoDoStart, NoDoVar, NoDoFrom, \
NoDoVarNum, NoDoTo, NoDoOpenExp, NoSetStart, NoSetVar, \
NoSetDefine, NotPolish, InstrnVarNum} ; 
typedef enum parsingError ParsingError ; 

/* PARSING_ERROR messages details issue and gives advice. */ 
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
