#include<iostream>
using namespace std;
inline void definecharvalue(char s[100][100], int n)
{
	for (int i = 0; i < n+2; i++) s[i][0] = '*';
	for (int j = 1; j < n+1; j++)
		for (int i = 0; i < n+2; i++)
		{
			if (i == 0 || i == n+1) s[i][j] = '*';
			else s[i][j] = ' ';
		}
	for (int i = 0; i < n+2; i++) s[i][n+1] = '*';
}