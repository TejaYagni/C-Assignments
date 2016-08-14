/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 03
   Due Date:   02/10/2016
*********************************/
/**************************************************
Header file for Caesar Cipher encryption algorithm
***************************************************/


#ifndef header_ascii
#define header_ascii
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;
/*Below are the function prototypes for the functions which will be used in this program*/
void process_infile(int);//this is a prototype for function used in main.cc and is called by main function
string encodeCaesarCipher(int,string);//this is a prototype for the function used in encodeCaesarCipher file which is called by process_infile function
char new_position(int,char);//this is a prototype for the functio used in new_function.cc file which is called by encodeCaesarCipher function
void error();//this is a prototype for function used in error.cc file which is called by process_infile function if the file is not opened
#endif/*HEADER_ASCII*/
