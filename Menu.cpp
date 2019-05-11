#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu(vector<Menu *> &listSelect)
{
	Menu *items = new Menu();
	Menu *items1 = new Menu();
	Menu *items2 = new Menu();
	Menu *items3 = new Menu();

	items->x = 40;
	items->y = 14;
	items->data = "Play Game";
	listSelect.push_back(items);

	items1->x = 42;
	items1->y = 16;
	items1->data = "Guide";
	listSelect.push_back(items1);

	items2->x = 42;
	items2->y = 18;
	items2->data = "Info";
	listSelect.push_back(items2);

	items3->x = 42;
	items3->y = 20;
	items3->data = "Exit";
	listSelect.push_back(items3);
}


Menu::~Menu()
{
}

void Menu::move(int &dir, bool &Choose, vector<Menu *> listMenu)
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();

			if (key == 72)  //UP
			{
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX(), listMenu[dir]->getY()); cout << listMenu[dir]->getData();

				if (dir == 0)
				{
					dir = 3;
				}
				else
				{
					dir--;
				}

				//print select
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << char(175) << " " << listMenu[dir]->getData();

				break;
			}
			else if (key == 80) //DOWN
			{
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX(), listMenu[dir]->getY()); cout << listMenu[dir]->getData();

				if (dir == 3)
				{
					dir = 0;
				}
				else
				{
					dir++;
				}

				//print select
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << "           ";
				gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << char(175) << " " << listMenu[dir]->getData();

				break;
			}
			else if (key == 13) // ENTER
			{
				Choose = true;
				break;
			}
		}
	}
}

void Menu::draw()
{
	ifstream FileIn("Text.In", ios::in);

	if (FileIn.fail())
	{
		cout << "ERROR file data";
		Sleep(5000);
		exit(0);
	}

	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		cout << text << endl;
	}

	FileIn.close();
}

void mButton()
{
	AnConTro();
	int Check;
	do {
		gotoxy(70, 20);
		cout << " 1: Back ";
		if (_kbhit())
		{
			Check = _getch();
			if (Check == 49)
				break;
		}
	} while (true);
}

void Menu::guide()
{
	system("cls");

	draw();

	gotoxy(10, 15); cout << "Player 1: use button W to UP, S to DOWN";
	gotoxy(10, 16); cout << "Player 2: use button I to UP, K to DOWN";
	gotoxy(10, 17); cout << "          Press Q to exit game";

	mButton();
}

void Menu::info()
{
	system("cls");

	draw();

	gotoxy(10, 15); cout << "Coppy Right: NguyenPTIT_D16";
	gotoxy(10, 16); cout << "Support: superntseal@gmail.com";
	gotoxy(10, 18); cout << "-->>> Thanks for play game <<<--";

	mButton();
}

int Menu::getX() { return x; }

int Menu::getY() { return y; }

string Menu::getData() { return data; }
