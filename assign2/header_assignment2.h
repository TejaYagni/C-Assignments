/*This is a user defined header file which will be included in every source code file as it cotains predefined headers,function prototypes and other statemens*/
#ifndef header_assignment2_h /*This is used to check if the statements in this header file are defined in other files where this header is included */
#define header_assignment2_h //This statement is used to define below statements
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
int divisors(); //function prototype with return type int
bool isPerfect(unsigned int); //function prototype with return type bool
#endif/*HEADER_ASSIGNMENT2_H*/

