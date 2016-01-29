#include "Stack.h"
#include <array>
#include <iostream>

using namespace std;

void Stack::ResizeArray(int size)
{
	auto tmpArr = arr;
	arr = new string[size];

	for (auto i = 0; i < count; i++)
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
	this->arr = new string[size];
}

Stack::Stack(const Stack& obj)
{
	arr = obj.arr;
	top = obj.top;
	size = obj.size;
	count = obj.count;
}

Stack::~Stack()
{
	if (arr) delete [] arr;
}

bool Stack::IsEmpty() const
{
	return count == 0;
}

void Stack::Push(string str)
{
	if (top + 1 >= size)
	{
		size *= 2;
		ResizeArray(size);
	}

	arr[++top] = str;
	count++;
}

string Stack::Pop()
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

string Stack::Peek() const
{
	if (IsEmpty())
	{
		throw logic_error("The stack is empty.");
	}

	return arr[top];
}
