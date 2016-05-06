#pragma once
#include <vector>

using namespace std;

inline int Partition(vector<int> *xs, int head, int tail)
{
	int midPoint = (tail + head) / 2;
	int pivot = xs->at(midPoint);

	swap((*xs)[head], (*xs)[midPoint]);

	int left = head + 1;
	int right = tail;

	while (left <= right)
	{
		while (left <= right && xs->at(left) <= pivot) left++;
		while (left <= right && xs->at(right) > pivot) right--;

		if (left < right)
		{
			swap((*xs)[left], (*xs)[right]);
		}
	}

	left--;

	swap((*xs)[left], (*xs)[head]); //Swap back to proper position

	return left;
}

inline void QuickSort(vector<int> *xs, int head, int tail) {
	if (head >= tail)
		return;

	int partition = Partition(xs, head, tail);

	QuickSort(xs, head, partition - 1);
	QuickSort(xs, partition + 1, tail);
}

inline void Merge(vector<int> *xs, int head, int midpoint, int tail)
{
	auto left = vector<int>();
	auto right = vector<int>();
	auto leftCount = midpoint - head;
	auto rightCount = tail - midpoint;

	for (int i = 0; i <= leftCount; i++)
		left.push_back(xs->at(head + i));
	for (int i = 0; i < rightCount; i++)
		right.push_back(xs->at(midpoint + i + 1));

	auto leftIdx = 0;
	auto rightIdx = 0;
	auto mergeIdx = head;

	while (leftIdx <= leftCount && rightIdx < rightCount)
	{
		if (left[leftIdx] <= right[rightIdx])
		{
			(*xs)[mergeIdx] = left[leftIdx++];
		}
		else
		{
			(*xs)[mergeIdx] = right[rightIdx++];
		}

		mergeIdx++;
	}

	while (leftIdx <= leftCount)	
		(*xs)[mergeIdx++] = left[leftIdx++];

	while (rightIdx < rightCount)
		(*xs)[mergeIdx++] = right[rightIdx++];
}

inline void MergeSort(vector<int> *xs, int head, int tail)
{
	if (xs->size() <= 0)
		return;

	if (head >= tail)
		return;

	int midpoint = (head + tail) / 2;

	MergeSort(xs, head, midpoint);
	MergeSort(xs, midpoint + 1, tail);
	
	Merge(xs, head, midpoint, tail);
}
