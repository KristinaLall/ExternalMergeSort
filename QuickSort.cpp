//QuickSort Class Implementation file

#include "QuickSort.h"

#include <iostream>
#include <ctime>
using namespace std;

//Constructor & Destructor
QuickSort::QuickSort(){}
QuickSort::~QuickSort(){}

//Implementation of sort from ISort.
int* QuickSort::sort(int* unsortedArray, int arraySize)
{
	if (arraySize > 1) //loops until only 1 item left in the array.
	{
		int pivotIndex = partition(unsortedArray, arraySize);
		sort(unsortedArray, pivotIndex); //sorts data less than pivot
		sort(&unsortedArray[pivotIndex + 1], arraySize - pivotIndex - 1); //sorts data greater than pivot
	}

	//returns sorted array.
	return unsortedArray;
}

//Reference: https://en.wikipedia.org/wiki/Quicksort
int QuickSort::partition(int* unsortedArray, int arraySize)
{
	int pivotIndex = 0; 
	int pivotValue = unsortedArray[arraySize-1];

	for (int i = 0; i < arraySize-1; i++) //looping from 0 to the end of the array.
	{
		if (unsortedArray[i] <= pivotValue)
		{
			//Swap numbers.
			int temp = unsortedArray[i];
			unsortedArray[i] = unsortedArray[pivotIndex];
			unsortedArray[pivotIndex] = temp;
			pivotIndex++;
		}
	}

	//Swap numbers.
	int temp = unsortedArray[pivotIndex];
	unsortedArray[pivotIndex] = unsortedArray[arraySize-1];
	unsortedArray[arraySize - 1] = temp;

	return pivotIndex;
}

