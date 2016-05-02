#include <iostream>
#include <fstream>
#include "inheritance.h"

using namespace std;

int main ()
{	
	fstream data;

	char *fileName = new char[20];

	cout << "Enter input file name: ";

	cin >> fileName;

	data.open(fileName);

	int numShapes;

	data >> numShapes;

	cout << "Found a file containing " << numShapes << " shapes!" << endl;

	Shape **shapeList = new Shape*[numShapes];

	Shape **listTrav = shapeList;

	for (int i = 0; i < numShapes; i++)
	{
		int shapeNum;

		data >> shapeNum;

		cout << "Found shape with ID: " << shapeNum << endl;

		if (shapeNum == 1) //Rectangle
		{
			float length;
			float width;

			data >> length;
			data >> width;

			*(listTrav) = new Rectangle(length, width);

		} else if (shapeNum == 2) //R Prism
		{
			float length;
			float width;
			float height;

			data >> length;
			data >> width;
			data >> height;

			*(listTrav) = new RectangularPrism(length, width, height);

		} else if (shapeNum == 3) //Circle
		{
			float radius;

			data >> radius;

			*(listTrav) = new Circle(radius);

		} else if (shapeNum == 4) //Cylinder
		{
			float radius;
			float height;

			data >> radius;
			data >> height;

			*(listTrav) = new Cylinder(radius, height);

		} else
		{
			cout << "Error: Shape ID " << shapeNum << " not found." << endl;

		}

		listTrav++;

	}

	listTrav = shapeList;

	for (int i = 0; i < numShapes; i++)
	{
		(*(*listTrav)).print();

		cout << endl;

		listTrav++;

	}

	cout << endl << "Calculations of Perimeter/SA: " << endl << endl;

	listTrav = shapeList;

	for (int i = 0; i < numShapes; i++)
	{
		float value;

		value = (*(*listTrav)).calculatePerimeterOrSurfaceArea();

		if ((*(*listTrav)).is3D())
		{
			cout << "The Surface Area of a ";

			(*(*listTrav)).print();

			cout << " is: " << value << endl;

		} else
		{
			cout << "The Perimeter of a ";

			(*(*listTrav)).print();

			cout << " is: " << value << endl;

		}

		listTrav++;

	}

	listTrav = shapeList;

	cout << endl << "Calculations of Area/Volume: " << endl << endl;

	for (int i = 0; i < numShapes; i++)
	{
		float value;

		value = (*(*listTrav)).calculateAreaOrVolume();

		if ((*(*listTrav)).is3D())
		{
			cout << "The Volume of a ";

			(*(*listTrav)).print();

			cout << " is: " << value << endl;

		} else
		{
			cout << "The Area of a ";

			(*(*listTrav)).print();

			cout << " is: " << value << endl;

		}

		listTrav++;

	}

	delete[] fileName;
	fileName = NULL;

	delete[] shapeList;
	shapeList = NULL;

	listTrav = NULL;

	return 0;

}