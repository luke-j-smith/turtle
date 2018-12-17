TARGET1 = turtle1
TARGET2 = turtle_errors1
TARGET3 = turtle_interp_setup1
TARGET4 = turtle_interp1
TARGET5 = turtle_extension1
TARGET6 = neillsdl2

COMP = gcc
CFLAGS = `pkg-config sdl2 --cflags` -pedantic -Wall -Wextra -Wfloat-equal -ansi -O2
CLIBS = `pkg-config sdl2 --libs` -lm 

$(TARGET1) : $(TARGET1).c $(TARGET1).h $(TARGET2).h $(TARGET3).c $(TARGET3).h $(TARGET4).c $(TARGET4).h $(TARGET5).c $(TARGET5).h $(TARGET6).c $(TARGET6).h

				$(COMP) $(TARGET1).c $(TARGET3).c $(TARGET4).c $(TARGET5).c $(TARGET6).c -o $(TARGET1) $(CFLAGS) $(CLIBS)

clean :
				rm -f $(TARGET1)
				
run :
				./$(TARGET1) $(TURTLE)

