# Extension Part One - Functions
Part one (and the most bulky part of my extension), is the addition of functions to the Turtle grammar. Functions can be defined either before of after ```MAIN```, however, the grammar specifies that they are defined before ```MAIN``` (i.e., where ```MAIN``` represents that start of our main procedure, much like in C). 

Within ```MAIN``` or other functions, functions are able to take inputs that are either: (i) numbers; (ii) variables; or (iii) have no inputs at all. However, when defining the function itself, we do not allow any of the input identifiers to be variables (i.e., ```[A-Z]```) or numbers. Note that if variables are passed as inputs to a function, then they are *passed by reference* rather than by value!

The user does not have to define any functions if they do not want to. However, if they do, all of the relevant information for each defined function is stored in a hash table. A *double hashing* approach is used for building and searching the function hash table. Each element of the function hash table includes the functions name, number of inputs and location of the function in the program memory. 

Functions can be nested within outer functions, however, recursion is not allowed.

## Extended Turtle Grammar
The formal grammar has been expanded and is detailed below: 

```
<START>         ::= "MAIN" <MAIN> |  
                    "FUNC_DEF" <FUNC_DEF>
<FUNC_DEF>      ::= <FUNC_NAME> "(" <DEF_INPUTS> <MAIN> <START>
<FUNC_NAME>     ::= !<GRAMMAR>
<GRAMMAR>       ::= <OP> | 
                    <VAR> | 
                    number | 
                    "{" | "}" | 
                    "SET"
                    ":=" | 
                    "FD" | 
                    "LT" | 
                    "RT" | 
                    "(" | ")" |
                    ";" | 
                    "DO" | 
                    "FROM" | 
                    "TO"       
<DEF_INPUTS>    ::= <DEF_INPUT> <DEF_INPUTS> | 
                    ")"
<DEF_INPUT>     ::= !<VAR> | 
                    !number
<MAIN>          ::= "{" <INSTRCTLST>
<INSTRCTLST>    ::= <INSTRUCTION> <INSTRCTLST> | 
                    "}"
<INSTRUCTION>   ::= <FD> | 
                    <LT> | 
                    <RT> | 
                    <DO> | 
                    <SET> | 
                    <FUN>
<FUN>           ::= <FUNC_NAME> "(" <INPUTS> ")" ";"
<INPUTS>        ::= <INPUT> <INPUTS> | 
                    ")"
<INPUT>         ::= <VARNUM>
<FD>            ::= "FD" <VARNUM>
<LT>            ::= "LT" <VARNUM>
<RT>            ::= "RT" <VARNUM>
<DO>            ::= "DO" <VAR> "FROM" <VARNUM> "TO" <VARNUM> "{" <INSTRCTLST>    
<VAR>           ::= [A−Z]
<VARNUM>        ::= number | 
                    <VAR>
<SET>           ::= "SET" <VAR> ":=" <POLISH>
<POLISH>        ::= <OP> <POLISH> | 
                    <VARNUM> <POLISH> | 
                    ";"
<OP>            ::= "+" |  
                    "−" | 
                    "*" | 
                    "/"
```

## Usage
The parser can be complied using the *makefile*:
```
make
```

The parser can then be run using the *makefile* and by specifying the input file:
```
make run TURTLE="input_file_name.txt"
```

Three valid example Turtle programs have been provided, they are called: ```example1.txt```, ```example2.txt``` and ```example3.txt```.

### Requirements
The compiler used in the *makefile* is GCC (https://gcc.gnu.org/) and you will need to have this installed in order to use it. In order to display the 'turtle', SDL2 is used and will also need to be installed (https://wiki.libsdl.org/Installation).

## neillsdl2
There are two files ```neillsdl2.c``` and ```neillsdl2.h``` that I have not written. These were written by Neill Campbell (http://www.bristol.ac.uk/engineering/people/neill-w-campbell/index.html) to facilitate the use of SDL2 in the assignment (as the direct use of this library was not being assessed).
