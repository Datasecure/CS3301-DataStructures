#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Sort.h"

using namespace std;

int main()
{
	ifstream file("C:\\code\\DataStructures\\Project6\\sortingdata.txt");
	string str;

	auto sorter = Sort();
	auto v = vector<int>();

	while (getline(file, str))
	{
		v.push_back(stoi(str));
	}

	clock_t start;

	start = clock();
	auto sort1 = sorter.InsertionSort(v);
	printf("Insertion Sort: %2.2f\n", (clock() - start) / (double) CLOCKS_PER_SEC);

	start = clock();
	auto sort2 = sorter.SelectionSort(v);
	printf("Selection Sort: %2.2f\n", (clock() - start) / (double)CLOCKS_PER_SEC);

	start = clock();
	auto sort3 = sorter.ExchangeSort(v);
	printf("Exchange Sort: %2.2f\n", (clock() - start) / (double)CLOCKS_PER_SEC);

	cout << "Writing..." << endl;

	sorter.WriteToFile("C:\\code\\DataStructures\\Project6\\insertionsorted.txt", sort1);
	sorter.WriteToFile("C:\\code\\DataStructures\\Project6\\selectionsorted.txt", sort2);
	sorter.WriteToFile("C:\\code\\DataStructures\\Project6\\exchangesorted.txt", sort3);

	cout << "Finished." << endl;
	cin.get();

	return 0;
}