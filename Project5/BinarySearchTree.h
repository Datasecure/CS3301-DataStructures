#pragma once
#include <string>

using namespace std;

enum TraversalType {
	Inorder,
	Preorder,
	Postorder
};

#define MAX_NODES 100

class BinarySearchTree
{
private :
	int _data[MAX_NODES];
	int size;

	bool isEmpty() const;

	void inorderTraversal(int index) const;
	void preorderTraversal(int index) const;
	void postOrderTraversal(int index) const;

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &obj);
	virtual ~BinarySearchTree();

	int Find(int value) const;
	int FindMin() const;
	int FindMax() const;
	bool Insert(int data);
	void Delete(int data);

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

