//BubbleSort Class Implementation file

#include "BubbleSort.h"

#include <iostream>
#include <ctime>
using namespace std;

//Constructor & Destructor
BubbleSort::BubbleSort(){}
BubbleSort::~BubbleSort(){}

//Implementation of sort from ISort
int* BubbleSort::sort(int* unsortedArray, int arraySize)
{
	//Outer is number of times the sort must be looped.
	//Inner is the index of the array being sorted.
	int outer, inner;

	for (outer = arraySize - 1; outer > 0; outer--)
	{
		for (inner = 0; inner < outer; inner++)
		{
			if (unsortedArray[inner] > unsortedArray[inner + 1])
			{
				//Swap numbers.
				int temp = unsortedArray[inner];
				unsortedArray[inner] = unsortedArray[inner + 1];
				unsortedArray[inner + 1] = temp; 
			}
		}
	} 

	//returns the sorted array.
	return unsortedArray;
}



