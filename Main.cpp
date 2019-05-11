#include "Menu.h"


int main()
{
	resizeConsole(WidthConsole, HeightConsole);
	AnConTro();

	vector<Menu *> listMenu;
	Menu *m = new Menu(listMenu);

	m->draw();

	int dir = 0, dir0 = 0, sizeOfListMenu = listMenu.size();
	bool Choose = false;
	char dChoose = 175;
	
	//mainloop
	while (true)
	{	

		for (int i = 0; i < listMenu.size(); i++)
		{
			gotoxy(listMenu[i]->getX(), listMenu[i]->getY()); cout << listMenu[i]->getData();
		}

		gotoxy(listMenu[dir]->getX() - 3, listMenu[dir]->getY()); cout << dChoose << " " << listMenu[dir]->getData() << "  "; // Select

		m->move(dir, Choose, listMenu);

		if (Choose == true)
		{
			Choose = false;
			if (dir == 0) // play game;
			{
				GameManager *game = new GameManager();

				game->DrawBox();

				while (!game->getQuit())
				{
					game->Draw();
					Sleep(50);
					game->Input();
					game->Logic();
				}

				delete game;
			}
			else if (dir == 1) // Guid
			{
				m->guide();

				system("cls");
				m->draw();
			}
			else if (dir == 2) //Info
			{
				m->info();

				system("cls");
				m->draw();
			}
			else if (dir == 3)
			{
				delete m;

				exit(0);
			}
	   }
	}
	
	return 0;
}