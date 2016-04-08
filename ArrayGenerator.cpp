//ArrayGenerator Class Implementation file

#include "ArrayGenerator.h"
#include <stdlib.h> 
#include <iostream>
using namespace std;

//Constructor & Destructor
ArrayGenerator::ArrayGenerator(){}
ArrayGenerator::~ArrayGenerator(){}

//Populates the array with unsorted data.
void ArrayGenerator::populateArray(int* emptyArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		//sets a random number within the limit to the array value.
		emptyArray[i] = rand() % rangeLimit;
	}

}
