#include "Stack.h"
#include <array>
#include <iostream>

using namespace std;

void Stack::ResizeArray(int size)
{
	auto tmpArr = arr;
	arr = new int[size];

	for (unsigned i = 0; i < count; i++)
	{
		arr[i] = tmpArr[i];
	}

	delete [] tmpArr;	
}

Stack::Stack()
{
	this->top = -1;
	this->count = 0;
	this->size = 2;
	this->arr = new int[size];
}


Stack::~Stack()
{
	if (arr) delete [] arr;
}

bool Stack::IsEmpty() const
{
	return count == 0;
}

void Stack::Push(int number)
{
	if (top + 1 >= size)
	{
		size *= 2;
		ResizeArray(size);
	}

	arr[++top] = number;
	count++;
}

int Stack::Pop()
{
	if (IsEmpty() || top < 0)
	{
		throw logic_error("The stack is empty.");
	}

	if (top > 2 && top < size / 4)
	{
		size /= 2;
		ResizeArray(size);
	}

	auto value = arr[top--];
	count--;

	return value;
}

int Stack::Peek() const
{
	if (IsEmpty())
	{
		throw logic_error("The stack is empty.");
	}

	return arr[top];
}
