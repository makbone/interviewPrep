// testPrep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "matrixFuncts.h"
#include "generalFuncts.h"
#include "sortFuncts.h"
#include "treeFuncts.h"
#include "graphFuncts.h"
#include "linkListFuncts.h"
#include "utilityFuncts.h"
#include "stringFuncts.h"
#include <unordered_set>
#include <unordered_map>

//
int main()
{
	// OTS Coding Problem 1
	matrixFuncts mf;
	mf.mtx = { { 1, 2, 3, 4 },{ 5, 6, 0, 7 },{ 8, 9, 1, 2 },{ 3, 4, 5, 6 } };
	mf.printMatrix(mf.mtx);

	mf.setMatrixZeros(mf.mtx);
	cout << endl;
	mf.printMatrix(mf.mtx);
	cout << endl << endl;


	// OTS Coding Problem 2
	generalFuncts gf;
	string cp2_str = gf.printExcelCols(27);


	// OTS Coding Problem 3
	sortFuncts sortF;
	vector<int> p3_v1{ 1, 2, 3 };
	vector<int> p3_v2{ 10, 12, 18 };
	vector<int> p3_v3{ 5, 7, 8 };

	sortF.sortedInts = sortF.merge3SortedArrays(p3_v1, p3_v2, p3_v3);

	// vector insert practice
	p3_v1.insert(p3_v1.end(), p3_v2.begin(), p3_v2.end());


	// Sorting Practice:
	vector<int> ec_v2 = { 5, 3, 8, 1, 4, 7, 10, 2 };
	
	// Merge, Insertion, Quick Sort, Heap
	sortF.sortedInts.clear();
	sortF.sortedInts = sortF.heapSort(ec_v2);

	sortF.sortedInts.clear();
	sortF.sortedInts = sortF.mergeSortSubV(ec_v2);	

	sortF.insertionSort(ec_v2);

	//sortF.quickSort(ec_v2);


	// BST Practice - find path in tree
	treeFuncts treF;
	vector<int> ec_v1 = { 5, 3, 8, 1, 4, 7, 10 };
	p3_v1.clear();
	p3_v1 = ec_v1;

	bst myTree = bst();

	for (uint i = 0; i < ec_v1.size(); i++)
		myTree.insert(ec_v1[i]);
	int treeCount = treF.printTree(myTree);

	bool found_cycle = treF.findCycle(myTree);	// Extra Credit
	if (!found_cycle)
	{
		if (treF.isBST(myTree))
		{
			int nextLow = treF.findNextLowest(myTree, 2);
			vector<int> ec_bst_path = treF.returnPathToTargetIt(myTree, 1);
		}
	}

	// Graph Problems
	// Dykstra
	vector<vector<int>> inGraph = {
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	graphFuncts graphF(inGraph);

	graphF.shortestDistance(0, 4);
	

	// Google Practice Question - find cycle in relative array pointers
	int g1SrcA[4] = { 1, 2, 10, -5 };
	vector<int> g1SrcV;
	for (int i = 0; i < 4; i++)
		g1SrcV.push_back(g1SrcA[i]);

	generalFuncts::isRelativePointerGood(g1SrcV);


	// STL Practice 
	tuple<int, int> tupTest;
	
	gf.iList.push_back(2); 
	gf.iList.push_back(3); 
	gf.iList.push_back(19); 
	gf.iList.push_back(5);
	
	tupTest = gf.FindTwoSum(gf.iList, 15);


	// Link List Practice
	linkListFuncts llF;
	Node* alphaRoot = NULL;
	llF.enqueueN(alphaRoot, 'a');
	llF.enqueueN(alphaRoot, 'b');
	llF.enqueueN(alphaRoot, 'c');
	llF.enqueueN(alphaRoot, 'd');
	llF.enqueueN(alphaRoot, 'e');
	llF.enqueueN(alphaRoot, 'f');
	llF.enqueueN(alphaRoot, 'g');
	llF.enqueueN(alphaRoot, 'h');

	llF.ReverseLLSectionsI(alphaRoot, 3);

	Node head(0);
	Node newhead = llF.InsertAtTheEnd(head, 2);

	//char firstCh = dequeueN(alphaRoot);
	//char ecChar = findMin(alphaRoot);
	//deleteLast(alphaRoot);
	//reverseLinkedList(alphaRoot);

	// Sort Link List
	Node* numRoot = NULL;
	llF.enqueueN(numRoot, '2');
	llF.enqueueN(numRoot, '1');
	llF.enqueueN(numRoot, '5');
	llF.enqueueN(numRoot, '9');
	llF.enqueueN(numRoot, '3');
	llF.enqueueN(numRoot, '4');
	llF.enqueueN(numRoot, '8');
	llF.enqueueN(numRoot, '6');

	Node* testList = llF.deleteMinSortRecurse(numRoot);


	// Extra Credit Converting Arrays / Ints
	vector<int> myArr = { 1, 3, 5 };
	int cTest = utilityFuncts::convertArrToInt(myArr);
	vector<int> myNewArr = utilityFuncts::convertIntToArray(cTest + 1);


	// String Practice 
	stringFuncts strF;
	string wCardStr = "t*2";
	strF.s = "test2";

	// wildcard matching
	bool matchTest = strF.stringMatch(wCardStr, strF.s);

	// String reversing
	strF.reverseString(strF.s);

	char ca1[] = {'t', 'e', 's', 't','\0'};
	int ca1Size = sizeof(ca1)/sizeof(char);
	char* ca1Ptr = ca1;
	strF.reverseCharString(ca1Ptr, ca1Size);

	// Staffing Interview Problem - Expand string 
	strF.s = "a3[bc2[e]]d";
	strF.printExpStr(strF.s);

	// 
	int atoiTest = strF.myAtoi("145");

	//
	string str("There are two needles in this haystack with needles.");
	string str2("needle");

	//data(str);	// not sure what this function does

	// different member versions of find in the same order as above:
	size_t strFound = str.find(str2);
	if (strFound != string::npos)
		std::cout << "first 'needle' found at: " << strFound << '\n';

	
	// Rand Practice 
	int deck[52];
	int shuffledDeck[52];

	for (int i = 0; i < 52; i++)
	{
		deck[i] = i + 101;
		shuffledDeck[i] = -1;
	}
	generalFuncts::shuffleCards(deck, shuffledDeck);


	// unordered set Practice
	unordered_set<string> dict;

	dict.insert("test1");
	dict.insert("test2");
	dict.insert("test3");

	unordered_set<string>::iterator found;
	string tStr = "test2";
	found = dict.find(tStr);
	

	if (found != dict.end())
		cout << "Found " << found->c_str() << endl;
	else
		cout << tStr.c_str() << " NOT Found!!" << endl;

	// Extra Credit: Hash Map Practice
	typedef pair <const int, int> cInt2Int;
	std::unordered_map <int, int> hm1;
	std::unordered_map <int, int> ::iterator hm1_Iter;

	// Insert data values  
	hm1.insert(cInt2Int(1, 10));
	hm1.insert(cInt2Int(2, 20));
	hm1.insert(cInt2Int(3, 30));

	hm1_Iter = hm1.find(3);

	cout << endl << "The values of the mapped elements are:";
	for (unsigned int i = 1; i <= hm1.size(); i++)
		cout << " " << hm1.at(i);
	cout << "." << endl;


	// Extra Credit: STL List Practice C++11
	list<int> inL{ 1, 2, 0, 4, 5, 0, 6, 7 };
	gf.addZeroSeperatedItems(inL);


	// Apptio Rat Maz
	gf.ratMazeSetup();

    return 0;
}

