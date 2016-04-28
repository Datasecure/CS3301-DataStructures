#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
#pragma once
class Sort
{
public:
	Sort();
	virtual ~Sort();

	static vector<int> InsertionSort(vector<int> data) {
		auto data_copy = data;
		auto size = data_copy.size();

		for (int i = 1; i < size; i++)
		{
			int element = data_copy[i];
			int j = i;

			while((j > 0) && (data_copy[j - 1] > element))
			{
				data_copy[j] = data_copy[j - 1];
				j--;
			}

			data_copy[j] = element;
		}

		return data_copy;
	}

	static vector<int> SelectionSort(vector<int> data) {
		auto data_copy = data;
		auto size = data.size();

		for (int i = 0; i < size; i++)
		{
			auto minIdx = i;
			auto j = i + 1;

			while (j < size - 1)
			{
				if (data_copy[minIdx] > data_copy[j])
				{
					minIdx = j;
				}
					
				j++;
			}

			auto tmp = data_copy[i];
			data_copy[i] = data_copy[minIdx];
			data_copy[minIdx] = tmp;
		}

		return data_copy;
	}

	static vector<int> ExchangeSort(vector<int> data) {
		auto data_copy = data;
		auto size = data.size();

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (data_copy[i] > data_copy[j])
				{
					auto tmp = data_copy[i];
					data_copy[i] = data_copy[j];
					data_copy[j] = tmp;
				}
			}
		}

		return data_copy;
	}

	static void WriteToFile(string file, vector<int> &data) {
		ofstream output_file(file);
		ostream_iterator<int> output_iterator(output_file, "\n");
		copy(data.begin(), data.end(), output_iterator);
	}
};

