#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "const.h"
#include "Shake.h"
#include "fruit.h"

using namespace std;

int main(void)
{
	Shake<int> shake = Shake<int>(widht, hight);
	Fruit fruit = Fruit(widht, hight);

	while (!shake.GameOver() )
	{

		shake.Input();
		shake.Logic(fruit);
		Draw<int>(shake, fruit);


		Sleep(500);
	}


	return 0;
}
