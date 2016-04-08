//QuickSort Header file
//Interface for the class QuickSort

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class QuickSort : public ISort
{
private:
	int partition(int* unsortedArray, int arraySize);
public:
	//Constructor & Destructor
	QuickSort();
	virtual ~QuickSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

