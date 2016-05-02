#include <iostream>
#include "inheritance.h"

#define PI 3.14159265

using namespace std;

//Rectangle Implementation
//******************************************************************************************
//Constructor
Rectangle::Rectangle (float sentLength, float sentWidth)
{
	width = sentWidth;
	length = sentLength;

	isThreeDimensional = false;

}

float Rectangle::calculateAreaOrVolume ()
{
	return (length * width);

}

float Rectangle::calculatePerimeterOrSurfaceArea ()
{
	return ((length * 2) + (width * 2));

}

void Rectangle::print ()
{
	cout << "Rectangle with length: " << length << " and width: " << width;

	return;

}

//Rectangular Prism Implementation
//******************************************************************************************
//Constructor
RectangularPrism::RectangularPrism (float sentLength, float sentWidth, float sentHeight)
{
	length = sentLength;
	width = sentWidth;
	height = sentHeight;

	isThreeDimensional = true;

}

float RectangularPrism::calculateAreaOrVolume () //Calculates volume
{
	return (length * width * height);

}

float RectangularPrism::calculatePerimeterOrSurfaceArea ()
{

	return (2 * ((width * length) + (height * length) + (height * width))); //A = 2(wl + hl + hw)

}

void RectangularPrism::print ()
{
	cout << "Rectangular Prism with length: " << length << ", width: " << width << ", and height: " << height;

	return;

}

//Circle Implementation
//******************************************************************************************
//Constructor
Circle::Circle (float sentRadius)
{
	radius = sentRadius;

	isThreeDimensional = false;

}

float Circle::calculateAreaOrVolume ()
{
	return (PI * (radius * radius)); //A = pi*r^2

}

float Circle::calculatePerimeterOrSurfaceArea ()
{
	return (2 * PI * radius);

}

void Circle::print ()
{
	cout << "Circle with radius: " << radius;

	return;

}

//Cylinder Implementation
//******************************************************************************************
//Constructor
Cylinder::Cylinder (float sentRadius, float sentHeight)
{
	radius =sentRadius;
	height = sentHeight;

	isThreeDimensional = true;

}

float Cylinder::calculateAreaOrVolume ()
{
	return (height * (PI * (radius * radius))); //V = h*(pi*r^2)

}

float Cylinder::calculatePerimeterOrSurfaceArea ()
{
	return ((2 * PI * radius * height) + (2 * PI * (radius * radius))); //A = 2pirh+2pir^2

}

void Cylinder::print ()
{
	cout << "Cylinder with radius: " << radius << " and height: " << height;

	return;

}