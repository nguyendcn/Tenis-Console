#pragma once

#include "paddle.h"
#include "ball.h"

class GameManager
{
private:
	int score1, score2;
	bool quit;
	Ball *ball;
	cPaddle *player1;
	cPaddle *player2;
public:
	GameManager();
	~GameManager();

	void ScoreUp(cPaddle *);
	void DrawBox();
	void Draw();
	void Input();
	void Logic();

	bool getQuit();
};

