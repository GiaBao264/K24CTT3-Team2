#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include "Library.h"

void fixConsoleWindow(int WIDTH, int HEIGHT);
void setPos(int x, int y);
void setColor(int backgroundColor, int textColor);
void drawSquare(int a, int b, int x, int y, int color);
void txtDraw(int x, int y, const string& nameFile);
void ShowCur(bool CursorVisibility);
void currCoordinate(int& x, int& y);
int isNextMove();
void draw_square(int i, int j, int x, int y, int color);
void decorate_draw(int x, int y, const string& nameFile);
void saveCurPos(COORD& currentPos);
#endif