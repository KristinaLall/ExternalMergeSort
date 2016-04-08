//ISort Header file
//Interface for the sort methods.

#ifndef ISORT_H
#define ISORT_H

#include <iostream>
using namespace std;

//Interface used for sorting algorithms.
class ISort
{
public:
	//True virtual function to be implemented.
	virtual int* sort(int* unsortedArray, int arraySize) = 0;
};

#endif