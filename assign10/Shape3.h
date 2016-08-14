/********************************
Name:       Saiteja Yagni
Class:      CSCI 689/1
TA Name:    Anthony Schroeder
Assignment: 10
Due Date:   04/20/2016
*********************************/

/*This header fiel contains the 3D shapes*/
#ifndef SHAPE3_H
#define SHAPE3_h
#include "Shape.h" //Includes Shape.h header file and its contents
#include "Shape2.h" //Includes Shape2.h header file and its content
using namespace std;
class Cube :public Square //Cube inherits Square properties
{
public:
	Cube(); //Default constructor
	Cube(double x); //parameterised constructor
	double area() const; //calculates the area of cube
	double perimeter()const; //calculates the perimeter
	void print() const; //Prints out the dimensions of the print method
	double volume() const; //calculates the volume of the cube
};
class Box :public Rectangle  //Box inherits the properties of rectangle
{
	double height; //private variable of Box class
public:
	Box(); //Default constructor
	Box(double l1, double w1, double h1); //Parameterised constructor
	double area() const; //calculates the surface area of box
	double perimeter()const; //calculates the perimetr of the box
	void print() const; //prints the dimensions of the box out
	double volume() const; //calculates the volume of the Box
};
class Cylinder :public Circle //Cylinder inherits the properties of Circle
{
	double height; //private member of Cylinder class
public:
	Cylinder(); //Default constructor
	Cylinder(double r1, double h1); //Parameterised constructor
	double area() const; //Calculates the area of Cylinder
	double perimeter()const; //Calculates the perimeter of the Cylinder
	void print() const; //Prints the dimensions of the cylinder
	double volume() const; //Calculates the volume of Cylinder
};

class Cone :public Circle //Circle is the super class of Cone
{
	double height; //private member of Cone
public:
	Cone(); //Default constructor
	Cone(double r1, double h1); //Parameterised constructor
	double area() const; //Calculate the area of Cone
	double perimeter()const; //Calclate the perimeter of Cone
	void print() const; //Display the dimensions of Cone
	double volume() const; //Calculate the volume of the Cone
};
class Sphere :public Circle //Sphere inherits the properties of Circle
{
public:
	Sphere(); //default constructor of Sphere
	Sphere(double r1); //Parameterised constructor of Sphere
	double area() const; //Calculates the area of Sphere
	double volume() const; //Calculates the volume of the Sphere
};
class Tetrahedron :public equTriangle //Tetrahedron inherits from equTriangle 
{
public:
	Tetrahedron(); //Default constructor 
	Tetrahedron(double a1);//Parameterised constructor
	double area() const; //Calculate the area of the Tetrahedron
	double perimeter()const; //Calculate the perimeter of Tetrahedron
	double volume() const; //Calculate the volume of the Tetrahedron
}; 

#endif /* SHAPE3_H */
