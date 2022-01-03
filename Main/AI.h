#ifndef _AI_H_
#define _AI_H_
#include<iostream>

using namespace std;

 
void Findmove(char s[100][100], int&x, int&y, int&a, int&b, char player1symbol, char player2symbol, int rule, int n, int playturnpvc);
int find_4_enermy(char s[100][100], int i, int j, int n, char player1symbol, char player2symbol);
int find_4_enermy_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol);
int find_4_enermy_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol);
int find_4_enermy_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol);
int find_4_enermy_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol);
int Check_attack_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_attack_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_attack_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_attack_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_defend_vertical(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_defend_horizontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_defend_lr_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
int Check_defend_rl_diagontal(char s[100][100], int i, int j, char player1symbol, char player2symbol, int rule, int n);
#endif 