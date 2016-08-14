Assignment7:assign7.o Date.o
	g++ -o Assignment7 assign7.o Date.o
assign7.o:assign7.cc Date.cc Date.h
	g++ -c -std=c++11 assign7.cc
Date.o:Date.cc Date.h
	g++ -c -std=c++11 Date.cc
run:
	./Assignment7
clean:
	-rm *.o *.cc~ *.h~ Makefile~ Assignment7
