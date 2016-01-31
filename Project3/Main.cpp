#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);

	cout << queue.Dequeue() << endl;

	queue.Enqueue(50);
	queue.Enqueue(60);
	queue.Enqueue(70);
	queue.Enqueue(80);
	queue.Enqueue(90);
	queue.Enqueue(100);

	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;

	queue.Enqueue(110);

	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;

	cin.get();

	return 0;
}