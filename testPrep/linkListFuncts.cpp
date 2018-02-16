#include "stdafx.h"
#include "linklistFuncts.h"
#include <cstdint>


linkListFuncts::linkListFuncts()
{
}


linkListFuncts::~linkListFuncts()
{
}



// Conversion Functions
vector<char> linkListFuncts::convertNodesToCharVector(Node* root)
{
	vector<char> retV;
	Node* cur = root;
	while (cur != NULL)
	{
		retV.push_back(cur->value);
		cur = cur->next;
	}
	return retV;
}

list<char> linkListFuncts::convertNodesToCharList(Node* root)
{
	list<char> retV;
	Node* cur = root;
	while (cur != NULL)
	{
		retV.push_back(cur->value);
		cur = cur->next;
	}
	return retV;
}

Node* linkListFuncts::convertCharVectorToNodes(vector<char> vChars)
{
	Node* retNodes = NULL;
	Node* curNode = NULL;

	for (unsigned int i = 0; i < vChars.size(); i++)
	{
		if (retNodes == NULL)
		{
			retNodes = new Node(vChars[i]);
			curNode = retNodes;
		}
		else
		{
			Node* tNode = new Node(vChars[i]);
			curNode->next = tNode;
			curNode = curNode->next;
		}
	}
	return retNodes;
}

// Extra Credit: Find Min in Link List
char linkListFuncts::findMin(Node* root)
{
	char min = UINT8_MAX / 2;
	Node* cur = root;

	while (cur != NULL)
	{
		if (cur->value < min)	// set new min
			min = cur->value;

		// advance to next node
		cur = cur->next;
	}
	return min;
}

// Extra Credit: Link List Delete Last
void linkListFuncts::deleteLast(Node* &root)
{
	Node* cur = root;
	Node* last = root->next;

	if (root == NULL)
		return;
	if (root->next == NULL)
	{
		root = NULL;
		return;
	}

	while (cur != NULL)
	{
		last = cur->next;
		if (last->next == NULL)
		{
			last = cur;
			delete cur->next;
			cur->next = NULL;
			return;
		}
		cur = cur->next;
	}
}

Node linkListFuncts::InsertAtTheEnd(Node head, int data)
{
	//write code here 
	Node* cur = &head;

	while (cur->next != NULL)
		cur = cur->next;

	Node* tNode = new Node(data);
	cur->next = tNode;

	return head;
}

// Extra Credit: Queue Link List implimentation
void linkListFuncts::enqueueN(Node* &root, char val)
{
	Node* cur = root;

	if (root == NULL)
	{
		Node* tNode = new Node(val);
		root = tNode;
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next == NULL)
			cur->next = new Node(val);
		else
			cur = cur->next;
	}
	Node* tNode = new Node(val);
	cur->next = tNode;
}

char linkListFuncts::dequeueN(Node* &root)
{
	if (root == NULL)
		return '\0';

	Node* cur = root;
	char v = cur->value;

	root = root->next;
	delete cur;

	return v;
}

// Extra Credit: Link List Delete Min Sort
Node* linkListFuncts::deleteMinSort(Node* root)
{
	char min = UINT8_MAX / 2;
	Node* cur = root;
	Node* prev = root;
	Node* leftOfMin = NULL;
	Node* sortedRoot = NULL;
	Node* sortedCur = NULL;

	while (cur != NULL)
	{
		if (cur->value < min)	// Handle New Min Found
		{
			min = cur->value;
			leftOfMin = prev;  // Indicates pointer to next is min
		}

		// Advance to Next Node
		prev = cur;
		cur = cur->next;

		// Reached End
		if (cur == NULL)
		{
			// update new List with min Node
			Node* newNode = new Node(min);
			if (sortedRoot == NULL)
			{
				sortedRoot = sortedCur = newNode;
			}
			else
			{
				sortedCur->next = newNode;
				sortedCur = sortedCur->next;
			}

			// delete min node
			Node* temp = NULL;
			if (root->value == min) // Need to delete root
			{
				temp = root;
				root = root->next;
			}
			else
			{	// Need to delete non root Node
				temp = leftOfMin->next;
				leftOfMin->next = temp->next;
			}
			delete temp;

			// reset cur and prev pointer and min
			cur = prev = root;
			min = UINT8_MAX / 2;
		}
	}
	return sortedRoot;
}

// Extra Credit: Link List Delete Min Sort
void linkListFuncts::deleteMinSortHelper(char* min, Node* &c, Node* &p, Node* &lom)
{
	if (c == NULL)
		return;

	if (c->value < *min)	// Handle New Min Found
	{
		*min = c->value;
		lom = p;  // Indicates pointer to next is min
	}

	// Advance to Next Node
	p = c;
	c = c->next;
	deleteMinSortHelper(min, c, p, lom);
}

Node* linkListFuncts::deleteMinSortRecurse(Node* root)
{
	char min = UINT8_MAX / 2;
	Node* cur = root;
	Node* prev = root;
	Node* leftOfMin = NULL;
	Node* sortedRoot = NULL;
	Node* sortedCur = NULL;

	while (cur != NULL)
	{
		deleteMinSortHelper(&min, cur, prev, leftOfMin);

		// update new List with min Node
		Node* newNode = new Node(min);
		if (sortedRoot == NULL)
		{
			sortedRoot = sortedCur = newNode;
		}
		else
		{
			sortedCur->next = newNode;
			sortedCur = sortedCur->next;
		}

		// delete min node
		Node* temp = NULL;
		if (root->value == min) // Need to delete root
		{
			temp = root;
			root = root->next;
		}
		else
		{	// Need to delete non root Node
			temp = leftOfMin->next;
			leftOfMin->next = temp->next;
		}
		delete temp;

		// reset cur and prev pointer and min
		cur = prev = root;
		min = UINT8_MAX / 2;
	}
	return sortedRoot;
}

// Extra Credit: Reverse Link List
void linkListFuncts::reverseLinkedList(Node* &root)
{
	Node* prev = NULL;
	Node* cur = root;
	Node* last = root->next;

	while (cur != NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = last;
		if (last != NULL)
			last = last->next;
	}
	root = prev;
}

// Official solution
Node* linkListFuncts::ReverseLLSections(Node * root, int sectionSize)
{
	Node* current = root;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	//reverse first k nodes of the linked list
	while (current != NULL && count < sectionSize)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	// next is now a pointer to (k+1)th node
	// Recursively call for the list starting from current.
	// And make rest of the list as next of first node 
	if (next != NULL)
		root->next = ReverseLLSections(next, sectionSize);

	// prev is new head of the input list
	return prev;
}

// iterative solution
Node* linkListFuncts::ReverseLLSectionsI(Node * &root, int sectionSize)
{
	if (root == NULL)
		return root;

	Node* cur = root;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	bool firstSect = true;
	Node* init = NULL;
	Node* nextInit = NULL;

	// loop through list
	while (cur != NULL)
	{
		while ((count < sectionSize) && (cur != NULL))
		{
			if (count == 0)
				nextInit = cur;

			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;

			count++;
			if ((count == sectionSize) || (cur == NULL))
			{
				if (firstSect)
				{
					root = prev;
					firstSect = false;
				}
				else
				{
					init->next = prev;
				}
				init = nextInit;
			}
		}
		prev = NULL;
		count = 0;
	}
	return root;
}