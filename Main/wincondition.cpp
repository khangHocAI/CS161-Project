#include"wincondition.h"

int Xwincondition(char s[100][100], int n, int rule, char player1symbol, char player2symbol)
{
	if (rule == 0)
	{
		for (int j = 1; j < n + 1; j++)
			for (int i = 1; i < n + 1; i++)
			{
				if (s[i][j] == player2symbol)
				{
					if (s[i + 1][j] == player2symbol && s[i + 2][j] == player2symbol && s[i + 3][j] == player2symbol && s[i + 4][j] == player2symbol) // dieu kien theo chieu ngang
					{
						if ((s[i - 1][j] == player1symbol || s[i - 1][j] == '*') && (s[i + 5][j] == player1symbol || s[i + 5][j] == '*')) return 0;
						else return 1;
					}
					else if (s[i][j + 1] == player2symbol && s[i][j + 2] == player2symbol && s[i][j + 3] == player2symbol && s[i][j + 4] == player2symbol) // dieu kien theo chieu doc
					{
						if ((s[i][j - 1] == player1symbol || s[i][j - 1] == '*') && (s[i][j + 5] == player1symbol || s[i][j + 5] == '*')) return 0;
						else return 1;
					}
					else if (s[i + 1][j + 1] == player2symbol && s[i + 2][j + 2] == player2symbol && s[i + 3][j + 3] == player2symbol && s[i + 4][j + 4] == player2symbol) // dieu kien theo chieu cheo (\)
					{
						if ((s[i - 1][j - 1] == player1symbol || s[i - 1][j - 1] == '*') && (s[i + 5][j + 5] == player1symbol || s[i +5][j + 5] == '*')) return 0;
						else return 1;
					}
					else if (i>5 && s[i - 1][j + 1] == player2symbol && s[i - 2][j + 2] == player2symbol && s[i - 3][j + 3] == player2symbol && s[i - 4][j + 4] == player2symbol) // dieu kien theo chieu cheo (/)
					{
						if ((s[i + 1][j - 1] == player1symbol || s[i + 1][j - 1] == '*') && (s[i - 5][j + 5] == player1symbol || s[i - 5][j + 5] == '*')) return 0;
						else return 1;
					}
				}
			}
		return 0;
	}
	else
	{
		for (int j = 1; j < n + 1; j++)
			for (int i = 1; i < n + 1; i++)
			{
				if (s[i][j] == player2symbol)
				{
					if (s[i + 1][j] == player2symbol && s[i + 2][j] == player2symbol && s[i + 3][j] == player2symbol && s[i + 4][j] == player2symbol) // dieu kien theo chieu ngang 
						return 1;
					else if (s[i][j + 1] == player2symbol && s[i][j + 2] == player2symbol && s[i][j + 3] == player2symbol && s[i][j + 4] == player2symbol) // dieu kien theo chieu doc
						return 1;
					else if (s[i + 1][j + 1] == player2symbol && s[i + 2][j + 2] == player2symbol && s[i + 3][j + 3] == player2symbol && s[i + 4][j + 4] == player2symbol) // dieu kien theo chieu cheo (\)
						return 1;
					else if (i > 5 && s[i - 1][j + 1] == player2symbol && s[i - 2][j + 2] == player2symbol && s[i - 3][j + 3] == player2symbol && s[i - 4][j + 4] == player2symbol) // dieu kien theo chieu cheo (/)
						return 1;
				}
			}
		return 0;
	}
}
int Owincondition(char s[100][100], int n, int rule, char player1symbol, char player2symbol)
{
	if (rule == 0)
	{
		for (int j = 1; j < n + 1; j++)
			for (int i = 1; i < n + 1; i++)
			{
				if (s[i][j] == player1symbol)
				{
					if (s[i + 1][j] == player1symbol && s[i + 2][j] == player1symbol && s[i + 3][j] == player1symbol && s[i + 4][j] == player1symbol) // dieu kien theo chieu ngang
					{
						if ((s[i - 1][j] == player2symbol || s[i - 1][j] == '*') && (s[i + 5][j] == player2symbol || s[i + 5][j] == '*')) return 0;
						else return 1;
					}
					else if (s[i][j + 1] == player1symbol && s[i][j + 2] == player1symbol && s[i][j + 3] == player1symbol && s[i][j + 4] == player1symbol) // dieu kien theo chieu doc
					{
						if ((s[i][j - 1] == player2symbol || s[i][j - 1] == '*') && (s[i][j + 5] == player2symbol || s[i][j + 5] == '*')) return 0;
						else return 1;
					}
					else if (s[i + 1][j + 1] == player1symbol && s[i + 2][j + 2] == player1symbol && s[i + 3][j + 3] == player1symbol && s[i + 4][j + 4] == player1symbol) // dieu kien theo chieu cheo (\)
					{
						if ((s[i - 1][j - 1] == player2symbol || s[i - 1][j - 1] == '*') && (s[i + 5][j + 5] == player2symbol || s[i+5][j + 5] == '*')) return 0;
						else return 1;
					}
					else if (i > 5 && s[i - 1][j + 1] == player1symbol && s[i - 2][j + 2] == player1symbol && s[i - 3][j + 3] == player1symbol && s[i - 4][j + 4] == player1symbol) // dieu kien theo chieu cheo (/)
					{
						if ((s[i + 1][j - 1] == player2symbol || s[i + 1][j - 1] == '*') && (s[i - 5][j + 5] == player2symbol || s[i - 5][j + 5] == '*')) return 0;
						else return 1;
					}
				}
			}
		return 0;
	}
	else
	{
		for (int j = 1; j < n + 1; j++)
			for (int i = 1; i < n + 1; i++)
			{
				if (s[i][j] == player1symbol)
				{
					if (s[i + 1][j] == player1symbol && s[i + 2][j] == player1symbol && s[i + 3][j] == player1symbol && s[i + 4][j] == player1symbol) // dieu kien theo chieu ngang
						return 1;
					else if (s[i][j + 1] == player1symbol && s[i][j + 2] == player1symbol && s[i][j + 3] == player1symbol && s[i][j + 4] == player1symbol) // dieu kien theo chieu doc
						return 1;
					else if (s[i + 1][j + 1] == player1symbol && s[i + 2][j + 2] == player1symbol && s[i + 3][j + 3] == player1symbol && s[i + 4][j + 4] == player1symbol) // dieu kien theo chieu cheo (\)
						return 1;
					else if (i > 5 && s[i - 1][j + 1] == player1symbol && s[i - 2][j + 2] == player1symbol && s[i - 3][j + 3] == player1symbol && s[i - 4][j + 4] == player1symbol) // dieu kien theo chieu cheo (/)
						return 1;
				}
			}
		return 0;
	}
}