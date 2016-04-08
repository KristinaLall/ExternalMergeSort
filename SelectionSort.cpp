//SelectionSort Class Implementation file

#include "SelectionSort.h"

#include <iostream>
#include <ctime>
using namespace std;

//Constructor and Destructor
SelectionSort::SelectionSort(){}
SelectionSort::~SelectionSort(){}

//Implementation of sort from ISort
int* SelectionSort::sort(int* unsortedArray, int arraySize)
{
	//Outer is number of times the sort must be looped.
	//Inner is the index of the array being sorted.
	//min is the smallest number.
	int outer, inner, min;

	for (outer = 0; outer < arraySize -1; outer++)
	{
		min = outer;

		for (inner = outer + 1; inner < arraySize; inner++)
		{
			if (unsortedArray[inner] < unsortedArray[min])
				min = inner; //set the smallest number.
		}

		//Swap numbers.
		int temp = unsortedArray[outer];
		unsortedArray[outer] = unsortedArray[min];
		unsortedArray[min] = temp;
	}

	//returns the sorted array.
	return unsortedArray;
}



