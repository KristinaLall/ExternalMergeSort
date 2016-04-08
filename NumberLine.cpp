//NumberLine Class Implementation file

#include "NumberLine.h"
#include <string>
using namespace std;

//Constructor & Destructor
NumberLine::NumberLine(){}
NumberLine::~NumberLine(){}

//Setters and Getters
void NumberLine::setNumber(int number) { this->number = number; }
int NumberLine::getNumber() { return this->number; }
void NumberLine::setLineNumber(int lineNumber){ this->lineNumber = lineNumber; }
int NumberLine::getLineNumber(){ return this->lineNumber; }

//Overloaded Compare Functions
bool NumberLine::operator<= (NumberLine &rightObj)
{
	return (this->getNumber() <= rightObj.getNumber());
}

//Overloading the input operator
void operator>>(istream& input, NumberLine& numberLine)
{
	string temp;

	//inputs the line from the file.
	input >> numberLine.number;
	input >> temp;
	input >> numberLine.lineNumber;
}

//Overloading the output operator.
ostream& operator<<(ostream& output, NumberLine& numberLine)
{
	//outputs the line to the file.
	output << numberLine.number <<"\tLine " << numberLine.lineNumber;
	return output;
}



