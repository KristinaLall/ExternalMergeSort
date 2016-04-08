//NumberLine Header file
//Interface for the class NumberLine

#ifndef NUMBERLINE_H
#define NUMBERLINE_H

#include <iostream>
using namespace std;

class NumberLine 
{
private:
	int number; //initial integer in the record.
	int lineNumber; //line number in the record.

public:
	//Constructor & Destructor
	NumberLine();
	virtual ~NumberLine();

	//Setters and Getters
	void setNumber(int number);
	int getNumber();
	void setLineNumber(int lineNumber);
	int getLineNumber();
	bool getIsValid();

	//Overloaded Compare Functions
	bool operator<= (NumberLine &rightObj);
	friend ostream& operator<<(ostream& output, NumberLine& numberLine);
	friend void operator>>(istream& input, NumberLine& numberLine);
};

#endif

