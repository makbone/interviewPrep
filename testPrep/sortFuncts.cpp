#include "stdafx.h"
#include "sortFuncts.h"
#include "utilityFuncts.h"
#include <iostream>


sortFuncts::sortFuncts()
{
}


sortFuncts::~sortFuncts()
{
}


// Merge 3 Sorted Arrays
vector<int> sortFuncts::merge3SortedArrays(vector<int> v1, vector<int> v2, vector<int> v3)
{
	uint v1index = 0;
	uint v2index = 0;
	uint v3index = 0;
	bool v1Active = true;
	bool v2Active = true;
	bool v3Active = true;

	if (sortedInts.size() > 0)
		sortedInts.clear();

	// move index
	while (v1Active || v2Active || v3Active)
	{

		if ((v1[v1index] <= v2[v2index]) && (v1[v1index] <= v3[v3index]))
		{
			sortedInts.push_back(v1[v1index]);
			if (v1index == v1.size() - 1)
			{
				v1Active = false;
				v1[v1index] = INT32_MAX;
			}
			if (v1index < v1.size() - 1)
				v1index++;
		}
		else if ((v2[v2index] <= v1[v1index]) && (v2[v2index] <= v3[v3index]))
		{
			sortedInts.push_back(v2[v2index]);
			if (v2index == v2.size() - 1)
			{
				v2Active = false;
				v2[v2index] = INT32_MAX;
			}
			if (v2index < v1.size() - 1)
				v2index++;
		}
		else if ((v3[v3index] <= v1[v1index]) && (v3[v3index] <= v2[v2index]))
		{
			sortedInts.push_back(v3[v3index]);
			if (v3index >= v3.size() - 1)
			{
				v3Active = false;
				v3[v3index] = INT32_MAX;
			}
			if (v3index < v1.size() - 1)
				v3index++;
		}
		else
		{
			cout << "Shouldn't be here!!!" << endl;
		}
	}
	return sortedInts;
}


// Merge 2 Sorted Arrays
vector<int> sortFuncts::mergeSortedArrays(vector<int> v1, vector<int> v2)
{
	vector<int> temp;
	uint v1Index = 0;
	uint v2Index = 0;

	while ((v1Index < v1.size()) && (v2Index < v2.size()))
	{
		if (v1[v1Index] <= v2[v2Index])
		{
			temp.push_back(v1[v1Index]);
			v1Index++;

		}
		else if (v2[v2Index] < v1[v1Index])
		{
			temp.push_back(v2[v2Index]);
			v2Index++;
		}
	}

	// Fill the rest of temp with v1
	if (v2Index == v2.size() && v1Index < v1.size())
	{
		while (v1Index < v1.size())
		{
			temp.push_back(v1[v1Index]);
			v1Index++;
		}
	}

	// Fill the rest of temp with v2
	if (v1Index == v1.size() && v2Index < v2.size())
	{
		while (v2Index < v2.size())
		{
			temp.push_back(v2[v2Index]);
			v2Index++;
		}
	}
	return temp;
}


// Extra Credit: Merge Sort using Vectors and Recursion
vector<int> sortFuncts::mergeSortHelperSubV(vector<int> a, vector<int> &tmpA, int left, int right)
{
	vector<int> vL;
	vector<int> vR;

	if (left < right)
	{
		int center = (left + right) / 2;
		vL = mergeSortHelperSubV(a, tmpA, left, center);
		vR = mergeSortHelperSubV(a, tmpA, center + 1, right);

		if (!utilityFuncts::isInList(a[left], vL))
			vL.push_back(a[left]);
		if (!utilityFuncts::isInList(a[center + 1], vR))
			vR.push_back(a[center + 1]);
		tmpA = mergeSortedArrays(vL, vR);
		return tmpA;
	}
	return vL;
}

vector<int> sortFuncts::mergeSortSubV(vector<int> inArray)
{
	vector<int> tmpArray;

	mergeSortHelperSubV(inArray, tmpArray, 0, inArray.size() - 1);

	return tmpArray;
}

// Extra Credit: Merge Sort
void sortFuncts::finalMerge(vector<int> &srcV, vector<int> &tmpV, int left, int right, int end)
{
	int leftEnd = right - 1;
	int tmpPos = left;

	// Move through left and right pointers in source Array and put lowest value in temp array
	while (left <= leftEnd && right <= end)
	{
		if (srcV[left] <= srcV[right])
			tmpV[tmpPos++] = srcV[left++];
		else
			tmpV[tmpPos++] = srcV[right++];
	}

	// Move the rest of the values in left side to temp array
	while (left <= leftEnd)
		tmpV[tmpPos++] = srcV[left++];

	// Move the rest of the values in right side to temp array
	while (right <= end)
		tmpV[tmpPos++] = srcV[right++];
}

void sortFuncts::mergeSortHelper(vector<int> &srcV, vector<int> &tmpV, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSortHelper(srcV, tmpV, left, center);
		mergeSortHelper(srcV, tmpV, center + 1, right);
		finalMerge(srcV, tmpV, left, center + 1, right);
	}
}

void sortFuncts::mergeSort(vector<int> &inArray)
{
	vector<int> tmpArray(inArray.size());

	mergeSortHelper(inArray, tmpArray, 0, inArray.size() - 1);

	// Copy temp array to referenced source array
	for (unsigned int i = 0; i<inArray.size(); i++)
		inArray[i] = tmpArray[i];
}

// Extra Credit : Quick Sort
void sortFuncts::qsortHelper(vector<int> &srcV)
{
	// Vector of size 1 is sorted so return
	if (srcV.size() <= 1)
		return;

	int newPivot = srcV[0];
	vector<int> leftV;
	vector<int> rightV;

	for (uint i = 1; i < srcV.size(); i++)
	{
		if (srcV[i] <= newPivot)
			leftV.push_back(srcV[i]);
		else
			rightV.push_back(srcV[i]);
	}

	qsortHelper(leftV);
	qsortHelper(rightV);

	leftV.insert(leftV.end(), newPivot);
	leftV.insert(leftV.end(), rightV.begin(), rightV.end());
	srcV = leftV;

	for (uint i = 0; i < srcV.size(); i++)
		cout << srcV[i] << " ";
	cout << endl;
}

void sortFuncts::quickSort(vector<int> &srcV)
{
	int pivot = srcV[0];
	vector<int> leftV;
	vector<int> rightV;

	// Build first left and right sub arrays 
	for (uint i = 1; i < srcV.size(); i++)	// skip pivot
	{
		if (srcV[i] < pivot)
			leftV.push_back(srcV[i]);
		else
			rightV.push_back(srcV[i]);
	}

	// Quick Sort Left array
	qsortHelper(leftV);

	// Quick sort Right array
	qsortHelper(rightV);

	// Append pivot and right array to end of left array
	leftV.insert(leftV.end(), pivot);
	leftV.insert(leftV.end(), rightV.begin(), rightV.end());
	srcV = leftV;
}


//
void sortFuncts::insertionSort(vector<int> &inArray)
{
	for (uint i = 1; i < inArray.size(); i++)
	{
		for (int j = (i); j > 0; j--)
		{
			if (inArray[j] < inArray[j - 1])
				utilityFuncts::swap(j, j - 1, inArray);
		}
	}
}

// Extra Credit: Shell Sort
void sortFuncts::shell_sort(vector<int> &inArray)
{
	int j = 0;

	for (int gap = inArray.size() / 2; gap > 0; gap = gap / 2)
	{
		for (unsigned int i = gap; i < inArray.size(); i++)
		{
			int tmp = inArray[i];
			for (j = i; (j >= gap); j = j - gap)
			{
				if (tmp < inArray[j - gap])
					inArray[j] = inArray[j - gap];
			}
			inArray[j] = tmp;
		}
	}
}


// Extra Credit: Heap Sort 
vector<int> sortFuncts::heapSort(vector<int> input)
{
	vector<int> sortedArray;

	// insert values into heap (tempIntArray)
	for (int i = 0; i < (int)input.size(); i++)
		insertIntoHeap(input[i], tempIntArray);
	
	// pop root and push to sortedArray Vector to Sort
	while (tempIntArray.size())
		sortedArray.push_back(popRoot(tempIntArray));
	
	return sortedArray;
}

void sortFuncts::perculateUp(vector<int> &h)
{
	int parent = 0;
	for (int i = h.size() - 1; i > 0; i = i / 2)
	{
		if (i % 2 == 0)
			parent = (i / 2) - 1;
		else
			parent = i / 2;

		if (h[i] < h[parent])
			utilityFuncts::swap(i, parent, h);
	}
}

void sortFuncts::perculateDown(vector<int> &h)
{
	if (h.size() < 2)
		return;

	// put last value in temp storage and create hole
	int temp = h[h.size() - 1];
	h[0] = INT_MAX;

	// create hole and perc down
	int hole = 0;
	while (hole < (int)h.size())
	{
		if (((2 * hole) + 1) >((int)h.size() - 1))
		{
			h[hole] = temp;
			return;
		}
		else if (((2 * hole) + 2) > ((int)h.size() - 1))
		{
			if (h[2 * hole + 1]> temp)
				h[hole] = temp;
			else
			{
				h[hole] = h[2 * hole + 1];
				h[2 * hole + 1] = temp;
			}
			return;
		}
		else if (h[(2 * hole) + 1] < h[(2 * hole) + 2])
		{
			swap(h[hole], h[2 * hole + 1]);
			hole = (2 * hole) + 1;
		}
		else
		{
			swap(h[hole], h[2 * hole + 2]);
			hole = (2 * hole) + 2;
		}
	}
}

void sortFuncts::insertIntoHeap(int x, vector<int> &h)
{
	h.push_back(x);
	if (h.size() > 1)
	{	// insert into last position and perculate up
		perculateUp(h);
	}
}

int sortFuncts::popRoot(vector<int> &h)
{
	int oldRoot = h[0];
	perculateDown(h);
	h.pop_back();

	return oldRoot;
}