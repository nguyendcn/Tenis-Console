#pragma once
#include "gameManager.h"

class Menu
{
private:
	int x, y;
	string data;
public:
	Menu();
	Menu(vector<Menu *> &);
	~Menu();

	void move(int &, bool &, vector<Menu *>);
	void draw();
	void guide();
	void info();

	int getX();
	int getY();
	string getData();

};

