/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 03
   Due Date:   02/10/2016
*********************************/

#include"header_ascii.h"//This header file contains prototypes of functions that we need for this program alon with include statements 
#include<iostream>
#include<string>

/************************************************************************************************************************************************************
FUNCTION: new_position
ARGUMENTS: int shift,char c
RETURN TYPE: char
NOTES: This function takes int shift and char c as arguments from encodeCaesarCipher process the input and then returns the character output after encryption
**************************************************************************************************************************************************************/
char new_position(int shift,char c)
{
  int p=shift%26;
  if(int(c)>64&&int(c)<91)//Here the if statements checks the ascii value of char c and if it is between 64 and 91 then if is executed
    {
      int temp=int(c)+p;
      if(temp>90)//Here after incrementing temp,if checks whether it is greater than 90 or not if not then skips the loop, if it is then decreases temp by 26 
	{
	  temp-=26;
	  return char(temp);//Here the temp is type casted to character and returned
	 }
      else if(temp<65)//Here after incrementing temp,if checks whether it is less than 65 or not if it isn't then skips the loop, if it is then decreases temp by 26
	{
	  temp+=26;
	  return char(temp);//Here the temp is type casted to character and returned
	}
      else
	return char(temp);//Here the temp is type casted to character and returned
    }
  else if(int(c)>96&&int(c)<123)//Here the if statements checks the ascii value of char c and if it is between 96 and 123 then if is executed
    {
      int temp=int(c)+p;
      if(temp>122)//Here after incrementing temp,if checks whether it is greater than 122 or not if it isn't then skips the loop, if it is then increases temp by 26
	{
	  temp-=26;
	  return char(temp);//Here the temp is type casted to character and returned
	}
      else if(temp<97)//Here after incrementing temp,if checks whethe it is less than 97 or not if it isn't  then skips the loop, if it is then increases temp by 26
	{
	  temp+=26;
	  return char(temp);//Here the temp is type casted to character and returned
	}
      else
	return char(temp);//Here the temp is type casted to character and returned
    }
  else
    return c;//Returns character as it is as it isn't and alphabet
}

