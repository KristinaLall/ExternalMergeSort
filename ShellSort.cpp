//ShellSort Class Implementation file

#include "ShellSort.h"

#include <iostream>
#include <ctime>
using namespace std;

//Constructor & Destructor
ShellSort::ShellSort(){}
ShellSort::~ShellSort(){}

//Implementation of sort function from ISort.
int* ShellSort::sort(int* unsortedArray, int arraySize)
{
	//i is number of times the sort must be looped.
	//j is the index of the array being sorted.
	//increment is the sequence being compared.
	int i, j, increment;

	for (increment = arraySize / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < arraySize; i++)
		{
			int temp = unsortedArray[i];

			for (j = i; j >= increment; j -= increment)
			{
				if (temp < unsortedArray[j - increment])
					unsortedArray[j] = unsortedArray[j - increment];
				else
					break;
			}
			unsortedArray[j] = temp;
		}
	}
	
	//returns the sorted array.
	return unsortedArray;
}

