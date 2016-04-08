//ShellSort Header file
//Interface for the class ShellSort

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <ctime>
#include "ISort.h"
using namespace std;

class ShellSort : public ISort
{
public:
	//Constructor & Destructor
	ShellSort();
	virtual ~ShellSort();

	//Sort function from ISort
	virtual int* sort(int* unsortedArray, int arraySize);
};

#endif

