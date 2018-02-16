#include "stdafx.h"
#include "graphFuncts.h"
#include <iostream>


graphFuncts::graphFuncts()
{
}

graphFuncts::graphFuncts(vector<vector<int>> inG)
{
	// create graph nodes for dijkstra's algorithm
	for (uint i = 0; i < inG.size(); i++)
		nodes.push_back(graphNode());

	graph = inG;
}


graphFuncts::~graphFuncts()
{
}


// Dijkstra's Algorithm
void graphFuncts::shortestDistance(uint src, uint dest)
{
	if (src > nodes.size())
	{
		cout << "Source " << src << " too high for Graph!!" << endl;
		return;
	}

	// Init shortest path to itself as 0
	nodes[src].dist = 0;

	// Find shortest path for all vertices
	for (uint count = 0; count < nodes.size() - 1; count++)
	{
		// Pick Node with min dist from Graph Nodes not yet processed
		int minI = findMinNodeIndex(nodes);	

		nodes[minI].processed = true;	// Mark Node as processed

		// Update dist value of the adjacent vertices of the picked vertex
		for (uint tarI = 0; tarI < nodes.size(); tarI++)
		{
			if (!nodes[tarI].processed && graph[minI][tarI]						// unvisited AND Target connected to minIndex											
				&& (nodes[minI].dist != INT_MAX)								// current minIndex not infinity
				&& ((nodes[minI].dist + graph[minI][tarI]) < nodes[tarI].dist))	// minIndex dist + distToTarget less than cur target dist
			{
				// Update TargetIndex distance from source with new lower value
				nodes[tarI].dist = nodes[minI].dist + graph[minI][tarI];
			}
		}
	}

	// print the constructed distance array
	printSolution(src, dest);
}

int graphFuncts::findMinNodeIndex(vector<graphNode> &nodes)
{
	int min = INT_MAX;
	int minIndex = 0;

	for (uint v = 0; v < nodes.size(); v++)
	{
		if (nodes[v].processed == false && nodes[v].dist <= min)
		{
			min = nodes[v].dist;
			minIndex = v;
		}
	}
	return minIndex;
}

void graphFuncts::printSolution(int Src, int Dest)
{
	cout << "Vertex         Dist from Src " << Src << endl;
	for (uint i = 0; i < nodes.size(); i++)
		cout << "   " << i << "                 " << nodes[i].dist << endl;

	cout << "Dist from " << Src << " to " << Dest << " = " << nodes[Dest].dist << endl;
}