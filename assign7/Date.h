/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 07
Due Date:   03/24/2016
*********************************/
/*Header file for Date class*/
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
#include<cctype> // This is header file is included as isdigit function
#include<vector> // This is used as a vector is used
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::to_string;
/*
CLASS NAME: Date
NOTES: This class contains prototypes of constructors and various functions
*/
class Date
{
	/*Private members of the Date class*/
	string month; //private string variable 
	int day, year; //private int variable
	vector<string> months{ "January","February","March","April","May","June","July","August","September","October","November","December" };
	bool isLeapYear(void) const;
	bool isValidMonth(void) const;
	int daysinMonth(const string&) const;
	int monthIndex();
public:
/* public members of the Date class */
	Date(const string &m="January", int d=1, int y=2000);
	Date(const Date &d);
	void setMonth(string);
	void setDay(int);
	void setYear(int);
	string getMonth();
	int getDay();
	int getYear();
	void Month(void);
	bool isValidDate(void) const;
	string toString(void);
	string intToString(int);
	Date & addDay(int n);
	Date & addMonth(int n);
	Date& addYear(int n);
	int dayIndex() const;
	Date& operator=(const Date &d);
	friend ostream &operator<<(ostream &output, const Date &object);
	friend istream &operator>>(istream &input, Date &object);

};
/* Below are the functions which aren't partf the Date class but are used for the progam execution */
unsigned int dateDiff(const Date &d1, const Date &d2);
ostream &operator<<(ostream &output, const Date &oject);
istream &operator>>(istream &input, Date &object);
#endif/*HEADER_H*/
