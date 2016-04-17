#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(34); 
	bst.Insert(24);
	bst.Insert(6);
	bst.Insert(12);
	bst.Insert(30);
	bst.Insert(88);
	bst.Insert(90);
	bst.Insert(42);
	bst.Insert(57);
	bst.Insert(102);

	cout << "Min: " + to_string(bst.FindMin()) << endl;
	cout << "Max: " + to_string(bst.FindMax()) << endl;

	string find1 = bst.Find(100) > -1 ? "true" : "false";
	string find2 = bst.Find(88) > -1 ? "true" : "false";

	cout << "100 in tree? " + find1 << endl;
	cout << "88 in tree? " + find2 << endl;

	bst.Traverse(Inorder);
	cout << endl;

	bst.Delete(30);

	bst.Traverse(Inorder);
	cout << endl;
	

	cin.get();
}