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

	auto v = vector<int>();

	while (getline(file, str))
	{
		v.push_back(stoi(str));
	}

	clock_t start;

	start = clock();
	QuickSort(&v, 0, v.size() - 1);
	printf("Quick Sort: %2.2f\n", (clock() - start) / double(CLOCKS_PER_SEC));

	cout << "Writing..." << endl;

	WriteToFile("C:\\code\\DataStructures\\Project7\\quicksorted.txt", v);

	cout << "Finished." << endl;
	cin.get();

	return 0;
}

