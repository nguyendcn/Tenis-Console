#include "gameManager.h"


	GameManager::GameManager()
	{
		srand(time(NULL));
		quit = false;
		score1 = score2 = 0;
		ball = new Ball(WidthGame / 2, (HeightGame / 2));
		player1 = new cPaddle(2, HeightGame / 2 - (MaxBarPlayer / 2));
		player2 = new cPaddle(WidthGame - 2, HeightGame / 2 - (MaxBarPlayer / 2));
	}

	GameManager::~GameManager()
	{
		delete ball, player1, player2;
	}

	void GameManager::ScoreUp(cPaddle * player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();
		player1->Reset();
		player2->Reset();
	}

	void GameManager::DrawBox()
	{
		system("cls");

		for (int i = 0; i <= HeightGame; i++)
		{
			for (int j = 0; j <= WidthGame; j++)
			{
				if (i == 0 || i == HeightGame || j == 0 || j == WidthGame)
				{
					gotoxy(j, i);  cout << char(219);
				}
			}
		}
	}

	void GameManager::Draw()
	{
		int ballx = ball->getX();
		int bally = ball->getY();

		int ballx0 = ball->getX0();
		int bally0 = ball->getY0();

		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		int player1x0 = player1->getX0();
		int player2x0 = player2->getX0();
		int player1y0 = player1->getY0();
		int player2y0 = player2->getY0();

		gotoxy(WidthGame + 3, 10); cout << "Player 1: " << score1;
		gotoxy(WidthGame + 3, 12); cout << "Player 2: " << score2;
		gotoxy(WidthGame + 5, 20); cout << "Press Q to Exit";

		//draw ball and delete back it
		gotoxy(ballx0, bally0); cout << " ";
		gotoxy(ballx, bally); cout << "O";


		//fix error don't delete back it
		if (ball->getDirection() == LEFT)
		{
			gotoxy(ballx + 1, bally); cout << " ";
		}
		if (ball->getDirection() == RIGHT)
		{
			gotoxy(ballx - 1, bally); cout << " ";
		}
		for (int i = 1; i < HeightGame - 1; i++)
		{
			gotoxy(4, i); cout << " ";
			gotoxy(WidthGame - 4, i); cout << " ";
		}

		//draw player
		for (int i = 0; i < MaxBarPlayer; i++)
		{
			gotoxy(player1x, player1y + i); cout << char(219);
			gotoxy(player2x, player2y + i); cout << char(219);
		}


		//delete back it
		if (ball->getDirection() != STOP)
		{
			if (player1y == 1) { gotoxy(player1x, player1y + 5); cout << " "; } // fix error don't delete player1y = 1

			if (player1y0 < player1y)
			{
				gotoxy(player1x0, player1y0); cout << " ";
			}
			if (player2y0 < player2y)
			{
				gotoxy(player2x0, player2y0); cout << " ";
			}
			if (player1y0 > player1x)
			{
				gotoxy(player1x0, player1y0 + MaxBarPlayer - 1); cout << " ";
			}
			if (player2y0 > player2y)
			{
				gotoxy(player2x0, player2y0 + MaxBarPlayer - 1); cout << " ";
			}
		}
	}

	void GameManager::Input()
	{
		ball->Move();

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		if (_kbhit())
		{
			char key = _getch();

			if (key == 'w' || key == 'W')
			{
				if (player1y > 1)
					player1->moveUp();
			}
			if (key == 'i' || key == 'I')
			{
				if (player2y > 1)
					player2->moveUp();
			}

			if (key == 's' || key == 'S')
			{
				if (player1y + MaxBarPlayer < HeightGame - 1)
					player1->moveDown();
			}
			if (key == 'k' || key == 'K')
			{
				if (player2y + MaxBarPlayer < HeightGame - 1)
					player2->moveDown();
			}
			if (key == 'q' || key == 'Q')
			{
				quit = true;
				exit(0);
			}

			if (ball->getDirection() == STOP)
				ball->randomDirection();
		}
	}

	void GameManager::Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		//left paddle
		for (int i = 0; i < MaxBarPlayer; i++)
		{
			if (ballx == player1x + 1)
			{
				if (bally == player1y + i)
					ball->changeDirection((eDir)((rand() % 3) + 4));
			}
		}

		//right paddle
		for (int i = 0; i < MaxBarPlayer; i++)
		{
			if (ballx == player2x - 1)
			{
				if (bally == player2y + i)
					ball->changeDirection((eDir)((rand() % 3) + 1));
			}
		}

		//bottom wall
		if (bally == HeightGame - 1)
		{
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		}

		//top wall
		if (bally == 1)
		{
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		}

		//right wall
		if (ballx == WidthGame - 1)
		{
			//delete 2 player
			for (int i = 1; i < HeightGame; i++)
			{
				gotoxy(WidthGame - 2, i); cout << " ";
			}
			for (int i = 1; i < HeightGame; i++)
			{
				gotoxy(2, i); cout << " ";
			}

			ScoreUp(player1);
		}

		//left wall
		if (ballx == 1)
		{
			//delete 2 player
			for (int i = 1; i < HeightGame; i++)
			{
				gotoxy(WidthGame - 2, i); cout << " ";
			}
			for (int i = 1; i < HeightGame; i++)
			{
				gotoxy(2, i); cout << " ";
			}

			ScoreUp(player2);
		}
	}

	bool GameManager::getQuit() { return quit; }