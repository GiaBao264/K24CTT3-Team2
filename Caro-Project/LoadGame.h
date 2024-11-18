#ifndef _LOADGAME_H_
#define _LOADGAME_H_
#include "Library.h"

typedef pair<int, int> ii;

void loadGame(int XX, int YY);
void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile, bool vsBot);
void loadFromFile(string nameFile, vector<ii>& Cache, int& Xscore, int& Oscore, string& name1, string& name2, bool& vsBot);
void pullList();
void pushList();
void deleteFile(string nameFile);

#endif