#pragma once

#include <vector>
#include <list>
using namespace std;

#ifndef uint
typedef unsigned int uint;
#endif

// Link List Node Object
struct Node
{
	Node * next;
	char value;

	Node(char c)
	{
		value = c;
		next = NULL;
	}
};

class linkListFuncts
{
public:
	linkListFuncts();
	~linkListFuncts();

	vector<char> convertNodesToCharVector(Node* root);
	list<char> convertNodesToCharList(Node* root);
	Node* convertCharVectorToNodes(vector<char> vChars);

	char findMin(Node* root);
	void deleteLast(Node* &root);
	Node InsertAtTheEnd(Node head, int data);
	void enqueueN(Node* &root, char val);
	char dequeueN(Node* &root);

	Node* deleteMinSort(Node* root);
	void deleteMinSortHelper(char* min, Node* &c, Node* &p, Node* &lom);
	Node* deleteMinSortRecurse(Node* root);

	void reverseLinkedList(Node* &root);
	Node* ReverseLLSections(Node * root, int sectionSize);
	Node* ReverseLLSectionsI(Node * &root, int sectionSize);
	
};

