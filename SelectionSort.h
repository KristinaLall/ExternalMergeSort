//SelectionSort Header file
//Interface for the class SelectionSort

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class SelectionSort : public ISort
{
public:
	//Constructor & Destructor
	SelectionSort();
	virtual ~SelectionSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

