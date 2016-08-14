/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 04
   Due Date:   02/18/2016
*********************************/
/**********************************************************************************************************************************
C++ program that copies characters from the input stream to the output stream except the characters that appear inside C++ comments
***********************************************************************************************************************************/
#include"process_data.h"//User defined header to include all the required headers for the program
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::string;
/*************************************************************************************************
Below declared are the function prototypes for the functions that will be used in this source file
**************************************************************************************************/
void open_files(ifstream&,ofstream&);
void close_files(ifstream&,ofstream&);
void error(const string);
/******************************************************************************************************************************************
FUNCTION: main
ARGUMENTS: none
RETURN TYPE: int
NOTES: This is where program execution starts, objects are created for ifstream and ofstream and functions are called to open and close files
*********************************************************************************************************************************************/
int main()
{
  ifstream inFile;
  ofstream outFile;
  open_files(inFile,outFile);
  close_files(inFile,outFile);
  return 0;
}
/**********************************************************************************************************************************************************************
FUNCTION: open_files
ARGUMENTS: ifstream &inFile,ofstream &outFile 
RETURN TYPE: void
NOTES: This function takes two references one for ifstream and other for ofstream and opens those files and calls process_data function,if either of the files don't open then executes error function 
**********************************************************************************************************************************************************************/
void open_files(ifstream &inFile,ofstream &outFile)
{
  string msg="files not opened";
  const char* file1="prog4-in.cc";
  const char* file2="prog4-out.cc";
  inFile.open(file1);//Opens prog4-in.cc file
  outFile.open(file2);//Opens prog4-out.cc file
  if(inFile.is_open()||outFile.is_open())
    {
      process_data(inFile,outFile);//Function call
    }
  else error(msg);//Function call for error function
}

/*******************************************************************************************************
FUNCTION: close_files
ARGUMENTS: ifstream &inFile,ofstream &outFile
RETURN TYPE: void
NOTES: This function takes two references one for ifstream and other for ofstream and closes those files
********************************************************************************************************/
void close_files(ifstream &inFile,ofstream &outFile)
{
  inFile.close();//closing ifstream file
  outFile.close();//closing outsream file
}

/*******************************************************************************************************************
FUNCTION: error
ARGUMENTS: const string msg
RETURN TYPE: void
NOTES: This funtion takes a constant string as argument and displays it on the standard output and exits the program
********************************************************************************************************************/
void error(const string msg)
{
  cerr<<msg;//displays error message on standard output
  exit(EXIT_FAILURE);//Exits the program
}
