#include "BinarySearchTree.h"
#include <iostream>

void BinarySearchTree::preorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	cout << to_string(_data[index]) << " ";
	preorderTraversal(2 * index + 1);
	preorderTraversal(2 * index + 2);
}

void BinarySearchTree::inorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	inorderTraversal(2 * index + 1);
	cout << to_string(_data[index]) << " ";
	inorderTraversal(2 * index + 2);
}

void BinarySearchTree::postOrderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	postOrderTraversal(2 * index + 1);
	postOrderTraversal(2 * index + 2);
	cout << to_string(_data[index]) << " ";
}

bool BinarySearchTree::isEmpty() const
{
	return _data[0] < 0;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& obj)
{
}

BinarySearchTree::BinarySearchTree()
{
	for (auto i = 0; i < MAX_NODES; i++) {
		_data[i] = -1;
	}
}

void BinarySearchTree::Delete(int data)
{
	return;
}

bool BinarySearchTree::Insert(int data)
{
	auto currIndex = 0;

	while (_data[0] > -1)
	{
		if (currIndex >= MAX_NODES)
			return false;

		if (_data[currIndex] < 0)
			break;

		if (data <= _data[currIndex])
		{
			currIndex = 2 * currIndex + 1;
		}
		else
		{
			currIndex = 2 * currIndex + 2;
		}
	}

	_data[currIndex] = data;
	size++;

	return true;
}

int BinarySearchTree::FindMax() const
{
	if (isEmpty())
	{
		return -1;
	}

	auto currIndex = 0;

	while (true)
	{
		if (_data[currIndex] < 0)
			break;

		currIndex = 2 * currIndex + 2;
	}

	return currIndex;
}

int BinarySearchTree::FindMin() const
{
	if (isEmpty())
	{
		return -1;
	}

	auto currIndex = 0;

	while (true)
	{
		if (_data[currIndex] < 0)
			break;

		currIndex = 2 * currIndex + 1;
	}

	return currIndex;
}

int BinarySearchTree::Find(int value) const
{
	if (isEmpty())
	{
		return -1;
	}

	auto currIndex = 0;

	while (_data[currIndex] > -1)
	{
		auto currValue = _data[currIndex];

		if (value <= currValue)
		{
			currIndex = 2 * currIndex + 1;
		}
		else if (value > currValue)
		{
			currIndex = 2 * currIndex + 2;
		}
		else if (value == currValue)
		{
			return currIndex;
		}
	}

	return -1;
}

BinarySearchTree::~BinarySearchTree()
{
}
