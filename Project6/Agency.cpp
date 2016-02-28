#include <iostream>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//							Begin Car Implementation						  //
////////////////////////////////////////////////////////////////////////////////

class Car
{

public:
	Car();
	Car(char *, char *, int, float, bool);
	Car(const Car&);
	~Car();

	void copy(Car);
	void print() const;

	char * getMake() const;
	char * getModel() const;
	int getYear() const;
	float getPrice() const;
	bool getAvailable() const;

	void setMake(char *);
	void setModel(char *);
	void setYear(int);
	void setPrice(float);
	void setAvailable(bool);

private:
	char * make;
	char * model;
	int year;
	float price;
	bool available;
	
};

//Constructors
Car::Car ()
{
	make = new char[20];
	model = new char[20];

}

Car::Car(char *sentMake, char *sentModel, int sentYear, float sentPrice, bool avail)
{
	make = new char[20];
	model = new char[20];

	char *inputTrav = sentMake;
	char *outputTrav = make;
	
	//Copy in the make
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
		
	}
	
	inputTrav = sentModel;
	outputTrav = model;
	
	//Copy in the model
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
	
	}
	
	year = sentYear;
	price = sentPrice;
	available = avail;
	
	inputTrav = NULL;
	outputTrav = NULL;
	
}

Car::Car(const Car& sentCar)
{
	make = new char[20];
	model = new char[20];
	
	char *inputTrav = sentCar.make;
	char *outputTrav = make;
	
	//Copy in the make
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
		
	}
	
	inputTrav = sentCar.model;
	outputTrav = model;
	
	//Copy in the model
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
	
	}
	
	year = sentCar.year;
	price = sentCar.price;
	available = sentCar.available;
	
	inputTrav = NULL;
	outputTrav = NULL;

}

//Destructor
Car::~Car ()
{
	delete[] make;
	delete[] model;
	
	make = NULL;
	model = NULL;
	
}

//Car Class Functions
void Car::copy(Car sentCar)
{
	delete[] make;
	delete[] model;
	
	make = new char[20];
	model = new char[20];
	
	char *inputTrav = sentCar.make;
	char *outputTrav = make;
	
	//Copy in the make
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
		
	}
	
	inputTrav = sentCar.model;
	outputTrav = model;
	
	//Copy in the model
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
	
	}
	
	year = sentCar.year;
	price = sentCar.price;
	available = sentCar.available;
	
	inputTrav = NULL;
	outputTrav = NULL;
	
	return;

}

void Car::print() const
{
	cout << "\t" << year << " " << make << " " << model << " (Price: $" << price << ")(";
	
	if (available)
	{
		cout << "Available)" << endl;
	
	} else
	{	
		cout << "Not Available)" << endl;
		
	}
	
	return;

}

//Get Car Class Value Functions
char * Car::getMake() const
{
	return make;

}

char * Car::getModel() const
{
	return model;

}

int Car::getYear() const
{
	return year;

}
float Car::getPrice() const
{
	return price;

}

bool Car::getAvailable() const
{
	return available;

}

//Car Class Set Value Functions
void Car::setMake(char *sentMake)
{
	delete[] make;
	
	make = new char[20];
	
	char *inputTrav = sentMake;
	char *outputTrav = make;
	
	//Copy in the make
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
		
	}
	
	inputTrav = NULL;
	outputTrav = NULL;
	
	return;

}

void Car::setModel(char *sentModel)
{
	delete[] model;
	
	model = new char[20];
	
	char *inputTrav = sentModel;
	char *outputTrav = model;
	
	//Copy in the model
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
	
	}
	
	inputTrav = NULL;
	outputTrav = NULL;
	
	return;
	
}

void Car::setYear(int sentYear)
{
	year = sentYear;
	
	return;

}

void Car::setPrice(float sentPrice)
{
	price = sentPrice;
	
	return;
	
}

void Car::setAvailable(bool avail)
{
	available = avail;
	
	return;
	
}

////////////////////////////////////////////////////////////////////////////////
//							Begin Agency Implementation						  //
////////////////////////////////////////////////////////////////////////////////
class Agency
{

public:

	Agency();
	Agency(const Agency&);
	~Agency();

	void readInData(char *);

	void print() const;
	void printAvailableCars() const;

	void findMostExpensive() const;
	float estimateCost(int, int) const;

	void sortByMake();    // alphabetical
	void sortByPrice();   // highest to lowest

	void searchByMake(char *) const;

private:

	char * name;
	int * zipcode;
	Car * inventory;

};

//Constructors
Agency::Agency()
{
	name = new char[20];
	zipcode = new int[5];
	inventory = new Car[15];

}

Agency::Agency(const Agency& sentAgency)
{
	name = new char[20];
	zipcode = new int[5];
	inventory = new Car[15];
	
	char *inputTrav = sentAgency.name;
	char *outputTrav = name;
	
	for (int i = 0; i < 20; i++)
	{
		*outputTrav = *inputTrav;
		
		if (*inputTrav == '\0')
		{
			break;
		
		}
		
		inputTrav++;
		outputTrav++;
	
	}
	
	inputTrav = NULL;
	outputTrav = NULL;
	
	int *zipTravIn = sentAgency.zipcode;
	int *zipTravOut = zipcode;
	
	for (int i = 0; i < 5; i++)
	{
		*zipTravOut = *zipTravIn;
		
		zipTravOut++;
		zipTravIn++;
	
	}
	
	zipTravIn = NULL;
	zipTravOut = NULL;
	
	Car *carTravIn = sentAgency.inventory;
	Car *carTravOut = inventory;
	
	for (int i = 0; i < 15; i++)
	{
		(*carTravOut).copy(*carTravIn);
		
		carTravIn++;
		carTravOut++;
	
	}
	
	carTravIn = NULL;
	carTravOut = NULL;
	
}

//Destructor
Agency::~Agency () 
{
	delete[] name;
	delete[] zipcode;
	delete[] inventory;

}

//Agency Class Functions
void Agency::readInData(char *fileName)
{
	ifstream input;
	
	input.open(fileName);
	
	//Read in agency name
	input >> name;
	
	char *buffer = new char[6];
	char *buffTrav = buffer;
	
	//Read in the zip as a string
	input >> buffer;
	
	int *zipTrav = zipcode;
	
	//Convert the zip string into an int array
	for (int i = 0; i < 5; i++)
	{
		*zipTrav = (int) ((*buffTrav) - '0');
		
		zipTrav++;
		buffTrav++;
		
	}
	
	delete[] buffer;
	
	Car *carTrav = inventory;
	
	//Read in the car data
	for (int i = 0; i < 15; i++)
	{
		char *carMake = new char[20];
		char *carModel = new char[20];
		float carPrice;
		int carYear;
		bool carAvail;
		
		input >> carYear;
		input >> carMake;
		input >> carModel;
		input >> carPrice;
		input >> carAvail;
		
		(*carTrav).setYear(carYear);
		(*carTrav).setMake(carMake);
		(*carTrav).setModel(carModel);
		(*carTrav).setPrice(carPrice);
		(*carTrav).setAvailable(carAvail);
		
		delete[] carMake;
		delete[] carModel;
		
		carTrav++;
		
	}
	
	carTrav = NULL;
	zipTrav = NULL;
	buffer = NULL;
	buffTrav = NULL;
	
	input.close();
	
	return;

}

void Agency::print() const
{
	cout << "Agency: " << name << " (Zip: ";
	
	int *zipTrav = zipcode;
	
	for (int i = 0; i < 5; i++)
	{
		cout << *zipTrav;
		
		zipTrav++;
	
	}
	
	zipTrav = NULL;
	
	cout << ")" << endl;
	
	Car *carTrav = inventory;
	
	for (int i = 0; i < 15; i++)
	{
		cout << (i + 1) << ". "; //To make it a numbered list
		
		(*carTrav).print();
		
		carTrav++;
		
	}
	
	carTrav = NULL;
	
	return;
	
}

void Agency::printAvailableCars() const
{
	Car *carTrav = inventory;
	
	for (int i = 0; i < 15; i++)
	{
		if ((*carTrav).getAvailable())
		{
			cout << (i + 1) << ". "; //To make it a numbered list in the array order
		
			(*carTrav).print();
			
		}
		
		carTrav++;
		
	}
	
	carTrav = NULL;
	
	return;

}

void Agency::findMostExpensive() const
{
	int expensiveLoc = 0;
	float highCost = 0.0;
	
	Car *carTrav = inventory;
	
	for (int i = 0; i < 15; i++)
	{
		float thisCost = (*carTrav).getPrice();
		
		if (thisCost > highCost)
		{
			expensiveLoc = i;
			highCost = thisCost;
			
		}
		
		carTrav++;
		
	}
	
	carTrav = inventory;
	
	for (int i = 0; i < expensiveLoc; i++)
	{
		carTrav++;
	
	}
	
	cout << "The most expensive car is: " << endl;
	
	(*carTrav).print();
	
	carTrav = NULL;
	
	return;
	
}

float Agency::estimateCost(int carNumber, int dayAmount) const
{
	Car *carTrav = inventory;
	
	for (int i = 0; i < carNumber; i++)
	{
		carTrav++;
	
	}
	
	float thisPrice = (*carTrav).getPrice();
	float cost = thisPrice * ((float) dayAmount);
	
	carTrav = NULL;
	
	return cost;

}

void Agency::sortByMake() // alphabetical
{
	//Insert tears here

}

void Agency::sortByPrice() // highest to lowest
{
	//Nope

}

void Agency::searchByMake(char *) const
{
	//https://youtu.be/mm4Ip_8aZjI

}

