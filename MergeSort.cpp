//MergeSort Class Implementation file

#include "MergeSort.h"
#include <iostream>
#include <ctime>
using namespace std;

//Constructor & Destructor
MergeSort::MergeSort(){}
MergeSort::~MergeSort(){}

//Implementation of sort function from ISort.
int* MergeSort::sort(int* unsortedArray, int arraySize)
{
	//Divides the sortSize.
	int sortSize = arraySize / 2;

	//Recursively runs until sorted.
	if (arraySize > 1) //loops until only 1 element left in array.
		return merge(sort(unsortedArray, sortSize), sortSize, sort(&unsortedArray[sortSize], arraySize - (sortSize)), arraySize - (sortSize));
	else
		return unsortedArray;
}

//merges the two arrays.
int* MergeSort::merge(int* leftArray, int leftSize, int* rightArray, int rightSize)
{
	int tempArraySize = leftSize + rightSize; //total array size.
	int* tempArray = new int[tempArraySize];
	int leftIndex = 0;
	int rightIndex = 0;

	//loops until tempArraySize to sort the run.
	for (int i = 0; i < tempArraySize; i++)
	{
		if (leftIndex >= leftSize)
			tempArray[i] = rightArray[rightIndex++];
		else if (rightIndex >= rightSize)
			tempArray[i] = leftArray[leftIndex++];
		else if (leftArray[leftIndex] <= rightArray[rightIndex]) //Compares the two numbers.
			tempArray[i] = leftArray[leftIndex++];
		else
			tempArray[i] = rightArray[rightIndex++];
	}

	//returns sorted array.
	return tempArray;
}

