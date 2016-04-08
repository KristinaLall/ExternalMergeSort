//BubbleSort Header file
//Interface for the class BubbleSort

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class BubbleSort : public ISort
{
public:
	//Constructor & Destructor
	BubbleSort();
	virtual ~BubbleSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

