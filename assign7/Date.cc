/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 07
Due Date:   03/24/2016
*********************************/
/*************************************************************************
Write a C++ program to implement the Date class and add additional members 
**************************************************************************/
#include"Date.h" // Header File which contains prototype of class and the header files required
#include<iostream>
#include<string> //This header is included so that string can be used
#include<cctype> //This header file is included so that isdigit() function can be used
Date::Date(const string &m , int d , int y ) // Definition of Date class parameterised constructor
{
	month = m; day = d, year = y; 
	Month();
}
/* 
FUNCTION NAME: setMonth
RETURN TYPE: void
ARGUMENTS: string MONTH
CLASS: Date
NOTES: This function takes a string value as input from the driver program and sets the value of month,this is a public member function of Date class which is a setter function for month variable
*/
void Date::setMonth(const string MONTH) 
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
void Date::setDay(const int DAY) 
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
void Date::setYear(const int YEAR)
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
		if ((daysinMonth(month) == 1)&&year!=0) //Here a function call is made to daysinMonth ,which takes private string variable month, if it returns true and year is greater than 0 then this loop is executed
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
	if (MONTH == months[1]) //If the month is February then this control statement is executed
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
/*
FUNCTION: Date class copy constructor
ARGUMENTS: const Date &d
RETURN TYPE: None
NOTES: This is a copy constructor of Date class is used to intialise an object with existin object, it takes the argument a date object which is to be intialised 
*/
 Date::Date(const Date &d)
 {
	 month = d.month;
	 day = d.day;
	 year = d.year;

 }
/* 
FUNCTION: operator=
ARGUMENTS: const Date &d
RETURN TYPE: Date&
NOTES: This is an overloaded assignment operator which takes a constant Date class reference as argument and assigns the object values to the current instance
*/
Date& Date::operator=(const Date &d)
{
  if (&d == this)//If the object passed as argument is same as the current object then the same value is returned 
    return *this;
  month = d.month;//If the current object is not equal to object passed as argument then the following statements are executed
  day = d.day;
  year = d.year;
  return *this;
}
/*
FUNCTION: addDay
ARGUMENTS: int n
RETURN TYPE: Date&
NOTES: This is public function of Date class which takes an integer as an argument and updates the Date object and returns  the reference of Date object. This function adds the number f days to the Date object if the  number of days is more than 36 it adds an year and same is the case with month.
*/ 
Date& Date::addDay(int n)
 {
   day = day + n; //day variable is incremented with argument passed to it
   while (isValidDate() == false)//If the Date that is formed after changing the day variable is not valid then this loop is executed
     {
       
       if (n > 0)//If the number of days added is positive then this control statement is executed 
	 {/*Below are the ontrol statements that will be executed depending upon the current month of the date object*/
	   if (month == months[0])//If the current month is January
	     {
	       if (day > 31)//If the day in the current object is greater than the number of days in the month then this control statement is executed
		 {
		   day = day - 31;//Here the day will be decremented by 31
		   month = months[1];//month will be changed to next month
		 }
	     }
	   if (month == months[1])
	     {
	       if (isLeapYear() == true)//If the current year is leap then the code in this control statement should be used
		 {
		   if (day > 29)
		     {
		       day = day - 29;
		       month = months[2];
		     }
		 }
	       else
		 {
		   if (day > 28)
		     {
		       day = day - 28;
		       month = months[2];
		     }
		 }
	     }
	   if (month == months[2])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[3];
		 }
	     }
	   if (month == months[3])
	     {
	       if (day > 30)
		 {
		   day = day - 30;
		   month = months[4];
		 }
	     }
	   if (month == months[4])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[5];
		 }
	     }
	   if (month == months[5])
	     {
	       if (day > 30)
		 {
		   day = day - 30;
		   month = months[6];
		 }
	     }
	   if (month == months[6])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[7];
		 }
	     }
	   if (month == months[7])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[8];
		 }
	       else return *this;
	     }
	   if (month == months[8])
	     {
	       if (day > 30)
		 {
		   day = day - 30;
		   month = months[9];
		 }
	     }
	   if (month == months[9])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[10];
		 }
	     }
	   if (month == months[10])
	     {
	       if (day > 30)
		 {
		   day = day - 30;
		   month = months[11];
		 }
	     }
	   if (month == months[11])
	     {
	       if (day > 31)
		 {
		   day = day - 31;
		   month = months[0];
		   year += 1;
		   if (year == 0)
		     {
		       year += 1;
		     }
		 }
	     }
	 }
       else if (n < 0)//If the passed argument is negative then this control statement is executed
	 {// Here in this depending upon the month component different control statements will be selected and the code will be executed
	   if (month == months[0])//When the current month is January
	     {
	       if (day < 1)
		 {
		   month = months[11];
		   day = day + 31;
		   year -= 1;
		   if (year == 0)
		     {
		       year -= 1;
		     }
		 }
	     }
	   if (month == months[1])//If month is February
	     {
	       if (day < 1)
		 {
		   month = months[0];
		   day = day + 31;
		 }
	     }
	   if (month == months[2])//If month is March
	     {
	       if (day < 1)
		 {
		   month = months[1];//Month is changed to February
		   if (isLeapYear() == true)// If the year is leap then the following code will be executed
		     {
		       day = day + 29;
		     }
		   else
		     day = day + 28;
		 }
	     }
	   if (month == months[3])//When month is April
	     {
	       if (day < 1)
		 {
		   month = months[2];
		   day = day + 31;
		 }
	     }
	   if (month == months[4])//When month is May
	     {
	       if (day < 1)
		 {
		   month = months[3];
		   day = day + 30;
		 }
	     }
	   if (month == months[5])//If month is June
	     {
	       if (day < 1)
		 {
		   month = months[4];
		   day = day + 31;
		 }
	     }
	   if (month == months[6])//If month is July
	     {
	       if (day < 1)
		 {
		   month = months[5];
		   day = day + 30;
		 }
	     }
	   if (month == months[7])//If month is August
	     {
	       if (day < 1)
		 {
		   month = months[6];
		   day = day + 31;
		 }
	     }
	   if (month == months[8])//If month is September
	     {
	       if (day < 1)
		 {
		   month = months[7];
		   day = day + 31;
		 }
	     }
	   if (month == months[9])//If month is October
	     {
	       if (day < 1)
		 {
		   month = months[8];
		   day = day + 30;
		 }
	     }
	   if (month == months[10])//If month is October
	     {
	       if (day < 1)
		 {
		   month = months[9];
		   day = day + 31;
		 }
	     }
	   if (month == months[11])//If month is  December
	     {
	       if (day < 1)
		 {
		   month = months[10];
		   day = day + 30;
		 }
	     }
	 }
     }
   return *this;
 }
 /*
 FUNCTION: addMonth
 ARGUMENTS: int n
 RETURN TYPE:Date&
 NOTES: addMonth is a public function  in Date class which takes an integer as an argument and add the number of mths specified by the integer to the Date object. If the day of the Date doesn't match the days in the month or is greater than the days in the month then the next month with the first day is added to the Date object.
 */
 Date& Date::addMonth(int n)
 {
	 int t = n / 12,k;
	 n = n % 12;
	 year += t;
	
	 if (month == months[0])
	 {
		 if (n < 0)
		 {
			 k = n + 0;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
			 
		 }
		 if (n > 0)
		 {
			 if (n + 0>11)
				 year += 1;
			 n = (0 + n) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[1])
	 {
		 if (n < 1)
		 {
			 k = n + 1;
			 if (k < 0)
			 {
				 year = year-1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 1 > 11)
				 year += 1;
			 n = (1 + n) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[2])
	 {
		 if (n < 0)
		 {
			 k = n + 2;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 2 > 11)
				 year += 1;
			 n = (2 + n) % 12;
			 month = months[n];
		 }
	}
	 else if (month == months[3])
	 {
		 if (n < 0)
		 {
			 k = n + 3;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 3 > 11)
				 year += 1;
			 n = (3 + n) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[4])
	 {
		 if (n < 0)
		 {
			 k = n + 4;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
			 return *this;
		 }
		 if (n > 0)
		 {
			 if (n + 4 > 11)
				 year += 1;
			 n = (4 + n) % 12;
			 month = months[n];
		 }
		}
	 else if (month == months[5])
	 {
		 if (n < 0)
		 {
			 k = n + 5;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 5 > 11)
				 year += 1;
			 n = (5 + n) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[6])
	 {
		 if (n < 0)
		 {
			 k = n + 6;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 6 > 11)
				 year += 1;
			 n = (n + 6) % 12;
			 month = months[n];

		 }
	 }
	 else if (month == months[7])
	 {
		 if (n < 0)
		 {
			 k = n + 7;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 7 > 11)
				 year += 1;
			 n = (n + 7) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[8])
	 {
		 if (n < 0)
		 {
			 k = n + 8;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 8 > 11)
				 year += 1;
			 n = (n + 8) % 12;
			 month = months[n];
		 }
	 }
	 else if (month == months[9])
	 {
		 if (n < 0)
		 {
			 k = n + 9;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 9 > 11)
				 year += 1;
			 n = (n + 9) % 12;
			 month = months[n];
		 }
	 }
					 
	 else if (month == months[10])
	 {
		 if (n < 0)
		 {
			 k = n + 10;
			 if (k < 0)
			 {
				 year -= 1;
			 }
			 k = (k + 12) % 12;
			 month = months[k];
		 }
		 if (n > 0)
		 {
			 if (n + 10 > 11)
				 year += 1;
			 n = (10 + n) % 12;
			 month = months[n];
		 }
	 }
	else if (month == months[11])
	{
	  if (n < 0)
	    {
	      k = n + 11;
	      if (k < 0)
		{
		  year -= 1;
		}
	      k = (k + 12) % 12;
	      month = months[k];
	    }
	  if (n > 0)
	    {
	      if (n + 11 > 11)
		year += 1;
	      n = (11 + n) % 12;
	      month = months[n];
	    }
	}
	 
	 if (month == months[1] && day>28)
	   {
	     if (isLeapYear() == 1)
	       {
		 if (day == 29)
		   {
		     return *this;
		   }
		 else
		   {	 month = months[2];
		     day = 1;
		   }
	       }
	     else
	       {
		 month = months[2];
		 day = 1;
	       }
	   }
	 if (year == 0)
	   year = 1;
	 return *this;
 }

/*
FUNCTION: addYear
ARGUMENTS: int n
RETURN TYPE: Date&
NOTES:  This is a public function of Date class which takes an integer as an argument and add the number to the year of the Date object and the returns the reference to the Dateobject
*/
Date& Date::addYear(int n)
{
  int j = year;
  year += n;
  if (year < 1 && j > 0)
    {
      
      year -= 1;
    }
  else if (year > 1 && j < 0)
    {
      year += 1;
    }
  else if (year == 0)
    year = 1;
  
  if (month == months[1])
    if (day == 29 && isLeapYear() == 0)
      {
	month = months[2];
	day = 1;
	return *this;
      }
  
  return *this;
}

 /*
 FUNCTION: dayIndex
 ARGUMENTS: none
 RETURN TYPE: int
 NOTES: This is a constant public Date function with no arguments which returns an integer which is equal to the number of Days between the default date of January 1 2000 and the Date object.
 */		 
 int Date::dayIndex() const
 {
	 int p, k;
	 if (year > 0)
	 {
	 k=year - 1;
	 p = k * 365;
	 p = p + (k / 4);
	 p = p - (k / 100);
	 p = p + (k / 400);
	 
		 if (isLeapYear() == 0)
		 {
			 if (month == months[11])
			 {
				 p = p + 334 + day;
			 }
			 if (month == months[10])
			 {
				 p = p + 304 + day;
			 }
			 if (month == months[9])
			 {
				 p = p + 273 + day;
			 }
			 if (month == months[8])
			 {
				 p = p + 243 + day;
			 }
			 if (month == months[7])
			 {
				 p = p + 212 + day;
			 }
			 if (month == months[6])
			 {
				 p = p + 181 + day;
			 }
			 if (month == months[5])
			 {
				 p = p + 151 + day;
			 }
			 if (month == months[4])
			 {
				 p = p + 120 + day;
			 }
			 if (month == months[3])
			 {
				 p = p + 90 + day;
			 }
			 if (month == months[2])
			 {
				 p = p + 59 + day;
			 }
			 if (month == months[1])
			 {
				 p = p + 31 + day;
			 }
			 if (month == months[0])
			 {
				 p = p + day;
			 }
		 }
		 if (isLeapYear() == 1)
		 {
			 if (month == months[0])
			 {
				 p = p + day;
			 }
			 if (month == months[1])
			 {
				 p = p + 31 + day;
			 }
			 if (month == months[2])
			 {
				 p = p + 60 + day;
			 }
			 if (month == months[3])
			 {
				 p = p + 91 + day;
			 }
			 if (month == months[4])
			 {
				 p = p + 121 + day;
			 }
			 if (month == months[5])
			 {
				 p = p + 152 + day;
			 }
			 if (month == months[6])
			 {
				 p = p + 182 + day;
			 }
			 if (month == months[7])
			 {
				 p = p + 213 + day;
			 }
			 if (month == months[8])
			 {
				 p = p + 244 + day;
			 }
			 if (month == months[9])
			 {
				 p = p + 274 + day;
			 }
			 if (month == months[10])
			 {
				 p = p + 305 + day;
			 }
			 if (month == months[11])
			 {
				 p = p + 335 + day;
			 }
		 }
	 }
	 if (year < 0)
	 {
		 k = year + 1;
		 p = k * 365;
		 p = p + (k / 4);
		 p = p - (k / 100);
		 p = p + (k / 400);
		 if (isLeapYear() == 0)
		 {
			 if (month == months[11])
			 {
				 p = p - 32 + day;
			 }
			 if (month == months[10])
			 {
				 p = p - 31 - 31 + day;
			 }
			 if (month == months[9])
			 {
				 p = p - 61 - 32 + day;
			 }
			 if (month == months[8])
			 {
				 p = p - 92 - 31 + day;
			 }
			 if (month == months[7])
			 {
				 p = p - 122 - 32 + day;
			 }
			 if (month == months[6])
			 {
				 p = p - 153 -32 + day;
			 }
			 if (month == months[5])
			 {
				 p = p - 184 - 31 + day;
			 }
			 if (month == months[4])
			 {
				 p = p - 214 - 32 + day;
			 }
			 if (month == months[3])
			 {
				 p = p - 245 -31 + day;
			 }
			 if (month == months[2])
			 {
				 p = p - 275 - 32 + day;
			 }
			 if (month == months[1])
			 {
				 p = p - 306 - 29 + day;
			 }
			 if (month == months[0])
			 {
				 p = p - 334 + 32 + day;
			 }
		 }
		 if (isLeapYear() == true)
		 {
			 if (month == months[11])
			 {
				 p = p - 32 + day;
			 }
			 if (month == months[10])
			 {
				 p = p - 31 - 31 + day;
			 }
			 if (month == months[9])
			 {
				 p = p - 61 - 32 + day;
			 }
			 if (month == months[8])
			 {
				 p = p - 92 - 31 + day;
			 }
			 if (month == months[7])
			 {
				 p = p - 122 - 32 + day;
			 }
			 if (month == months[6])
			 {
				 p = p - 153 - 32 + day;
			 }
			 if (month == months[5])
			 {
				 p = p - 184 - 31 + day;
			 }
			 if (month == months[4])
			 {
				 p = p - 214 - 32 + day;
			 }
			 if (month == months[3])
			 {
				 p = p - 245 - 31 + day;
			 }
			 if (month == months[2])
			 {
				 p = p - 275 - 32 + day;
			 }
			 if (month == months[1])
			 {
				 p = p - 305 - 30 + day;
			 }
			 if (month == months[0])
			 {
				 p = p - 334 + 32 + day;
			 }
		 }
	 }
	 return p;
 }
 /*
 FUNCTION: monthIndex
 ARGUMENTS: None
 RETURN TYPE: int 
 NOTES: This is a private Date function which has no arguments and returns an integer which is equal to the address of the month from the current Date instance
 */
 int Date::monthIndex()
 {
	 
	 for (int i = 0; i < 12, month == months[i];++i)
	 {
		 if (month == months[i]);
		 return i;
	 }
 }
 /*
 FUNCTION: dateDiff
 ARGUMENTS: const Date &d1, const Date &d2
 RETURN TYPE: unsigned int
 NOTES: This dateDiff function takes two arguments both constant references of Date objects and finds the number of days between the two objects
 */
 unsigned int dateDiff(const Date &d1, const Date &d2)
 {
	 int a = d1.dayIndex();
	 int b = d2.dayIndex();
	 int c;
	 if (b > 0 && a > 0)
	 {
		 if (b > a)
			 c = b - a;
		 if (b < a)
			 c = a - b;
		 return c;
	 }
	 else if (b < 0 && a>0)
	 {
		 c = a - b-1;
		 return c;
	 }
	 else if (b > 0 && a < 0)
	 {
		 c = b - a-1;
		 return c;
	 }
	 else if (b < 0 && a < 0)
	 {
		 c = b - a;
		 if (c < 0)
		 {
			 return -c;
		 }
		 if (c > 0)
		 {
			 return c;
		 }
	 }
 }
