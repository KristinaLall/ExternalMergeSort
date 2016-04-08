//InsertionSort Class Implementation file

#include "InsertionSort.h"

#include <iostream>
#include <ctime>
using namespace std;

//Constructor & Destructor
InsertionSort::InsertionSort(){}
InsertionSort::~InsertionSort(){}

//Implementation of sort from ISort
int* InsertionSort::sort(int* unsortedArray, int arraySize)
{
	//Outer is number of times the sort must be looped.
	//Inner is the index of the array being sorted.
	//temp is the temporary int to store the number to sort.
	int outer, inner, temp;

	for (outer = 1; outer < arraySize; outer++)
	{
		inner = outer;

		while (inner > 0 && unsortedArray[inner - 1] > unsortedArray[inner])
		{
			//Swap numbers
			temp = unsortedArray[inner];
			unsortedArray[inner] = unsortedArray[inner - 1];
			unsortedArray[inner - 1] = temp;
			inner--;
		}
	}

	//return unsorted array.
	return unsortedArray;
}


