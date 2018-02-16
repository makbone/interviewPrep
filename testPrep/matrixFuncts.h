#pragma once
#include <iostream>
#include <vector>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

class matrixFuncts
{
public:
	matrixFuncts();
	~matrixFuncts();

	void markRowCol(vector<int> &v, int val);
	void setMatrixZeros(vector<vector<int>> &mtx);
	void printMatrix(vector<vector<int>> mtx);

	vector<vector<int>> mtx;
};

