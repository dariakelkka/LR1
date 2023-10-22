#include "lib.h"

using namespace std;

Textbooks::Textbooks()
{
	cout << "Constructor Textbook without attributes was called." << endl;
}

Textbooks::~Textbooks()
{
	cout << "Destructor Textbook was called." << endl;
}

Textbooks::Textbooks(const Textbooks& Textbook_copy)
{
	name = Textbook_copy.name;
	author = Textbook_copy.author;
	yearin = Textbook_copy.yearin;
	WhStudy = Textbook_copy.WhStudy;
	Ystudy = Textbook_copy.Ystudy;
	volume = Textbook_copy.volume;
	cost = Textbook_copy.cost;
}

Textbooks::Textbooks(string)
{
	this->name = name;
}

string Textbooks::get_name() const { return name; }

void Textbooks::set_name(string name_ch) { name = name_ch; }

string Textbooks::get_author() const { return author; }

void Textbooks::set_author(string author_ch) { author = author_ch; }

string Textbooks::get_yearin() const { return yearin; }

void Textbooks::set_yearin(string yearin_ch) { yearin = yearin_ch; }

string Textbooks::get_WhStudy() const { return WhStudy; }

void Textbooks::set_WhStudy(string WhStudy_ch) { WhStudy = WhStudy_ch; }

string Textbooks::get_Ystudy() const { return Ystudy; }

void Textbooks::set_Ystudy(string Ystudy_ch) { Ystudy = Ystudy_ch; }

string Textbooks::get_volume() const { return volume; }

void Textbooks::set_volume(string volume_ch) { volume = volume_ch; }

string Textbooks::get_cost() const { return cost; }

void Textbooks::set_cost(string cost_ch) { cost = cost_ch; }

bool Textbooks::SameCost(string SC_ch) {

	if (SC_ch == (this->get_cost()))
		return true;
	else return false;
}

void Textbooks::show()
{
	setlocale(LC_ALL, "Russian");
	cout << "------------------------------------" << endl;
	cout << "Предмет: Учебник" << endl;
	cout << "Название: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Год выпуска: " << yearin << endl;
	cout << "Для какого уч заведения:" << WhStudy << endl;
	cout << "Год обучения: " << Ystudy << endl;
	cout << "Кол-во страниц: " << volume << endl;
	cout << "Стоимость: " << cost << endl;
	cout << "------------------------------------" << endl;
}

void Textbooks::rewrite()
{
	setlocale(LC_ALL, "Russian");
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Учебник: " << endl;
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите нового автора: ";
	getline(cin, author);
	cout << "Введите новый год выпуска: ";
	getline(cin, yearin);
	cout << "Введите новое уч заведение: ";
	getline(cin, WhStudy);
	cout << "Введите год обучения: ";
	getline(cin, Ystudy);
	cout << "Введите кол-во страниц: ";
	getline(cin, volume);
	cout << "Введите новую стоимость: ";
	getline(cin, cost);
	cout << "------------------------------------" << endl;
}

void Textbooks::saving()
{
	setlocale(LC_ALL, "Russian");
	ofstream outfile;
	string initfile = "bibliary.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Ошибка файла";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << author << endl << yearin << endl << WhStudy << endl << Ystudy << endl << volume << endl << cost << endl;
		outfile.close();
	}

}

void Textbooks::redact_str(int num_str, string red_str)
{
	setlocale(LC_ALL, "Russian");
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->author = red_str;
		break;
	case 3:
		this->yearin = red_str;
		break;
	case 4:
		this->WhStudy = red_str;
		break;
	case 5:
		this->Ystudy = red_str;
		break;
	case 6:
		this->volume = red_str;
		break;
	case 7:
		this->cost = red_str;
		break;
	default:
		throw "Неверный номер меню";
		break;
	}
}