CC = g++
CCFLAGS = -Wall -Werror
Assignment10:Shape2.o Shape3.o assign10.o
	$(CC) -o Assignment10 Shape2.o Shape3.o assign10.o
assign10.o:assign10.cc Shape2.cc Shape3.cc Shape.h Shape2.h Shape3.h
	$(CC) -c $(CCFLAGS) -std=c++11 assign10.cc
Shape2.o:Shape2.cc Shape2.h Shape.h
	$(CC) -c $(CCFLAGS) -std=c++11 Shape2.cc
Shape3.o:Shape3.cc Shape3.h Shape2.h Shape.h
	$(CC) -c $(CCFLAGS) -std=c++11 Shape3.cc
run:
	./Assignment10
clean:
	-rm *.o *.cc~ *.h~ Makefile~ Assignment10
