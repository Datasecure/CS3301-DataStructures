#pragma once
#include "Node.h"

class LinkedList
{
	Node* head;

public:
	LinkedList();
	virtual ~LinkedList();

	void Insert(int value);
};

