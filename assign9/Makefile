CC = g++
CCFLAGS = -Wall -Werror
Assignment9:main.o calculator.o
	$(CC) -o Assignment9 main.o calculator.o
main.o:main.cc calculator.cc calculator.h
	$(CC) -c $(CCFLAGS) -std=c++11 main.cc
calculator.o:calculator.cc calculator.h
	$(CC) -c $(CCFLAGS) -std=c++11 calculator.cc
run:
	./Assignment9
clean:
	-rm *.o calculator.cc~ calculator.h~ main.cc~ Assignment9
