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
	if (tail > 7)
	{
		tail = 0;
		//throw logic_error("The queue is full.");
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
