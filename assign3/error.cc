/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 03
   Due Date:   02/10/2016
*********************************/

#include"header_ascii.h"//This header file contains all include files required for this program and function prototypes
#include<iostream>
#include<string>
#include<cstdlib>//This header file is included so as to use exit function and variable EXIT_FAILURE
using std::cerr;
/***************************************************************************
FUNCTION: error
ARGUMENT: none
RETURN TYPE: nothing
NOTES: This function prints out the error message onto the standard output
****************************************************************************/
void error()
{
  string msg="Error:file didn't open";//this msg is printed on to the standard output
  cerr<<msg<<endl;//cerr is used to print standard output and is generally used when describing errors
  exit(EXIT_FAILURE);//this predefined function terminates the execution abruptly
}

