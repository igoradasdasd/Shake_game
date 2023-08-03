#pragma once
#include "const.h"
#include <random>
#include "Shake.h"

struct Fruit
{
	//friend Shake;
	//friend extern void Draw(const Shake&, const Fruit &);
	Fruit() = delete;
	Fruit(const int inX, const int inY) : fruitX(rand() % inX), fruitY(rand() % inY) {};

	void placement()
	{
		fruitX = rand() % widht;  fruitY = rand() % hight;
	}
	int fruitX;
	int fruitY;
};