Assignment5:main.o mine.o counts.o
	g++ -o Assignment5 main.o counts.o mine.o
main.o:main.cc counts.cc mine.cc header.h
	g++ -c -std=c++11 main.cc
counts.o:counts.cc header.h
	g++ -c -std=c++11 counts.cc
mine.o:mine.cc header.h
	g++ -c -std=c++11 mine.cc
run:
	./Assignment5
clean:
	-rm *.o *.h~ *.cc~ Assignment5 Makefile~ 
