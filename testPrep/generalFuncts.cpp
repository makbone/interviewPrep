#include "stdafx.h"
#include "generalFuncts.h"
#include <time.h>       /* time */
#include <iostream>

using namespace std;


generalFuncts::generalFuncts()
{
}


generalFuncts::~generalFuncts()
{
}


// Coding Problem 2 : Print Excell Columns
string generalFuncts::printExcelCols(uint val)
{
	if (val == 0)
		return NULL;

	int count = 0;
	int dictIndex = -1;
	string colName;
	vector<string> dictMap{ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

	dictIndex = (val - 1) % dictMap.size();

	while (val > 0)
	{
		val = val / dictMap.size();
		count++;
	}

	for (int i = 0; i < count; i++)
		colName.append(dictMap[dictIndex]);

	return colName;
}


// shuffle cards
void generalFuncts::shuffleCards(int deck[52], int(&shuffledDeck)[52])
{
	int pos = 0;

	srand((uint)time(NULL));

	for (int i = 0; i < 52; i++)
	{
		pos = rand() % 52;
		while (shuffledDeck[pos] != -1)
		{
			pos++;
			if (pos > 51)
				pos = 0;
		}
		//cout << "Inserting Card " << deck[i] << " into position " << pos << endl;
		shuffledDeck[pos] = deck[i];
	}
}


// Google Practice
bool generalFuncts::isRelativePointerGood(vector<int> src)
{
	// Set Max count as size of input array
	int maxCount = src.size();
	int count = 0;
	int index = 0;

	while (count < maxCount)
	{
		if (src[index] == 0)
			return false;
		else
		{
			int oldIndex = index;
			// Go to next relative node
			index = (index + src[index]) % maxCount;

			// handle negative modulous
			if (index < 0)
				index = index*-1;

			// Set value at old index to visited 
			src[oldIndex] = 0;
		}
		// increase count to ensure only one loop through array
		count++;
	}
	return true;
}


tuple<int, int> generalFuncts::FindTwoSum(list<int> input, int number)
{
	//write code here 
	pair<int, int> foundP(INT32_MIN, INT32_MIN);
	tuple<int, int> retT = foundP;
	list<int>::iterator li;
	list<int>::iterator li2;

	for (li = input.begin(); li != input.end(); li++)
	{
		for (li2 = ++input.begin(); li2 != input.end(); li2++)
		{
			if (*li + *li2 == number)
			{
				foundP.first = *li;
				foundP.second = *li2;
				retT = foundP;
				return retT;
			}
		}
	}
	// Return unset Tuple if not found
	return retT;
}


//
vector<char> generalFuncts::ReverseSections(vector<char> vc, int sectionSize)
{
	vector<char> retV;
	unsigned int count = 1;

	for (unsigned int i = 0; i < vc.size(); i = i + sectionSize)
	{
		unsigned int cur = (sectionSize*count);
		if (cur >(vc.size()))
			cur = vc.size();
		while (cur > (sectionSize*(count - 1)))
		{
			retV.push_back(vc[cur - 1]);
			cur--;
		}
		count++;
	}
	return retV;
}


//
void generalFuncts::addZeroSeperatedItems(list<int> inputL)
{
	int temp = 0;
	list<int> tempL;

	iList.clear();

	// Make sure last values are added
	if (inputL.back() != 0)
		inputL.push_back(0);
	
	// foreach style loop
	for (auto i : inputL) [&]()
	{
		if (i != 0)
		{
			temp = temp + i;
			tempL.push_back(i);
		}
		else
		{
			cout << "adding " << temp << endl;
			iList.push_back(temp);
			temp = 0;
			tempL.clear();
		}
	}();

	iList.insert(iList.end(), tempL.begin(), tempL.end());

	// Loop using auto to specify iterator type
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		cout << *i;
		if (i != (--iList.end()))
			cout << "->";
		else
			cout << endl;
	}
}


//
void generalFuncts::calcRatsKilled(bombNode* &bNode, vector<nestNode*> &rNests, int bRange)
{
	for (uint i = 0; i < rNests.size(); i++)
	{
		// Check X and Y range
		if ((rNests[i]->x <= (bNode->x + bRange)) && (rNests[i]->x >= (bNode->x - bRange))
			&& (rNests[i]->y <= (bNode->y + bRange)) && (rNests[i]->y >= (bNode->y - bRange)))
			bNode->killed = bNode->killed + rNests[i]->pop;
	}
	cout << bNode->x << "," << bNode->y << " Killed =" << bNode->killed << endl;
}

//
void generalFuncts::ratMazeSetup()
{
	static const int MAZE_SIZE = 1024;
	int numTest = 0;
	int bRange = 0;
	int numRatNest = 0;
	vector<nestNode*> nests;

	int leftMost = MAZE_SIZE, topMost = MAZE_SIZE, rightMost = -1, bottomMost = -1;

	cout << "Enter rat maze setup params... numTest bombRange numRatNest RatNestParms\n";
	cin >> numTest >> bRange >> numRatNest;
	cout << " " << numTest << " " << bRange << " " << numRatNest << endl;

	for (int i = 0; i < numRatNest; i++)
	{
		int x, y, p;
		cin >> x >> y >> p;
		nestNode* tNode = new nestNode(x, y, p);
		nests.push_back(tNode);

		// Determin Range Variables
		if (x < leftMost)
			leftMost = x;
		if (x > rightMost)
			rightMost = x;
		if (y < topMost)
			topMost = y;
		if (y > bottomMost)
			bottomMost = y;
	}
	for (uint i = 0; i < nests.size(); i++)
	{
		cout << nests[i]->x << ", " << nests[i]->y << ", " << nests[i]->pop << endl;
	}

	// build game map
	cout << "Left=" << leftMost << ", Right=" << rightMost << ", Top=" << topMost << ", Bottom=" << bottomMost << endl;

	// calc scan range
	leftMost = leftMost - bRange;
	if (leftMost < 0)
		leftMost = 0;
	topMost = topMost - bRange;
	if (topMost < 0)
		topMost = 0;
	rightMost = rightMost + bRange;
	if (rightMost > MAZE_SIZE - 1)
		rightMost = MAZE_SIZE - 1;
	bottomMost = bottomMost + bRange;
	if (bottomMost > MAZE_SIZE - 1)
		bottomMost = MAZE_SIZE - 1;

	cout << "Scanning - " << leftMost << "," << topMost << " to " << rightMost << "," << bottomMost << endl;

	// Scan each index to find max kills
	bombNode bestBomb(-1, -1);

	for (int i = leftMost; i < rightMost; i++)
	{
		for (int j = topMost; j < bottomMost; j++)
		{
			bombNode* bNode = new bombNode(i, j);
			calcRatsKilled(bNode, nests, bRange);
			if (bNode->killed > bestBomb.killed)
			{
				bestBomb.killed = bNode->killed;
				bestBomb.x = bNode->x;
				bestBomb.y = bNode->y;
			}
		}
	}
	cout << "Results = " << bestBomb.x << "," << bestBomb.y << " " << bestBomb.killed << endl;
}


// Extra Credit: Divide with math operators
unsigned generalFuncts::divide(unsigned dividend, unsigned divisor) 
{
	unsigned denom = divisor;
	unsigned current = 1;
	unsigned answer = 0;

	if (denom > dividend)
		return 0;

	if (denom == dividend)
		return 1;

	while (denom <= dividend) {
		denom <<= 1;
		current <<= 1;
	}

	denom >>= 1;
	current >>= 1;

	while (current != 0) {
		if (dividend >= denom) {
			dividend -= denom;
			answer |= current;
		}
		current >>= 1;
		denom >>= 1;
	}
	return answer;
}