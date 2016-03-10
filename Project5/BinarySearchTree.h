#pragma once
#include <string>

using namespace std;

enum TraversalType {
	Inorder,
	Preorder,
	Postorder
};

struct BinaryTreeNode {
	int data;
	int leftndex;
	int rightIndex;
};

#define MAX_NODES 100

class BinarySearchTree
{
private :
	BinaryTreeNode nodeArray[MAX_NODES];
	int size;
	int rootIndex;

	bool isEmpty() const;

	string inorderTraversal(int index, string str = "") const;
	string preorderTraversal(int index, string str = "") const;
	string postOrderTraversal(int index, string str = "") const;

	int findHelper(int index, int value) const;
	int insertHelper(int index, int data);
	int deleteHelper(int index, int value);

	static BinaryTreeNode createNode(int data) {
		auto node = BinaryTreeNode();

		if (data < 0)
		{
			data = 0;
		}

		node.data = data;
		node.leftndex = -1;
		node.rightIndex = -1;

		return node;
	};

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &obj);
	virtual ~BinarySearchTree();

	int Find(int value) const;
	int FindMin() const;
	int FindMax() const;
	void Insert(int data);
	void Delete(int data);

	string Traverse(TraversalType traversal) const
	{
		if (isEmpty() || rootIndex == -1)
		{
			return "";
		}

		string result;

		switch (traversal) {
		case Inorder:
			result = inorderTraversal(rootIndex);
			break;
		case Preorder:
			result = preorderTraversal(rootIndex);
			break;
		case Postorder:
			result = postOrderTraversal(rootIndex);
			break;
		default:
			result = "";
			break;
		}

		return result;
	};
};

