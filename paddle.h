#pragma once

#include "Graphics.h"

class cPaddle
{
private:
	int x, y;
	int x0, y0;
	int originalX, originalY;
public:
	cPaddle(int, int);
	void Reset();
	void moveUp();
	void moveDown();

	int getX();
	int getY();
	int getX0();
	int getY0();

};