#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "const.h"
#include "Shake.h"
#include "fruit.h"

using namespace std;

namespace
{
	bool gameOver;

//	const int widht = 20;
//	const int hight = 20;
//	int x, y, fruitX, fruitY, score;
//	int fruitX, fruitY, score;
//	enum eDirections { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirections dir = STOP;
	int tailX[100], tailY[100];
	int nTail;

}

void Setup()
{
	/*
	gameOver = false;
	x = widht / 2 - 1;
	y = hight / 2 - 1;
		score = 0;

	fruitX = rand() % widht;
	fruitY = rand() % hight;
*/
	
}

void Draw(const Shake & inShake, const Fruit & inFruit)
{
	system("cls");
	for (int i = 0; i != (widht + 1) ; ++i)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i != hight; ++i)
	{
		for (int j = 0; j != widht; ++j)
		{
			if (j == 0 || j == (widht - 1))
				cout << "#";

			if (i == inShake.y && j == inShake.x)
				cout << "0";
			else
				if (i == inFruit.fruitY && j == inFruit.fruitX)
					cout << "F";
				else
				{
					bool print = false;
					for (int k = 0; k < nTail; ++k)
					{
						if (inShake.tailX[k] == j && inShake.tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}
					if (print == false)
					cout << " ";

				}
			
		}
		cout << endl;
	}

	for (int i = 0; i != (widht + 1); ++i)
	{
		cout << "#";
	}
	cout << endl;
	cout << " Score: " << inShake.score;
}
/*
void Input()
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
*/
/*
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
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

	switch(dir)
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
	
	if (x > widht || x < 0 || y > hight || y < 0)
		gameOver = true;

	
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

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % widht;
		fruitY = rand() % hight;
		++nTail;
	}
		
}

*/
int main(void)
{
	Setup();
	Shake shake = Shake(widht, hight);
	Fruit fruit = Fruit(widht, hight);

	while (!shake.GameOver() )
	{

		shake.Input();
		shake.Logic(fruit);
		Draw(shake, fruit);
//		Input();
//		Logic();

		Sleep(500);
	}


	return 0;
}
