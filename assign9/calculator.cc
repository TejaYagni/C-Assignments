/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 09
Due Date:   04/12/2016
*********************************/

/*This is a soucre file which contains the defintions of all the functions whose prototypes are in calculator.h header file */

#include "calculator.h" //User defined header file
#include<iostream> 
#include<stack>

/*
Name: process_token
Arguments: string &str, stack<double> &input
Return type: void
Notes: This function takes references to a string and a stack as arguments and parses the string to check if the string contains a valid floating point number or operators or any other special characters and takes appropriate steps to process it. 
*/
void process_token(string &str,stack<double> & input)
{
  int b=str.length(); //b stores the length of the string
  for (int i = 0; i < b; i++) //string is parsed using the for loop
	{
		if (isdigit(str[i])) //if the string character contains a digit then this if control statement is executed 
		{
			string str2;
			str2 = getNumber(str, input, i); //function call to getNumber function and the string str2 to stores the return value of the getNumber
			if (str == str2) //If the string returned and the string from process_token are same then i is set to length of string
			  i = b;
			else
			str = str2; //If the returned string and and string from this function is not same then the returned string is set to the variable str
			b=str.length(); //value of b is changed to the returned string str's length
			i = -1;//i is set to -1
		}
		else if (isValidOperator(str[i])) //If the character is an operator then this part of the control statement is executed
		{
			if (!unarySign(str, i)) //This control statement is executed when the opeator is not unary
			{
				double d = operation(str[i], popStack(input), popStack(input)); //If the operator is not unary then it is binary obviously and operation function is called 
				input.push(d); //The value returned by the opeation function is stored in d and is pushed into stack
			}
			else //If the operator is unary then this part of the control statement is executed
			{
				string str4;
				str4 = getNumber(str, input, i); // function call to getNumber and value returned is stored in str4
				if (str == str4) //If the returned string is same as the process_token string then i set to length of the string str
					i = b;
				else //If both are different
				str = str4; //str is set to str4
				b=str.length(); //b is assigned with length of the new string that is the string returned by getNumber
				i = -1; //i is set to -1
			}
		}
		else if (floatPoint(str, i)) //If the string character is a valid float point then this loop is executed
		{
			string str2;
			str2 = getNumber(str, input, i); //Function call to getNumber and value returned is stored in str2
			if (str == str2) // If the returned string is same as the string passed to process_token
			i = b;
			else
			str = str2; //str is assigned with return value of getNumber
			b=str.length(); //b is set with the length of the string returned by getNumber
			i = -1;// i is set to -1
		}
		else if (str[i] == '=') //If the character encountered here is = then printResult function is called and stack is sent as an argument
			printResult(input);
		else if (str[i] == 'c') //If the character is c then this part of control statement is executed
		{
			emptyStack(input); //function call
			str = str.substr(i + 1, str.length()); // String is manipulated to remove the characetr c from it
			b=str.length();
			i = -1;
		}
		else //If anyother character is encountered then this part is executed
		{
			cerr << "error: character " << "'"<<str[i]<<"' is invalid" << endl; //Error message is displayed on the console
			break;
		}
	}
	
}
/*
Name: printResult
Arguments: const stack<double>&input
Return Type: void
Notes: This function takes a reference of stack of type double as argument and returns nothing, this funcion checks if the stack is empty, if it is ten prints out the error message, if the stack isn't empty then printsout the contains of the stack as specified with setprecsion and fixed attributes
*/
void printResult(const stack<double>&input)
{
	if (input.empty() == 1) //checks whether the stack is empty
	{
		cerr << "error: stack is empty"<<endl; // Error message displayed
	}
	else
	{
	  cout <<setw(8)<<fixed<<setprecision(2)<< input.top() << endl; //Printing the top element of the stack
	}
}
/*
Name: emptyStack
Arguments: stack<double>&input
Return Type: void
Notes: This function takes a reference to a stack of type double as argument and returns nothing, this function checks if the stack is empty or not, if it is then prints out the cerr showing stack is empty else it clears the stack completely
*/
void emptyStack(stack<double>&input)
{
  if(input.empty()==1) //Checks if the stack is empty
    {
      cerr<<"error: stack is empty"<<endl; //Displays the error message on the console
    }
  else
  while (input.empty() == 0) //If the stack isn't empty then it clears the content in the stack
	{
		input.pop();
	}
}
/*
Name: isValidOperator
Arguments: const char&c,const double &x, const double &y
Return Type: bool
Notes: This function takes a constant reference to a char c and returns a boolean value,this function checks if the char is a valid operator or if it is then true is returned else false is returned
*/
bool isValidOperator(const char& c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/') //checks if the argument is valid operator or not
		return true;
	return false;
}
/*
Name: operation
Arguments: const char&c, const double &x, const double &y
Return Type: double
Notes: This function takes a char which is obviously an operator and two double values and performs operation on it
*/
double operation(const char& c, const double &x, const double &y)
{
	double temp;
	if (c == '+') //If operator is +
		temp = x + y;
	if (c == '-') //If it is minus
		temp = x - y;
	if (c == '*') //If it is multiplication
		temp = x*y;
	if (c == '/') //If it is division operator
		temp = x / y;
	return temp; //Value is returned
}
/*
Name: popStack
Arguments: stack<double>& input
Return Type:double
Notes: This function takes a stack of type double as input and checks if the stack is empty if it is then prints out an error message or it just pops out a vlaue from the stack and returns the next element which is on the top of stack
*/
double popStack(stack<double> &input)
{
 	if (input.empty()) //if stack is empty
	{
		cerr << "error: stack is empty"<<endl; //Error message is displayed on the console
		
	}
	else if(!input.empty()) //if stack is not empty
	{
		double temp=input.top(); //stores the top of the stack element in a temp variable and deltes it from the stack and then returns the value in the temp variable
		input.pop();
		return temp;
	}
	return 0.00;
}
/*
Name: floatPoint
Arguments: const string &str, int i
Return Type: bool
Notes: This function takes a constant reference to a string and an integer as arguments and returns a bool, it checks if the character in the string is a dot and the next digit is digit and is it the last element in the string and returns the appropriate boolean value
*/
bool floatPoint(const string &str, int i)
{
  int b=str.length();
  if (str[i] == '.'&&isdigit(str[i + 1]) && (i != b - 1))
		return true;
	return false;
}
/*
Name: unarySign
Arguments: const string &str, const int i
Return Type: bool
Notes: This function takes a constant reference to a string  and a constant integer as input returns a boolean true if it is unary else returns false
*/
bool unarySign(const string &str,const int i)
{
  int b=str.length();
	if ((i != b - 1) && ((isdigit(str[i + 1])) || str[i + 1] == '.'))
		return true;
	return false;
}
/*
Name: getNumber
Arguments: string &str, stack<double> &input,const int i
Return Type: string
Notes: This funcion takes a string reference stack refernce and a constant integer i as arguments and returns a string ,it stores the string value into stack and returns the string which isn't part of the floating point , this function takes the argument which is valid floating point number only
*/
string getNumber( string &str,stack<double> &input, const int i)
{
  int q = 0,b=str.length();
	char *k;
	for (int p = i; p < b&&((isdigit(str[p]))||str[p]=='.'); ++p) //checks if there are more than one decimal points in teh string`
	{
		if (str[p] == '.')
			q++;
	}
	if (q > 1) //if there are more than one decimal points
	{
		cerr << "error: number '"<<str<<"' is invalid" << endl;
		return "";
	}
	else
	{
		double d = strtod(str.c_str(), &k);//string is converted into double and the concatinated string is stored in k which is a c style string converted into c++ stle and then returned 
		input.push(d);
		string str1 = k;
		return str1;
	}
}
