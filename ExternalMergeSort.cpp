//ExternalMergeSort Class Implementation file

#include "ExternalMergeSort.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//Constructor & Destructor
ExternalMergeSort::ExternalMergeSort(){}
ExternalMergeSort::~ExternalMergeSort(){}

//Writes the initial run set from the unsorted input file
int ExternalMergeSort::writeRunSet(istream& input, ostream& output)
{
	int i = 0;
	NumberLine* runSet = new NumberLine[memorySize];

	input >> std::ws; //consumes whitespace.
	//Writes the unsorted numbers to an array with memorySize limit.
	for (i = 0; i < memorySize && input.peek() != EOF; i++)
	{
		NumberLine line;
		input >> line;
		runSet[i] = line;
		input >> std::ws;
	}

	runSet = sort(runSet, i);

	for (int j = 0; j < i; j++)
		output << runSet[j] << endl;
	
	//adds the delimeter to the end of the run
	input >> std::ws;
	output << runDelimeter << endl;

	return i; //returns the runset total.
}

void ExternalMergeSort::sort(istream& input, string fileName1, string fileName2, string fileName3, string fileName4, ostream& output)
{
	//Declare the input and output files.
	ofstream ofile1, ofile2, ofile3, ofile4;
	ifstream ifile1, ifile2, ifile3, ifile4;

	int totalLines = 0; //total amount of NumberLines in the file.
	input >> std::ws;

	//Open output files
	ofile1.open(fileName1);
	ofile2.open(fileName2);

	//Writes to files 1 and 2 for initial run set.
	while (input.peek() != EOF)
	{
		totalLines += writeRunSet(input, ofile1);
		totalLines += writeRunSet(input, ofile2);
		input >> std::ws;
	}

	//Closes output files.
	ofile1.close();
	ofile2.close();

	int linesMerged = 0;

	while (true)
	{
		//Open files to be used, merges, then closes files.
		ifile1.open(fileName1);
		ifile2.open(fileName2);
		ofile3.open(fileName3);
		ofile4.open(fileName4);

		linesMerged = mergePass(ifile1, ifile2, ofile3, ofile4, totalLines);

		ifile1.close();
		ifile2.close();
		ofile3.close();
		ofile4.close();

		//Check if the number of lines in the file has reached the totalLines.
		//if it has, merge the files and write the sort to the output file.
		if (linesMerged >= totalLines)
		{
			ifile3.open(fileName3);
			ifile4.open(fileName4);

			merge(ifile3, ifile4, output);

			ifile3.close();
			ifile4.close();
			break;
		}
		//Close used files.
		ifile1.close();
		ifile2.close();
		ofile3.close();
		ofile4.close();

		//Open files and do the same check for files 1 and 2 and then close.
		ifile3.open(fileName3);
		ifile4.open(fileName4);
		ofile1.open(fileName1);
		ofile2.open(fileName2);

		linesMerged = mergePass(ifile3, ifile4, ofile1, ofile2, totalLines);
		
		ifile3.close();
		ifile4.close();
		ofile1.close();
		ofile2.close();
	
		//Check if the number of lines in the file has reached the totalLines.
		//if it has, merge the files and write the sort to the output file.
		if (linesMerged >= totalLines)
		{
			ifile1.open(fileName1);
			ifile2.open(fileName2);

			merge(ifile1, ifile2, output);

			ifile1.close();
			ifile2.close();
			break;
		}
	}//end while
}

//This function merges the runs and returns the number of NumberLines in the larger file.
int ExternalMergeSort::mergePass(istream& input1, istream& input2, ostream& output1, ostream& output2, int totalLines)
{
	//Stores the number of NumberLines in each file.
	int linesMergedInput1 = 0;
	int linesMergedInput2 = 0;

	//Keep merging until the total number of unsorted data is reached.
	while ((linesMergedInput1+ linesMergedInput2) < totalLines)
	{
		linesMergedInput1 += merge(input1, input2, output1);
		linesMergedInput2 += merge(input1, input2, output2);
	}
	
	//returns the larger number.
	if (linesMergedInput1 > linesMergedInput2)
		return linesMergedInput1;
	else
		return linesMergedInput2;
}

//Merge sort performed with NumberLine array.
NumberLine* ExternalMergeSort::sort(NumberLine* unsortedArray, int arraySize)
{
	int sortSize = arraySize / 2;

	if (arraySize > 1) //check if the array only has 1 item in it.
		return merge(sort(unsortedArray, sortSize), sortSize, sort(&unsortedArray[sortSize], arraySize - (sortSize)), arraySize - (sortSize));
	else
		return unsortedArray;
}

//Merging algorithm for merge sort
//Merges a NumberLine array.
NumberLine* ExternalMergeSort::merge(NumberLine* leftArray, int leftSize, NumberLine* rightArray, int rightSize)
{
	int tempArraySize = leftSize + rightSize;
	NumberLine* tempArray = new NumberLine[tempArraySize];
	int leftIndex = 0;
	int rightIndex = 0;

	//loops until tempArraySize to sort the run.
	for (int i = 0; i < tempArraySize; i++)
	{
		if (leftIndex >= leftSize)
			tempArray[i] = rightArray[rightIndex++];
		else if (rightIndex >= rightSize)
			tempArray[i] = leftArray[leftIndex++];
		else if (leftArray[leftIndex] <= rightArray[rightIndex])
			tempArray[i] = leftArray[leftIndex++];
		else
			tempArray[i] = rightArray[rightIndex++];
	}

	return tempArray;
}

//merges the runs from both files.
//returns the total number of records.
int ExternalMergeSort::merge(istream& file1, istream& file2, ostream& output)
{
	int i = 0; //number of records.
	NumberLine numberLine1, numberLine2;
	bool isFile1Empty = false;
	bool isFile2Empty = false;

	//Inputs the two numbers from each file run.
	file1 >> std::ws; //consumes whitespace
	if (file1.peek() != EOF && file1.peek() != runDelimeter)
		file1 >> numberLine1;
	else
		isFile1Empty = true;

	file2 >> std::ws; //consumes whitespace
	if (file2.peek() != EOF && file2.peek() != runDelimeter)
		file2 >> numberLine2;
	else
		isFile2Empty = true;

	//Checks if either file is empty, then set the flag to true.
	//Checks if the end of file has been reached or if the delimeter has
	//been reached. Inputs the correct number based on condition.
	for (;!isFile1Empty || !isFile2Empty; i++)
	{
		if (isFile1Empty)
		{
			output << numberLine2 << endl;
			file2 >> std::ws; //consume whitespace
			if (file2.peek() != EOF && file2.peek() != runDelimeter)
				file2 >> numberLine2;
			else
				isFile2Empty = true;
		}
		else if (isFile2Empty)
		{
			output << numberLine1 << endl;
			file1 >> std::ws;//consume whitespace
			if (file1.peek() != EOF && file1.peek() != runDelimeter)
				file1 >> numberLine1;
			else
				isFile1Empty = true;
		}
		else if (numberLine1 <= numberLine2)
		{
			output << numberLine1 << endl;
			file1 >> std::ws;//consume whitespace
			if (file1.peek() != EOF && file1.peek() != runDelimeter)
				file1 >> numberLine1;
			else
				isFile1Empty = true;
		}
		else
		{
			output << numberLine2 << endl;
			file2 >> std::ws;//consume whitespace
			if (file2.peek() != EOF && file2.peek() != runDelimeter)
				file2 >> numberLine2;
			else
				isFile2Empty = true;
		}
	}//end for loop

	//Get rid of runDelimeter
	char temp;
	file1 >> temp;
	file2 >> temp;

	//set the delimeter at the end of the total run.
	if (i > 0)
		output << runDelimeter << endl;

	//returns the total number of records.
	return i;
}