#pragma once
#include <vector>

using namespace std;

void print(vector<int> *a, int n)
{
	int i = 0;
	while (i < n) {
		std::cout << a->at(i) << ",";
		i++;
	}
	std::cout << "\n";
}

inline int Partition(vector<int> *xs, int left, int right)
{
	int midPoint = (right - left) / 2;
	int pivot = xs->at(midPoint);

	swap((*xs)[left], (*xs)[midPoint]);

	int l = left + 1;
	int r = right;

	while (l <= r)
	{
		while (l <= r && xs->at(l) <= pivot) l++;
		while (l <= r && xs->at(r) > pivot) r--;

		if (l < r)
		{
			swap((*xs)[l], (*xs)[r]);
		}
	}

	swap((*xs)[l - 1], (*xs)[left]);

	return l - 1;
}

inline void QuickSort(vector<int> *xs, int left, int right) {
	if (left >= right)
		return;

	int partition = Partition(xs, left, right);
	std::cout << "QSC:" << left << "," << right << " part=" << partition << "\n";
	print(xs, xs->size());

	QuickSort(xs, left, partition - 1);
	QuickSort(xs, partition + 1, right);
}
