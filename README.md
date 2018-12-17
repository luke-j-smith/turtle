# Turtle Graphics
Turtle Graphics was the fourth and final assignment (completed in January 2016) of my Programing in C course. The assignment involved writing a parser and interpreter for the Turtle language. The Turtle language was inspired by a subset of *LOGO* (https://en.wikipedia.org/wiki/Logo_(programming_language)) and was intended to be a simple programming language that allowed young children to learn a computer language by driving a 'turtle' around the screen.

### Turtle's Grammar
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

## Assignment
The assignment involved implementing a parser and interpreter for the Turtle language. The structure of the assignment and this repository is as follows:

#### Parser
Implementation of a recursive parser that would determine whether a Turtle program followed the formal grammar. The Turtle program to be parsed is specified via  ```argv[1]```. Output is only provided for an __invalid__ Turtle program.

#### Interpreter
Extension of the parser to an interpreter that would allow a Turtle program to be executed and drawn using SDL.

#### Testing
Testing of the parser and interpreter to convince the marker that every line of code had been tested.

#### Extension 
An extension of the interpreter in some way. I chose to implement two different extensions:

##### Functions
Extension of the formal grammar to allow the use of functions in a Turtle program.

##### Real-time Entry
Real-time entry of a Turtle program via the command line.

## Disclaimer
I have have confirmed with the University that I am able to publish my solution to this assignment. However, as there is the possibility that a similar assignment may still be used by the University, I have been informed that I should state that *this work cannot be used without my permission* and if it is submitted by as current student as their own, they will be investigated for plagiarism.
