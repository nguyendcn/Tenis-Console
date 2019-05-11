#include "ball.h"



	Ball::Ball(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = x0 = posX; y = y0 = posY;
		direction = STOP;
	}

	void Ball::Reset()
	{
		x = x0 = originalX; y = y0 = originalY;
		direction = STOP;
	}

	void Ball::changeDirection(eDir dir)
	{
		direction = dir;
	}

	void Ball::randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}

	void Ball::Move()
	{
		if (direction == STOP)
		{
			return;
		}
		else if (direction == LEFT)
		{
			x0 = x;
			x--;
			return;
		}
		else if (direction == RIGHT)
		{
			x0 = x;
			x++;
			return;
		}
		else if (direction == UPLEFT)
		{
			x0 = x;
			y0 = y;
			x--; y--;
			return;
		}
		else if (direction == DOWNLEFT)
		{
			x0 = x;
			y0 = y;
			x--; y++;
			return;
		}
		else if (direction == UPRIGHT)
		{
			x0 = x;
			y0 = y;
			x++; y--;
			return;
		}
		else if (direction == DOWNRIGHT)
		{
			x0 = x;
			y0 = y;
			x++; y++;
			return;
		}
	}

	int Ball::getX() { return x; }
	int Ball::getY() { return y; }
	int Ball::getX0() { return x0; }
	int Ball::getY0() { return y0; }
	eDir Ball::getDirection() { return direction; }

