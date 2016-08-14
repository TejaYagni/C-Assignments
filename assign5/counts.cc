/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 05
   Due Date:   02/26/2016
*********************************/
#include"header.h" // User defined header file for this program which contains function prototypes and include libraries which will be used in this program 
#include<iostream>
#include<vector> //This is included so tht we can use vectors in this file
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

/**********************************************************************************************************************************************************************FUNCTION NAME: fixcounts

RETURN TYPE: void

ARGUMENTS: vector<vector<bool>>&Abc, vector<vector<unsigned int> >&Def

NOTES: This function takes two vector of vectors, one is of boolean type and the other is of type unsigned int. Depending upon the values of boolean type 2D vector the unsigned int vector is intialised or set i.e. if the value of a position in the vector Abc which is bool is 1 then in the Def vector the values around that position will be incremented along with position,if the value is 0 then it is ignored, this opertion is done every element   
**********************************************************************************************************************************************************************/
void fixcounts(vector < vector < bool > >&Abc, vector < vector < unsigned int > >&Def)
{
  for(unsigned int i=0;i<Abc.size();i++)
    {
      
      for(unsigned int j=0;j<Abc.size();j++)
	{
	  if(Abc.size()==1) // If the vector size is 1 then this control statement is executed 
	    {
	      if(Abc[i][j]==1) // If the value is 1 then this control statement is executed
		{
		  Def[i][j]+=1; //Here the value in the position is incremented
		}
	    }
	  else //If the size of the vector isn't 1 then this part of the control statement is executed 
	    while(Abc[i][j]==1) //Only when the value in the position is 1 this loop will be executed
	      {
		if(i==0&&j==0) //For the position where both the coordinates are 0, this control statement is executed
		  {
		    /* Below positions will be incremented if the value is 1 */
		    
		    Def[i][j]+=1;
		    Def[i+1][j+1]+=1;
		    Def[i+1][j]+=1;
		    Def[i][j+1]+=1;
		    break;
		    
		  }
		else if(i==0&&j==Abc.size()-1) // For the position where a coordinate is minimum and the other is maximum, this control statement is executed 
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i+1][j-1]+=1;
		    Def[i][j-1]+=1;
		    Def[i+1][j]+=1;
		    break;
		    
		  }
		else if(i==Abc.size()-1&&j==0)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i-1][j]+=1;
		    Def[i-1][j+1]+=1;
		    Def[i][j+1]+=1;
		    break;
		  }
		else if(i==Abc.size()-1&&j==Abc.size()-1)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i-1][j-1]+=1;
		    Def[i-1][j]+=1;
		    Def[i][j-1]+=1;
		    break;
		  }
		else if(i==0)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i][j-1]+=1;
		    Def[i+1][j-1]+=1;
		    Def[i+1][j]+=1;
		    Def[i+1][j+1]+=1;
		    Def[i][j+1]+=1;
		    break;
		  }
		else if(i==Abc.size()-1)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i][j-1]+=1;
		    Def[i-1][j-1]+=1;
		    Def[i-1][j]+=1;
		    Def[i-1][j+1]+=1;
		    Def[i][j+1]+=1;
		    break;
		  }
		else if(j==0)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i-1][j]+=1;
		    Def[i-1][j+1]+=1;
		    Def[i][j+1]+=1;
		    Def[i+1][j+1]+=1;
		    Def[i+1][j]+=1;
		    break;
		  }
		else if(j==Abc.size()-1)
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i-1][j]+=1;
		    Def[i-1][j-1]+=1;
		    Def[i][j-1]+=1;
		    Def[i+1][j-1]+=1;
		    Def[i+1][j]+=1;
		    break;
		  }
		else 
		  {
		    /* Below statements are executed to increment the values around the position as well as itself */
		    Def[i][j]+=1;
		    Def[i-1][j-1]+=1;
		    Def[i][j-1]+=1;
		    Def[i+1][j-1]+=1;
		    Def[i-1][j]+=1;
		    Def[i-1][j+1]+=1;
		    Def[i][j+1]+=1;
		    Def[i+1][j+1]+=1;
		    Def[i+1][j]+=1;
		    break;
		  } 
		
	      }
	}
    }
  
}

/**********************************************************************************************************************************************************************
FUNCTION NAME: displayMineCounts

RETURN TYPE: void

ARGUMENTS: vector<vector< unsigned int > >&

NOTES: This functiontakes vector of vector of unsigned int as argument and prints the values on to the output stream 
**********************************************************************************************************************************************************************/
void displayMineCounts( vector < vector < unsigned int > >&Def)
{
  char a='-'; // Here - is intialised to character a to be diplayed as a border while displaying
  cout<<"Mine Counts:"<<endl;
  // From here the below code is used to display the output in the desired format
  for(unsigned int i=0;i<Def.size();i++)
    {
      
      cout<<"   ";
      for(unsigned int p=0;p<(6*Def.size())-2;p++)
	{
	  cout<<a;
	}
      cout<<a<<endl;
      for(unsigned int q=0;q<Def.size();q++)
	{
	  cout<<"  |   ";
	}
      cout<<"  |   "<<endl;
      for(unsigned int j=0;j<Def.size();j++)
	{
	  cout<<"  |  "<<Def[i][j];// Value is displayed from here
	} cout<<"  |  "<<endl;
      for(unsigned int r=0;r<Def.size();r++)
	{
	  cout<<"  |   ";
	}
      cout<<"  |   "<<endl;
    }
  cout<<"   ";
  for(unsigned int p=0;p<(6*Def.size())-2;p++)
    {
      cout<<a;
    }cout<<a<<endl;	
}
