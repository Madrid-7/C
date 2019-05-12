#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 3
#define LINE 3

void ChessBoard(int row, int line, char board[ROW][LINE]);
void InitBoard(char board[ROW][LINE], int row, int line);
void PlayerMove(int row, int line, char board[ROW][LINE]);
void ComputerMove(int row, int line, char board[ROW][LINE]);

char CheakWin(int row, int line, char board[ROW][LINE]);
