#include "Stack.h"
#include <array>
#include <iostream>

using namespace std;

void Stack::ResizeArray(int size)
{
	auto newArr = new int[size];

	for (auto i = 0; i < count; i++)
	{
		newArr[i] = this->arr[i];
	}

	delete [] this->arr;

	top = count;
	arr = newArr;
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
	if (this->arr) delete [] this->arr;
}

bool Stack::IsEmpty() const
{
	return count == 0;
}

void Stack::Push(int number)
{
	if (++top > size)
	{
		size *= 2;
		ResizeArray(size);
	}

	arr[top] = number;
	count++;
}

int Stack::Pop()
{
	if (IsEmpty() || top < 0)
	{
		throw logic_error("The stack is empty.");
	}

	auto value = arr[top--];
	count--;

	if (top > 2 && top < size / 4)
	{
		size /= 2;
		ResizeArray(size);
	}

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
