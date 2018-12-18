# Extension Part Two - Real-Time Entry
The second part of the extension has altered the Turtle interpreter so that it does not read in a program from a file, but instead, the user can type in their program from the command line in real-time.

The SDL display updates as instructions are typed and all of the same features of the original grammar are present (including ```DO``` loops, etc). If the user makes a syntax or semantic error then we exit the program immediately. 

At the end of the program, the user has the option to save their program to a file using ```SAVE``` or to discard and close the program using ```END```. If ```SAVE``` is chosen, the user then inputs a name and a ```.txt``` file is created and saved in the current directory. 

A *dynamic structure* is used to store the strings inputted at the command line and this grows when nearing its capacity.

## Extended Turtle Grammar
The slightly expanded grammar is detailed below: 
```
<MAIN>          ::= "{" <INSTRCTLST> <END_SEQUENCE>
<INSTRCTLST>    ::= <INSTRUCTION><INSTRCTLST> | 
                    "}"
<INSTRUCTION>   ::= <FD> | 
                    <LT> | 
                    <RT> | 
                    <DO> | 
                    <SET>
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
<END_SEQUENCE>  ::= "END" | 
                    <SAVE>
<SAVE>          ::= "SAVE" <FILE_NAME>
<FILE_NAME>     ::= string
```
## Usage
The real-time interpreter can be compiled using the *makefile*:
```
make
```
#### Saving a File
The real-time entry interpreter can then be run using the *makefile* and the Turtle program saved using the following example input:
```
make run
{
DO A FROM 1 TO 100 {
SET C := A 1.5 * ; 
FD C
RT 62 
}
}
SAVE turtle_program_output
```

The (valid) Turtle program that has just been input via the command line will then be saved in a file called *turtle_program_output.txt* in the current directory.

#### Discarding a File
The real-time entry interpreter can then be run using the *makefile* and the Turtle program discarded using following example input:
```
make run
{
DO A FROM 1 TO 100 {
SET C := A 1.5 * ; 
FD C
RT 62 
}
}
END
```

The real-time entry interpreter will then exit and no output file will saved.

### Requirements
The compiler used in the *makefile* is GCC (https://gcc.gnu.org/) and you will need to have this installed in order to use it. In order to display the 'turtle', SDL2 is used and will also need to be installed (https://wiki.libsdl.org/Installation).

## neillsdl2
There are two files ```neillsdl2.c``` and ```neillsdl2.h``` that I have not written. These were written by Neill Campbell (http://www.bristol.ac.uk/engineering/people/neill-w-campbell/index.html) to facilitate the use of SDL2 in the assignment (as the direct use of this library was not being assessed).

