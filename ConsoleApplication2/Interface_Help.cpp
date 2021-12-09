#include "Interface_Help.h"

Interface_Help::Interface_Help()
{
	setlocale(LC_ALL, "RUSSIAN");
	bool boolPerf = true;
	int command1 = 1;
	ifstream fin("input.txt");

	do
	{
		try
		{
			if (!fin.is_open())
			{
				throw(1);
			}
			else if (fin.peek() == EOF)
			{
				throw(2);
			}
		}
		catch (int number)
		{
			switch (number)
			{
			case 1:
				boolPerf = false;
				std::cerr << "���� \"input.txt\" � ���������� ��������� �����������" << endl;
				break;
			case 2:
				boolPerf = false;
				std::cerr << "���� \"input.txt\" ������" << endl;
				break;
			default:
				break;
			}
		}
		if (!boolPerf)
		{
			short int response;
			cout << "�� ������ ��������� ������� �������� �����? (1 - ��, 0 - ���): ";
			cin >> response;
			if (!response)
			{
				boolPerf = true;
			}
		}
	} while (!boolPerf);


	if (fin.is_open() && fin.peek() != EOF)
	{
		std::multimap <std::string, Interface*> __book;
		std::vector <Interface*> __town;
		short townCount;
		short bookCount;
		fin >> townCount;
		for (int i = 0; i < townCount; i++)
		{
			__town.push_back(new ListTown());
			__town[i]->AddData(fin);
		}
		fin >> bookCount;
		for (int i = 0; i < bookCount; i++)
		{
			Library* newbook = new Library;
			newbook->AddData(fin);
			std::string destination = newbook->returnSecond();
			__book.insert(std::pair <std::string, Interface*>(newbook->returnSecond(), new Library(*newbook)));
			delete newbook;
		}

		std::sort(__town.begin(), __town.end(), [](Interface* first, Interface* second)->bool
		{
			if (first->returnSecond() < second->returnSecond())
			{
				return true;
			}
			if (first->returnSecond() == second->returnSecond())
			{
				if (first->returnFirst() < second->returnFirst())
				{
					return true;
				}
			}
			return false;
		});

		std::string compareParameter1;
		std::string compareParameter2;
		bool flag;
		do
		{
			
			cout << "��������, � ����� ����� ������ ��������:" << endl;
			cout << "1 - ������" << endl;
			cout << "2 - ����������" << endl;
			cout << "0 - �����" << endl;
			cin >> command1;
			switch (command1)
			{
			case 1:
				cout << "������� ������� ��������� ����� �������: ";

				cin >> compareParameter1;
				cout << "������� ������� ����������: ";

				cin >> compareParameter2;
				flag = false;
				cout << "�� ������� ���������� ������� ��������� ������: " << endl;
				for (int i = 0; i < __town.size(); i++)
				{
					if (__town[i]->Find(compareParameter1, compareParameter2))
					{
						flag = true;
						__town[i]->Out();
					}
					if (i == __town.size() - 1)
					{
						cout << "#---------------------------------------------#" << endl;
					}
				}
				if (flag == false)
				{
					cout << "�� ���� ����� �� ������� ���������� ������ �� ���" << endl;
				}
				break;
			case 2:
				cout << "������� ������: ";
				cin >> compareParameter1;
				cout << "������� ��� ������� �� �������� ���������� �����: ";
				cin >> compareParameter2;
				flag = false;
				for (auto itt : __book)
				{
					if (itt.second->Find(compareParameter1, compareParameter2))
					{
						if (flag == false)
						{
							cout << "�� ������� ���������� ������� ��������� �����: " << endl;
						}
						flag = true;
						itt.second->Out();
					}
				}
				if (flag == false)
				{
					cout << "#---------------------------------------------#" << endl;
					cout << "�� ���� ����� �� ���� �������" << endl;
				}
				cout << "#---------------------------------------------#" << endl;
				break;
			case 0:
				break;
			default:
				cout << "������� ������������ �������" << endl;
				break;
			}
		} while (command1);
		system("pause");

		for (auto itt : __book)
		{
			delete itt.second;
		}
		for (auto itp : __town)
		{
			delete itp;
		}
	}
}