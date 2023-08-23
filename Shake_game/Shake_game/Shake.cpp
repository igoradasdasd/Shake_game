#include "Shake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

void DrawBorder()
{
	for (int i = 0; i != (widht + 2); ++i)
	{
		cout << "#";
	}
	cout << endl;
}
