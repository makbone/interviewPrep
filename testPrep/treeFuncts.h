#pragma once
#include <vector>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;


// Extra Credit : Tree Object
struct tree_node
{
	int value;
	tree_node *left;
	tree_node *right;

	int index;
	tree_node* parent;

	tree_node(int val)
	{
		value = val;
		left = NULL;
		right = NULL;
		index = 0;
	}
};


//
class bst
{
	tree_node* root;
	int nodeCount;

public:

	bst()
	{
		nodeCount = 0;
	}

	bst(int val)
	{
		root = new tree_node(val);
		nodeCount = 1;
		root->index = nodeCount;
	}

	tree_node* get_root();

	bool insert_helper(int val, tree_node* &n);
	void insert(int val);

};


//
class treeFuncts
{
public:
	treeFuncts();
	~treeFuncts();

	void printTreeHelper(tree_node* tn, int &count);
	int printTree(bst myT);

	bool isBSTHelper(tree_node* n, int pVal, bool isleftSide);
	bool isBST(bst myBST);
	bool findCycle(bst myT);

	void getSortedHelper(tree_node* n, vector<int> &v, int *count);
	vector<int> getSortedBST(bst myBST);

	int findNextLowest(bst myBST, int value);

	vector<int> returnPathToTargetIt(bst myTree, int targetVal);

};

