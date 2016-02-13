#include "Queue.h"
#include <stdexcept>

using namespace std;

Queue::Queue()
{
	count = 0;
	head = tail = 0;
}


Queue::~Queue()
{
	
}

bool Queue::IsEmpty() const
{
	return count == 0;
}

void Queue::Enqueue(int number)
{
	if (count == 8)
	{
		throw logic_error("The queue is full.");
	}
	
	if (tail > 7)
	{
		tail = 0;
	}

	array[tail++] = number;
	count++;
}

int Queue::Dequeue()
{
	if (IsEmpty())
	{
		throw logic_error("The queue is empty.");
	}

	if (head == 8)
	{
		head = 0;
	}

	count--;
	return array[head++];
}

int Queue::Peek()
{
	if (IsEmpty())
	{
		throw logic_error("The queue is empty.");
	}

	return array[head];
}
