CC = g++
CCFLAGS = -Wall -Werror
Assignment11:routines.o main.o
	$(CC) -o Assignment11 routines.o main.o
main.o:main.cc routines.cc routines.h
	$(CC) -c $(CCFLAGS) -std=c++11 main.cc
routines.o:routines.cc routines.h
	$(CC) -c $(CCFLAGS) -std=c++11 routines.cc
run:
	./Assignment11
clean:
	-rm *.o *.cc~ *.h~ Makefile~ Assignment11
