/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 11
Due Date:   04/28/2016
*********************************/
#include "routines.h" //User defined header which contains function prototypes and headers
#include<iostream>
#include<vector> //Need to include since vector is used 
#include<stdlib.h> //For srand and rand to generate a random number
#include<time.h>  //For time

using std::endl;
using std::cout;
using std::vector;
/*
Name: initBoard
Arguments: vector< vector <bool> >&Abc, const int N
Return Type: void
Notes: This function intialises srand with seed time(0)
*/
void initBoard(vector< vector < bool > > &Abc,const int N)
{
	srand(time(0));//random number generator is intialised
}
/*
Name: solveNQueens
Arguments: const int N
Return Type: void
Notes: This funtion takes a constant integer as argument and then creates a vector and calls the initBoard routines by passing vector and ineger N as parameters and then prints the value of N and the calls solveNQueensUtil to check if the N queens board can be created or not if yes then this routine calls printBoard routine to display the board else a statement is displayed on the console displaying that solution doesn't exist 
*/
void solveNQueens(const int N)
{
	vector< vector < bool > > Abc(N, vector < bool >(N, false)); //vector of vector of bool with size N is created
	initBoard(Abc,N); //function call to initBoard routine
	cout << "N = " << N << endl; //Displayes the value of N
	
	bool k = solveNQueensUtil(Abc, 0); //Function call to solveNQueensUtil and stores the value in a boolean k;
	if (k == true) //if solveNQueensUtil reti=urns true then printBoard is called
	{
		printBoard(Abc);//Function call printBoard
	}
	else
		cout << "Solution doesn't exist" << endl; //prints the message on the screen
}
/*
Name: solveNQueensUtil
Arguments: vector< vector <bool> >&Abc,const int i
Return Type: bool
Notes: This function takes a vector of vector bools and a constant integer and then generates a random number and using that number a queen is placed in first row
*/
bool solveNQueensUtil(vector < vector < bool > >&Abc, int i)
{
	
	int k=Abc.size();
	if (i == 0) //when i is equal to 0 that is in the first row
	{
		unsigned int j = rand() % Abc.size(); 
		if ((Abc.size() == 4 || Abc.size() == 6) && (j == 0 ) )
			j++;
		if ((Abc.size() == 4 || Abc.size() == 6) && (j == Abc.size() - 1))
			j--;
		if (isSafe(Abc, 0, j))
			Abc[0][j] = 1;
		i++;
	}
	if (i >= k) //when the current row is greater than or equal to the size of vector then return true
		return true;
	for (unsigned int j = 0; j < Abc.size(); j++)
	{
		if (isSafe(Abc, i, j)) //checks whether the current position is safe or not
		{
			Abc[i][j] = 1;//Assigns the current positin with 1
			if (solveNQueensUtil(Abc, i + 1)) //recursive call with next row as argument
			{
				return true;
			}
			else
				Abc[i][j] = 0; //if it is false then current position is set 0
			
		}
	}
	return false;
}
/*
Name: isSafe
Arguments: vector<vector<bool>>&Abc, int i,int j
Return Type: bool
Notes: the routine takes a reference to a two dimensional vector and two inteersas arguments and this routine checks whether the current position formd by the arguments is safe for the queen to be placed or not if it is safe to place then returns true else returns false
*/
bool isSafe(vector < vector < bool > >&Abc, int i, int j)
{
	int k=Abc.size();
	int p, q; 

	for (p = 0; p < k; ++p)//row check to see if there is any queen that can attack
	
	{
		if (Abc[i][p] == 1)
			return false;
	}	
	
	for (p = 0; p < k; ++p)//column check to see if there is an queen that can attack
	{
		if (Abc[p][j] == 1)
			return false;
	}
	for (p = i, q = j; p >= 0 && q >= 0; p--, q--)//upper diagonal left check to see if there is an queen that can attack
	{
		if (Abc[p][q]==1)
			return false;
	}
	for (p = i, q = j; p >= 0 && q < k; p--, q++)//upper diagonal right check to see if there is an queen that can attack
	{
		if (Abc[p][q] == 1)
			return false;
	}
	for (p = i, q = j; p < k && q < k; p++, q++)//lower diagonal right check to see if there is an queen that can attack
	{
		if (Abc[p][q] == 1)
			return false;
	}
	for (p = i, q = j; q >= 0 && p < k; p++, q--)//lower diagonal left check to see if there is an queen that can attack
	{
		if (Abc[p][q]==1)
			return false;
	}
	return true;
}
/*
Name: printBoard
Arguments: vector<vector<bool>>&Abc
Return Type: void
Notes: This function takes a two dimensional vector and prints out it in the form of a board on the screen
*/
void printBoard(vector < vector < bool > >&Abc)
{
	char a = '-';
	for (unsigned int i = 0; i < Abc.size(); ++i)
	{
		cout << "   ";
	for (unsigned int p = 0; p < (6 * Abc.size()) - 2; ++p)
		cout << a;
	cout << a << endl;
	for (unsigned int p = 0; p < Abc.size(); ++p)
		cout << "  |   ";
	cout << "  |   "<<endl;
		for (unsigned int j = 0; j < Abc.size(); ++j)
		{
			
			if (Abc[i][j] == 1)
			{
				cout << "  | "<<" Q" ; //In place of 1 Q is generated
			}
			else
				cout << "  | " << "  "; //In place of 0 space is generated
		}
		cout <<"  |  "<< endl;
		for (unsigned int q = 0; q < Abc.size(); q++)
		{
			cout << "  |   ";
		}
		cout << "  |   " << endl;
	}
	cout << "   ";
	for (unsigned int p = 0; p < (6 * Abc.size() - 2); p++)
		cout << a;
	cout << a << endl;
}
