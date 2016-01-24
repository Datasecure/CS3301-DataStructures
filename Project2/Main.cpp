#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack stack;

	stack.Push(4);
	stack.Push(3);
	stack.Push(2);
	stack.Push(0);


	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;

	cin.get();

	return 0;
}