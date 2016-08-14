/********************************
   Name:       Saiteja Yagni
   Class:      CSCI 689/1
   TA Name:    Anthony Schroeder
   Assignment: 05
   Due Date:   02/26/2016
*********************************/
/**********************************************************************************************************************************************************************
Write a program that sets up some data structures for the game of Minesweeper
 *********************************************************************************************************************************************************************/
#include"header.h" //User defined header file which contains function prototypes, libraries
#include<iostream>
#include<vector>//To use vectors we need to include this library
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

/**********************************************************************************************************************************************************************
FUNCTION NAME: main
RETURN TYPE: int
ARGUMENTS: none
NOTES: This is where the program execution starts where in input is taken from the standard input stream and and grids are created and functions are called  
**********************************************************************************************************************************************************************/
int main()
{
  int size_mine;  //To store size of mine 
  double prob_mine; //To store probability of mine
  
  while(cin>>size_mine>>prob_mine) //while proper input is given this loop will execute
    {
      /*Below are the grids that are used in the process of creating a minesweeper map and display the mine location and mine counts*/
      vector< vector< bool > > Abc(size_mine, vector< bool >(size_mine,false));
      vector< vector< unsigned int > > Def(size_mine, vector< unsigned int >(size_mine,0));
      /*Below are the function calls for various functions */
      buildMineField(Abc,prob_mine); //grid Abc and double prob_mine are passed as arguments for building a mine field
      displayMineLocations(Abc);// grid Abc is passed as argument to display the mine locations
      fixcounts(Abc,Def);// bool grid Abc and unsigned int grid Def are passed as arguments
      displayMineCounts(Def); // unsigned integer grid i passes as argument ti display mine counts for each poistion on the output screen
      
    }
  cout<<"wrong input"<<endl; //Is displayed when wrong format input is given
  return 0;
}
