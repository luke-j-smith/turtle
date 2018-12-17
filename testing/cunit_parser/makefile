TARGET1 = test_turtle
TARGET2 = test_turtle_errors
TARGET3 = turtle_parser_setup
TARGET4 = turtle_parser
TARGET5 = test_turtle_parser
TARGET6 = test_turtle_parser_setup
TARGET7 = test_turtle_test_files

COMP = gcc
CFLAGS = -pedantic -Wall -Wextra -Wfloat-equal -ansi -O2
CLIBS = -lm -lcunit 

$(TARGET1) : $(TARGET1).c $(TARGET1).h $(TARGET2).h $(TARGET3).c $(TARGET3).h $(TARGET4).c $(TARGET4).h $(TARGET5).c $(TARGET5).h $(TARGET6).c $(TARGET6).h $(TARGET7).h 


				$(COMP) $(TARGET1).c $(TARGET3).c $(TARGET4).c $(TARGET5).c $(TARGET6).c -o $(TARGET1) $(CFLAGS) $(CLIBS)

clean :
				rm -f $(TARGET1)
				
run :
				valgrind ./$(TARGET1)
