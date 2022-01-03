#include<iostream>
using namespace std;
inline void drawplayboard(char s[100][100], int n, char player1symbol, char player2symbol)
{
	system("cls");
	TextColor(15);
	for (int i = 0; i <= n+1; i++)
	{
		if (i < 11) cout << "  " << i;
		else cout << " " << i;
		Sleep(50);
	}
	cout << "\n";
	cout << "0 ";
	for (int i = 0; i < n+2; i++)
	{
		if (s[i][0] == player1symbol) TextColor(12);
		else if (s[i][0] == player2symbol) TextColor(11);
		cout << s[i][0] << "  ";
		Sleep(40);
		TextColor(15);
	}
	cout << "\n";
	for (int j = 1; j < n+1; j++)
	{
		cout << j;
		if (j < 10)
		{
			cout << " "; Sleep(5);
			for (int i = 0; i < n + 2; i++) 
			{
				if (s[i][j] == player1symbol) TextColor(12);
				else if (s[i][j] == player2symbol)TextColor(11);
				cout << s[i][j] << "  ";
				TextColor(15);
			}
		}
		else if (j > 9) for (int i = 0; i < n+2; i++)
		{
			if (s[i][j] == player1symbol) TextColor(12);
			else if (s[i][j] == player2symbol) TextColor(11);
			cout << s[i][j] << "  ";
			Sleep(5);
			TextColor(15);
		}
		cout << "\n";
	}
	cout << n+1;
	for (int i = 0; i < n+2; i++)
	{
		if (s[i][n+1] == player1symbol) TextColor(12);
		else if (s[i][n+1] == player2symbol) TextColor(11);
		cout << s[i][n+1] << "  ";
		Sleep(40); 
		TextColor(15);
	}
	cout << "\n";
}
