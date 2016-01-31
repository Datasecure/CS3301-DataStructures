#pragma once
class Node
{
	int _data;
	
public:
	Node* Next;

	explicit Node(int data);
	virtual ~Node();

	int Data() const
	{
		return _data;
	}
};

