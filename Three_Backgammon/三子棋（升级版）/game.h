#ifndef __GAME_H__
#define __GAME_H__

#define ROW 3
#define COL 3


#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>



void PrintBroad(char broad[ROW][COL], int row, int col);
void Playermove(char broad[ROW][COL], int row, int col,char sz,int flag);

int CheckResult(char broad[ROW][COL], int row, int col);

#endif