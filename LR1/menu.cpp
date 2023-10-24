#include "lib.h"

using namespace std;
void Menu::main_menu()
{
	while (exit == 1)
	{
		switch (show_options())
		{
		case1:
			show_all_Bibliarys();
			break;
		case2:
			change_data();
			break;
		case3:
			add_new();
			break;
		case4:
			save_to_file();
			break;
		case5:
			load_from_file();
			break;
		case6:
			delete_Bibliary();
			break;
		case7:
			findCostsame();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}

void Menu::findCostsame()
{
	string a;
	setlocale(LC_ALL, "Rus");
	cout << "\n������� ���������" << endl;
	cin >> a;
	if (list.get_size() == 0)
	{
		return;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		if ((list[i]->SameCost(a)) == true)
			list[i]->show();
	}
	system("pause");
}

int Menu::show_options()
{
	int c1;
	setlocale(LC_ALL, "Rus");
	cout << "\n�������� ��������: " << endl;
	cout << "1. �������� ��" << endl;
	cout << "2. �������� ������ � ������" << endl;
	cout << "3. �������� �����" << endl;
	cout << "4. ��������� ���������� � ����" << endl;
	cout << "5. ������� ���������� �� �����" << endl;
	cout << "6. ������� �����" << endl;
	cout << "7. ����� ������� � ���������� �����" << endl;
	cout << "8. �����" << endl;
	cin >> c1;
	return c1;
}

void Menu::show_all_Bibliarys()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "������ ���. ";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << "_" << endl;
			cout << i + 1 << "|";
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::change_data()
{
	int c2, c3;
	system("cls");
	try
	{
		cout << "����� ����� ��������?" << list.get_size() << endl;
		cin >> 2;
		if ((c2 < c1) || (c2 > list.get_size()))
		{
			throw "������!";
		}
		list[c2 - 1]->show();
		cout << "����� ������ ��������?" << enld;
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "��� ��������?" << endl;
		if (c3 == 5)
		{
			bool fl = false;
			while (fl == false)
			{
				try
				{
					getline(cin, redact);
					float f = stof(redact);
					fl = true;
				}
				catch (...)
				{
					cout << "������� �����" << endl;
				}
			}
			list[c2 - 1]->redact_str(c3, redact);
		}
		else
		{
			getline(cin, redact);
			list[c2 - 1]->redact_str(c3, redact);
			cout << "������";
		}
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::add_new()
{
	int c2;
	system("cls");
	cout << "\n��� ��������?" << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ����������" << endl;
	cout << "4. �����" << endl;
	cin >> c2;

	switch (c2)
	{
	case 1:
		Books * book;
		book = new Books;
		Bibliarys = book;
		bool->rewrite();
		list.insert(Bibliarys);
		cout << "������!" << endl;
		break;
	case 2:
		Textbooks * textbook;
		Textbook = new Textbooks;
		Bibliarys = Textbook;
		Textbook->rewrite();
		list.insert(Bibliarys);
		cout << "������!" << endl;
		break;
	case 3:
		Canselard * emp;
		emp = new Canselars;
		Bibliarys = emp;
		emp->rewrite();
		list.insert(Bibliarys);
		cout << "������!" << endl;
		break;
	default:
		break;
	}
	system("pause");
}

void Menu::save_to_file()
{
	system("cls");
	try
	{
		if (list.get_size() == 0)
		{
			throw "�����";
		}
		list.save();
		cout << "������!" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
	system("pause");
}

void Menu::load_from_file()
{
	system("cls");
	try
	{
		list.load();
		cout << "���������" << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}

void Menu::delete_Bibliary()
{
	int c2;
	system("cls");
	cout << "��� �������?" << list.get_size() << endl;
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << "_" << endl;
		cout << i + 1 << "|";
		list[i]->show();
	}
	cin >> c2;
	c2 = list.get_size() - c2 + 1;
	try
	{
		if ((c2 < c1) || (c2 > list.get_size()))
		{
			throw"������";
			exception;
		}
		list.remove(c2 - 1);
		cout << "���������" << endl;
		system("pause");
	}
	catch (const char* i)
	{
		cout << i << endl;
	}
}

void Menu::exit_from_programm()
{
	exit = 8;
}