/*Source code file for isPerfect function*/
#include "header_assignment2.h" // Userdefined header is included
#include<iostream>
bool isPerfect(unsigned int n)
{
  unsigned int arr[n/2],z=0,k=0,p=0,i;

  for(unsigned int i=2;i<n+1;i++)
    {
      if(n%i==0)
	{
	  arr[k]=n/i;
	  k++;
	  z++;
	}

	}
  for(int i=0;i<z;i++)//Logic for testing whether the number is perfect number or not
    {
      p=p+arr[i];
    }
  
  if(n==p) //here boolean value is returned true if number is perfect,false if not
    {
      return true;
    }
  else
    {
      return false;
    }
}   
