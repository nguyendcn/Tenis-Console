#include "paddle.h"


	cPaddle::cPaddle(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = x0 = posX;
		y = y0 = posY;
	}
    void cPaddle::Reset() { x = x0 = originalX; y = y0 = originalY; }

	void cPaddle::moveUp() { y0 = y; y--; }
	void cPaddle::moveDown() { y0 = y; y++; }

	int cPaddle::getX() { return x; }
	int cPaddle::getY() { return y; }
	int cPaddle::getX0() { return x0; }
	int cPaddle::getY0() { return y0; }