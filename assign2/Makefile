assignment2:main.o isPerfect_function.o divisors_function.o
	g++ -o assignment2 main.o isPerfect_function.o divisors_function.o

main.o:main.cc isPerfect_function.cc divisors_function.cc header_assignment2.h
	g++ -c -std=c++11 main.cc isPerfect_function.cc divisors_function.cc

isPerfect_function.o:isPerfect_function.cc header_assignment2.h
	g++ -c -std=c++11 isPerfect_function.cc

divisors_function.o:divisors_function.cc header_assignment2.h
	g++ -c -std=c++11 divisors_function.cc

clean:
	-rm *.o assignment2 
