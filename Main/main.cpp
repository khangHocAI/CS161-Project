#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
#include"gotoxy.hpp"
#include"color.hpp"
#include"AI.h"
#include"intro.hpp"
#include"about.hpp"
#include"wincondition.h"
#include"splashscreen.hpp"
#include"definecharvalue.hpp"
#include"drawplayboard.hpp"
#include"escape.hpp"

using namespace std;          


int playturn; //  using in defining a draw game PVP MODE
int playturnpvc;    // using in defining a draw game  PVC MODE
int load =0; // load = 0 mean create new game 

void menu(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int winpvp1, int winpvp2, int winpvc_com, int winpvc_player, string&playername1, string&playername2, string&playername);
void pvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
void controlpvp(char s[100][100],int&x, int&y, int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
void controlpvc(char s[100][100],int&x, int&y, int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
void pvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
void settings(char s[100][100],int&n, int&rule, char&player1symbol, char&player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int savegamepvp(char s[100][100], int n,  int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int loadgamepvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int savegamepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int loadgamepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int load_removegame(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int removepvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int removepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int playerstatistic(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername);
int main()
{
	char s[100][100];   // for creating playboard
	int n = 20; // size of playboard
	char player1symbol = 'O', player2symbol = 'X';
	int rule = 0; //default(0): blocked head ,  1 : non-blocked head
	int winpvp1 = 0, winpvp2 = 0;  // for announce the current score in pvp mode
	int winpvc_player = 0, winpvc_com = 0; // for announce the current score in pvc mode
	string playername1, playername2, playername;   // for entering playername in pvp vs pvc mode
	menu(s,n,rule,player1symbol,player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	return 0;
}
 
//Function:

void menu(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int winpvp1, int winpvp2, int winpvc_com, int winpvc_player, string&playername1, string&playername2, string&playername)
{
	
	definecharvalue(s, n);
	splashscreen();
	gotoxy(45, 14);
	cout << "* * * * * * * * * * * * * *"; Sleep(50);
	gotoxy(44, 15);
	cout << "*   !!!!!WELLCOME!!!!!      *"; Sleep(50);
	gotoxy(44, 16);
	cout << "*   1. PvP MODE.            *"; Sleep(50);
	gotoxy(44, 17);
	cout << "*   2. PvC MODE.            *"; Sleep(50);
	gotoxy(44, 18); 
	cout << "*   3. LOAD GAME.           *"; Sleep(50);
	gotoxy(44, 19);
	cout << "*   4. SETTINGS.            *"; Sleep(50);
	gotoxy(44, 20);
	cout << "*   5. PLAYER STATISTICS    *"; Sleep(50);
	gotoxy(44, 21);
	cout << "*   6. ABOUT US             *"; Sleep(50);
	gotoxy(44, 22);
	cout << "*   7. EXIT                 *"; Sleep(50);
	gotoxy(45, 23);
	cout << "* * * * * * * * * * * * * *"; Sleep(50);
	gotoxy(47, 25);
	cout << " CHOOSE MODE: ";
	Sleep(200);
	char choose;
	while (1) {
		choose = _getch();
		bool isOk = false;          // dung de ngan nguoi dung nhap sai 
		switch (choose)
		{
		   case '1':
		   case '2':
		   case '3':
		   case '4':
		   case '5':
		   case '6':
		   case '7': isOk = true; break;
		}
		if (isOk) break;
	}
	switch (choose)
	{
	   case '1': pvp(s,n, rule, player1symbol, player2symbol,winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername); break;
	   case '2': pvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername); break;
	   case '3': load_removegame(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername); break;
	   case '4': settings(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername); break;
	   case '5': playerstatistic(s,n,rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername); break;
	   case '6': 
	   {
		   about();
		   system("pause");
		   menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	   }
	   break;
	   case '7': escape(); break;
	}
}

void controlpvp(char s[100][100],int&x, int&y, int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
{
	do
	{
		gotoxy(70, 2);
		cout << " 2 PLAYER MODE:  " << playername1 << " vs " << playername2;
		gotoxy(70, 6);
		cout << "  Turn :" << playturn + 1 << " ";
		if ((winpvp1 + winpvp2) % 2 == 0)
		{
			if ((playturn + 1) % 2 == 1) cout << playername1 << "             ";
			else cout << playername2 << "               ";
		}
		else
		{
			if ((playturn + 1) % 2 == 1) cout << playername2 << "               ";
			else cout << playername1 << "               ";
		}
		gotoxy(x, y);
		char play = ' ';
		play = _getch();
		if (play == 'a' || play == 75)
		{
			x = x - 3;
			if (x < 5) x = 5;
			gotoxy(x, y);
		}
		else if (play == 'd' || play == 77)
		{
			x = x + 3;
			if (x > 3 * n + 2) x = 3 * n + 2;
			gotoxy(x, y);
		}
		else if (play == 'w' || play == 72)
		{
			y = y - 1;
			if (y < 2) y = 2;
			gotoxy(x, y);
		}
		else if (play == 's' || play == 80)
		{
			y = y + 1;
			if (y > n + 1) y = n + 1;
			gotoxy(x, y);
		}
		else if (play == 'q' || play == 'p')
		{
			int a = (x - 2) / 3;
			int b = y - 1;
			if (s[a][b] == ' ')
			{
				playturn++;
				if ((winpvp1 + winpvp2) % 2 == 0)
				{
					if (playturn % 2 == 0)
					{
						s[a][b] = player2symbol;
						TextColor(11);
					}
					else
					{
						s[a][b] = player1symbol;
						TextColor(12);
					}

				}
				else
				{
					if (playturn % 2 == 0)
					{
						s[a][b] = player1symbol;
						TextColor(12);
					}
					else
					{
						s[a][b] = player2symbol;
						TextColor(11);
					}
				}
				cout << s[a][b];
				gotoxy(x, y);
			}
		}
		else if (play == 'r')
		{
			TextColor(15);
			load = 0;
			pvp(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		}
		else if (play == 27)
		{
			TextColor(15);
			winpvp1 = 0;
			winpvp2 = 0;
			load = 0;
			menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		}
		else if (play == 't' || play == 'T')
		{
			TextColor(15);
			savegamepvp(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
			winpvp1 = 0;
			winpvp2 = 0;
			load = 0;
		}
	} while ((Xwincondition(s, n, rule, player1symbol, player2symbol) == 0 && Owincondition(s, n, rule, player1symbol, player2symbol) == 0) && playturn != n * n + 1);
	TextColor(15);
	if (Xwincondition(s, n, rule, player1symbol, player2symbol) != 0)
	{
		load = 0;
		Sleep(200);
		gotoxy(70, 18);
		winpvp2++;
		cout << "PLAYER 2: " << playername2 << " - THE WINNER" << endl;
	}
	else if (Owincondition(s, n, rule, player1symbol, player2symbol) != 0)
	{
		load = 0;
		Sleep(200);
		gotoxy(70, 18);
		winpvp1++;
		cout << "PLAYER 1: " << playername1 << " - THE WINNER" << endl;
	}
	else if (playturn = n * n + 1)
	{
		load = 0;
		Sleep(200);
		gotoxy(70, 18);
		cout << "IT'S DRAW GAME. " << endl;
	}
}

void pvp(char s[100][100],int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	int x, y; // coordination xy
	if (n % 2 == 0)
	{
		x = 3* n / 2 +2; 
		y = n/2 + 1;
	}
	else
	{
		x = 3 * n / 2 + 1;
		y = n / 2 + 1;
	}
	 while (winpvp1 + winpvp2 == 0 && load ==0)
	 {
		 intro();
		 Sleep(40);
		 system("cls");
		 gotoxy(44, 5);
		 cout << " ENTER PLAYER 1 NAME: ";
		 cin >> playername1;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 Sleep(50);
		 gotoxy(44, 7);
		 cout << " ENTER PLAYER 2 NAME: ";
		 cin >> playername2;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 break;
	 }
	 if (load == 0)
	 {
		 definecharvalue(s, n);
		 
		 playturn = 0;
	 }
	 drawplayboard(s,n, player1symbol,player2symbol);
	 gotoxy(70, 8);
	 if (rule == 0) cout << "RULE: BLOCKED HEAD.";
	 else cout << "RULE: NON-BLOCKED HEAD.";
	 gotoxy(70, 9);
	 cout << "BOARD SIZE : " << n <<"x" << n;
	 gotoxy(69, 12);
	 cout << "* * * * * * * * * * * * * * * * * *";
	 gotoxy(70, 13);
	 cout << "RESULT:  "<< playername1 <<" " << winpvp1 << " - " << winpvp2 << " "  << playername2;
	 gotoxy(69, 14);
	 cout << "* * * * * * * * * * * * * * * * * *";
	 gotoxy(5, 24);
	 cout << "->PRESS R TO REPLAY. PRESS ESC TO EXIT.";
	 gotoxy(5, 25);
	 cout << "->USE A,W,S,D OR ARROW BUTTON TO MOVE";
	 gotoxy(5, 26);
	 cout << "->USE Q OR P TO TICK.";
	 gotoxy(5, 27);
	 cout << "->IF YOU WANT TO EXIT AND SAVE YOUR GAME, PRESS T";
	 gotoxy(x, y);
	 controlpvp(s,x, y,n, rule, player1symbol, player2symbol,winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 gotoxy(70, 19);
	 cout << "PRESS Y TO REPLAY, ANY OTHER KEYS TO EXIT. ";
	 char replay;
	 cin >> replay;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (replay == 'Y' || replay == 'y')
	 {
		 load = 0;
		 pvp(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 else
	 {
		 load = 0;
		 winpvp1 = 0;
		 winpvp2 = 0;
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
}
 
 void controlpvc(char s[100][100],int&x, int&y, int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 char playpvc = ' ';
	 int kiemtradadichua = 0;
	 while (kiemtradadichua ==0)
	 {
		 playpvc = _getch();
		 if (playpvc == 'a' || playpvc == 75)
		 {
			 x = x - 3;
			 if (x < 5) x = 5;
			 gotoxy(x, y);
		 }
		 else if (playpvc == 'd' || playpvc == 77)
		 {
			 x = x + 3;
			 if (x > 3*n+2) x = 3*n+2;
			 gotoxy(x, y);
		 }
		 else if (playpvc == 'w' || playpvc == 72)
		 {
			 y = y - 1;
			 if (y < 2) y = 2;
			 gotoxy(x, y);
		 }
		 else if (playpvc == 's' || playpvc == 80)
		 {
			 y = y + 1;
			 if (y > n+1) y = n+1;
			 gotoxy(x, y);
		 }
		 else if (playpvc == 'q' || playpvc == 'p')
		 {
			 int a = (x - 2) / 3;
			 int b = y - 1;
			 if (s[a][b] == ' ')
			 {
			     s[a][b] = player2symbol;
				 TextColor(11);
				 cout << s[a][b];
				 gotoxy(x, y);
				 kiemtradadichua++;
				 
			 }
		 }
		 else if (playpvc == 'r')
		 {
			 load = 0;
			 pvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
			 TextColor(15);
		 }
		 else if (playpvc == 't' || playpvc == 'T')
		 {
			 TextColor(15);
			 savegamepvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
			 winpvc_com = 0;
			 winpvc_player = 0;
		 }
		 else if (playpvc == 27)
		 {
			 TextColor(15);
			 winpvc_com = 0;
			 winpvc_player = 0;
			 load = 0;
			 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 }
	 }
 }

 void pvc(char s[100][100], int n,int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 int gameplayed = 0;     // using in player statistic mode 
	 int numofwingame = 0;   // using in player statistic mode
	 ifstream input_numofgame_statis;
	 input_numofgame_statis.open("D:\\18APCS2_Gr12\\Main\\statistic\\numofgame.txt");
	 if (input_numofgame_statis.fail())
	 {
		 perror("statistic\\numofgame.txt");
		 system("pause");
	 }
	 while (input_numofgame_statis.eof() == false)
	 {
		 input_numofgame_statis >> numofwingame;
		 input_numofgame_statis >> gameplayed;
	 }
	 input_numofgame_statis.close();

	 while (winpvc_player + winpvc_com ==0 && load == 0 )
	 {
		 intro();
		 system("cls");
		 gotoxy(44, 5);
		 cout << " ENTER YOUR NAME: ";
		 cin >> playername;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 Sleep(50);
		 break;
	 }
	 if (load ==0) definecharvalue(s,n);
	 drawplayboard(s,n, player1symbol, player2symbol);
	 gotoxy(70, 2);
	 cout << "PLAYER VS COMPUTER MODE:  COM vs " << playername;
	 gotoxy(70, 8);
	 if (rule == 0) cout << "RULE: BLOCKED HEAD.";
	 else cout << "RULE: NON-BLOCKED HEAD.";
	 gotoxy(70, 9);
	 cout << "BOARD SIZE : " << n << "x" << n;
	 gotoxy(70, 10);
	 cout << "SYMBOL: " << player1symbol << " vs " << player2symbol;
	 gotoxy(69, 12);
	 cout << "* * * * * * * * * * * * * * * * * *";
	 gotoxy(70, 13);
	 cout << "RESULT:   COM "<< winpvc_com << " - " << winpvc_player << " " << playername;
	 gotoxy(69, 14);
	 cout << "* * * * * * * * * * * * * * * * * *";
	 gotoxy(5, 24);
	 cout << "->PRESS R TO REPLAY. PRESS ESC TO EXIT.";
	 gotoxy(5, 25);
	 cout << "->USE A,W,S,D OR ARROW BUTTON TO MOVE";
	 gotoxy(5, 26);
	 cout << "->USE Q OR P TO TICK.";
	 gotoxy(5, 27);
	 cout << "->IF YOU WANT TO EXIT AND SAVE YOUR GAME, PRESS T";
	 int a, b;
	 int x, y; // coordination xy
	 if (n % 2 == 0)
	 {
		 x = 3 * n / 2 + 2;
		 y = n / 2 + 1;
	 }
	 else
	 {
		 x = 3 * n / 2 + 1;
		 y = n / 2 + 1;
	 }
	 playturnpvc = 0;
	 if (gameplayed % 2 == 0)
	 {
		 TextColor(12);
		 s[n / 2][n / 2] = player1symbol;
		 gotoxy(x, y);
		 cout << s[n / 2][n / 2];
		 TextColor(15);
	 }
	 gotoxy(x, y);
	 do
	 {
		 controlpvc(s,x,y,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 if (Xwincondition(s, n, rule, player1symbol, player2symbol) != 0) break;
		 Findmove(s, x, y, a, b, player1symbol, player2symbol, rule,n, playturnpvc);
		 gotoxy(x, y);
		 playturnpvc+=2;
		 TextColor(12);
		 cout << s[a][b];
		 gotoxy(x, y);
		 TextColor(15);
		 if (Owincondition(s, n, rule, player1symbol, player2symbol) != 0) break;
		 
	 }
	 while (Xwincondition(s, n, rule, player1symbol, player2symbol) == 0 && Owincondition(s, n, rule, player1symbol, player2symbol) == 0 && playturnpvc != n*n);  // ma acsii cua phim ESC
	 if (Xwincondition(s, n, rule, player1symbol, player2symbol) != 0)
	 {
		 Sleep(200);
		 gotoxy(70, 18);
		 load = 0;
		 numofwingame++;    // statistic mode
		 winpvc_player++;
		 cout << "      YOU WON!!!! EXCELLENT!" << endl;
	 }
	 else if (Owincondition(s, n, rule, player1symbol, player2symbol) != 0)
	 {
		 Sleep(200);
		 gotoxy(70, 18); // statistic mode
		 winpvc_com++;
		 load = 0;
		 cout << "COMPUTER - THE WINNER!! TOO BAD!" << endl;
	 }
	 else if (playturnpvc == n*n)
	 {
		 Sleep(200);
		 gotoxy(70, 18);
		 load = 0;
		 cout << "IT'S DRAW GAME. " << endl;
	 }
	 gameplayed++;
	 ofstream output_savenumofgame;
	 output_savenumofgame.open("D:\\18APCS2_Gr12\\Main\\statistic\\numofgame.txt");
	 output_savenumofgame << numofwingame << "\n";
	 output_savenumofgame << gameplayed;
	 output_savenumofgame.close();
	 ofstream saveforstatis;
	 int sttgame = (gameplayed-1) % 15 +1;
	 std::string st = std::to_string(sttgame);
	 saveforstatis.open("D:\\18APCS2_Gr12\\Main\\statistic\\game" + st + ".txt");
	 saveforstatis << playername;
	 saveforstatis << '\n';
	 saveforstatis << player1symbol;
	 saveforstatis << '\n';
	 saveforstatis << player2symbol;
	 saveforstatis << '\n';
	 saveforstatis << rule;
	 saveforstatis << '\n';
	 saveforstatis << n;  // size
	 saveforstatis << '\n';
	 saveforstatis << playturnpvc;
	 saveforstatis << '\n';
	 for (int i = 0; i < n + 2; i++)
	 {
		 for (int j = 0; j < n + 2; j++)
		 {
			 if (s[i][j] == ' ') saveforstatis << '1'; else
				 saveforstatis << s[i][j] << '\n';
		 }
	 }
	 saveforstatis.close();
	 gotoxy(70, 16);
	 cout << "   SAVED!!! NAME: game" << sttgame ;
	 gotoxy(70, 19);
	 cout << " PRESS Y TO REPLAY, ANY OTHER KEYS TO EXIT. ";
	 char replay;
	 cin >> replay;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (replay == 'Y' || replay == 'y')
	 {
		 TextColor(15);
		 load = 0;
		 pvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 else
	 {
		 TextColor(15);
		 load = 0;
		 winpvc_player = 0;
		 winpvc_com = 0;
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
 }

 void settings(char s[100][100],int&n, int&rule, char&player1symbol, char&player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 system("cls");
	 gotoxy(15, 2);
	 cout << "* * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(15, 3);
	 cout << "*                SETTINGS               *";
	 gotoxy(15, 4);
	 cout << "*    1. Change player symbol.           *";
	 gotoxy(15, 5);
	 cout << "*    2. Change play rule.               *";
	 gotoxy(15, 6);
	 cout << "*    3. Change board size               *";
	 gotoxy(15, 7);
	 cout << "* * * * * * * * * * * * * * * * * * * * *";
	 char set;
	 gotoxy(5, 9);
	 cout << "What do you want to change? (Press 1,2,3 to choose and others key to exit) : ";
	 cin >> set;
	 cin.clear();
	 cin.ignore(1000,'\n');
	 if (set != '1' && set != '2' && set != '3') menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 else if (set == '1')
	 {
		 gotoxy(20, 10);
		 cout << "* * * * * * * * * * * * * * * *";
		 gotoxy(20, 11);
		 cout << "*   DEFAULT SYMBOL: O & X     *";
		 gotoxy(20, 12);
		 cout << "* * * * * * * * * * * * * * * *";
		 gotoxy(20, 13);
		 cout << "Player 1 symbol change to :"; 
		 cin >> player1symbol;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 gotoxy(20, 14);
		 cout << "Player 2 symbol change to :";
		 cin >> player2symbol;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 while (player1symbol == player2symbol || player1symbol == 'p' || player2symbol == 'p')
		 {
			 gotoxy(20, 15);
			 cout << "ERROR. PLEASE REENTER THEM.";
			 gotoxy(20, 16);
			 cout << "Player 1 symbol change to :";
			 cin >> player1symbol;
			 cin.clear();
			 cin.ignore(1000, '\n');
			 gotoxy(20, 17);
			 cout << "Player 2 symbol change to :";
			 cin >> player2symbol;
			 cin.clear();
			 cin.ignore(1000, '\n');
		 }
		 gotoxy(20, 18);
		 cout << "YOU CHANGED PLAYER SYMBOL TO: " << player1symbol << " & " << player2symbol;
		 system("pause");
	 }
	 else if (set == '2')
	 {
		 gotoxy(20, 10);
		 cout << "* * * * * * * * * * * * * * * * *";
		 gotoxy(20, 11);
		 cout << "*   DEFAULT RULE: BLOCKED HEAD  *";
		 gotoxy(20, 12);
		 cout << "*  0. Blocked head              *";
		 gotoxy(20, 13);
		 cout << "*  1. Non-blocked head          *";
		 gotoxy(20, 14);
		 cout << "* * * * * * * * * * * * * * * * *";
		 gotoxy(15, 15);
		 cout << "WHAT RULE YOU WANT TO CHOOSE: (PRESS 0,1 TO CHOOSE , OTHER KEYS TO EXIT.) ";
		 cin >> rule;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 if (rule != 0 && rule != 1)
		 {
			 gotoxy(25, 16);
			 cout << "ERROR!!!!";
			 rule = 0;
			 system("pause");
			 menu(s, n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 }
		 system("pause");
		 menu(s, n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 else if (set == '3')
	 {
		 gotoxy(20, 10);
		 cout << "* * * * * * * * * * * * * * * *";
		 gotoxy(20, 11);
		 cout << "*   DEFAULT SIZE: 20x20       *";
		 gotoxy(20, 12);
		 cout << "*  1. Small  (10x10)          *";
		 gotoxy(20, 13);
		 cout << "*  2. Medium (15x15)          *";
		 gotoxy(20, 14);
		 cout << "*  3. Big    (20x20)          *";
		 gotoxy(20, 15);
		 cout << "* * * * * * * * * * * * * * * *";
		 gotoxy(15, 16);
		 cout << "WHAT SIZE YOU WANT TO PLAY : ";
		 int size;
		 cin >> size;
		 cin.clear();
		 cin.ignore(1000, '\n');
		 if (size == 1) n = 10;
		 else if (size == 2) n = 15;
		 else if (size == 3) n = 20;
		 else
		 {
			 cout << "ERROR";
			 n = 20;
			 system("pause");
		 }
	 }
	 menu(s, n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
 }

 int savegamepvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player,string&playername1, string&playername2, string&playername)
 { 
	 string tengamemoi;
	 string savedgame;
	 system("cls");
	 gotoxy(30, 10);
	 cout << "* * * * * * * * * * * * * * * *";
	 gotoxy(30, 11);
	 cout << "  SAVED GAME MODE OF PVP :     ";
	 gotoxy(30, 12);
	 cout << "Please enter file name:        ";
	 getline(cin, tengamemoi);
	 cin.clear();
	 cin.ignore(1000,'\n');
	 ifstream inputfile_gamename;
	 inputfile_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 if (inputfile_gamename.fail())
	 {
		 perror("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
		 system("pause");
		 return 1;
	 }
	 while (inputfile_gamename.eof() == false)
	 {
		 getline(inputfile_gamename,savedgame);
	 }
	 inputfile_gamename.close();

	 while (savedgame.find(tengamemoi)!= string::npos )
	{
		 system("cls");
		 gotoxy(30, 4);
		 cout << "THIS FILE HAS ALREADY EXIST PLEASE ENTER ANOTHER NAME:";
		 getline(cin, tengamemoi);
		 cin.clear();
		 cin.ignore(1000,'\n');
		 gotoxy(35, 5);
		 cout << "PRESS ENTER TO CONTINUE.";
	}
	 string barrier = { '_' };
	 if (savedgame == "") savedgame += tengamemoi;
	 else savedgame += barrier + tengamemoi;
	 ofstream outputfile_gamename;
	 outputfile_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 outputfile_gamename << savedgame;
	 outputfile_gamename.close();
//
	 ofstream outputfile_gametosave;
	 outputfile_gametosave.open("D:\\18APCS2_Gr12\\Main\\save\\pvp\\" + tengamemoi + "pvp.txt");
	 outputfile_gametosave << playername1;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << playername2;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << player1symbol;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << player2symbol;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << rule;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << n;  // size
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << playturn;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << winpvp1;
	 outputfile_gametosave << '\n';
	 outputfile_gametosave << winpvp2;
	 outputfile_gametosave << '\n';
	 for (int i = 0; i < n+2; i++)
	 {
		 for (int j = 0; j < n + 2; j++) 
		 {
			 if (s[i][j] == ' ') outputfile_gametosave << 'p'; else
			 outputfile_gametosave << s[i][j] << '\n';
		 }
	 }
	 outputfile_gametosave.close();
	 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }

 int loadgamepvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 system("cls");
	 gotoxy(30, 5);
	 cout << "* * * * * * * * * * * * * * * * *";
	 gotoxy(30, 6);
	 cout << "*        SAVED GAME PVP MODE        ";
	 gotoxy(0, 7);
	 ifstream inputfile_gamename;
	 inputfile_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 if (inputfile_gamename.fail())
	 {
		 perror("D:\\18APCS2_Gr12\\save\\savedgamepvp.txt");
		 system("pause");
		 return 1;
	 }
	 int i = 1;
	 string gamename;
	 while (inputfile_gamename.eof() == false)
	 {
		 getline(inputfile_gamename,gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 cout << "                              * " << i << " . " << gamename << endl;
			 i++;
		 }
	 }
	 cout << "                              * * * * * * * * * * * * * * * * *\n";
	 inputfile_gamename.close();
	 gotoxy(20, 2);
	 cout << "=> PLEASE CHOOSE A FILE FROM SAVED LIST: ";
	 int chonfile;
	 cin >> chonfile;
	 cin.clear();
	 cin.ignore(1000,'\n');
	 if (chonfile >= i || chonfile <= 0)
	 {
		 gotoxy(15, 3);
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
//
	 ifstream inputfile_findgamename;
	 inputfile_findgamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 if (inputfile_findgamename.fail())
	 {
		 perror("D:\\18APCS2_Gr12\\save\\savedgamepvp.txt");
		 system("pause");
		 return 1;
	 }
	 int dem = 0; 
	 string gametoload;
	 while (inputfile_findgamename.eof() == false)
	 {
		 getline(inputfile_findgamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 dem++;
			 if (dem == chonfile) gametoload = gamename;
		 }
	 }
	 inputfile_findgamename.close();
	 cout <<"YOU CHOOSE: " << gametoload << endl;
	 system("pause");
//
	 ifstream gamedata;
	 gamedata.open("D:\\18APCS2_Gr12\\Main\\save\\pvp\\" + gametoload + "pvp.txt");
	 if (gamedata.fail())
	 {
		 perror("game to load");
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 return 1;
	 }
	 while (gamedata.eof() == false)
	 {
		 gamedata >> playername1;
		 gamedata >> playername2;
		 gamedata >> player1symbol;
		 gamedata >> player2symbol;
		 gamedata >> rule;
		 gamedata >> n;
		 gamedata >> playturn;
		 gamedata >> winpvp1;
		 gamedata >> winpvp2;
		 for (int i = 0; i < n + 2; i++)
		 {
			 for (int j = 0; j < n + 2; j++)
			 {
				 
				 gamedata >> s[i][j];
				 if (s[i][j] == 'p') s[i][j] = ' ';
			 }
		 }
	 }
	 
	 gamedata.close();
	 load = 1;
	 pvp(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
	 
 }

 int savegamepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 string tengamemoi;
	 string savedgame;
	 system("cls");
	 gotoxy(30, 10);
	 cout << "* * * * * * * * * * * * * * * *";
	 gotoxy(30, 11);
	 cout << "  SAVED GAME MODE OF PVC:       ";
	 gotoxy(30, 12);
	 cout << "Please enter file name:        ";
	 getline(cin, tengamemoi);
	 cin.clear();
	 cin.ignore(1000,'\n');
	 gotoxy(20, 13);
	 cout << "PRESS ENTER TO CONTINUE.";
	 //	 
	 ifstream input_gamename;
	 input_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 if (input_gamename.fail())
	 {
		 perror("D:\\18APCS2_Gr12\\save\\savedgamepvc.txt");
		 system("pause");
		 return 1;
	 }
	 while (input_gamename.eof() == false)
	 {
		 getline(input_gamename, savedgame);
	 }
	 input_gamename.close();
	 while (savedgame.find(tengamemoi) != string::npos)
	 {
		 system("cls");
		 gotoxy(30, 4);
		 cout << "THIS FILE HAS ALREADY EXIST PLEASE ENTER ANOTHER NAME:";
		 getline(cin, tengamemoi);
		 cin.clear();
		 cin.ignore(1000,'\n');
		 gotoxy(35, 5);
		 cout << "PRESS ENTER TO CONTINUE.";
	 }
	 string barrier = { '_' };
	 if (savedgame == "") savedgame += tengamemoi;
	 else savedgame += barrier + tengamemoi;
	 ofstream output_gamename;
	 output_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 output_gamename << savedgame;
	 output_gamename.close();
	 //
	 ofstream output_gametosave;
	 output_gametosave.open("D:\\18APCS2_Gr12\\Main\\save\\pvc\\" +tengamemoi + "pvc.txt");
	 output_gametosave << playername;
	 output_gametosave << '\n';
	 output_gametosave << player1symbol;
	 output_gametosave << '\n';
	 output_gametosave << player2symbol;
	 output_gametosave << '\n';
	 output_gametosave << rule;
	 output_gametosave << '\n';
	 output_gametosave << n;  // size
	 output_gametosave << '\n';
	 output_gametosave << playturnpvc;
	 output_gametosave << '\n';
	 output_gametosave << winpvc_player;
	 output_gametosave << '\n';
	 output_gametosave << winpvc_com;
	 output_gametosave << '\n';
	 for (int i = 0; i < n + 2; i++)
	 {
		 for (int j = 0; j < n + 2; j++)
		 {
			 if (s[i][j] == ' ') output_gametosave << 'p'; else
				 output_gametosave << s[i][j] << '\n';
		 }
	 }
	 output_gametosave.close();
	 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }

 int loadgamepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 string gamename;
	 system("cls");
	 gotoxy(30, 5);
	 cout << "* * * * * * * * * * * * * * * * *";
	 gotoxy(30, 6);
	 cout << "*        SAVED GAME PVC MODE        ";
	 gotoxy(0, 7);
	 ifstream input_gamename;
	 input_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 if (input_gamename.fail())
	 {
		 perror("D:\\18APCS2_Gr12\\save\\savedgamepvc.txt");
		 system("pause");
		 return 1;
	 }
	 int i = 1;
	 while (input_gamename.eof() == false)

	 {
		 getline(input_gamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 cout << "                              * " << i << " . " << gamename << endl;
			 i++;
		 }
	 }
	 cout << "                              * * * * * * * * * * * * * * * * *\n";
	 input_gamename.close();
	 gotoxy(20, 2);
	 cout << "=> PLEASE CHOOSE A FILE FROM SAVED LIST: ";
	 int chonfile;
	 cin >> chonfile;
	 cin.clear();
	 cin.ignore(1000,'\n');
	 if (chonfile >= i || chonfile <= 0)
	 {
		 gotoxy(15, 3);
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 //
	 ifstream input_findgamename;
	 input_findgamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 if (input_findgamename.fail())
	 {
		 perror("savedgamepvc.txt");
		 system("pause");
		 return 1;
	 }
	 int dem = 0;
	 string gametoload;
	 while (input_findgamename.eof() == false)
	 {
		 getline(input_findgamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 dem++;
			 if (dem == chonfile) gametoload = gamename;
		 }
	 }
	 input_findgamename.close();
	 cout << "YOU CHOOSE: " << gametoload << endl;
	 system("pause");
	 //
	 ifstream gamedata;
	 gamedata.open("D:\\18APCS2_Gr12\\Main\\save\\pvc\\"+gametoload + "pvc.txt");
	 if (gamedata.fail())
	 {
		 perror("game to load");
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 return 1;
	 }
	 while (gamedata.eof() == false)
	 {
		 gamedata >> playername;
		 gamedata >> player1symbol;
		 gamedata >> player2symbol;
		 gamedata >> rule;
		 gamedata >> n;
		 gamedata >> playturnpvc;
		 gamedata >> winpvc_player;
		 gamedata >> winpvc_com;
		 for (int i = 0; i < n + 2; i++)
		 {
			 for (int j = 0; j < n + 2; j++)
			 {

				 gamedata >> s[i][j];
				 if (s[i][j] == 'p') s[i][j] = ' ';
			 }
		 }
	 }

	 gamedata.close();
	 load = 1;
	 pvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;

 }

 int removepvp(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 string gamename;
	 system("cls");
	 gotoxy(30, 6);
	 cout << "* * * * * * * * * * * * * * * * *";
	 gotoxy(30, 7);
	 cout << "        REMOVE GAME PVP MODE     ";
	 gotoxy(0, 8);
	 ifstream inputfile_gamename;
	 inputfile_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 if (inputfile_gamename.fail())
	 {
		 perror("savedgamepvp.txt");
		 system("pause");
		 return 1;
	 }
	 int i = 1;
	 while (inputfile_gamename.eof() == false)
	 {
		 getline(inputfile_gamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 cout << "                              * " << i << " . " << gamename << endl;
			 i++;
		 }
	 }
	 cout << "                              * * * * * * * * * * * * * * * * *\n";
	 inputfile_gamename.close();
	 gotoxy(20, 2);
	 cout << "=> PLEASE CHOOSE A FILE FROM SAVED LIST TO REMOVE: ";
	 int chonfile;
	 cin >> chonfile;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (chonfile >= i || chonfile <= 0)
	 {
		 gotoxy(15, 3);
		 system("pause");
		 load_removegame(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 ifstream inputfile_findgamename;
	 inputfile_findgamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 if (inputfile_findgamename.fail())
	 {
		 perror("save\\savedgamepvp.txt");
		 system("pause");
		 return 1;
	 }
	 int dem = 0;
	 string gametoremove;
	 string listafter_remove;
	 string barrier = { '_' };
	 while (inputfile_findgamename.eof() == false)
	 {
		 getline(inputfile_findgamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 dem++;
			 if (dem == chonfile)
			 {
				 gametoremove = gamename;
			 }
			 else listafter_remove += gamename + barrier;
		 }
	 }
	 inputfile_findgamename.close();
	 gotoxy(15, 4);
	 cout << "YOU CHOOSE: " << gametoremove << endl;
	 ofstream output_gamename;
	 output_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvp.txt");
	 output_gamename << listafter_remove;
	 output_gamename.close();
	 system("pause");
	 load_removegame(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }

 int removepvc(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 string gamename;
	 system("cls");
	 gotoxy(30, 6);
	 cout << "* * * * * * * * * * * * * * * * *";
	 gotoxy(30, 7);
	 cout << "        REMOVE GAME PVC MODE     ";
	 gotoxy(0, 8);
	 ifstream inputfile_gamename;
	 inputfile_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 if (inputfile_gamename.fail())
	 {
		 perror("savedgamepvc.txt");
		 system("pause");
		 return 1;
	 }
	 int i = 1;
	 while (inputfile_gamename.eof() == false)
	 {
		 getline(inputfile_gamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 cout << "                              * " << i << " . " << gamename << endl;
			 i++;
		 }
	 }
	 cout << "                              * * * * * * * * * * * * * * * * *\n";
	 inputfile_gamename.close();
	 gotoxy(20, 2);
	 cout << "=> PLEASE CHOOSE A FILE FROM SAVED LIST TO REMOVE: ";
	 int chonfile;
	 cin >> chonfile;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (chonfile >= i || chonfile <= 0)
	 {
		 gotoxy(15, 3);
		 system("pause");
		 load_removegame(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 ifstream inputfile_findgamename;
	 inputfile_findgamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 if (inputfile_findgamename.fail())
	 {
		 perror("save\\savedgamepvc.txt");
		 system("pause");
		 return 1;
	 }
	 int dem = 0;
	 string gametoremove;
	 string listafter_remove;
	 string barrier = { '_' };
	 while (inputfile_findgamename.eof() == false)
	 {
		 getline(inputfile_findgamename, gamename, '_');
		 if (gamename == "") continue;
		 else
		 {
			 dem++;
			 if (dem == chonfile)
			 {
				 gametoremove = gamename;
			 }
			 else listafter_remove += gamename + barrier;
		 }
	 }
	 inputfile_findgamename.close();
	 gotoxy(15, 4);
	 cout << "YOU CHOOSE: " << gametoremove << endl;
	 ofstream output_gamename;
	 output_gamename.open("D:\\18APCS2_Gr12\\Main\\save\\savedgamepvc.txt");
	 output_gamename << listafter_remove;
	 output_gamename.close();
	 system("pause");
	 load_removegame(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }

 int load_removegame(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 system("cls");
	 gotoxy(10, 3);
	 cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(10, 4);
	 cout << " *                LOAD/ REMOVE MODE:           *";
	 gotoxy(10, 5);
	 cout << " *    1. LOAD SAVED PVP GAME.                  *";
	 gotoxy(10, 6);
	 cout << " *    2. LOAD SAVED PVC GAME.                  *";
	 gotoxy(10, 7);
	 cout << " *    3. REMOVE SAVED PVP GAME.                *";
	 gotoxy(10, 8);
	 cout << " *    4. REMOVE SAVED PVC GAME.                *";
	 gotoxy(10, 9);
	 cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(15, 11);
	 cout << "PLEASE CHOOSE WHAT YOU WANT TO DO: (Press any others keys to exit) ";
	 int chooseload;
	 cin >> chooseload;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (chooseload == 1) loadgamepvp(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 else if  (chooseload ==2) loadgamepvc(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 else if (chooseload == 3) removepvp(s, n, rule, player1symbol, player2symbol,winpvp1,winpvp2, winpvc_com,winpvc_player, playername1, playername2, playername);
	 else if (chooseload == 4) removepvc(s, n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 else menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }

 int playerstatistic(char s[100][100], int n, int rule, char player1symbol, char player2symbol, int&winpvp1, int&winpvp2, int&winpvc_com, int&winpvc_player, string&playername1, string&playername2, string&playername)
 {
	 int gameplayed;     // using in player statistic mode 
	 int numofwingame;   // using in player statistic mode
	 ifstream input_numofgame;
	 input_numofgame.open("D:\\18APCS2_Gr12\\Main\\statistic\\numofgame.txt");
	 if (input_numofgame.fail())
	 {
		 perror("numofgame.txt");
		 system("pause");
		 return 1;
	 }
	 while (input_numofgame.eof() == false)
	 {
		 input_numofgame >> numofwingame;
		 input_numofgame >> gameplayed;
	 }
	 input_numofgame.close();
	 system("cls");
	 gotoxy(20, 3);
	 cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(20, 4);
	 cout << "*          PLAYER STATISTIC IN PVC MODE:             *";
	 gotoxy(20, 5);
	 cout << "YOU HAVE PLAYED " << gameplayed << " AND WON " << numofwingame;
	 gotoxy(20, 6);
	 cout << "YOUR WIN RATE:" << fixed << setprecision(2) << 100.00*numofwingame / gameplayed << "%.";
	 gotoxy(20, 7);
	 cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(20, 10);
	 cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	 gotoxy(30, 11);
	 cout << "PLAYED GAME LIST:";
	 cout << "\n";
	 for (int i = 1; gameplayed > 0 && ((gameplayed < 16 && i <= (gameplayed - 1) % 15 + 1) || (gameplayed > 16 && i < 16)); i++)
	 {
		 if (i<10) cout << "                           *" << i << " . game" << i << endl;
		 else cout << "                           *" << i << ". game" << i << endl;
	 }
	 cout << "                       * * * * * * * * * * * * * * * * * * * * * * *\n";
	 gotoxy(20, 9);
	 cout << "=> PLEASE CHOOSE A FILE FROM SAVED LIST, PRESS ANY OTHERS KEY TO EXIT: ";
	 int chonfile;
	 cin >> chonfile;
	 cin.clear();
	 cin.ignore(1000, '\n');
	 if (chonfile > gameplayed || chonfile > 15 || chonfile <= 0)
	 {
		 gotoxy(0, 0);
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 }
	 //
	 gotoxy(75, 11);
	 cout << "YOU CHOOSE: game" << chonfile << endl;
	 gotoxy(75, 12);
	 system("pause");
	 std::string st1 = std::to_string(chonfile);
	 //
	 ifstream gamedata;
	 gamedata.open("D:\\18APCS2_Gr12\\Main\\statistic\\game" + st1 + ".txt");
	 if (gamedata.fail())
	 {
		 perror("game to load");
		 system("pause");
		 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
		 return 1;
	 }
	 while (gamedata.eof() == false)
	 {
		 gamedata >> playername;
		 gamedata >> player1symbol;
		 gamedata >> player2symbol;
		 gamedata >> rule;
		 gamedata >> n;
		 gamedata >> playturnpvc;
		 for (int i = 0; i < n + 2; i++)
		 {
			 for (int j = 0; j < n + 2; j++)
			 {
				 gamedata >> s[i][j];
				 if (s[i][j] == '1') s[i][j] = ' ';
			 }
		 }
	 }
	 gamedata.close();
	 system("cls");
	 drawplayboard(s, n, player1symbol, player2symbol);
	 gotoxy(70, 2);
	 cout << "PLAYER VS COMPUTER MODE:  COM vs " << playername;
	 gotoxy(70, 8);
	 if (rule == 0) cout << "RULE: BLOCKED HEAD.";
	 else cout << "RULE: NON-BLOCKED HEAD.";
	 gotoxy(70, 9);
	 cout << "BOARD SIZE : " << n << "x" << n;
	 gotoxy(70, 10);
	 cout << "SYMBOL: " << player1symbol << " vs " << player2symbol;
	 gotoxy(0, 24);
	 system("pause");
	 menu(s,n, rule, player1symbol, player2symbol, winpvp1, winpvp2, winpvc_com, winpvc_player, playername1, playername2, playername);
	 return 0;
 }
     
     

    
   
    
    
  
