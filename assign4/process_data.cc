/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 04
Due Date:   02/18/2016
*********************************/

#include"process_data.h"//User defined header file whic contains the function prototype for the function that is used in this source file
#include<iostream>
#include<fstream>
/**********************************************************************************************************************************************************************
FUNCTION: process_data
ARGUMENTS: ifstream &inFile,ofstream &outFile
RETURN TYPE: void
NOTES: Thhis function takes stream references as arguments, and  takes input character by character from ifstream and sends it to ofstream if they aren't in comments
**********************************************************************************************************************************************************************/
void process_data(ifstream &inFile,ofstream &outFile)
{
  char value;//character variable declared to process input from inFile and place it in outFile
  if(inFile.is_open()&&outFile.is_open())//if both the files are open then the control statement is executed
    {
      while(!inFile.eof())//This loop is exected untill end of file is reached
	while(inFile.get(value))//It takes character by character from inFile
	  {
	    if(value=='/')//If the character is '/' then this control statement is executed as it is the begining of comments 
	      {
		inFile.get(value);//Takes the next character fro stream
		while(value=='*')//If the next character is * then the loop is executed
		  {
		    inFile.get(value);//Takes the next character from the ifstream
		    while(!(value=='*'&&char(inFile.peek())=='/'))//Here peek is used to fetch the next character from the buffer
		      {//This loop is executed if the input char and next char aren't * and / respectively,that is untill end of comment is reached
			inFile.get(value);
		      }
		    inFile.get(value);
		    inFile.get(value);
		    break;
		  }
		if(value=='/')//If the next value is / then this control statement is executed, i.e single line comment is found
		  {
		    while(value!='\n')//This loop is executed untill new line character is found, after that it exits the control statement
		      {
			inFile.get(value);
		      }
		  }
	      }
	    if(value=='"')//If the character is " then this control statement is parsed untill the next " is found
	      {
		outFile<<value;
		inFile.get(value);
		while(value!='"')
		  {
		    outFile<<value;
		    inFile.get(value);
		  }
		outFile<<value;
	      }
	    else
	      outFile<<value;//If the character is not the one mentioned above then the value is send to outFile
	  }
    }
}
  
