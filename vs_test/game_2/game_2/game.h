#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_MINE 80

void InitBoard(char board[ROWS][COLS], int row, int col, char str);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);