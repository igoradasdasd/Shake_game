#pragma once
#include "const.h"
#include "fruit.h"
#include "utility"
//#include "vector"


//using std::vector;
using std::pair;

class Shake
{
	friend extern void Draw(const Shake&, const Fruit&);
public:
	Shake() = delete;
	Shake(const int x_in, const int y_in): x(x_in / 2 - 1), y(y_in / 2 - 1), dir(STOP), gameOver(false),
		nTail(0), score(0) {};
	void Input();
	void Logic( Fruit& );
	bool GameOver() const { return gameOver; }

private:
	int x;
	int y;
	int tailX[100]{0}, tailY[100]{0};		// координаты €чеек змейки
	int nTail;								// длина змейки
	//forward_list<pair<int, int>> elements;		// элементы змейки в векторе X  и Y
	eDirections dir;					// направление движени€
	bool gameOver;					// false - game continue; true - gameover
	int score;
};

