/*Source code file for  divisors function */
#include "header_assignment2.h" //includes userdefined header where divisors function is declared
#include<iostream>
#include<string>
#define CONST 9999 //Defining 9999 as a constant
using std::cout;
using std::endl;
using std::string;
using std::to_string;
int divisors()
{
  unsigned int x,k,z,p;
  bool y;
  for(unsigned int d=1;d<CONST+1;d++) //Loop to read 1 to 9999 numbers
    {
      x=d,k=0,z=0,p=0;
      unsigned int arr[x/2];//divisors will be stored in this array
      for(unsigned int i=2;i<x+1;i++) //the logic for finding perfect number starts here
	{
	  if(x%i==0)
	    {
	      arr[k]=x/i;
	      k++;
	      z++;
	    }
	}
      y=isPerfect(x);//isPerfect function is called which returns boolean value 1 or 0 depending upon whether the number is perfect or not
      if(y==1)//If the number is Perfect i.e true, this part is executed for printing output 
	{
	  cout<<x<<" = ";
	  for(int i=z-1;i>-1;i--)
	    {
	      string s=to_string(arr[i]);
	      cout<<s;
	      if(i>0)
		cout<<" + ";
	    }
	  cout<<endl;
	}

    }
     	return 0;
}

