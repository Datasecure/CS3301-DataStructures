#include "BinarySearchTree.h"
#include <tuple>
#include <iostream>

void BinarySearchTree::preorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	auto children = getChildren(index);

	cout << to_string(_data[index]) << " ";
	preorderTraversal(get<LEFT_CHILD>(children));
	preorderTraversal(get<RIGHT_CHILD>(children));
}

void BinarySearchTree::inorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	auto children = getChildren(index);

	inorderTraversal(get<LEFT_CHILD>(children));
	cout << to_string(_data[index]) << " ";
	inorderTraversal(get<RIGHT_CHILD>(children));
}

void BinarySearchTree::postOrderTraversal(int index) const
{
	if (_data[index] < 0)
		return;
	auto children = getChildren(index);

	postOrderTraversal(get<LEFT_CHILD>(children));
	postOrderTraversal(get<RIGHT_CHILD>(children));
	cout << to_string(_data[index]) << " ";
}

tuple<int, int> BinarySearchTree::getChildren(int index)
{
	return make_tuple(2 * index + 1, 2 * index + 2);
}

bool BinarySearchTree::isEmpty() const
{
	return _data[0] < 0;
}

BinarySearchTree::BinarySearchTree()
{
	for (auto i = 0; i < MAX_NODES; i++) {
		_data[i] = -1;
	}
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& obj)
{
	for (auto i = 0; i < MAX_NODES; i++) {
		_data[i] = obj._data[i];
	}
}

BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::Delete(int data)
{
	if (isEmpty())
		return false;

	auto index = Find(data);
	auto children = getChildren(index);

	if (index < 0)
	{
		return false;
	}


	if (_data[get<LEFT_CHILD>(children)] < 0 && _data[get<RIGHT_CHILD>(children)] < 0)	//Leaf node
	{
		_data[index] = -1;
	}
	else if (data == 0)	//One child
	{
	}
	else //Two children
	{
	}

	return true;

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

		auto children = getChildren(currIndex);

		if (data <= _data[currIndex])
		{
			currIndex = get<LEFT_CHILD>(children);
		}
		else
		{
			currIndex = get<RIGHT_CHILD>(children);
		}
	}

	_data[currIndex] = data;

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

		currIndex = get<RIGHT_CHILD>(getChildren(currIndex));
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

		currIndex = get<LEFT_CHILD>(getChildren(currIndex));
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
		auto children = getChildren(currIndex);

		if (value == currValue)
			return currIndex;
		
		if (value <= currValue)
		{
			currIndex = get<LEFT_CHILD>(children);
		}
		else
		{
			currIndex = get<RIGHT_CHILD>(children);
		}
	}

	return -1;
}