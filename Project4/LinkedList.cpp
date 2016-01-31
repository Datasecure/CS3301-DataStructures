#include "LinkedList.h"



LinkedList::LinkedList()
{
	head = nullptr;
}


LinkedList::~LinkedList()
{
	auto node = head;

	while (node != nullptr)
	{
		
	}
}

void LinkedList::Insert(int value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}
	else
	{
		auto currentNode = head;

		while (currentNode->Next != nullptr && currentNode->Data() >= value)
		{
			currentNode = currentNode->Next;
		}
	}
}
