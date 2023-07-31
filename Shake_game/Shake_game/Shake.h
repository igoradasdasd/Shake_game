#pragma once
#include "const.h"

class Shake
{
public:
	Shake(const int x_in, const int y_in): x(x_in / 2 - 1), y(y_in / 2 - 1) {};
	void Input();
	void Logic();
	bool GameOver() { return gameOver; }

private:
	int x;
	int y;
	int tailX[100]{0}, tailY[100]{0};		// координаты €чеек змейки
	int nTail;								// длина змейки
	eDirections dir = STOP;					// направление движени€
	bool gameOver = false;					// false - game continue; true - gameover
};

