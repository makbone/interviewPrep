#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef uint
typedef unsigned int uint;
#endif

struct exprNode
{
	bool processed = false;
	int strCount = 0;
	string enStr = "";

	exprNode(int sc, string s = "") :
		strCount(sc), enStr(s) {};

};

class stringFuncts
{
public:
	stringFuncts();
	~stringFuncts();

	// string Functions
	bool isPalindrome(string input);
	bool stringMatch(string source, string compStr);
	void reverseString(string &source);
	int myAtoi(string src);
	void printExpStr(string str);

	// char* Functions
	int getIntFromChar(char c);
	void reverseCharString(char* (&source), int size);

	string s;
};

