#pragma once

#include "stdint.h"
#include <vector>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

struct graphNode	// Graph node
{
	// int Index		// (position in vector/list/tree is Index)
	int dist;			// Shortest path from Source to given Node 
	bool processed;		// Flag indicating node has been processed

	graphNode(int d = INT32_MAX, bool p = false) :
		dist(d), processed(p) {}
};

class graphFuncts
{
public:

	vector<graphNode> nodes;
	vector<vector<int>> graph;

	graphFuncts();
	graphFuncts(vector<vector<int>> inG);
	~graphFuncts();

	void shortestDistance(uint src = 0, uint dest = 0);
	int findMinNodeIndex(vector<graphNode> &nodes);
	void printSolution(int Src, int Dest = 0);
};

