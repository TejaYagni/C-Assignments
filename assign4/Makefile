Assignment4:main.o process_data.o
	g++ -o Assignment4 main.o process_data.o
main.o:main.cc process_data.cc process_data.h
	g++ -c -std=c++11 main.cc
process_data.o:process_data.cc process_data.h
	g++ -c -std=c++11 process_data.cc

run:
	./Assignment4
clean:
	-rm *.o *.cc~ *.h~ Makefile~ prog4-out.cc Assignment4
