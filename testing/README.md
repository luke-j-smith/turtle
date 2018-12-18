# Testing
Part of the assignment was to convince the marker that every line of code had been tested. In order to do this I wrote the report below to detail my experience using TDD, CUnit and Valgrind. This report has not been edited since handing in my assignment in January 2016.

#### Usage
In order to test the parser and interpreter, we can use:
```
make
```
and then:
```
make run
```
from *cunit_parser* and *cunit_interp*, respectively.

#### Requirements
The compiler used in the *makefile* is GCC (https://gcc.gnu.org/) and you will need to have this installed in order to use it. For the testing, you will also be required to install CUnit (http://cunit.sourceforge.net/) and Valgrind (http://www.valgrind.org/).

## Turtle Testing Report
### Testing Strategy
I adopted a test-driven development ("TDD") process when writing the Turtle parser and interpreter. In order to  facilitate the process I have used the CUnit framework (http://cunit.sourceforge.net/) for unit testing and Valgrind (http://valgrind.org/) for testing memory management and threading bugs. 

To fully achieve this TDD approach, I adopted the philosophy that: 
1. Functions should be as small and simple as possible;
2. Where possible, functions should have a single purpose. For example, a function like ```memory_for_string()``` which is used to *calloc* up space for a string, should do only that and return a ```char *``` pointer to that space. The testing of whether the returned pointer is null is done separately, rather than in the function itself (i.e., preventing it from becoming multi-purpose); 
3. Dependencies between functions should be kept as low as possible to enable unit testing to be efficient and informative; 
4. The inputs and outputs of a function (or if void, what the function should alter/achieve) should be predefined and the CUnit Test Suite for that function written BEFORE the actual function itself. 

As such, I started with the most basic and fundamental functions that would been needed to construct the program, working my way up to functions which joined everything together and actually carried out tasks in the program. 

### CUnit
This philosophy I adopted can be observed in the order in which I have tested each function in CUnit. The order in the CUnit test files is the order in which the functions were written (rather than how they are presented in the parser and interp folders). 

Any function tested in CUnit is not dependent on any of the subsequent functions (i.e.,  if function X is tested in Suite 9 and function Y testing in Suite 13, then X is not dependent on Y. However, Y might be dependent on X). This allowed me to ensure that each function was behaving as expected before it was used elsewhere in the code. 

I used a mixture of black-box, white-box and integration testing. This enabled me to test both: (i) the outputs of functions for a range of inputs; and (ii) the path taken through a function/chunk of code. 

##### Mock Functions 
Some functions were difficult to test because they were void and/or a certain input should cause a parsing or interpreting error in the real program, with ```exit()``` being called. In such cases, where I needed to check the exact coverage of the function, I would create a mock function. Typically, I would replace the error and ```exit()``` with a specific return value. This enabled me to ensure that the path through the function was as expected for all possible inputs. These return values are defined in the *test_turtle_parser.h* and *test_turtle_interp.h* files. 

##### Integration Testing 
As the complexity and dependencies of functions increased, I implemented integration testing to ensure that the functions still behaved and interacted as expected when combined with other functions. 

### Valgrind 
All testing, including the CUnit tests were ran through Valgrind. The output of the CUnit test registers for the parser and interpreter can been seen in *parser_CUnit_with_Valgrind* and *interp_CUnit_with_Valgrind*, respectively. Both show zero errors and zero failed tests. 

### Examples of Errors/Issues Discovered
A few specific examples of where testing was especially useful:
1. Typos - For example, ```(p->program)++``` instead of ```(p->place)++``` ; 
2. Not defining a variable before it was potentially changed and then used in a ```switch()``` - For example, forgetting to set ```operationType``` to be ```NoOperation``` in ```calculation()``` ; 
3. Defining a variable to be the wrong type - For example, in my Prog struct, I originally had currentMove as an unsigned int. But when initiating the program I set it to ```-1``` (i.e., ```NO_MOVE```). The resulting unexpected behaviour was easily identified using the unit tests. 
4. Not freeing objects that had been calloc’d - For example, not freeing ```p->var[i]``` values after they had been set. 
5. Checking the value between floating points - For example, in ```check_if_integer()``` I originally had 
```
  if((fabs(fraction) - FLOAT_DIF) < 0){
    ... ; 
  }
```

However, this was incorrect and needed to be changed to :
```
  if((fabs(fraction) - FLOAT_DIF) < 0){
    ... ; 
  }
```
5. The different ordering of functions when used as inputs on Mac compared to Linux - For example, on *OS X* ```calculation(... , pop(...), pop(...))``` does the left ```pop()``` first (this wasn't expected)!

### Testing of Final Programs and Error Codes 
After testing each individual function, I went on to test that the actual code ran as expected. This included both the running of files that were correct (i.e., should be parsed/interpreted correctly) and the running of files that should cause an error and exit the program.

The program was designed so that each parsing/interpreting error has a unique error code and message. As such, Turtle programs were designed to cause each of these specific errors (16 in total for the parser and 26 for the interpreter). 

The parser/interpreter was then ran, in conjunction with Valgrind, with all of these correct and incorrect files. The output for each test is saved in their respective parser/interpreter folder in the  *run_time_screen_dumps_with_valgrind* folder. 

The output was compared with what was expected. For example, it was ensured that the each particular parser/interpreter error caused its corresponding and correct error code and message to be displayed. The test files are found in the *program_run_test_turtle_files* folder and cover every kind of parsing/interpreting issue. Additionally, in each case Valgrind reported no errors or memory loss. 

A summary table of the error codes, what they stand for and whether they appeared under the correct circumstances is detailed in the file the summary files *parser_summary_run_time_error_checks.txt* and *interp_summary_run_time_error_checks.txt* - the actual files used and screen dumps can be found in their respective folders. 

### Conclusion 
  
Testing was an extremely painstaking and time consuming process to begin with. However, it did allow me to discover any issues with my code immediately and I am sure prevented a lot of potential debugging when bringing the whole program together. When putting all of the working functions together, I was surprised with how well it worked and how little additional work/debugging was required.

With 59 Suites and 365 tests for the interpreter, in addition to the all of the run time checks with Valgrind, I am confident that every line of this this code has been extensively tested!
