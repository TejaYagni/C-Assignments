/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 11
Due Date:   04/28/2016
*********************************/
/*Program to solve N Queens problem*/
#include "routines.h" //This is the user defined header file which contains the headers using statements and function prototypes
#include<iostream>

using std::cin; //Allows us to use cin that is input operator
/*
Name: main
Arguments: void
Return Type: int
Notes: This is where the execution starts, this function calls solveNQueens routine every a input is passed from console
*/
int main()
{
	int N;
	while (cin >> N) 
	{
		solveNQueens(N); //Function call to solveNQueens which takes the size of the board as argument
	}
    return 0;
}

