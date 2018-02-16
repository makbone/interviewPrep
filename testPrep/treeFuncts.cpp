#include "stdafx.h"
#include "treeFuncts.h"
#include <iostream>
#include <stack>

//
tree_node* bst::get_root()
{
	return root;
}

//
bool bst::insert_helper(int val, tree_node* &n)
{
	if ((val < n->value) && (n->left == NULL))
	{
		nodeCount++;
		tree_node* tNode = new tree_node(val);
		n->left = tNode;
		n->left->index = nodeCount;
		return true;
	}
	else if ((val > n->value) && (n->right == NULL))
	{
		nodeCount++;
		tree_node* tNode = new tree_node(val);
		n->right = tNode;
		n->right->index = nodeCount;
		return true;
	}
	else if (val < n->value && (n->left != NULL))
	{
		insert_helper(val, n->left);
	}
	else if (val > n->value && (n->right != NULL))
	{
		insert_helper(val, n->right);
	}
	else {}
	return false;
}

//
void bst::insert(int val)
{
	if (root == NULL)
	{
		root = new tree_node(val);
		nodeCount = 1;
		root->index = nodeCount;
	}
	else
	{
		insert_helper(val, root);
	}
}


treeFuncts::treeFuncts()
{
}


treeFuncts::~treeFuncts()
{
}

//
void treeFuncts::printTreeHelper(tree_node* tn, int &count)
{
	if (tn == NULL)
		return;
	if (tn != NULL)
	{
		cout << tn->value << endl;
		count++;
	}

	if (tn->left != NULL)
	{
		cout << " <-" << tn->value << endl;
		printTreeHelper(tn->left, count);
	}
	if (tn->right != NULL)
	{
		cout << tn->value << "-> ";
		printTreeHelper(tn->right, count);
	}
}

//
int treeFuncts::printTree(bst myT)
{
	int count = 0;
	printTreeHelper(myT.get_root(), count);
	cout << endl;
	return count;
}


// Interview 1 Question : Check if object is BST
bool treeFuncts::isBSTHelper(tree_node* n, int pVal, bool isleftSide)
{
	if (n == NULL)
		return true;

	if (n->left != NULL)
	{
		if (n->left->value >= n->value)
			return false;

		if (!isleftSide && (n->left->value < pVal))  // if on Right Side of Tree
			return false;
	}

	if (n->right != NULL)
	{
		if (n->right->value <= n->value)
			return false;

		if (isleftSide && (n->right->value > pVal))  // if on Left Side of Tree
			return false;
	}

	isBSTHelper(n->left, n->value, isleftSide);
	isBSTHelper(n->right, n->value, isleftSide);
	return true;
}

//
bool treeFuncts::isBST(bst myBST)
{
	if (myBST.get_root() == NULL)
		return true;	// empty tree is a tree

	bool leftGood = isBSTHelper(myBST.get_root()->left, myBST.get_root()->value, true);
	bool rightGood = isBSTHelper(myBST.get_root()->right, myBST.get_root()->value, false);

	if (leftGood && rightGood)
		return true;

	return false;
}

// Extra Credit: Find cycle in BST - DFS
bool treeFuncts::findCycle(bst myT)
{
	stack<tree_node*> act_stack;
	tree_node* cur_node;
	vector<int> visitedNodes;

	cur_node = myT.get_root();
	act_stack.push(cur_node);

	while (!act_stack.empty())
	{
		if ((cur_node == NULL) && (act_stack.size() > 0))				// Hit a dead end, so process next element in stack
		{
			cur_node = act_stack.top();
			act_stack.pop();
		}
		else
		{
			visitedNodes.push_back(cur_node->index);
			if (cur_node->left != NULL)
			{
				act_stack.push(cur_node->left);
				for (int i = 0; i < (int)visitedNodes.size(); i++)		// Check if new nodes have already been visited
				{
					if (visitedNodes[i] == cur_node->left->index)
						return true;
				}
			}
			if (cur_node->right != NULL)
			{
				act_stack.push(cur_node->right);
				for (int i = 0; i < (int)visitedNodes.size(); i++)		// Check if new nodes have already been visited
				{
					if (visitedNodes[i] == cur_node->right->index)
						return true;
				}
			}
		}
		if (act_stack.size() > 0)	// Get next node from active stack
		{
			cur_node = act_stack.top();
			act_stack.pop();
		}
	}
	return false;
}

//
void treeFuncts::getSortedHelper(tree_node* n, vector<int> &v, int *count)
{
	if (n == NULL)
		return;

	getSortedHelper(n->left, v, count);

	v.push_back(n->value);
	if (n->value > 5)
		*count = *count + 1;

	getSortedHelper(n->right, v, count);

}

//
vector<int> treeFuncts::getSortedBST(bst myBST)
{
	vector<int> sortedNodes;
	int count = 0;

	// Do Inorder Traversal of Tree
	getSortedHelper(myBST.get_root()->left, sortedNodes, &count);

	sortedNodes.push_back(myBST.get_root()->value);
	if (myBST.get_root()->value > 5)
		count++;

	getSortedHelper(myBST.get_root()->right, sortedNodes, &count);

	return sortedNodes;
}

//
int treeFuncts::findNextLowest(bst myBST, int value)
{
	vector<int> sortedNodes = getSortedBST(myBST);

	if (sortedNodes.size() <= 1)
		return -1;
	if (value <= sortedNodes[0])
		return -1;

	for (uint i = 1; i < sortedNodes.size(); i++)
	{
		if (sortedNodes[i] >= value)
			return sortedNodes[i - 1];
	}
	return -1;
}


// Extra Credit: Path from root to target in BST
vector<int> treeFuncts::returnPathToTargetIt(bst myTree, int targetVal)
{
	vector<int> path;
	vector<int> actIndex;

	tree_node* cur = myTree.get_root();

	while ((cur->value != targetVal) || (cur->index != NULL))
	{
		if (cur->value == targetVal)
		{
			path.push_back(cur->value);
			return path;
		}
		else
		{
			path.push_back(cur->value);
			if (targetVal < cur->value)
				cur = cur->left;
			else
				cur = cur->right;
		}
	}
	return path;
}




