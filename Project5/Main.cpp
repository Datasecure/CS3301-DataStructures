#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(8); 
	bst.Insert(6);
	bst.Insert(4);
	bst.Insert(7);
	bst.Insert(9);
	bst.Insert(11);

	bst.Traverse(Inorder);
	cout << endl;
	bst.Traverse(Preorder);
	cout << endl;
	bst.Traverse(Postorder);
	cout << endl;

	cout << to_string(bst.Find(3)) << endl;
	cout << to_string(bst.FindMin()) << endl;
	cout << to_string(bst.FindMax()) << endl;

	bst.Delete(9);
	bst.Traverse(Preorder);
	cout << endl;

	cin.get();
}