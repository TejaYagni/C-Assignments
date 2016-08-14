/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 05
   Due Date:   02/26/2016
*********************************/

/* Header file which is to be included in source code files*/
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<vector> //To include vectors we need to include this library
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;//To use vector this is to be declared
/*Below are the function protottypes for the functions which will be used in the program*/
void buildMineField(vector< vector<bool> >&,double); // This function takes vector of vector of bool and a double as arguments
void displayMineLocations(vector< vector<bool> >&); // This function takes a vector of vector of bool as an argument
void fixcounts(vector< vector < bool > >&,vector< vector < unsigned int > >&); // This function takes vectors of vector of bool and vector of unsigned int as arguments
void displayMineCounts(vector < vector < unsigned int > >&); // This function takes a vector of vector of unsigned int as argument
#endif/*PROCESS_DATA*/
