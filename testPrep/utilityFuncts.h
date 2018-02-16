#pragma once
#include <vector>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

class utilityFuncts
{
public:
	utilityFuncts();
	~utilityFuncts();

	static bool isInList(int val, vector<int> v);
	static void swap(uint iPos, uint jPos, vector<int> &t);
	static int convertArrToInt(vector<int> v);
	static vector<int> convertIntToArray(int num);

};

