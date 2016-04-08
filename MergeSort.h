//MergeSort Header file
//Interface for the class MergeSort

#ifndef MERGESORT_H
#define MERGESORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class MergeSort : public ISort
{
private:
	int* merge(int* leftArray, int leftSize, int* rightArray, int rightSize); //merges two data sets.
public:
	//Constructor & Destructor
	MergeSort();
	virtual ~MergeSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

