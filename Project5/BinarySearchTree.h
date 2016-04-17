#pragma once
#include <string>

using namespace std;

enum TraversalType {
	Inorder,
	Preorder,
	Postorder
};

#define MAX_NODES 100
#define LEFT_CHILD 0
#define RIGHT_CHILD 1

class BinarySearchTree
{
private :
	int _data[MAX_NODES];

	static tuple<int, int> getChildIndexes(int index);
	tuple<int, int> getChildren(int index) const;
	bool isEmpty() const;
	void inorderTraversal(int index) const;
	void preorderTraversal(int index) const;
	void postOrderTraversal(int index) const;
	int deleteHelper(int index, int data);
	int findMinHelper(int index = 0) const;
	int findMaxHelper(int index = 0) const;

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &obj);
	virtual ~BinarySearchTree();

	int Find(int value) const;
	int FindMin(int index = 0) const;
	int FindMax(int index = 0) const;
	bool Insert(int data);
	bool Delete(int data);

	void Traverse(TraversalType traversal) const
	{
		switch (traversal) {
		case Inorder:
			inorderTraversal(0);
			break;
		case Preorder:
			preorderTraversal(0);
			break;
		case Postorder:
			postOrderTraversal(0);
			break;
		}
	};
};

