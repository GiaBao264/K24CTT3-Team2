#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include "Library.h"

void fixConsoleWindow(int WIDTH, int HEIGHT);
void setPos(int x, int y);
void setColor(int backgroundColor, int textColor);
void ShowCur(bool CursorVisibility);
int isInput();

#endif