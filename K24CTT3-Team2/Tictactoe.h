#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_
#include "Library.h"

typedef pair <int, int> ii;


void makeMove(char player, int row, int col);
void botPlay();
void displayWinLine();
void drawX(int x, int y, int color);
void drawO(int x, int y, int color);
void drawX_WIN(int x, int y);
void drawO_WIN(int x, int y);
void drawDRAW(int x, int y);
void drawPopUp(int x, int y, int height, int width);
void decorate_draw(int x, int y, const string& nameFile);
void drawStatus(int x, int y, int color);
void saveGame(int XX, int YY, int Cache, int Xscore, int Oscore, string name1, string name2, string fileName, bool vsBot);
void startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore);


#endif