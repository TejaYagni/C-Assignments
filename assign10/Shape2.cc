/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 10
Due Date:   04/20/2016
*********************************/


#include "Shape2.h" //Includes the class definitons and headers in Shape2.h this will as include headers in Shape2.h
#include<iostream>
#include<cmath> //For doing to mathematical comptations
#define PI (4*atan(1)) //Defining the value of pi
using std::cout;
using std::cin;
using std::endl;

/*
Name: Rectangle()
Arguments:void
Return Type:void
Class:Rectangle
Notes:This is a default constructor for Rectangle clss which sets the values to zero
*/
Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}
/*
Name: Rectangle
Arguments:double l1,double l2
Return Type:Void
Class:Rectangle
Notes:This is a parameterised constructor which takes two values and assigns the length and width
*/
Rectangle::Rectangle(double l1, double w1)
{
	length = l1;
	width = w1;
}
/*
Name: Rectangle
Arguments:const Rectangle &obj
Return Type:void
Class:Rectangle
Notes:This is a copy constructor of Rectangle class which takes a constant reference of a Rectangle instance as an argument and assigns its values to the current instance
*/
 Rectangle::Rectangle(const Rectangle &obj)
{
	length = obj.length;
	width = obj.width;
}
/*
Name:operator=
Arguments:const Rectangle &obj
Return Type:Rectangle&
Class: Rectangle`
Notes:This is an assignment opeator which takes a constant reference to a Rectangle class as an argument and checks if the the instance is same as current instance if yes the returns the current reference as a return type else the current instance is assigned with the values of the passes instance and returns the reference of current instance
*/
 Rectangle& Rectangle::operator=(const Rectangle &obj)
 {
	 if (this == &obj)
		 return *this;
	 length = obj.length;
	 width = obj.width;
	 return *this;
 }
 /*
Name: operator+=
Arguments:const Rectangle &obj
Return Type:Rectangle &
Class:Rectangle
Notes:This is an overloaded operator which takes a constant reference of rectangle and adds its values to the current instance and returns the reference of the current instance
*/
 Rectangle& Rectangle::operator+=(const Rectangle &obj)
 {
	 length += obj.length;
	 width += obj.width;
	 return *this;
 }
 /*
Name: ~Rectangle
Arguments:void
Return Type:void
Class:Rectangle
Notes:This is a destructor it frees up any dynamicallly allocated memory
*/
 Rectangle::~Rectangle()
 {

 }
 /*
Name: area
Arguments: void
Return Type:double
Class:Rectangle
Notes:This is a public member function which calculates the area ofthe rectangle and returns it
*/
 double Rectangle::area() const
 {
	 return length*width;
 }
 /*
Name: perimeter
Arguments:void
Return Type:double
Class:Rectangle
Notes: This is a public member function which calculates the perimeter of the rectangle and returns it
*/
 double Rectangle::perimeter() const
 {
	 return 2 * (length + width);
 }
 /*
Name: print
Arguments: void
Return Type: void
Class: Rectangle
Notes: This function displays the dimensions of the rectangle here in this class length and width
*/
 void Rectangle::print() const
 {
	 cout << " length = " << length << " : width = " << width;
 }
 /*
Name: Square
Arguments:void
Return Type:void
Class:Square
Notes: This is a default constructor which calls the super class constructor and sets the deafult values zero
*/
 Square::Square()
 {
	 ::Rectangle();
 }
 /*
Name: Square
Arguments: double s
Return Type:void
Class:Square
Notes: This is a parameterised constructor which takes a double as arguments and sets as the theonly dimension of square i.i square has same length and width
*/
 Square::Square(double s) :Rectangle(s, s)
 {
	 //sets the values to parameterised constructor of Rectangle
 }
 /*
Name: area
Arguments: void
Return Type: double
Class: Square
Notes: This function calculates the area of square,it actually calls the area function of rectangle and returns it.
*/
 double Square::area () const
 {
	 return Rectangle::area();
 }
 /*
Name: perimeter
Arguments: void
Return Type: double
Class: Square
Notes: This function calls the perimeter function of Rectangle and returns it
*/
 double Square::perimeter () const
 {
	 return Rectangle::perimeter();
 }
 /*
Name: print
Arguments: void
Return Type: void
Class: Square
Notes: This function displays the dimensions of the square
*/
 void Square::print () const
 {
	 cout << " length = " << length;
 }
 /*
Name: Circle
Arguments: void
Return Type: void
Class: Circle
Notes:This is a default constr5uctor which sets the value of radius to 0
*/
 Circle::Circle()
 {
	 radius = 0;
 }
 /*
Name: Circle
Arguments: double r1
Return Type: void
Class: Circle
Notes:This is a parameterised constructor which takes a double as argument and assigns it to radius
*/
 Circle::Circle(double r1)
 {
	 radius = r1;
 }
 /*
Name: Circle
Arguments: const Circle &obj
Return Type: void
Class: Circle
Notes: This is a copy constructor which  takes a constant reference to a circle as an object and sets the instance value to the current instance
*/
 Circle::Circle(const Circle &obj)
 {
	 radius = obj.radius;
 }
 /*
Name: operator=
Arguments:const Circle &obj
Return Type:Circle&
Class:Circle
Notes:This is an assignment operator which takes a constant reference to an instance of Circle class and assigns it to the current instance
*/
 Circle& Circle::operator=(const Circle &obj)
 {
	 if (this == &obj)
		 return *this;
	 radius = obj.radius;
	 return *this;
 }
 /*
Name: operator+=
Arguments:const Circle &obj
Return Type: Circle&
Class: Circle
Notes: This is an overloaded operator which adds the the reference instance to the current instance and returns the current instance reference
*/
 Circle& Circle::operator+=(const Circle &obj)
 {
	 radius += obj.radius;
	 return *this;
 }
 /*
Name:~Circle
Arguments:void
Return Type: void
Class: Circle
Notes: This is a destructor which frees the dynamically allocated memory
*/
 Circle::~Circle(void)
 {
   
 }
 /*
Name: area
Arguments:void
Return Type:double
Class: Circle
Notes: This is a public member function which calculates the area of the circle and returns it
*/
 double Circle::area() const
 {
	 return PI*radius*radius;
 }
 /*
Name: perimeter
Arguments: void
Return Type: double
Class: Circle
Notes: This function calcuates the perimeter of circle and returns it
*/
 double Circle::perimeter() const
 {
	  double k=2*PI*radius;
	  return k;
 }
 /*
Name: print
Arguments: void
Return Type:void
Class:Circle
Notes: prints he radius of the circle
*/
 void Circle::print() const
 {
	 cout << " radius = " << radius;
 }
 /*
Name: Triangle
Arguments: void
Return Type: void
Class: Triangle
Notes: Default constructor which sets the sides of the triangle to zero
*/
 Triangle::Triangle()
 {
	 a = b = c = 0;
 }
 /*
Name: Triangle
Arguments: double a1,double b1,double c1
Return Type: void
Class:Triangle
Notes: Parameterised constructor which takes three parameters and sets them to the three sides of the triangle
*/
 Triangle::Triangle(double a1, double b1, double c1)
 {
	 a = a1;
	 b = b1;
	 c = c1;
 }
/*
Name: Triangle
Arguments: const Triangle &obj
Return Type: void
Class: Triangle
Notes: This is a copy constructor which takes a constant reference to a Triangle instance as argument and sets its values to the current instance
*/ 
 Triangle::Triangle(const Triangle &obj)
 {
	 a = obj.a;
	 b = obj.b;
	 c = obj.c;
 }
 /*
Name: operator=
Arguments: const Triangle &obj
Return Type: Triangle&
Class: Triangle
Notes: This is an overloaded assignment operator which takes the a constant reference to Triangle as a reference and assign its value to the the current instance and retyurns a reference of current instance
*/
 Triangle& Triangle::operator=(const Triangle &obj)
 {
	 if (this == &obj)
		 return *this;
	 a = obj.a;
	 b = obj.b;
	 c = obj.c;
	 return *this;
 }
/*
Name: operator+=
Arguments: const Triangle &obj
Return Type: Triangle&
Class: Triangle
Notes: This is an overloaded operator which takes a constant reference to an instance of triangle and adds its values to the current instance and returns the nreference of the current instance
*/
 Triangle& Triangle::operator+=(const Triangle &obj)
 {
	 a += obj.a;
	 b += obj.b;
	 c += obj.c;
	 return *this;
 }
/*
Name:~Triangle
Arguments: void
Return Type:void
Class: Yriangle
Notes: This is a destructor which frees the dynamically allocated memory
*/
 Triangle::~Triangle(void)
 {
   
 }
 /*
Name: area
Arguments: void
Return Type: double
Class: Triangle
Notes: Calculates the area of trianlge and returns it
*/
 double Triangle::area() const
 {
	 double k = (a + b + c)*0.5; //value of semi-perimeter

	 return sqrt(k*(k - a)*(k - b)*(k - c));
 }
 /*
Name: perimeter
Arguments: void
Return Type: double
Class: Triangle
Notes: Calculates the perimeter of the Triangle
*/
 double Triangle::perimeter() const
 {
	 return a + b + c;
 }
 /*
Name: print
Arguments: void
Return Type: void
Class: Triangle
Notes: displays the dimensions of the Triangle
*/
 void Triangle::print() const
 {
	 cout << " a = " << a << " : b = " << b << " : c = " << c;
 }
 /*
Name: rightTriangle
Arguments: void
Return Type: void
Class: rightTriangle
Notes: This is a constructor which call the super class constructor
*/
 rightTriangle::rightTriangle()
 {
	 ::Triangle();//call to super class constructor
 }
 /*
Name: rightTriangle
Arguments: double a1,double b1
Return Type: void
Class: rightTriangle
Notes: This parameterised constructor takes two arguments and assigns them to the super class parameterised constructor 
*/
 rightTriangle::rightTriangle(double a1, double b1):Triangle(a1,b1,sqrt(pow(a1,2)+pow(b1,2)))
 {

 }
 /*
Name: area
Arguments: void
Return Type: double
Class: rightTriangle
Notes: Calculates the area of rightTriangle by calling the area of superclass constructor
*/
 double rightTriangle::area() const
 {
	 return Triangle::area();
 }
 /*
Name: perimeter	
Arguments: void
Return Type: double
Class: rightTriangle
Notes: Calculates the perimeter by calling the perimeter of super class
*/
 double rightTriangle::perimeter() const
 {
	 return Triangle::perimeter();
 }
 /*
Name: print
Arguments: void
Return Type: void
Class: rightTriangle
Notes: prints out the dimensions of the rightTriangle
*/
 void rightTriangle::print() const
 {
	 cout << " length = " << a << " : height = " << b;
 }
 /*
Name: equTriangle
Arguments: void
Return Type: void
Class: equTriangle
Notes:Default constructor which calls the super class constructor
*/
 equTriangle::equTriangle()
 {
	 ::Triangle();
 }
 /*
Name:equTriangle
Arguments: double a
Return Type: void
Class: equTriangle
Notes: parameterised constructor which takes a single argument and assigns it to the three variab;e of Trianlge by calling its constructor
*/
 equTriangle::equTriangle(double a) :Triangle(a, a, a)
 {

 }
 /*
Name: area
Arguments: void
Return Type: double
Class: equTriangle
Notes: Calculates the area of equTriangle by calling the superclass area function
*/
 double equTriangle::area() const
 {
	 return Triangle::area();
 }
 /*
Name: perimeter
Arguments: void
Return Type: double
Class: equTriangle
Notes: Calculates the perimeter by calling super class perimeter function
*/
 double equTriangle::perimeter() const
 {
	 return Triangle::perimeter();
 }
 /*
Name: equTriangle
Arguments: void
Return Type: void
Class: equTriangle
Notes: Prints the dimensions of equTriangle
*/
 void equTriangle::print() const
 {
	 cout << " length = " << a;
 }
