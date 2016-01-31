#pragma once
class Queue
{
	int array[8];
	int head;
	int tail;
	int count;

public:
	Queue();
	virtual ~Queue();

	bool IsEmpty() const;
	void Enqueue(int number);
	int Dequeue();
	int Peek();

	int Size() const
	{
		return 0;
	}
};

