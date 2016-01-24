#pragma once
#include <array>

using namespace std;

class Stack
{
	//Fields
	int* arr;
	int count;
	int size;
	int top;
	void ResizeArray(int size);

public:
	//Constructors
	Stack();
	virtual ~Stack();

	//Members
	bool IsEmpty() const;
	void Push(int number);
	int Pop();
	int Peek() const;
};

