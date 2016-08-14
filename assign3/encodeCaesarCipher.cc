/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 03
   Due Date:   02/09/2016
*********************************/

#include"header_ascii.h"// this header file contains the prototype of encodeCaesarCipher function and other required headers if not declared in the source code file
#include<iostream>
#include<string>
/**************************************************************************************************************************************************
FUNCTION: encodeCaesarCipher
ARGUMENT:int shift,string str
RETURN TYPE: string
NOTES: This function takes an integer and a string as arguments from process_infile function and passes each each character to new_position function
****************************************************************************************************************************************************/
string encodeCaesarCipher(int shift,string str)
{
  int p=str.length();
  char new_value[p];//A character array is declared
  for(int i=0;i<p+1;i++)
    {
      new_value[i]=new_position(shift,str[i]);//Character array here is used to collect the characters returned by new_position function
    }
  return new_value;
}  
