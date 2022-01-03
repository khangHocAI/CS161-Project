#include<iostream>
#include<Windows.h>

using namespace std;
inline void escape()
{
	system("cls");
	gotoxy(30, 9);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	Sleep(40);
	gotoxy(30, 10);
	cout << "*                    THANKS FOR USING OUR GAME.                     *";
	Sleep(40);
	gotoxy(30, 11);
	cout << "* IT'S STILL IN DEVELOPING SO IF ANY ERROR OCCUR PLEASE FORGIVE US. *";
	Sleep(40);
	gotoxy(30, 12);
	cout << "*         HOPE THAT YOU HAD FUN AND WILL BE BACK SOON.              *";
	Sleep(40);
	gotoxy(30, 13);
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	gotoxy(15, 25);
	cout << "FROM GROUP12- 18APCS2: NGUYEN HUU KHANG, BUI MINH DUC TAI, NGUYEN TIEN ANH.";
	Sleep(3000);
	ExitProcess(0);
}
