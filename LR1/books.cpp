#include "lib.h"
#include "Books.h"

using namespace std;

Books::Books()
{
    cout << "Constructor Books without attributes was called." << endl;
}

Books::~Books()
{
    cout << "Destructor Books was called." << endl;
}


Books::Books(const Books& Books_copy)
{
    name = Books_copy.name;
    author = Books_copy.author;
    yearin = Books_copy.yearin;
    annotation = Books_copy.annotation;
    genre = Books_copy.genre;
    volume = Books_copy.volume;
    cost = Books_copy.cost;
}

Books::Books(string name)
{
    this->name = name;
}

string Books::get_name() const { return name; }
void Books::set_name(string name_ch) { name = name_ch; }

string Books::get_author() const { return author; }
void Books::set_author(string author_ch) { author = author_ch; }



string Books::get_yearin() const { return yearin; }

void Books::set_yearin(string yearin_ch) { yearin = yearin_ch; }


string Books::get_annotation() const { return annotation; }

void Books::set_annotation(string annotation_ch) { annotation = annotation_ch; }


string Books::get_genre() const { return genre; }

void Books::set_genre(string genre_ch) { genre = genre_ch; }


string Books::get_volume() const { return volume; }

void Books::set_volume(string volume_ch) { volume = volume_ch; }

string Books::get_cost() const { return cost; }

void Books::set_cost(string cost_ch) { cost = cost_ch; }

bool Books::SameCost(string SC_ch) {

    if (SC_ch == (this->get_cost()))
        return true;
    else return false;
}

void Books::show()
{
    setlocale(LC_ALL, "Russian");
    cout << "------------------------------------" << endl;
    cout << "Предмет: Книга" << endl;
    cout << "Название: " << name << endl;
    cout << "Автор: " << author << endl;
    cout << "Год выпуска: " << yearin << endl;
    cout << "Аннотация: " << annotation << endl;
    cout << "Жанр: " << genre << endl;
    cout << "Кол-во страниц: " << volume << endl;
    cout << "Стоимость: " << cost << endl;
    cout << "------------------------------------" << endl;
}

void Books::rewrite()
{
    setlocale(LC_ALL, "Russian");
    cout << "------------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Предмет: Книги" << endl;
    cout << "Введите новое название: ";
    getline(cin, name);

    cout << "Введите нового автора: ";
    getline(cin, author);

    cout << "Введите новый год выпуска: ";
    getline(cin, yearin);
    cout << "Введите новую аннотацию: ";
    getline(cin, annotation);
    cout << "Введите новый жанр: ";
    getline(cin, genre);
    cout << "Введите кол-во страниц: ";
    getline(cin, volume);
    cout << "Введите новую стоимость: ";
    getline(cin, cost);

    cout << "------------------------------------" << endl;
}

void Books::saving()
{
    setlocale(LC_ALL, "Russian");
    ofstream outfile;
    string initfile = "bibliary.txt";
    outfile.open(initfile, ios_base::app);
    if (!outfile)
    {
        throw "Ошибка!";
        system("pause");
        exit(1);
    }
    outfile << 1 << endl << name << endl << author << endl << yearin << endl << annotation << endl << genre << endl << volume << endl << cost << endl;
    outfile.close();

}

void Books::redact_str(int num_str, string red_str)
{
    setlocale(LC_ALL, "Russian");
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:

        break;
    case 3:
        this->yearin = red_str;

        break;
    case 4:
        this->annotation = red_str;

        break;
    case 5:
        this->genre = red_str;

        break;
    case 6:
        this->volume = red_str;

        break;
    case 7:
        this->cost = red_str;

        break;
    default:
        throw "Ошибка пункта меню!";
        break;
    }
}