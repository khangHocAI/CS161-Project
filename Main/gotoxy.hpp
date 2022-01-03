#include<Windows.h>

inline void gotoxy(int x, int y)
{
	COORD co = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}