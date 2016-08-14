/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 04
   Due Date:   02/18/2016
*********************************/
/****************************************************************************************************************
User defined header file which has function prototype of process_data file and includes libraries of iostream,fstream,cstdlib
****************************************************************************************************************/

#ifndef PROCESS_DATA
#define PROCESS_DATA
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::string;

void process_data(ifstream&,ofstream&);//Function prototype
#endif/*PROCESS_DATA*/
