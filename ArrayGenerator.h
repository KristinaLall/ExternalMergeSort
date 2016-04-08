//ArrayGenerator Header file
//Interface for the class ArrayGenerator

#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <iostream>
using namespace std;

class ArrayGenerator
{
private:
	const int rangeLimit = 32767; //range of numbers for sorting

public:
	//Constructors and Destructor
	ArrayGenerator();
	virtual ~ArrayGenerator();

	//Methods
	void populateArray(int* emptyArray, int arraySize); //populate array with unsorted numbers.
};


#endif