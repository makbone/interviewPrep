#include "stdafx.h"
#include "matrixFuncts.h"


//using namespace std;

matrixFuncts::matrixFuncts()
{
}


matrixFuncts::~matrixFuncts()
{
}


// Coding Problem 1 : Print Zeros
void matrixFuncts::markRowCol(vector<int> &v, int val)
{
	for (uint i = 0; i < v.size(); i++)
	{
		if (v[i] == val)
			return;	// Found item so return
	}
	// Item not found so update vector
	v.push_back(val);
	return;
}

void matrixFuncts::setMatrixZeros(vector<vector<int>> &mtx)
{
	vector<int> zero_cols;
	vector<int> zero_rows;
	bool dupe = true;

	// mark rows and columns that need to be zeroed out
	for (uint i = 0; i < mtx.size(); i++)
	{
		for (uint j = 0; j < mtx[i].size(); j++)
		{
			if (mtx[i][j] == 0)
			{
				markRowCol(zero_rows, i);
				markRowCol(zero_cols, j);
			}
		}
	}

	// zero rows and cols
	for (uint i = 0; i < mtx[0].size(); i++)			// loop through matrix rows
	{
		for (uint k = 0; k < zero_rows.size(); k++)		// loop through marked rows
		{
			if (zero_rows[k] == i)						// if matrix row matches a marked row
			{
				for (uint j = 0; j < mtx.size(); j++)
					mtx[i][j] = 0;						// set each col val in row to 0
			}			
		}		
	}

	// zero cols
	for (uint i = 0; i < mtx.size(); i++)				// loop through matrix cols
	{
		for (uint k = 0; k < zero_cols.size(); k++)		// loop through marked cols
		{
			if (zero_cols[k] == i)						// if matrix col == marked col
			{
				for (uint j = 0; j < mtx[0].size(); j++)
					mtx[j][i] = 0;						// set each row val in col to 0
			}
		}
	}
}

//
void matrixFuncts::printMatrix(vector<vector<int>> mtx)
{
	for (uint i = 0; i < mtx.size(); i++)
	{
		for (uint j = 0; j < mtx[i].size(); j++)
			cout << mtx[i][j] << " ";
		cout << endl;
	}
}
