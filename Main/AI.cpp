#include"AI.h"
#include"gotoxy.hpp"


void  Findmove(char s[100][100], int&x, int&y, int&a, int&b, char player1symbol, char player2symbol, int rule, int n, int playturnpvc)
{
	long Attackpoint = 0, Defendpoint = 0;
	long max =0 , temp =0;
	int max_find_4_enermy = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] == ' ')
			{
				temp = 0;
				Attackpoint = Check_attack_vertical(s, i, j, player1symbol, player2symbol, rule, n) + Check_attack_horizontal(s, i, j, player1symbol, player2symbol, rule, n) + Check_attack_lr_diagontal(s, i, j, player1symbol, player2symbol, rule, n) + Check_attack_rl_diagontal(s, i, j, player1symbol, player2symbol, rule, n);
				Defendpoint = Check_defend_vertical(s, i, j, player1symbol, player2symbol, rule, n) + Check_defend_horizontal(s, i, j, player1symbol, player2symbol, rule, n) + Check_defend_lr_diagontal(s, i, j, player1symbol, player2symbol, rule, n) + Check_defend_rl_diagontal(s, i, j, player1symbol, player2symbol, rule, n);
				if (Attackpoint > Defendpoint) temp = Attackpoint;
				else temp = Defendpoint;
				
				if (temp >= 700000)
				{
					if (temp > max)
					{
						max = temp;
						a = i, b = j;
						x = 3 * i + 2, y = j + 1;
					}
				}
				else
				{
					if (max>=49000&&max < 70000 && find_4_enermy(s, i, j, n, player1symbol, player2symbol) >= 250&& find_4_enermy(s, i, j, n, player1symbol, player2symbol) > max_find_4_enermy)
					{
						max_find_4_enermy = find_4_enermy(s, i, j, n, player1symbol, player2symbol);
						x = 3 * i + 2, y = j + 1;
						a = i, b = j;
					}
					else if (temp >= 49000)
					{
						if (temp > max)
						{
							max = temp;
							x = 3 * i + 2, y = j + 1;
							a = i, b = j;

						}
					}
					else if (max < 49000 && find_4_enermy(s, i, j, n, player1symbol, player2symbol) >= 200 && find_4_enermy(s, i, j, n, player1symbol, player2symbol) > max_find_4_enermy)
					{
						max_find_4_enermy = find_4_enermy(s, i, j, n, player1symbol, player2symbol);
						x = 3 * i + 2, y = j + 1;
						a = i, b = j;
					}
					else if (temp > max)
					{
						max = temp;
						x = 3 * i + 2, y = j + 1;
						a = i, b = j;
					}

				}
			}
		}
	}
	s[a][b] = player1symbol;
}


int find_4_enermy(char s[100][100], int i, int j, int n, char player1symbol, char player2symbol)
{
	int tim_duong_4 = 0;
    tim_duong_4 = find_4_enermy_horizontal(s, i, j, player1symbol, player2symbol) + find_4_enermy_vertical(s, i, j, player1symbol, player2symbol) + find_4_enermy_lr_diagontal(s, i, j, player1symbol, player2symbol) + find_4_enermy_rl_diagontal(s, i, j, player1symbol, player2symbol);
	return tim_duong_4;
}
int find_4_enermy_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol)
{
	int soquandich = 0;
	int soquanta = 0;
	for (int dem = 1; dem < 6; dem++)
	{
		if (s[i][j + dem] == '*') break;
		else if (s[i][j + dem] == player2symbol) soquandich++;
		else if (s[i][j + dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	for (int dem = 1; dem < 6 && dem <= j; dem++)
	{
		if (s[i][j - dem] == '*') break;
		else if (s[i][j - dem] == player2symbol) soquandich++;
		else if (s[i][j - dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	if (soquandich == 3 && soquanta < 2) return 150;
	else if (soquandich == 2)
	{
		if (soquanta == 0) return 100;
	}
	return 0;
}
int find_4_enermy_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol)
{
	int soquandich = 0;
	int soquanta = 0;
	for (int dem = 1; dem < 6; dem++)
	{
		if (s[i + dem][j] == '*') break;
		else if (s[i + dem][j] == player2symbol) soquandich++;
		else if (s[i + dem][j] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	for (int dem = 1; dem < 6 && dem <= i; dem++)
	{
		if (s[i - dem][j] == '*') break;
		else if (s[i - dem][j] == player2symbol) soquandich++;
		else if (s[i - dem][j] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	if (soquandich == 3 && soquanta < 2) return 150;
	else if (soquandich == 2)
	{
		if (soquanta == 0) return 100;
	}
	return 0;
}
int find_4_enermy_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol)
{
	int soquandich = 0;
	int soquanta = 0;
	for (int dem = 1; dem < 6; dem++)
	{
		if (s[i + dem][j + dem] == '*') break;
		else if (s[i + dem][j + dem] == player2symbol) soquandich++;
		else if (s[i + dem][j + dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	for (int dem = 1; dem < 6 && dem <= i && dem <= j; dem++)
	{
		if (s[i - dem][j - dem] == '*') break;
		else if (s[i - dem][j - dem] == player2symbol) soquandich++;
		else if (s[i - dem][j - dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	if (soquandich == 3&& soquanta <2) return 150;
	else if (soquandich == 2)
	{
		if (soquanta == 0) return 100;
	}
	return 0;
}
int find_4_enermy_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol)
{
	int soquandich = 0;
	int soquanta = 0;
	for (int dem = 1; dem < 6 && dem <= i; dem++)
	{
		if (s[i - dem][j + dem] == '*') break;
		else if (s[i - dem][j + dem] == player2symbol) soquandich++;
		else if (s[i - dem][j + dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	for (int dem = 1; dem < 6 && dem <= j; dem++)
	{
		if (s[i + dem][j - dem] == '*') break;
		else if (s[i + dem][j - dem] == player2symbol) soquandich++;
		else if (s[i + dem][j - dem] == player1symbol)
		{
			soquanta++;
			break;
		}
	}
	if (soquandich == 3 && soquanta <2) return 150;
	else if (soquandich == 2)
	{
		if (soquanta == 0) return 100;
	}
	return 0;
}

int Check_attack_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Attackpointarray[2] = { 0, 20 };
	long totalpoint = 0;
	int Allynumber = 0;
	int Enermynumber = 0;
	for (int dem = 1; dem <= 6 && j + dem < n + 2; dem++)
	{
		if (s[i][j + dem] == player1symbol)	Allynumber++;
		else if (s[i][j + dem] == player2symbol)
		{
			Enermynumber++;
			break;
		}
		else if (s[i][j + dem] == '*')
		{
			Enermynumber++;
			break;
		}
		else break;
	}
	for (int dem = 1; dem <= 6 && j - dem > -1; dem++) // duyet tu duoi len
	{
		if (s[i][j - dem] == player1symbol)	Allynumber++;
		else if (s[i][j - dem] == player2symbol)
		{
			Enermynumber++;
			break;
		}
		else if (s[i][j - dem] == '*')
		{
			Enermynumber++;
			break;
		}
		else break;    
	}
	if (Allynumber == 2)
	{
		if (Enermynumber == 0) return 1001;
		else if (Enermynumber == 1) return  510;
		else if (Enermynumber == 2) return 0;
	}
	else if (Allynumber == 3)
	{
		if (Enermynumber == 0) return 100000;
		else if (Enermynumber == 1)
		{
			if (rule == 0)
			{
				int enermy = 0;
				for (int dem = 1; dem < 6; dem++)
				{
					if (s[i][j + dem] == player2symbol || s[i][j + dem] == '*')
					{
						enermy++;
						break;
					}
				}
				for (int dem = 1; j >= dem && dem < 6; dem++)
				{
					if (s[i][j - dem] == player2symbol || s[i][j - dem] == '*')
					{
						enermy++;
						break;
					}
				}
				if (enermy == 2) return 0;
			}
			return 50001;
		}
		else if (Enermynumber == 2) return 0;
	}
	else if (Allynumber == 4)
	{
		if (Enermynumber == 0 || Enermynumber ==1) return 10000000;
		else if (Enermynumber == 2) {
			if (rule == 0) return 0;
			return 10000000;
		}
		
	}
	totalpoint = Attackpointarray[Allynumber];
	return totalpoint;
}
int Check_attack_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Attackpointarray[2] = { 0, 20 };
	long totalpoint = 0;
	int Allynumber = 0;
	int Enermynumber = 0;
	for (int dem = 1; dem <= 6 && i + dem < n + 2; dem++) 
	{
		if (s[i + dem][j] == player1symbol)	Allynumber++;
		else if (s[i + dem][j] == player2symbol)
		{
			Enermynumber++;
			break;
		}
		else if (s[i + dem][j] == '*')
		{
			Enermynumber++;
			break;
		}
		else break;  
	}
	for (int dem = 1; dem <= 6 && i - dem > -1; dem++) 
	{
		if (s[i - dem][j] == player1symbol)	Allynumber++;
		else if (s[i - dem][j] == player2symbol)
		{
			Enermynumber++;
			break;
		}
		else if (s[i - dem][j] == '*')
		{
			Enermynumber++;
			break;
		}
		else break;   
	}
	if (Allynumber == 2)
	{
		if (Enermynumber == 0) return 1001;
		else if (Enermynumber == 1) return  510;
		else if (Enermynumber == 2) return 0;
	}
	else if (Allynumber == 3)
	{
		if (Enermynumber == 0) return 100000;
		else if (Enermynumber == 1)
		{
			if (rule == 0)
			{
				int enermy = 0;
				for (int dem = 1; dem < 6; dem++)
				{
					if (s[i + dem][j] == player2symbol || s[i + dem][j] == '*')
					{
						enermy++;
						break;
					}
				}
				for (int dem = 1; j >= dem && dem < 6; dem++)
				{
					if (s[i - dem][j] == player2symbol || s[i - dem][j] == '*')
					{
						enermy++;
						break;
					}
				}
				if (enermy == 2) return 0;
			}
			return 50001;
		}
		else if (Enermynumber == 2) return 0;
	}
	else if (Allynumber == 4)
	{
		if (Enermynumber == 0 || Enermynumber == 1) return 10000000;
		else if (Enermynumber == 2) {
			if (rule == 0) return 0;
			return 10000000;
		}

	}
	totalpoint = Attackpointarray[Allynumber];
	return totalpoint;
}
int Check_attack_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Attackpointarray[2] = { 0, 20 };
		long totalpoint = 0;
		int Allynumber = 0;
		int Enermynumber = 0;
		for (int dem = 1; dem <= 6 && i + dem < n + 2 && j + dem < n + 2; dem++) // duyet tu trai sang phai
		{
			if (s[i + dem][j + dem] == player1symbol)	Allynumber++;
			else if (s[i + dem][j + dem] == player2symbol)
			{
				Enermynumber++;
				break;
			}
			else if (s[i + dem][j + dem] == '*')
			{
				Enermynumber++;
				break;
			}
			else break;   
		}
		for (int dem = 1; dem <= 6 && i - dem > -1 && j - dem > -1; dem++)
		{
			if (s[i - dem][j - dem] == player1symbol)	Allynumber++;
			else if (s[i - dem][j - dem] == player2symbol)
			{
				Enermynumber++;
				break;
			}
			else if (s[i - dem][j - dem] == '*')
			{
				Enermynumber++;
				break;
			}
			else break;   // truong hop o trong hoac toi bien *
		}
		if (Allynumber == 2)
		{
			if (Enermynumber == 0) return 1001;
			else if (Enermynumber == 1) return  510;
			else if (Enermynumber == 2) return 0;
		}
		else if (Allynumber == 3)
		{
			if (Enermynumber == 0) return 100000;
			else if (Enermynumber == 1)
			{
				if (rule == 0)
				{
					int enermy = 0;
					for (int dem = 1; dem < 6; dem++)
					{
						if (s[i + dem][j + dem] == player2symbol || s[i + dem][j + dem] == '*')
						{
							enermy++;
							break;
						}
					}
					for (int dem = 1; j >= dem && i >= dem && dem < 6; dem++)
					{
						if (s[i - dem][j - dem] == player2symbol || s[i - dem][j - dem] == '*')
						{
							enermy++;
							break;
						}
					}
					if (enermy == 2) return 0;
				}
				return 50001;
			}
			else if (Enermynumber == 2) return 0;
		}
		else if (Allynumber == 4)
		{
			if (Enermynumber == 0 || Enermynumber == 1) return 10000000;
			else if (Enermynumber == 2) {
				if (rule == 0) return 0;
				return 10000000;
			}

		}
		totalpoint = Attackpointarray[Allynumber];
		return totalpoint;
	
}
int Check_attack_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Attackpointarray[2] = { 0, 20 };

	
			long totalpoint = 0;
			int Allynumber = 0;
			int Enermynumber = 0;
			for (int dem = 1; dem <= 6 && i + dem <n + 2 && j - dem >-1; dem++) // duyet tu trai sang phai
			{
				if (s[i + dem][j - dem] == player1symbol)	Allynumber++;
				else if (s[i + dem][j - dem] == player2symbol)
				{
					Enermynumber++;
					break;
				}
				else if (s[i + dem][j - dem] == '*')
				{
					Enermynumber++;
					break;
				}
				else break;  
			}
			for (int dem = 1; dem <= 6 && i - dem > -1 && j + dem < n + 2; dem++) 
			{
				if (s[i - dem][j + dem] == player1symbol)	Allynumber++;
				else if (s[i - dem][j + dem] == player2symbol)
				{
					Enermynumber++;
					break;
				}
				else if (s[i - dem][j + dem] == '*')
				{
					Enermynumber++;
					break;
				}
				else break;   
			}
			if (Allynumber == 2)
			{
				if (Enermynumber == 0) return 1001;
				else if (Enermynumber == 1) return  510;
				else if (Enermynumber == 2) return 0;
			}
			else if (Allynumber == 3)
			{
				if (Enermynumber == 0) return 100000;
				else if (Enermynumber == 1)
				{
					if (rule == 0)
					{
						int enermy = 0;
						for (int dem = 1; i > dem && dem < 6; dem++)
						{
							if (s[i - dem][j + dem] == player2symbol || s[i + dem][j + dem] == '*')
							{
								enermy++;
								break;
							}
						}
						for (int dem = 1; j >= dem && dem < 6; dem++)
						{
							if (s[i + dem][j - dem] == player2symbol || s[i - dem][j - dem] == '*')
							{
								enermy++;
								break;
							}
						}
						if (enermy == 2) return 0;
					}
					return 50001;
				}
				else if (Enermynumber == 2) return 0;
			}
			else if (Allynumber == 4)
			{
				if (Enermynumber == 0 || Enermynumber == 1) return 10000000;
				else if (Enermynumber == 2) {
					if (rule == 0) return 0;
					return 10000000;
				}

			}
			totalpoint = Attackpointarray[Allynumber];
			return totalpoint;
		
	
}
int Check_defend_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Defendpointarray[2] = { 0, 10 };
		long totalpoint = 0;
		int Allynumber = 0;
		int Enermynumber = 0;
		for (int dem = 1; dem <= 6 && j + dem < n + 2; dem++) 
		{
			if (s[i][j + dem] == player1symbol) 
			{
				Allynumber++;
				break;
			}
			else if (s[i][j + dem] == player2symbol)  Enermynumber++;
			else if (s[i][j + dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;  
		}
		for (int dem = 1; dem <= 6 && j - dem > -1; dem++) 
		{
			if (s[i][j - dem] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i][j - dem] == player2symbol) Enermynumber++;
			else if (s[i][j - dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		if (Enermynumber == 2)
		{
			if (Allynumber == 0) return 150;
			else if (Allynumber == 1) return 85;
			else if (Allynumber == 2) return 0;
		}
		else if (Enermynumber == 3)
		{
			if (Allynumber == 0) return 75000;
			else if (Allynumber == 1) return 300;
		}
		else if (Enermynumber == 4)
		{
			if (Allynumber == 2)
			{
				if (rule == 0) return 0;
				else return 700000;
 			}
			else
			{
				if (s[i][j-1] == player1symbol) return 0;
				return 700000;
			}
		}
		totalpoint = Defendpointarray[Enermynumber];
		return totalpoint;
}
int Check_defend_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Defendpointarray[2] = { 0, 10 };
		long totalpoint = 0;
		int Allynumber = 0;
		int Enermynumber = 0;
		for (int dem = 1; dem <= 6 && i + dem < n + 2; dem++) // duyet tu trai sang phai
		{
			if (s[i + dem][j] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i + dem][j] == player2symbol)  Enermynumber++;
			else if (s[i + dem][j] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		for (int dem = 1; dem <= 6 && i - dem > -1; dem++)
		{
			if (s[i - dem][j] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i - dem][j] == player2symbol) Enermynumber++;
			else if (s[i - dem][j] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		if (Enermynumber == 2)
		{
			if (Allynumber == 0) return 150;
			else if (Allynumber == 1) return 85;
			else if (Allynumber == 2) return 0;
		}
		else if (Enermynumber == 3)
		{
			if (Allynumber == 0) return 49000;
			else if (Allynumber == 1) return 300;
		}
		else if (Enermynumber == 4)
		{
			if (Allynumber == 2)
			{
				if (rule == 0) return 0;
				else return 700000;
			}
			else
			{
				if (s[i - 1][j] == player1symbol) return 0;
				return 700000;
			}
		}
		totalpoint = Defendpointarray[Enermynumber];
		return totalpoint;
}
int Check_defend_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Defendpointarray[2] = { 0, 10 };
		long totalpoint = 0;
		int Allynumber = 0;
		int Enermynumber = 0;
		for (int dem = 1; dem <= 6 && i + dem < n + 2 && j + dem < n + 2; dem++) 
		{
			if (s[i + dem][j + dem] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i + dem][j + dem] == player2symbol)  Enermynumber++;
			else if (s[i + dem][j + dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		for (int dem = 1; dem <= 6 && i - dem > -1 && j - dem > -1; dem++)
		{
			if (s[i - dem][j - dem] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i - dem][j - dem] == player2symbol) Enermynumber++;
			else if (s[i - dem][j - dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		if (Enermynumber == 2)
		{
			if (Allynumber == 0) return 150;
			else if (Allynumber == 1) return 85;
			else if (Allynumber == 2) return 0;
		}
		else if (Enermynumber == 3)
		{
			if (Allynumber == 0) return 49000;
			else if (Allynumber == 1) return 300;
		}
		else if (Enermynumber == 4)
		{
			if (Allynumber == 2)
			{
				if (rule == 0) return 0;
				else return 700000;
			}
			else
			{
				if (s[i - 1][j - 1] == player1symbol) return 0;
				return 700000;
			}
			
		}
		totalpoint = Defendpointarray[Enermynumber];
		return totalpoint;
}

int Check_defend_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n)
{
	int Defendpointarray[2] = { 0, 10 };
		long totalpoint = 0;
		int Allynumber = 0;
		int Enermynumber = 0;
		for (int dem = 1; dem <= 6 && i - dem > 0 && j + dem < n + 2; dem++) 
		{
			if (s[i - dem][j + dem] == player1symbol)
			{
				Allynumber++;
				break;
			}
			else if (s[i - dem][j + dem] == player2symbol)  Enermynumber++;
			else if (s[i - dem][j + dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   // truong hop o 
		}
		for (int dem = 1; dem <= 6 && i + dem <n + 2 && j - dem >-1; dem++) 
		{
			if (s[i + dem][j - dem] == player1symbol)
			{
				Allynumber++;
				break;

			}
			else if (s[i + dem][j - dem] == player2symbol) Enermynumber++;
			else if (s[i + dem][j - dem] == '*')
			{
				Allynumber++;
				break;
			}
			else break;   
		}
		if (Enermynumber == 2)
		{
			if (Allynumber == 0) return 150;
			else if (Allynumber == 1) return 85;
			else if (Allynumber == 2) return 0;
		}
		else if (Enermynumber == 3)
		{
			if (Allynumber == 0) return 49000;
			else if (Allynumber == 1) return 300;
		}
		else if (Enermynumber == 4)
		{
			if (Allynumber == 2)
			{
				if (rule == 0) return 0;
				else return 700000;
			}
			else
			{
				if (s[i + 1][j-1] == player1symbol) return 0;
				return 700000;
			}
		}
		totalpoint = Defendpointarray[Enermynumber];
		return totalpoint;
	
}

