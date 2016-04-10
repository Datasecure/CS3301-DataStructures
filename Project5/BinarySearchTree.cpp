#include "BinarySearchTree.h"
#include <tuple>
#include <iostream>

void BinarySearchTree::preorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	auto children = getChildIndexes(index);

	cout << to_string(_data[index]) << " ";
	preorderTraversal(get<LEFT_CHILD>(children));
	preorderTraversal(get<RIGHT_CHILD>(children));
}

void BinarySearchTree::inorderTraversal(int index) const
{
	if (_data[index] < 0)
		return;

	auto children = getChildIndexes(index);

	inorderTraversal(get<LEFT_CHILD>(children));
	cout << to_string(_data[index]) << " ";
	inorderTraversal(get<RIGHT_CHILD>(children));
}

void BinarySearchTree::postOrderTraversal(int index) const
{
	if (_data[index] < 0)
		return;
	auto children = getChildIndexes(index);

	postOrderTraversal(get<LEFT_CHILD>(children));
	postOrderTraversal(get<RIGHT_CHILD>(children));
	cout << to_string(_data[index]) << " ";
}

int BinarySearchTree::deleteHelper(int root, int data)
{
	if (root >= MAX_NODES || _data[root] < 0)
	{
		return root;
	}

	auto indexChildren = getChildIndexes(root);
	auto leftChildIndex = get<LEFT_CHILD>(indexChildren);
	auto rightChildIndex = get<RIGHT_CHILD>(indexChildren);

	if (data < _data[root])
	{	
		_data[leftChildIndex] = deleteHelper(leftChildIndex, data);
	}
	else if (data > _data[root])
	{
		_data[rightChildIndex] = deleteHelper(rightChildIndex, data);
	}
	else
	{
		auto children = getChildren(root);
		auto leftChild = get<LEFT_CHILD>(children);
		auto rightChild = get<RIGHT_CHILD>(children); 

		if (leftChild < 0 && rightChild < 0)	//Leaf node
		{
			_data[root] = -1;
		}
		else if ((leftChild >= 0 && rightChild < 0) || (leftChild < 0 && rightChild >= 0))	//One child
		{
			//Move up
		}
		else //Two children
		{
			auto indexOfMin = FindMin(get<RIGHT_CHILD>(getChildIndexes(root)));
			auto tmp = _data[root] = data;
			_data[root] = _data[indexOfMin];
			_data[indexOfMin] = tmp;

			deleteHelper(rightChildIndex, data);
		}
	}	

	return root;
}

tuple<int, int> BinarySearchTree::getChildIndexes(int index)
{
	return make_tuple(2 * index + 1, 2 * index + 2);
}

tuple<int, int> BinarySearchTree::getChildren(int index) const
{
	if (index < 0 || index > MAX_NODES - 1)
	{
		//throw some type of error
	}

	auto childIndexes = getChildIndexes(index);

	return make_tuple(_data[get<LEFT_CHILD>(childIndexes)], _data[get<RIGHT_CHILD>(childIndexes)]);
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

	if (data < 0)
	{
		return false;
	}

	return deleteHelper(0, data) >= 0;
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

		auto children = getChildIndexes(currIndex);

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

int BinarySearchTree::FindMax(int index) const
{
	if (isEmpty())
	{
		return -1;
	}

	while (index < MAX_NODES && get<RIGHT_CHILD>(getChildren(index)) >= 0)
	{
		index = get<RIGHT_CHILD>(getChildIndexes(index));
	}

	return index;
}

int BinarySearchTree::FindMin(int index) const
{
	if (isEmpty())
	{
		return -1;
	}

	while (index < MAX_NODES && get<LEFT_CHILD>(getChildren(index)) >= 0)
	{
		index = get<LEFT_CHILD>(getChildIndexes(index));
	}

	return index;
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
		auto children = getChildIndexes(currIndex);

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