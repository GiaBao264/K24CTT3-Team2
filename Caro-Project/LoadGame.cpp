﻿#include "Library.h"
#include "Maincaro.h"
#include "Loadgame.h"
#include "Console.h"
#include "Tictactoe.h"
#include "Graphic.h"
#include "NewGame.h"

#define gameTheme 15, 0

const int boardSize = 15;

vector<string> fileSave;

void loadGame(int XX, int YY) {
	struct loadMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawLoadMenu(X, Y, size, b_color, str);
		}
	};

	int size = min((int)fileSave.size() - 1, 8);
	loadMenu s1[10], s2[10];
	for (int i = 0; i < 9; ++i) {
		s1[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 11, "      EMPTY       " };
		s2[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 8, "" };

		if (i <= size) {
			string tmp = fileSave[i];
			int siz = 8 - (int)tmp.size();

			for (int j = 1; 2 * j <= siz; ++j)
				tmp = ' ' + tmp + ' ';
			if (siz & 1) tmp += ' ';

			s1[i].str = "  " + tmp + "  ";
			s2[i].str = ">>" + tmp + "<<";
			s1[i].b_color = 15;
		}
	}

	system("cls");
	setColor(gameTheme);

	drawSavedFile(XX - 26, YY - 9);

	int S = min(0, size);
	while (true) {
		for (int i = 0; i < 9; ++i)
			s1[i].draw();
		if (S != -1) s2[S].draw();

		int inputt = isNextMove();
		if (inputt == 5) break;
		else if (S == -1) continue;

		if (inputt == 0) {
			loadMenu s3[3], s4[3];
			s3[0] = { XX - 12, YY + 15, 16, 15, "     PLAY     " };
			s3[1] = { XX + 8, YY + 15, 16, 15,  "    DELETE    " };
			s3[2] = { XX + 28, YY + 15, 16, 15, "    RENAME    " };

			s4[0] = { XX - 12, YY + 15, 16, 14, ">>   PLAY   <<" };
			s4[1] = { XX + 8, YY + 15, 16, 14,  ">>  DELETE  <<" };
			s4[2] = { XX + 28, YY + 15, 16, 14, ">>  RENAME  <<" };

			s1[S].draw();
			setPos(XX - 30, YY + 16); setColor(gameTheme);
			cout << "                                                                                 ";
			setPos(XX - 24, YY + 16); setColor(11, 0); cout << " Choose: ";

			int k = 0;
			while (true) {
				setPos(XX - 30, YY + 16); setColor(gameTheme);
				cout << "                                                                                 ";
				setPos(XX - 24, YY + 16); setColor(11, 0); cout << " Choose: ";

				for (int j = 0; j < 3; ++j)
					s3[j].draw();
				s4[k].draw();

				int inputt = isNextMove();
				if (inputt == 5) break;
				else if (inputt == 2) k = (k + 2) % 3;
				else if (inputt == 4) k = (k + 1) % 3;
				else if (inputt == 0) {
					
					//continue
				}
			} if (S != -1) s2[S].draw();

		}
		else {
			int col = S / 5, mouSe;
			if (inputt == 1) mouSe = (S + 4) % 5 + col * 5;
			else if (inputt == 2) mouSe = (S + 10) % 15;
			else if (inputt == 3) mouSe = (S + 1) % 5 + col * 5;
			else if (inputt == 4) mouSe = (S + 5) % 15;
			if (mouSe <= size) S = mouSe;
		}
	}
}

void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile, bool vsBot) {
	if (nameFile == "") {
		insertNames:
		drawOutBoard(XX - 31, YY + 2 * boardSize - 1, 2);
		if (!insertName(XX - 18, YY + 2 * boardSize - 1, nameFile)) {
			drawOutBoard(XX - 31, YY + 2 * boardSize - 1, 1);
			return;
		} if (nameFile == "") goto insertNames;
	}

	bool checkSame = 0;
	for (string tmp : fileSave)
		if (tmp == nameFile) checkSame = 1;

	if (checkSame) {
		drawOutBoard(XX - 31, YY + 2 * boardSize - 1, 3);
		while (true) {
			char key = _getch();
			if (key == 'N' || key == 'n') {
				drawOutBoard(XX - 31, YY + 2 * boardSize - 1, 1);
				nameFile = "";
				return;
			} else if (key == 'Y' || key == 'y') break;
		}
	} else {
		while ((int)fileSave.size() >= 15)
			fileSave.erase(fileSave.begin());
		fileSave.push_back(nameFile);
	}

	drawOutBoard(XX - 31, YY + 2 * boardSize - 1, 1);
	drawName_LoadBoard(XX + 4 * boardSize - 33, YY + 2 * boardSize - 1, nameFile);
	pushList();

	ofstream File(nameFile + ".txt");
	File << int(vsBot) << " " << Xscore << " " << Oscore << '\n';
	File << name1 << " " << name2 << '\n';

	for (const auto& tmp : Cache) {
		File << tmp.first << " " << tmp.second << "\n";
	} File.close();
}

void loadFromFile(string nameFile, vector<ii>& Cache, int& Xscore, int& Oscore, string& name1, string& name2, bool& vsBot) {	// Load data from file is saved
	Cache.clear();
	nameFile += ".txt";
	ifstream file(nameFile);
	int x, y;

	file >> vsBot >> Xscore >> Oscore >> name1 >> name2;
	while (file >> x >> y) Cache.emplace_back(x, y);
	file.close();
}

void pullList() {
	string s; fileSave.clear();
	ifstream file("ListNameFiles.txt");
	while (file >> s) fileSave.emplace_back(s);
	file.close();
}

void pushList() {
	ofstream File("ListNameFiles.txt");
	for (string s : fileSave) File << s << '\n';
	File.close();
}

void deleteFile(string nameFile) {
	nameFile += ".txt";
	remove(nameFile.c_str());
}