#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "string"
#include "Interface.h"



class Library : public Interface
{
private:
	short int _number = 0;
	string _title;
	string _author;
	string _year;
	string _count;
public:
	Library() = default;
	~Library() = default;
	void AddData(ifstream&);
	void Out();
	bool Find(string, string);
	std::string returnFirst();
	string returnSecond();
};