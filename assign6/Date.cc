/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 06
Due Date:   03/07/2016
*********************************/
/***********************************************
Write a C++ program to implement the Date class
************************************************/
#include"Date.h" // Header File which contains prototype of class and the header files required
#include<iostream>
#include<string> //This header is included so that string can be used
#include<cctype> //This header file is included so that isdigit() function can be used

Date::Date(const string &m , int d , int y ) // Definition of Date class parameterised constructor
{
	month = m; day = d, year = y; Month();
}
/* 
FUNCTION NAME: setMonth
RETURN TYPE: void
ARGUMENTS: string MONTH
CLASS: Date
NOTES: This function takes a string value as input from the driver program and sets the value of month,this is a public member function of Date class which is a setter function for month variable
*/
void Date::setMonth(string MONTH) 
{ 
	month = MONTH; // Sets the value passed as an argument to the private string variable month 
	Month();  //function call for Month function
}

/*
FUNCTION NAME: getMonth
RETURN TYPE: string
ARGUMENTS: void
CLASS: Date
NOTES: This function is a public member function of Date class which is used as a getter function to get the private variable of Date class month, it returns a string variable as month is a string
*/
string Date::getMonth() 
{ 
	return month; 
}

/*
FUNCTION NAME: setDay
RETURN TYPE: void
ARGUMENTS: int Day
CLASS: Date
NOTES: This function is a public member function of Date class which is used as setter to set the private int variable day value from the argument passed to it which is also int
*/
void Date::setDay(int DAY) 
{ 
	day = DAY; 
}

/*
FUNCTION NAME: getDay
RETURN TYPE: int
ARGUMENTS: void
CLASS: Date
NOTES: This function is a public member function of Date class which is used as a getter to get the value that is stored in private int variable day
*/
int Date::getDay()
{ 
	return day; 
}

/*
FUNCTION NAME: setYear
RETURN TYPE: void
ARGUMENTS: int YEAR
CLASS: Date
NOTES: This is a public member function in Date class which is used to set the value of private member variable year which is passed as argument to it by the driver program  
*/
void Date::setYear(int YEAR)
{ 
	year=YEAR; 
}

/*
FUNCTION NAME: getYear
RETURN TYPE: int
ARGUMENTS: void
CLASS: Date
NOTES: This is a public member function in Date which is used to get the value of the private member variable year which is a int, it returns the int value
*/
int Date::getYear()
{ 
	return year; 
}

/*
FUNCTION NAME: Month
RETURN TYPE: void
ARGUMENTS: void
CLASS: Date
NOTES: This is a public member function which is used to convert the value in the string variable month to the desired format, in this case it is converted using two functions tolower() and to upper in a way that the first letter in the variable is in Upper case and the rest in lower case and if any special characters then they are displayed as it is. 
*/
void Date::Month()
{

	month[0] = toupper(month[0]); //The first letter in the variable is converted to Upper case using toupper
	for (unsigned int j = 1; j<month.size(); ++j)
	{
		month[j] = tolower(month[j]); // Here all the letters in the variable except the first one is converted into lower using tolower
	}
}

/*
FUNCTION NAME: const isValidDate 
RETURN TYPE: bool
ARGUMENTS: void
CLASS: Date
NOTES: This is a constant public member function which is returns a boolean value 1 or true if the date is valid else 0 or false
*/
bool Date::isValidDate(void) const
{
	
	if (isValidMonth() == 1) //Here a function call is made to isValidMonth, if it returns true then this control statement is executed 
	{
		if ((daysinMonth(month) == 1) && year >0) //Here a function call is made to daysinMonth ,which takes private string variable month, if it returns true and year is greater than 0 then this loop is executed
			return true;
		else return false;
	}
	else return false;
	
}

/*
FUNCTION NAME: const isValidMonth
RETURN TYPE: bool
ARGUMENTS: void
CLASS: Date
NOTES: This is a private member function which checks if the month given is a valid month or not, if it is true then it returns true
*/
bool Date::isValidMonth() const
{
	for (unsigned int i = 0; i < 12;++i)
	{
		if (months[i] == month)
		{
			return true;
		}
	}
	return false;
}

/*
FUNCTION NAME: const daysInMonth 
RETURN TYPE: int
ARGUMENTS: const string& month
CLASS: Date
NOTES: This is a private member function which takes a reference to a string variable MONTH, and checks the number of days in a month, if it has the correct day then returns true else false
*/
int Date::daysinMonth(const string & MONTH) const
{
	if (MONTH == "January"||MONTH=="March"||MONTH=="May"||MONTH=="July"||MONTH=="August"||MONTH=="October"||MONTH=="December") 
	{
		if (day > 31||day<1) 
			return false;
		else return true;
	}
	if (MONTH == "February") //If the month is February then this control statement is executed
	{
		if (isLeapYear() == true) // A function call to isLeapYear is made, if it returns true then this control statement is executed
		{
			if (day > 29 || day < 1) //In case of leapyear then 29 is also considered as a day
				return false;
			else return true;
		}
		else
		{
			if (day > 28 || day < 1)
				return false;
			else return true;
		}
		
	}
	else
	{
		if (day > 30 || day < 1)
			return false;
		else return true;
	}
}

/*
FUNCTION NAME: const isLeapYear
RETURN TYPE: bool
ARGUMENTS: void
CLASS: Date
NOTES: This is a private member function which returns a bool value true or 1 if the year is found to be leap else it returns false
*/
bool Date::isLeapYear(void) const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // Here the logic for leap year is checked
		return true;
	else return false;
}

/*
FUNCTION NAME: toString
RETURN TYPE: string
ARGUMENTS: void
CLASS: Date
NOTES: This is a public member function which is used to append the private variables month, day and year together and returns the string
*/
string Date::toString(void)
{
	string str1=intToString(day);//Function call to intToString to convert the integer to string
	string str2=intToString(year);
	str1.append("-");
	str1.append(month,0,3);
	str1.append("-");
	str1.append(str2);
	return str1;
}

/*
FUNCTION NAME: intToString
RETURN TYPE: string
ARGUMENTS: int num
NOTES: This is used to convert the integer variable into string and return the value
*/
string Date::intToString(int num)
{
	string intStr = to_string(num);
	return intStr;
}
/*
FUNCTION NAME: opearator>>
RETURN TYPE:istream
ARGUMENTS:istream &input, Date &object
NOTES: This ia friend function which is used in overloading an operator >> so that the input is taken in a right way as the user desires, here in this case if there is a character in between day and year it is ignored
*/

 istream &operator>>(istream &input, Date &object)
{
	char c;
	input >> object.month >> object.day;
	input >> c;
	if (isdigit(c))
	{
		input.unget();
	}

	input >> object.year;

	return input;
}
 /*
 FUNCTION: friend operator<<
 ARGUMENTS: ostream &output, const Date &object
 RETURN TYPE: ostream
 NOTES: This is operator overloading, and here << operator is overloaded so that output is printed out in the users desired way, here in this a comma is used to seperate the day and the year
 */
 ostream &operator<<(ostream &output, const Date &object)
{
	output << object.month << " " << object.day << ", " << object.year;
	return output;
}
