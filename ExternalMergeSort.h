//ExternalMergeSort Header file
//Interface for the class ExternalMergeSort

#ifndef EXTERNALMERGESORT_H
#define EXTERNALMERGESORT_H

#include <ctime>
#include "NumberLine.h"
#include <iostream>
using namespace std;

class ExternalMergeSort
{
private:
	const int memorySize = 1000; //total amount of items that can be processed at a time.
	int writeRunSet(istream& input, ostream& file1);
	const char runDelimeter = '*'; //used in order to determine when the next run should be.
public:
	//Constructor & Destructor
	ExternalMergeSort();
	virtual ~ExternalMergeSort();

	//Sorting methods used for External Merge Sort.
	void sort(istream& input, string fileName1, string fileName2, string fileName3, string fileName4, ostream& output);
	NumberLine* sort(NumberLine* unsortedArray, int arraySize);
	NumberLine* merge(NumberLine* leftArray, int leftSize, NumberLine* rightArray, int rightSize);
	int merge(istream& file1, istream& file2, ostream& file3);
	int mergePass(istream& file1, istream& file2, ostream& file3, ostream& file4, int totalLines);
};

#endif

