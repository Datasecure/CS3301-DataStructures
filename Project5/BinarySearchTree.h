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
	int size;
	int rootIndex;
	bool isEmpty() const;

	BinaryTreeNode nodeArray[MAX_NODES];

	string inorderTraversal();
	string preorderTraversal();
	string postOrderTraversal();

	int findHelper(int index, int value) const;
	int insertHelper(int index, int data);
	int deleteHelper(int index, int value);

	static BinaryTreeNode createNode(int data) {
		auto node = BinaryTreeNode();

		node.data = data;
		node.leftndex = NULL;
		node.rightIndex = NULL;

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

	string Traversal(TraversalType traversal) {
		string result;

		switch (traversal) {
		case Inorder:
			result = inorderTraversal();
			break;
		case Preorder:
			result = preorderTraversal();
			break;
		case Postorder:
			result = postOrderTraversal();
			break;
		default:
			result = "";
			break;
		}

		return result;
	};
};

