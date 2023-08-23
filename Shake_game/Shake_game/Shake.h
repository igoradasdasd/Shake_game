#ifndef __Shake_H
#define __Shake_H



#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>


#include "const.h"
#include "fruit.h"
#include <utility>
//#include "vector"
#include <deque>


//using std::vector;
using std::pair;
using std::deque;
using namespace std;
template <typename T>
class Shake
{
	template <class T> friend extern void Draw(const Shake<T>&, const Fruit&);
public:
	Shake() = delete;
	Shake(const T x_in, const T y_in): x(x_in / 2 - 1), y(y_in / 2 - 1), dir(STOP), gameOver(false),
		nTail(0), score(0), FruitEat(false) {};
	void Input();
	void Logic( Fruit& );
	bool GameOver() const { return gameOver; }

private:
	T x;
	T y;
	T tailX[100]{0}, tailY[100]{0};		// координаты €чеек змейки
	int nTail;								// длина змейки
	bool FruitEat;
	deque<pair<T, T>> elements;	// элементы змейки в векторе X  и Y
	eDirections dir;						// направление движени€
	bool gameOver;							// false - game continue; true - gameover
	int score;								// очки		
};

template <typename T>
void Shake<T>::Input()
{
	if (_kbhit())
	{
		switch (_getch())
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
			y = hight;


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


void DrawBorder();

template <class T>
void Draw(const Shake<T>& inShake, const Fruit& inFruit)
{
	system("cls");
	DrawBorder();

	for (int i = 0; i != hight; ++i)
	{
		for (int j = 0; j != (widht + 1); ++j)
		{
			if (j == 0 || j == (widht))
				cout << "#";

			if (i == inShake.y && j == inShake.x)
				cout << "0";
			else
				if (i == inFruit.fruitY && j == inFruit.fruitX)
					cout << "F";
				else
				{
					bool print = false;
					for (int k = 0; k < inShake.elements.size(); ++k)
					{
						if (inShake.elements[k].first == j && inShake.elements[k].second == i)
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

	DrawBorder();

	cout << " Score: " << inShake.score;
}
#endif // !__Shake_H
