#include "BinarySearchTree.h"

int BinarySearchTree::insertHelper(int index, int data)
{
	auto currNode = nodeArray[index];

	if (currNode.data < 0)
	{
		nodeArray[index] = createNode(data);

		return index;
	}

	if (data > currNode.data)
	{
		return insertHelper(currNode.rightIndex, data);
	}

	return insertHelper(currNode.leftndex, data);
}

int BinarySearchTree::deleteHelper(int index, int value)
{
	return 0;
}

int BinarySearchTree::findHelper(int index, int value) const
{
	auto currNode = nodeArray[index];

	if (value == currNode.data)
	{
		return index;
	}

	if (value > currNode.data)
	{
		return findHelper(currNode.rightIndex, value);
	}

	if (value <= currNode.data)
	{
		return findHelper(currNode.leftndex, value);
	}

	return -1;
}

string BinarySearchTree::preorderTraversal(int index, string str) const
{
	if (index < 0)
	{
		return str;
	}

	auto node = nodeArray[index];

	str += to_string(node.data);
	preorderTraversal(node.leftndex, str);
	preorderTraversal(node.rightIndex, str);

	return str;
}

string BinarySearchTree::inorderTraversal(int index, string str) const
{
	if (index < 0)
	{
		return str;
	}

	auto node = nodeArray[index];

	inorderTraversal(node.leftndex, str);
	str += to_string(node.data);
	inorderTraversal(node.rightIndex, str);

	return str;
}

string BinarySearchTree::postOrderTraversal(int index, string str) const
{
	if (index < 0)
	{
		return str;
	}

	auto node = nodeArray[index];

	postOrderTraversal(node.leftndex, str);
	postOrderTraversal(node.rightIndex, str);
	str += to_string(node.data);

	return str;
}

bool BinarySearchTree::isEmpty() const
{
	return size <= 0;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& obj)
{
}

BinarySearchTree::BinarySearchTree()
{
	size = 0;
	rootIndex = -1;
}

void BinarySearchTree::Delete(int data)
{
	deleteHelper(rootIndex, data);
}

void BinarySearchTree::Insert(int data)
{
	if (isEmpty())
	{
		rootIndex = 0;
		nodeArray[rootIndex] = createNode(data);
		size++;
	}
	else
	{
		insertHelper(rootIndex, data);
	}
}

int BinarySearchTree::FindMax() const
{
	if (isEmpty())
	{
		return -1;
	}

	if (size == 1)
	{
		return rootIndex;
	}

	auto currIndex = rootIndex;

	while (nodeArray[currIndex].rightIndex != -1)
	{
		currIndex = nodeArray[currIndex].rightIndex;
	}

	return currIndex;
}

int BinarySearchTree::FindMin() const
{
	if (isEmpty())
	{
		return -1;
	}

	if (size == 1)
	{
		return rootIndex;
	}

	auto currIndex = rootIndex;

	while (nodeArray[currIndex].rightIndex != -1)
	{
		currIndex = nodeArray[currIndex].leftndex;
	}

	return currIndex;
}

int BinarySearchTree::Find(int value) const
{
	return findHelper(rootIndex, value);
}

BinarySearchTree::~BinarySearchTree()
{
}
