#include "Shake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

/*
template <typename T>
void Shake<T>::Input()
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
template <typename T>
void Shake<T>::Logic(Fruit& inFruit)
{
	T prevX = tailX[0];
	T prevY = tailY[0];
	T prev2X, prev2Y;
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


	if (!elements.empty() && FruitEat == false)
	{
		rotate(elements.rbegin(), elements.rbegin() + 1, elements.rend());
		elements[0].first = x;
		elements[0].second = y;
	}
	else
		FruitEat = false;

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
			x = widht - 1;

	if (y >= hight)
		y = 0;
	else
		if (y < 0)
			y = hight ;


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

		pair<int, int>* p = new pair<int, int>{ x, y };
		elements.push_front(*p);
		delete p;
		FruitEat = true;

	}
}
*/

void DrawBorder()
{
	for (int i = 0; i != (widht + 2); ++i)
	{
		cout << "#";
	}
	cout << endl;
}
