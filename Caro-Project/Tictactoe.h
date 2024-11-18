#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_
#include "Library.h"

typedef pair <int, int> ii;

struct _Point {
	int X, Y;
	char opt;
};

void makeMove(char player, int row, int col);
void displayWinLine(int z);
void startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore);


#endif