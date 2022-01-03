#include<iostream>
#include<Windows.h>

using namespace std;

inline void splashscreen()
{
	system("cls");
	gotoxy(12, 4); Sleep(50);
	cout << "XXXX    XXXX    ";
	cout << "OOOOO         "; 
	cout << "CCCC    ";
	cout << "OOOOO     ";
	cout << "MM      MM   BBBBBB       ";
	cout << "AAAA    ";
	cout << "TTTTTTTTT";
	gotoxy(12, 5); Sleep(50);
	cout << " XXXX  XXXX   "; 
	cout << "OOO   OOO     "; 
	cout << "CCC     "; 
	cout << "OOO   OOO   ";
	cout << "MMM    MMM   BB   BBB    ";
	cout << "AA  AA      ";
	cout << "TTT ";
	gotoxy(12, 6); Sleep(50);
	cout << "   XXXXXX     ";
	cout << "OOO   OOO     ";
	cout << "CCC     "; 
	cout << "OOO   OOO   ";
	cout << "MM M  M MM   BBBBBB     ";
	cout << "AAAAAAAA     ";
	cout << "TTT";
	gotoxy(12, 7); Sleep(50);
	cout << " XXXX  XXXX   ";
	cout << "OOO   OOO     ";
	cout << "CCC     ";
	cout << "OOO   OOO   ";
	cout << "MM  MM  MM   BB   BBB  ";
	cout <<"AAA    AAA    ";
	cout << "TTT";
	gotoxy(12, 8); Sleep(50);
	cout << "XXXX    XXXX    ";
	cout << "OOOOO         ";
	cout << "CCCC    ";
	cout << "OOOOO     ";
	cout << "MM      MM   BBBBBBB  ";
	cout << "AAA      AAA   ";
	cout << "TTT";
	gotoxy(45, 12); Sleep(50);
	cout << "..........LOADING..........";
	gotoxy(15, 26); Sleep(50);
	cout << "THIS GAME WAS MADE BY GROUP 12 APCS18: NGUYEN HUU KHANG, BUI MINH DUC TAI, NGUYEN TIEN ANH.";
	Sleep(1000);
}