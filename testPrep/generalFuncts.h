#pragma once
#include <string>
#include <vector>
#include <list>
#include <tuple>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

// rat maze - apptio
struct nestNode
{
	int x;
	int y;
	int pop;

	nestNode(int xCoord, int yCoord, int p) :
		x(xCoord), y(yCoord), pop(p) {}
};

struct bombNode
{
	int x;
	int y;
	int killed;

	bombNode(int xCoord, int yCoord) :
		x(xCoord), y(yCoord), killed(0) {}
};

class generalFuncts
{
public:
	generalFuncts();
	~generalFuncts();

	list<int> iList;
	list<char> cList;
	vector<int> iArray;
	vector<char> cArray;

	static void shuffleCards(int deck[52], int(&shuffledDeck)[52]);
	static bool isRelativePointerGood(vector<int> src);

	string printExcelCols(uint val);
	tuple<int, int> FindTwoSum(list<int> input, int number);
	void addZeroSeperatedItems(list<int> input);
	vector<char> ReverseSections(vector<char> vc, int sectionSize);

	void calcRatsKilled(bombNode* &bNode, vector<nestNode*> &rNests, int bRange);
	void ratMazeSetup();

	unsigned divide(unsigned dividend, unsigned divisor);

};

