/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 11
Due Date:   04/28/2016
*********************************/
/*Header file which contains include file using statements and function prototypes*/
#ifndef N_QUEENS
#define N_QUEENS
#include<iostream> //For input and output streams
#include<vector> //To use vector 
#include<stdlib.h> //To use random functions
#include<time.h> //To use time function

using std::cin;
using std::cout;
using std::endl;
using std::vector;
/*Function prototypes*/
void initBoard(vector< vector < bool > > &,const int);
void solveNQueens(const int);
bool solveNQueensUtil(vector < vector < bool > >&, int);
bool isSafe(vector < vector < bool > >&, int, int);
void printBoard(vector < vector < bool > >&);

#endif /*N_QUEENS*/
