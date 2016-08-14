run:Assignment3
	./Assignment3
Assignment3:main.o encodeCaesarCipher.o new_position.o error.o
	g++ -o Assignment3 main.o encodeCaesarCipher.o new_position.o error.o
main.o:main.cc encodeCaesarCipher.cc new_position.cc error.cc header_ascii.h
	g++ -c -std=c++11 main.cc
encodeCaesarCipher.o:encodeCaesarCipher.cc header_ascii.h
	g++ -c -std=c++11 encodeCaesarCipher.cc
new_position.o:new_position.cc header_ascii.h
	g++ -c -std=c++11 new_position.cc
error.o:error.cc header_ascii.h
	g++ -c -std=c++11 error.cc
clean:
	-rm *.o *.cc~ *.h~ *.txt~ Makefile~ Assignment3

