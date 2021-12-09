#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "string"

using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
class Interface
{
public:
	virtual void AddData(ifstream&) = 0;
	virtual bool Find(string, string) = 0;
	virtual void Out() = 0;
	virtual std::string returnFirst() = 0;
	virtual std::string returnSecond() = 0;
};