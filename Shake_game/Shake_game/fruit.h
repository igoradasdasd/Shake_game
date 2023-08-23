#pragma once
#include "const.h"
#include <random>
#include "Shake.h"

struct Fruit
{
	Fruit() = delete;
	Fruit(const int inX, const int inY) : fruitX(rand() % inX), fruitY(rand() % inY) {};

	void placement()	// перемещаем фрукт на новое место
	{
		fruitX = rand() % widht;  fruitY = rand() % hight;
	}
	int fruitX;
	int fruitY;
};