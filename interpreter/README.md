# Interpreter
The interpreter takes a Turtle program specified in a text file as its input and draws the program (i.e., the 'turtle' moving around) to the screen. The interpreter will continue to draw the 'turtle' until it reaches the end of the program or an error in the program, at which point it will exit and display a message detailing the error. The program can be stopped at any point by clicking on the terminal.

## neillsdl2
There are two files ```neillsdl2.c``` and ```neillsdl2.h``` that I have not written. These were written by Neill Campbell (http://www.bristol.ac.uk/engineering/people/neill-w-campbell/index.html) to facilitate the use of SDL2 in the assignment (as the direct use of this library was not being assessed).

#### Turtle Grammar
```
<MAIN>        ::= "{" <INSTRCTLST>
<INSTRCTLST>  ::= <INSTRUCTION><INSTRCTLST> | "}"
<INSTRUCTION> ::= <FD> |
                  <LT> |
                  <RT> |
                  <DO> |
                  <SET>
<FD>          ::= "FD" <VARNUM>
<LT>          ::= "LT" <VARNUM>
<RT>          ::= "RT" <VARNUM>
<DO>          ::= "DO" <VAR> "FROM" <VARNUM> "TO" <VARNUM> "{" <INSTRCTLST>
<VAR>         ::= [A−Z]
<VARNUM>      ::= number | <VAR>
<SET>         ::= "SET" <VAR> ":=" <POLISH>
<POLISH>      ::= <OP> <POLISH> | <VARNUM> <POLISH> | ";"
<OP>          ::= "+" | "−" | "*" | "/"
```

## Usage
The parser can be complied using the *makefile*:
```
make
```

The parser can then be ran using the *makefile* and by specifying the input file:
```
make run TURTLE="input_file_name.txt"
```

Four example Turtle programs have been provided - two are valid and two and invalid - they are called: ```valid_program_1.txt```, ```valid_program_2.txt```, ```invalid_program_1.txt``` and ```invalid_program_2.txt```.

### Requirements
The compiler used in the *makefile* is GCC (https://gcc.gnu.org/) and you will need to have this installed in order to use it. In order to display the 'turtle', SDL2 is used and will also need to be installed (https://wiki.libsdl.org/Installation).
