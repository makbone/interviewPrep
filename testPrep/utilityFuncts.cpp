#include "stdafx.h"
#include "utilityFuncts.h"


utilityFuncts::utilityFuncts()
{
}


utilityFuncts::~utilityFuncts()
{
}

// Utility
bool utilityFuncts::isInList(int val, vector<int> v)
{
	for (uint i = 0; i < v.size(); i++)
	{
		if (v[i] == val)
			return true;
	}
	return false;
}

// Extra Credit : Insertion Sort
void utilityFuncts::swap(uint iPos, uint jPos, vector<int> &t)
{
	int temp = t[iPos];

	t[iPos] = t[jPos];
	t[jPos] = temp;
}

// Extra Credit: Converting Vector to Nums
int utilityFuncts::convertArrToInt(vector<int> v)
{
	int t = 0;
	int count = 0;

	for (int i = (v.size() - 1); i >= 0; i--)
	{
		t = t + (int)pow(10, count)*v[i];
		count++;
	}
	return t;
}

// Extra Credit: Converting Num to Vectors
vector<int> utilityFuncts::convertIntToArray(int num)
{
	vector<int> v;
	int count = 0;

	while (num > 0)
	{
		auto it = v.begin();
		int t = num % 10;
		v.insert(it, t);
		num = num / 10;
	}
	return v;
}