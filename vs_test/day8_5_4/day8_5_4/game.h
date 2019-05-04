#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 4
#define LINE 4

void ChessBoard(int row, int line, char board[ROW][LINE]);
void InitBoard(char board[ROW][LINE], int row, int line);
void PlayerMove(int row, int line, char board[ROW][LINE]);
void ComputerMove(int row, int line, char board[ROW][LINE]);
