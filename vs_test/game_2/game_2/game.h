#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_MINE 10

//³õÊ¼»¯ÆåÅÌ
void InitBoard(char board[ROWS][COLS], int row, int col, char str);
//´òÓ¡ÆåÅÌ
void PrintBoard(char board[ROWS][COLS], int row, int col);
//ÂñÀ×
void SetMine(char board[ROWS][COLS], int row, int col);
//É¨À×º¯Êý
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);