#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "string"
#include "Interface.h"



class ListTown : public Interface
{
private:
	string _name;
	string _income;
	string _price;
	string _green;
public:
	ListTown() = default;
	~ListTown() = default;
	void AddData(ifstream&);
	bool Find(string,string);
	string returnFirst();
	string returnSecond();
	void Out();
};