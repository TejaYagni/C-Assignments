/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 10
Due Date:   04/20/2016
*********************************/

#include "Shape.h" //Header file which contains defintion of Shape class
#include "Shape2.h" 
#include "Shape3.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/*
Name:Cube
Arguments: void
Return Type: void
Class:Cube
Notes:Default constructor calls the super class constructor`
*/
Cube::Cube()
{
	::Square();//constructor call to super class`
}
/*
Name: Cube
Arguments: double x
Return Type: void
Class: Cube
Notes: Parameterised constructor which takes a double value and sets it to superclass constructor
*/
Cube::Cube(double x):Square(x)
{

}
/*
Name: area
Arguments: void
Return Type: void
Class: Cube
Notes: Calculates the area of the cube using the area of square routine
*/
double Cube::area() const
{
	return 6*Square::area() ;
}
/*
Name:perimeter
Arguments: void
Return Type: double
Class: Cube
Notes: This function simply returns o asmentioned in the assignment
*/
double Cube::perimeter() const
{
	return 0;
}
/* 
Name: volume	
Arguments: void
Return Type: void
Class: Cube
Notes: This function calculates the volume of the Cube using the area routine of Square class and the length
*/
double Cube::volume() const
{
	return Square::area()*length;
}
/*
Name: print
Arguments: void
Return Type: void
Class: Cube
Notes: This function prints the dimensions of the Cube
*/
void Cube::print() const
{
	cout << " length = " << length;
}
/*
Name:Box
Arguments: void
Return Type: void
Class: Box
Notes: Default constructor which calls the default constructor of Super class and sets height variable of this class to 0
*/
Box::Box()
{
	::Rectangle();
	height = 0;
}
/*
Name:Box
Arguments: double l1,double w1,double h1
Return Type: Void
Class: Box
Notes: Parametrised constructor which sets the values specified by the arguments
*/
Box::Box(double l1, double w1, double h1):Rectangle(l1,w1)
{
	height = h1;
}
/*
Name: area
Arguments: void
Return Type: double
Class: Box
Notes: Calculates the area using the perimeter and area routines of the rectangle
*/
double Box::area() const
{
	double A1= Rectangle::area();
	double P1 = Rectangle::perimeter();
	return 2 * A1 + height*P1;
}
/*
Name:volume
Arguments: void
Return Type: double
Class: Box
Notes: Calculates the volume of Box
*/
double Box::volume() const
{
	double A1 = Rectangle::area();
	return height*A1;
}
/*
Name: perimeter
Arguments: void
Return Type: double
Class: Box
Notes: returns 0 as mentioned in the assignment
*/
double Box::perimeter() const
{
	return 0;
}
/*
Name: print
Arguments:void
Return Type: void
Class: Box
Notes: Prints the dimensions of the Box
*/
void Box::print() const
{
	cout << " length = " << length << " : width = " << width << " : height = " << height;
}
/*
Name:Cylinder
Arguments:void
Return Type: void
Class: Cylinder
Notes: Default constructor call the superclass constructor to set the radius value to 0 and itself assigns 0 to height	
*/
Cylinder::Cylinder()
{
	::Circle();
	height = 0;
}
/*
Name:Cylinder
Arguments:double r1,double h1
Return Type:void
Class: Cylinder
Notes: Parameterised constructor which takes two values one for radius and othe for height and super class constructor is called to set the radius	
*/
Cylinder::Cylinder(double r1, double h1) :Circle(r1)
{
	height = h1;
}
/*
Name: area
Arguments: void
Return Type: double
Class: Cylinder
Notes: Calculates the area by using area and perimeter routines from Circle class
*/
double Cylinder::area() const
{
	return 2 * Circle::area() + height*Circle::perimeter();
}
/*
Name: perimeter
Arguments: void
Return Type: double
Class: Cylinder
Notes: Returns 0 as mentioned in assignment
*/
double Cylinder::perimeter() const
{
	return 0;
}
/*
Name: volume
Arguments: void
Return Type: double
Class: Cylinder
Notes: Calculates the volume using the area routine from parent class
*/
double Cylinder::volume() const
{
	return height*Circle::area();
}
/*
Name: print
Arguments: void
Return Type: void
Class: Cylinder
Notes: prints the dimensions of the cylinder
*/
void Cylinder::print() const
{
	cout << " radius = " << radius << " : height = " << height;
}
/*
Name:Cone
Arguments:void
Return Type:void
Class:Cone
Notes:This is a default constructor which assigns 0 to all the variables that it has access to either by itself or use the superclass constructor
*/
Cone::Cone()
{
	::Circle();
	height = 0;
}
/*
Name: Cone
Arguments: double r1,double h1
Return Type: void
Class: Cone
Notes: Parameterised constructor which sets the values for the dimensions and it uses super class constructor to set tha value o radius
*/
Cone::Cone(double r1, double h1):Circle(r1)
{
	height = h1;
}
/*
Name: area
Arguments: void
Return Type: double
Class: Cone
Notes: Claculates the area of Cone using super class routines perimeter area and also using cmath functions pow and sqrt as shown in the code
*/
double Cone::area() const
{
	double A1 = (0.5)*(sqrt(pow(radius, 2) + pow(height, 2)));
	double P0 = Circle::perimeter();
	double A0 = Circle::area();
	return A0 + (A1*P0);
}
/*
Name: perimeter
Arguments: void
Return Type: void
Class: Cone
Notes: returns 0 as mentioned in assignment
*/
double Cone::perimeter() const
{
	return 0;
}
/*
Name: volume
Arguments: void
Return Type:double
Class: Cone
Notes: calculates the volume using area routine from Circle class
*/
double Cone::volume() const
{
	return (0.33333333)*height*Circle::area();
}
/*
Name: print
Arguments: void
Return Type: void
Class: Cone
Notes: prints the dimensions out on console
*/
void Cone::print() const
{
	cout << " radius = " << radius << " : height = " << height;
}
/*
Name:Sphere
Arguments: void
Return Type:void
Class:Sphere
Notes:Default constructor calls the super class constructor
*/
Sphere::Sphere()
{
	::Circle();
}
/*
Name:Sphere
Arguments: double r1
Return Type: void
Class: Sphere
Notes: Parametrised constructor which assigns the argument to the super class constructor
*/
Sphere::Sphere(double r1) :Circle(r1)
{

}
/*
Name:area
Arguments: void
Return Type: void
Class: Sphere
Notes: calculates the area using routine area from Circle class
*/
double Sphere::area() const
{
	return 4 * Circle::area();
}
/*
Name: volume
Arguments: void
Return Type: double 
Class: Sphere
Notes: Calculates the volume of the sphere using the area routine of the Circle
*/
double Sphere::volume() const
{
	double p = 1.33333333;
	return p*radius*Circle::area();
}
/*
Name: Tetrahedron
Arguments:void
Return Type:void
Class:Tetrahedron
Notes:Default constructor which inturn calls the super class constructor
*/
Tetrahedron::Tetrahedron()
{
	::equTriangle();
}
/*
Name: Tetrahedron
Arguments: double a1
Return Type: void
Class: Tetrahedron
Notes: Parameterised constructor that assigns its parameter to super clas constructor
*/
Tetrahedron::Tetrahedron(double a1):equTriangle(a1)
{

}
/*
Name: area
Arguments: void
Return Type: double
Class: double
Notes: Calculates the area using area routine of equTriangle
*/
double Tetrahedron::area() const
{
	return 4 * equTriangle::area();
}
/*
Name: perimeter
Arguments: void
Return Type: double
Class: Tetrahedron
Notes: returns 0 as mentioned in assignment
*/
double Tetrahedron::perimeter() const
{
	return 0;
}
/*
Name: volume
Arguments: void
Return Type: double
Class: Tetrahedron
Notes:calculates the volume of the Tetrahedron using area routine of equTriangle
*/
double Tetrahedron::volume() const
{
	double p = 0.33333333;
	double q = 0.66666666;
	return (p)*sqrt(q)*a*equTriangle::area();
}