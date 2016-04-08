//Driver Implementation Class

#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ExternalMergeSort.h"
#include "ISort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

//Initial Array Size and Unsorted Array
const int arraySize = 100000;
static int unsortedArray[arraySize];

//Generates the copy to be used with all sorting algorithms.
int* generateCopy()
{
	int* copiedArray = new int[arraySize];

	//copying the array.
	for (int i = 0; i < arraySize; i++)
		copiedArray[i] = unsortedArray[i];

	return copiedArray;
}

//Opens the Read file.
ifstream openFileRead(string textName)
{
	ifstream fin;
	fin.open(textName);

	//Verifying if file encountered a failure and if file is open
	if (fin.fail() || !fin.is_open())
		cout << "Input file opening failed.";

	return fin;
}

//Opens the Write file.
ofstream openFileWrite(string outText)
{
	ofstream fout;
	fout.open(outText);

	//Verifying if file encountered a failure and if file is open
	if (fout.fail() || !fout.is_open())
		cout << "Output file opening failed.";

	return fout;
}

//Opens the Read/Write file.
fstream openFileReadWrite(string outText)
{
	fstream fio;
	fio.open(outText);

	//Verifying if file encountered a failure and if file is open
	if (fio.fail() || !fio.is_open())
		cout << "File opening failed.";

	return fio;
}

//Displays the Timer to the Console.
void displayStartEndTime(time_t startTime, time_t endTime, string sortType)
{
	struct tm now;
	localtime_s(&now, &startTime);
	cout << sortType << endl;
	cout << "Start Time: " << now.tm_hour << ':' << now.tm_min << ':' << now.tm_sec << endl;
	localtime_s(&now, &endTime);
	cout << "End Time: " << now.tm_hour << ':' << now.tm_min << ':' << now.tm_sec << endl <<endl;
}

//Performs the passed in sort functions.
void performSort(ISort* sorter, ofstream& fout, string sortType)
{
	int* arrayCopy = generateCopy(); //creates the unsorted array copy.
	time_t startTime = time(0); //sets the start time.
	int* sortedArray = sorter->sort(arrayCopy, arraySize); //performs sort.
	time_t endTime = time(0); //sets the end time.
	displayStartEndTime(startTime, endTime, sortType); //displays to console.

	//Writes to the file.
	fout << sortType << endl;
	fout << "------------" << endl;
	for (int i = 0; i < arraySize; i++)
		fout << sortedArray[i] << endl;

	fout.close();
}

//Creates the file with the unsorted array and line numbers
//to be used for the External Merge Sort algorithm.
void createSeedFile()
{
	int*externalUnsorted = generateCopy(); //generates the copy.
	ofstream fout = openFileWrite("externalUnsorted.txt"); //output file.

	//Write elements to the output file.
	for (int i = 0; i < arraySize; i++)
		fout << externalUnsorted[i] << "\t Line " << i << endl;

	fout.close();
}

int main()
{
	//Creates the unsorted array.
	ArrayGenerator myArray;
	myArray.populateArray(unsortedArray, arraySize);

	cout << "Welcome to the Sorting Application!" << endl <<endl;

	//Performs the requested sorting algorithms.
	performSort(new BubbleSort(), openFileWrite("bubbleSort.txt"), "Bubble Sort: ");
	performSort(new SelectionSort(), openFileWrite("selectionSort.txt"), "Selection Sort: ");
	performSort(new InsertionSort(), openFileWrite("insertionSort.txt"), "Insertion Sort: ");
	performSort(new ShellSort(), openFileWrite("shellSort.txt"), "Shell Sort: ");
	performSort(new MergeSort(), openFileWrite("mergeSort.txt"), "Merge Sort: ");
	performSort(new QuickSort(), openFileWrite("quickSort.txt"), "Quick Sort: ");

	//External Merge Sort
	//Create the file used for External Merge Sort.
	//createSeedFile();

	//Performing the External Merge Sort
	ExternalMergeSort externalMergeSort;

	//Opening the files to be used.
	ifstream inputFile = openFileRead("externalUnsorted.txt");
	ofstream outputFile = openFileWrite("externalSorted.txt");
	const string fileName1 = "file1.txt";
	const string fileName2 = "file2.txt";
	const string fileName3 = "file3.txt";
	const string fileName4 = "file4.txt";

	time_t startTime = time(0); //sets the start time.
	externalMergeSort.sort(inputFile,fileName1, fileName2, fileName3, fileName4, outputFile);
	time_t endTime = time(0); //sets the end time.
	displayStartEndTime(startTime, endTime, "External Merge Sort: "); //Writes times to console.

	_getch();
}