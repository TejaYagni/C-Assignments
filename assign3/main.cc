/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 03
   Due Date:   02/10/2016
*********************************/

/**********************************************************************************************************
Program that takes two files and encrypts the second several times using a very basic encryption algorithm
***********************************************************************************************************/
#include"header_ascii.h" //Header file that contains all the function protottypes, include statements
#include<iostream>
#include<fstream> //This header file provides us file streaming
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

void process_infile(int); //function prototype

/**********************************************************************************************************
FUNCTION: main
ARGUMENTS: none
RETURN TYPE: int
NOTES: This is where program execution starts and reads the file prog3 and calls process_infile 
***********************************************************************************************************/
int main()
{
  int shift;
  ifstream shiftValue("data/prog3.d1");//opens file prog3.d1 from data folder
  if(shiftValue.is_open())
    {
      while(shiftValue>>shift)
	{
	  process_infile(shift);//function call for process_infile for every shift value
	}
    }
      
  return 0;
}

/**********************************************************************************************************************************************************************

FUNCTION: process_infile
ARGUMENTS: int shift
RETURN TYPE: Nothing
NOTES: This function takes integer value shift and reads pro3.d2 file from data and calls the encodeCaesarCipher function and if the file doesn't open then calls error function.

**********************************************************************************************************************************************************************/
void process_infile(int shift)
{
  cout<<endl<<"shift = "<<shift<<endl;
  ifstream theFile;
  theFile.open("data/prog3.d2");//Opens prog3.d2 file
  if(theFile.is_open())
    {
      string str,str2;
      while(getline(theFile,str))
	{
	  str2=encodeCaesarCipher(shift,str); //Function call for encodeCaesaCipher function
	  cout<<str2<<endl;
	}
    }
  else
    error();// Function call for error function if doesn't open
}  
  
