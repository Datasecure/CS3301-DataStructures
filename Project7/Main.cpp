#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <time.h>
#include <vector>
#include "FastSort.h"

using namespace std;

void WriteToFile(string file, vector<int> data) 
{
	ofstream output_file(file);
	ostream_iterator<int> output_iterator(output_file, "\n");
	copy(data.begin(), data.end(), output_iterator);
}

int main()
{
	ifstream file("C:\\code\\DataStructures\\Project7\\testdata.txt");
	string str;

	auto v1 = vector<int>();
	
	while (getline(file, str))
	{
		v1.push_back(stoi(str));
	}

	auto v2 = v1;

	clock_t start;

	start = clock();
	QuickSort(&v1, 0, v1.size() - 1);
	printf("Quick Sort: %2.2f\n", (clock() - start) / double(CLOCKS_PER_SEC));

	start = clock();
	MergeSort(&v2, 0, v1.size() - 1);
	printf("Merge Sort: %2.2f\n", (clock() - start) / double(CLOCKS_PER_SEC));

	cout << "Writing..." << endl;

	WriteToFile("C:\\code\\DataStructures\\Project7\\quicksorted.txt", v1);
	WriteToFile("C:\\code\\DataStructures\\Project7\\mergesorted.txt", v2);

	cout << "Finished." << endl;
	cin.get();

	return 0;
}

