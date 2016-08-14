/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 06
Due Date:   03/07/2016
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
	string month; //private string variable 
	int day, year; //private int variable
	vector<string> months{ "January","February","March","April","May","June","July","August","September","October","November","December" };
	bool isLeapYear(void) const;
	bool isValidMonth(void) const;
	int daysinMonth(const string&) const;
public:
	Date(const string &m="January", int d=1, int y=2000);
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
	friend ostream &operator<<(ostream &output, const Date &object);
	friend istream &operator>>(istream &input, Date &object);

};

#endif/*HEADER_H*/
