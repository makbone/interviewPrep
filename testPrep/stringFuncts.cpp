#include "stdafx.h"
#include "stringFuncts.h"
#include <vector>


stringFuncts::stringFuncts()
{
}


stringFuncts::~stringFuncts()
{
}

//
bool stringFuncts::isPalindrome(string input)
{
	//write code here 
	int startIndex = 0;
	int endIndex = input.size() - 1;

	while (startIndex < endIndex)
	{
		if (input[startIndex] != input[endIndex])
			return false;
	}
	return true;
}

//
bool stringFuncts::stringMatch(string source, string compStr)
{
	if (source.compare(compStr) == 0)	// If direct match return true
		return true;

	if (source.size() == 0 || compStr.size() == 0) // Empty string returns false
		return false;

	string::iterator sourceIter = source.begin();
	string::iterator compIter = compStr.begin();

	uint wildCardActive = false;

	while (compIter != compStr.end())
	{
		if (*sourceIter == *compIter)
		{	// Match so continue to next element
			compIter++;
			sourceIter++;
			if (wildCardActive)
				wildCardActive = false;
			if ((sourceIter == source.end()) && (compIter == compStr.end()))
				return true;
		}
		else if (*sourceIter == '*')
		{	// Handle wild card
			wildCardActive = true;
			sourceIter++;
			if (sourceIter == source.end())
				return true;	// Last char *, so match
		}
		else if (wildCardActive)
		{
			compIter++;
		}
		else
		{
			return false;
		}
	}
	return false;
}

// reverse string
void stringFuncts::reverseString(string &source)
{
	// swap the last and first
	int startIndex = 0;
	int endIndex = source.size() - 1;
	char tChar = NULL;

	while (startIndex < endIndex)
	{
		tChar = source[startIndex];
		source[startIndex] = source[endIndex];
		source[endIndex] = tChar;

		startIndex++;
		endIndex--;
	}
}

// reverse string
void stringFuncts::reverseCharString(char* (&source), int strSize)
{
	char t = NULL;
	int startIndex = 0;
	int endIndex = strSize - 2;	// ignore null terminator

	while (startIndex < endIndex)
	{
		t = source[startIndex];
		source[startIndex] = source[endIndex];
		source[endIndex] = t;

		startIndex++;
		endIndex--;
	}
}

//
int stringFuncts::myAtoi(string src)
{
	int finVal = 0;
	int count = 0;
	int pos = src.size() - 1;

	while (pos >= 0)
	{
		int tChar = src[pos];
		int tVal = tChar - '0';
		if (tVal > 9)
			return -1;

		finVal = int(finVal + (tVal * pow(10, count)));
		count++;
		pos--;
	}
	return finVal;
}

// Zen3 Interview
int stringFuncts::getIntFromChar(char c)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
	else
	{
		//cout << "Not Supported Number " << c << endl;
	}

	return -1;
}

void stringFuncts::printExpStr(string str)
{
	if (str.size() == 0)
	{
		cout << "Empty string!!";
		return;
	}

	string expStr = "";
	uint pos = 0;
	int multi = 0;
	int bracketPos = 0;
	vector<exprNode*> eNodes;

	while (pos < str.size())
	{
		multi = getIntFromChar(str[pos]);
		if (multi >= 0)
		{
			bracketPos++;
			exprNode* tNode = new exprNode(multi);
			eNodes.push_back(tNode);
		}
		else if ((str[pos] != '[') && (str[pos] != ']'))
		{
			if (bracketPos == 0)	// Append to main string
				expStr.append(1, str[pos]);
			else
				eNodes[bracketPos - 1]->enStr.append(1, str[pos]);
		}
		else if (str[pos] == '[')
		{
			cout << "Entering Bracket " << bracketPos << " String=" << expStr.c_str() << endl;
		}
		else if (str[pos] == ']')
		{
			// append string for closing bracket 
			string tempStr = eNodes[bracketPos - 1]->enStr;
			int strCount = (eNodes[bracketPos - 1]->strCount) - 1;
			for (int i = 0; i < strCount; i++)	// -1 from count since first string already built
				eNodes[bracketPos - 1]->enStr.append(tempStr);

			if (strCount < 0)	// handle 0 multiplier
				eNodes[bracketPos - 1]->enStr = "";
			eNodes[bracketPos - 1]->processed = true;
			bracketPos--;

			// Take appended string and move into higher level bracket, since processed
			if (bracketPos > 0)
				eNodes[bracketPos - 1]->enStr.append(eNodes[bracketPos]->enStr);
			else
				expStr.append(eNodes[bracketPos]->enStr);

		}
		else {}
		pos++;
	}
	cout << expStr.c_str() << endl;
}