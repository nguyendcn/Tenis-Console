#pragma once
#include "Graphics.h"

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class Ball
{
private:
	int x, y;
	int x0, y0;
	int originalX, originalY;
	eDir direction;
public:

	Ball(int, int);
	void Reset();
	void changeDirection(eDir);
	void randomDirection();
	void Move();
	int getX();
	int getY();
	int getX0();
	int getY0();
	eDir getDirection();

};
