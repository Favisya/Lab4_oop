#include "Library.h"

void Library::AddData(std::ifstream& fin)
{
	fin >> _title;
	fin >> _author;
	fin >> _year;
	fin >> _count;
}

string Library::returnFirst()
{
	return _author;
}

string Library::returnSecond()
{
	return _year;
}

bool Library::Find(string author, string _year)
{
	if (_author == author && (_year >= _year))
	{
		return true;
	}
	return false;
}

void Library::Out()
{
	cout << "#---------------------------------------------#" << endl;
	cout << "�������� : " << _title << endl;
	cout << "����� : " << _author << endl;
	cout << "��� ������� : " << _year << endl;
	cout << "���-�� ���� � ���������� : " << _count << endl;
	
}