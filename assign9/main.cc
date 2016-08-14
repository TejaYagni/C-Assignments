/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 09
Due Date:   04/12/2016
*********************************/
/***************************************************
Write a C++ program to implement a simple calculator
****************************************************/

/*This is the main function for the assignment and execution starts here*/
#include "calculator.h" //User defined header file which contains headers using statement and function prototypes
#include<iostream> 
#include<stack>
#include<cstdlib>
#include<string>

using std::cin;
using std::stack;
/*
Name: main
Arguments: void
Return Type: int
Notes: This is the main function and the execution starts here, in this a string and a stack are declared and after every input taken process_token function is called for processing the input
*/
int main()
{
	string str; //string declaration
	stack<double> input; //stack declaration
	while (cin>>str)
	{
		process_token(str,input); //function call 
	}
	return 0;
}

