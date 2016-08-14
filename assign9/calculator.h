/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 09
Due Date:   04/12/2016
*********************************/
/* Headerfile for calculator.cc file */
#ifndef STACK_H //Header guard 
#define STACK_H
#include<iostream>
#include<string> //To use string class
#include<stack> //To use stack we need to include this header
#include<iomanip> //TO use setw and setprecision functions this header file is to be included
 /* Below are the using statements of functions and other types which will be used in the code */
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::setprecision;
using std::fixed;
using std::setw; 
using std::cerr;
/* Below are the function prototypes for the functions that will be used in the program */
void process_token(string &str, stack<double> &input); //This function takes references of a string and a stack as arguments and returns nothing
void printResult(const stack<double>&input); //This function takes a constnt reference to a stack and returns nothing
void emptyStack(stack<double>&s); //This function takes a reference to stack as an argument and returns nothing
bool isValidOperator(const char &); // function takes a reference to a constant character as argument and returns a bool
double operation(const char&c, const double &x, const double &y); //This function takes references to a character and two double values and returns a double
double popStack(stack<double>&input); //This function takes a reference to a stack as argument and returns a double
bool floatPoint(const string &str, int i); //This function takes a constant reference to a string and an integer as arguments and returns a boolean 
bool unarySign(const string &str, const int i); //This function takes a constant reference to a string and a const integer as arguuments and returns a bool
string getNumber (string &str, stack<double>&input,const int i); //This function takes a reference to a string and a stack and a constant integer as arguments and returns a string

#endif /*STACK_H*/
