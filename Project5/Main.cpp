#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(3); 
	bst.Insert(1);
	bst.Insert(5);

	bst.Traverse(Inorder);
	cout << endl;
	bst.Traverse(Preorder);
	cout << endl;
	bst.Traverse(Postorder);
	cout << endl;

	cout << to_string(bst.Find(3)) << endl;
	cout << to_string(bst.FindMin()) << endl;
	cout << to_string(bst.FindMax()) << endl;

	cin.get();
}