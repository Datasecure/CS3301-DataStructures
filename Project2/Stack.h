#pragma once
#include <array>

using namespace std;

class Stack
{
	//Fields
	string* arr;
	int count;
	int size;
	int top;
	void ResizeArray(int size);

public:
	//Constructors
	Stack();
	Stack(const Stack& obj);
	virtual ~Stack();

	//Members
	bool IsEmpty() const;
	void Push(string str);
	string Pop();
	string Peek() const;

	//Properties
	int Count() const
	{ return count; }
};

