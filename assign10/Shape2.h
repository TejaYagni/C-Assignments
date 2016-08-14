/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 10
Due Date:   04/20/2016
*********************************/

/* This is the header file which contains class definitions of Rectangle,Square,Circle,Triangle,rightTriangle and eqiTriangle*/
#ifndef SHAPE2_H
#define SHAPE2_H
#include"Shape.h"
#include<cmath> //To include sqrt and pow functions we need this header file
class Rectangle :public Shape 
{
protected: //Access specifier which is protected which means these memebres can be accessed only by the derived class of this Class
	double length, width;
public:
	Rectangle(); //default constructor
	Rectangle(double l1,double w1); //Parameterised constructor
	Rectangle(const Rectangle &obj); //COpy constructor
	Rectangle& operator=(const Rectangle &obj); //Assignment operator for Rectangle class
	Rectangle& operator += (const Rectangle &obj); //Overloaded operator
	~Rectangle(void); //Destructor
	double area() const; //this is inherited from SHape class and used to calculate area of rectangle
	double perimeter() const; //This is also inherited form Shape class which is used to calculate perimeter of rectangle
	void print() const; //This function is used to print the dimensions of the shape in this case rectangle which are length and width
};
class Square :public Rectangle //Square class is inherited from Rectangle
{
public: //public data members of Square class
	Square(); //This is a default constructor which sets the default values 0 to its dimensions
	Square(double s); //Parametrised constructor 
	double area() const; //This function is used to calculate area of square
	double perimeter() const; //This function calculates the perimeter
	void print() const; //This function prints the dimensions
};
class Circle :public Shape //Circle class is derived from Shape
{
protected: //since circle has only one dimension it takes radius as protected member
	double radius;
public:
	Circle(); //default constructor
	Circle(double r1); //parameterised constructor
	Circle(const Circle &obj); //copy constructor
	Circle& operator=(const Circle &obj); //assignment operator for circle class
	Circle& operator+=(const Circle &obj); //Overloader operator for Circle class
	~Circle(void); //Destructor for Circle class which freees memory if there is any used
	double area () const; //Used to calculate area of circle
	double perimeter() const; //used to calculate perimeter of class
	void print() const; //Prints the dimensions of circle which is radius

};
class Triangle :public Shape //Triangle is also a derived class of Shape class 
{
protected: //The dimensions of Triangle are all protected
	double a, b, c;
public: //Public memebers of Triangle class
	Triangle(); //Default constructor of Triangle
	Triangle(double a1,double b1,double c1); //Parameeriseed constructor
	Triangle(const Triangle &obj); //Copy constructor of Triangle
	Triangle& operator=(const Triangle &obj); //Assignment operator of Triangle class
	Triangle& operator+=(const Triangle &obj); //Overloaded plus or equal to operator of Triangle class
	~Triangle(void); //Destructor`
	double area() const; //Calculates the area of Triangle
	double perimeter() const; //Calculates the perimeter of class
	void print() const; //Prints the dimesnsions of the Triangle
};
class rightTriangle :public Triangle //rightTriangle is derived from Triangle class
{
public: //public members of rightTriangle class
	rightTriangle(); //Default Constructor
	rightTriangle(double a1,double b1); //Parameeriseed Constructor
	double area() const; //Calculates the area of rightTriangle
	double perimeter() const; //Calculates perimeter 
	void print() const; //Prints out the dimensions 
};
class equTriangle :public Triangle //equTriangle is the sub class Triangle
{
public:
	equTriangle(); //Default Constructor
	equTriangle(double a); //Parameterised constructor
	double area() const; //Calculates area
	double perimeter() const; //Calculates perimeter
	void print() const;//Prints the dimensions out
};

#endif /*SHAPE2_H*/