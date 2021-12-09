#include "ListTown.h"

void ListTown::AddData(ifstream& fin)
{
	fin >> _name;
	fin >> _income;
	fin >> _price;
	fin >> _green;
}

string ListTown::returnSecond()
{
	return _green;
}

string ListTown::returnFirst()
{
	return _price;
}

bool ListTown::Find(string price, string green)
{
	if (_price == price && _green == green)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ListTown::Out()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "#---------------------------------------------#" << endl;
	cout << "Название города: " << _name << endl;
	cout << "Средняя зарплата в тыс.руб. : " << _income << endl;
	cout << "Степень озеленения в % : " << _green << endl;
	cout << "Средняя стоимость жилой площади : " << _price << endl;
}