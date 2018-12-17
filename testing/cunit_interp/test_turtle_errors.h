/* 
 * Header file contains all possible errors that could occur
 * with the test code itself (ie, NOT what we are testing). 
 */ 
#ifndef TEST_TURTLE_ERRORS_H
#define TEST_TURTLE_ERRORS_H

#define TEST_ERROR(message, type) {fprintf(stderr, message,\
type) ; exit(type) ; }

enum testError {NoError, ErrProgMem, ErrStrMem, \
ErrContentMem, ErrOpen, ErrClose, ErrFscanf} ; 
typedef enum testError TestError ; 

#define TE_PROG_MEM "\nTESTING ERROR: %d - Unable to " \
"allocate enough memory for a Prog pointer.\n\n." 
#define TE_STR_MEM "\nTESTING ERROR: %d - Unable to " \
"allocate enough memory for a string pointer.\n\n." 
#define TE_CONTENT_MEM "\nTESTING ERROR: %d - Unable to " \
"allocate enough memory for a pointer of type char **.\n\n." 
#define TE_OPEN "\nTESTING ERROR: %d - Unable to open " \
"a file for testing.\n\n."  
#define TE_CLOSE "\nTESTING ERROR: %d - Unable to close " \
"a file used for testing.\n\n."
#define TE_FSCANF "\nTESTING ERROR: %d - Unexpected return"\
" value from fscanf().\n\n."

#endif 
/* TEST_TURTLE_ERRORS_H */ 
