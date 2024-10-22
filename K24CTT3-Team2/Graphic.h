#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "Library.h"
#include "Console.h"

using namespace std;

void drawMenu1(int x, int y, int size, int bgColor, string text);
void drawMenu2(int x, int y, int size, int bgColor, string text);
void drawMenu3(int x, int y, int size, int bgColor, string text);
void drawBoard(int Xi, int Yi, string name1, string name2, int Xscore, int Oscore, string fileName);

#endif