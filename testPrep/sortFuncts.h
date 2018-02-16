#pragma once
#include <vector>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

class sortFuncts
{
public:
	sortFuncts();
	~sortFuncts();

	vector<int> sortedInts;
	vector<char> sortedChars;
	vector<int> tempIntArray;

	// Insertion Sort
	void insertionSort(vector<int> &inArray);
	void shell_sort(vector<int> &inArray);

	// Merge Sorted Arrays
	vector<int> mergeSortedArrays(vector<int> v1, vector<int> v2);
	vector<int> merge3SortedArrays(vector<int> v1, vector<int> v2, vector<int> v3);

	// Merge Sort
	void mergeSortHelper(vector<int> &a, vector<int> &tmpA, int left, int right);
	void mergeSort(vector<int> &inArray);
	void finalMerge(vector<int> &srcV, vector<int> &tmpV, int left, int right, int end);
	vector<int> mergeSortHelperSubV(vector<int> a, vector<int> &tmpA, int left, int right);
	vector<int> mergeSortSubV(vector<int> inArray);

	// Quick Sort
	void quickSort(vector<int> &srcV);
	void qsortHelper(vector<int> &srcV);

	// Heap Sort
	vector<int> heapSort(vector<int> srcV);
	void perculateUp(vector<int> &h);
	void perculateDown(vector<int> &h);
	void insertIntoHeap(int x, vector<int> &h);
	int popRoot(vector<int> &h);
};

