# Parser
The parser takes a text file as its input and determines whether that file contains a valid Turtle program, as defined by the grammar below. If the file contain a valid program then there is no output. If the file contains an invalid program then a description of the issue is displayed.

#### Turtle Grammar
```
<MAIN>        ::= "{" <INSTRCTLST>
<INSTRCTLST>  ::= <INSTRUCTION><INSTRCTLST> |
                  "}"
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
<VARNUM>      ::= number | 
                  <VAR>
<SET>         ::= "SET" <VAR> ":=" <POLISH>
<POLISH>      ::= <OP> <POLISH> |
                  <VARNUM> <POLISH> |
                  ";" 
<OP>          ::= "+" |
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

Four example Turtle programs have been provided - two are valid and two and invalid - they are called: ```valid_program_1.txt```, ```valid_program_2.txt```, ```invalid_program_1.txt``` and ```invalid_program_2.txt```.

### Requirements
The compiler used in the *makefile* is GCC (https://gcc.gnu.org/) and you will need to have this installed in order to use it.
