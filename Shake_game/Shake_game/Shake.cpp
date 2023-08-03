#include "Shake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>


void Shake::Input()
{
	if (_kbhit())
	{
		switch ( _getch() )
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			dir = STOP;
			break;
		}
	}
}

void Shake::Logic(Fruit& inFruit)
{

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; ++i)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir)
	{
	case LEFT:
		--x;
		break;
	case RIGHT:
		++x;
		break;
	case UP:
		--y;
		break;
	case DOWN:
		++y;
		break;

	default:
		break;
	}

	if (x >= widht)
		x = 0;
	else
		if (x < 0)
			x = widht - 2;

	if (y >= hight)
		y = 0;
	else
		if (y < 0)
			y = hight - 2;


	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}

	if (x == inFruit.fruitX && y == inFruit.fruitY)
	{
		score += 10;
		inFruit.placement();
		++nTail;
	}
}
