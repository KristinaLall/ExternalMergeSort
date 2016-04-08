//InsertionSort Header file
//Interface for the class InsertionSort

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class InsertionSort : public ISort
{
public:
	//Constructor & Destructor
	InsertionSort();
	virtual ~InsertionSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

