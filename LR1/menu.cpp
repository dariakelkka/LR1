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

