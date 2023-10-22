#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "lib.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}

Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }

Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Bibliary();
			delete(buffer);
		}
		head->m_data->~Bibliary();
		delete(head);
	}
}

Bibliary* Keeper::operator[](const int index)
{
	if ((index >= m_size) || index < 0)
	{
		throw "Неверный индекс";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

int Keeper::get_size() { return m_size; }

void Keeper::insert(Bibliary* new_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}

void Keeper::remove(int index)
{

	if ((head != NULL) && (index < m_size) && (index >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		// Mass - объекты, которые хранятся в списке
		Elem* tmonst = head, * helping = head;

		for (int i = 0; i < index; i++)
		{
			helping = tmonst; // предыдущее значение tmonst
			tmonst = tmonst->next;
		}

		if (tmonst == head) // если элемент который надо удалить первый
		{
			head = tmonst->next;
		}
		else
		{
			helping->next = tmonst->next;
		}
		tmonst->m_data->~Bibliary();
		delete(tmonst);
		m_size--; // уменьшаем размер списка
	}

}



void Keeper::save()
{
	setlocale(LC_ALL, "Russian");
	ofstream outfile;
	string initfile = "bibliary.txt";
	try {
		outfile.open(initfile);
		if (!outfile) {
			throw std::runtime_error("Error while opening file " + initfile + " to save data.");
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
	outfile << m_size << endl;
	outfile.close();


	Elem* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}
	system("bibliary.txt");
}



void Keeper::load()
{
	setlocale(LC_ALL, "Russian");
	if (m_size != 0)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Bibliary();
			delete(buffer);
		}
		head->m_data->~Bibliary();
		delete(head);
	}


	ifstream infile;
	int read_size, num_Bibliary;
	string a, b, c, d, e, f, j; //считываемые строки
	string initfile = "bibliary.txt";
	Bibliary* Bibliarys;

	infile.open(initfile);
	if (!infile)
	{
		throw "ошибка открытия ";
		system("pause");
		exit(1);
	}

	infile >> read_size;

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_Bibliary; //читаем номер
		infile.ignore(32767, '\n');

		if (num_Bibliary == 1) // книга
		{

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			Books* book;
			book = new Books;
			book->set_name(a);
			book->set_author(a);
			book->set_yearin(b);
			book->set_annotation(c);
			book->set_genre(d);
			book->set_volume(e);
			book->set_cost(f);
			Bibliarys = book;
			insert(Bibliarys);
		}

		if (num_Bibliary == 2) //и учебник
		{

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, j);
			Textbooks* Textbook;
			Textbook = new Textbooks;
			Textbook->set_name(a);
			Textbook->set_author(b);
			Textbook->set_yearin(c);
			Textbook->set_WhStudy(d);
			Textbook->set_Ystudy(e);
			Textbook->set_volume(f);
			Textbook->set_cost(j);
			Bibliarys = Textbook;
			insert(Bibliarys);
		}

		if (num_Bibliary == 3) // канцелярия
		{

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);

			Canselars* canselar;
			canselar = new Canselars;
			canselar->set_type(a);
			canselar->set_color(b);
			canselar->set_purpose(c);
			canselar->set_cost(d);
			Bibliarys = canselar;
			insert(Bibliarys);
		}
	}
}