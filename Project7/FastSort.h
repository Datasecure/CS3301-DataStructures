#pragma once
#include <vector>

using namespace std;

inline int Partition(vector<int> *xs, int left, int right)
{
	int midPoint = (right + left) / 2;
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

	l--;

	swap((*xs)[l], (*xs)[left]); //Swap back to proper position

	return l;
}

inline void QuickSort(vector<int> *xs, int left, int right) {
	if (left >= right)
		return;

	int partition = Partition(xs, left, right);

	QuickSort(xs, left, partition - 1);
	QuickSort(xs, partition + 1, right);
}
