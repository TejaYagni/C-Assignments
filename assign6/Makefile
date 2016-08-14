Assignment6:assign6.o Date.o
	g++ -o Assignment6 assign6.o Date.o
assign6.o:assign6.cc Date.cc Date.h
	g++ -c -std=c++11 assign6.cc
Date.o:Date.cc Date.h
	g++ -c -std=c++11 Date.cc
run:
	./Assignment6
clean:
	-rm *.o *.cc~ *.h~ Makefile~ Assignment6
