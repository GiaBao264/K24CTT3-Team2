#include "Library.h"
#include "Maincaro.h"
#include "Loadgame.h"
#include "Console.h"
#include "Tictactoe.h"
#include "Graphic.h"
#include "NewGame.h"
#include "Language.h"


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
		s1[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 11, (*selectedLanguage)["      EMPTY       "] };
		s2[i] = { XX - 30 + 30 * (i / 3), YY + 5 + (i % 3) * 4, 20, 8, "" };

		if (i <= size) {
			string tmp = fileSave[i];
			int siz = 14 - (int)tmp.size();

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
			s3[0] = { XX - 12, YY + 16, 16, 15, (*selectedLanguage)["     PLAY     "] };
			s3[1] = { XX + 8, YY + 16, 16, 15,  (*selectedLanguage)["    DELETE    "] };
			s3[2] = { XX + 28, YY + 16, 16, 15, (*selectedLanguage)["    RENAME    "] };

			s4[0] = { XX - 12, YY + 16, 16, 14, (*selectedLanguage)[">>   PLAY   <<"] };
			s4[1] = { XX + 8, YY + 16, 16, 14,  (*selectedLanguage)[">>  DELETE  <<"] };
			s4[2] = { XX + 28, YY + 16, 16, 14, (*selectedLanguage)[">>  RENAME  <<"] };

			s1[S].draw();
			setPos(XX - 30, YY + 17); setColor(gameTheme);
			cout << "                                                                                 ";
			setPos(XX - 24, YY + 17); setColor(11, 0); cout << (*selectedLanguage)[" Choose: "];

			int k = 0;
			while (true) {
				setPos(XX - 30, YY + 17); setColor(gameTheme);
				cout << "                                                                                 ";
				setPos(XX - 24, YY + 17); setColor(11, 0); cout << (*selectedLanguage)[" Choose: "];

				for (int j = 0; j < 3; ++j)
					s3[j].draw();
				s4[k].draw();

				int inputt = isNextMove();
				if (inputt == 5) break;
				else if (inputt == 2) k = (k + 2) % 3;
				else if (inputt == 4) k = (k + 1) % 3;
				else if (inputt == 0) {
					if (k == 0) {		// Load file and play
						vector<ii> Data;
						int Xscore, Oscore;
						string name1, name2;
						bool vsBot;

						loadFromFile(fileSave[S], Data, Xscore, Oscore, name1, name2, vsBot);
						startGame(vsBot, 0, XX, YY, name1, name2, Data, fileSave[S], Xscore, Oscore);
						return;
					}

					if (k == 1) {		// Delete file
						deleteFile(fileSave[S]);
						setPos(XX - 29, YY + 16); cout << "                                                                               ";
						setPos(XX - 29, YY + 17); cout << "                                                                               ";
						setPos(XX - 29, YY + 18); cout << "                                                                               ";
						for (int t = S + 1; t <= size; ++t) {
							fileSave[t - 1] = fileSave[t];
							s1[t - 1].str = s1[t].str;
							s2[t - 1].str = s2[t].str;
						}

						fileSave.pop_back();
						s1[size].str = (*selectedLanguage)["      EMPTY       "];
						s1[size].b_color = 11;
						s2[size].str = "";
						--size;  S = min(S, size);
						drawOutBoard(XX - 12, YY + 16, 5);
						drawOutBoard(XX - 24, YY + 17, 5);
						drawOutBoard(XX - 24, YY + 18, 5);
					}
					else {			// Rename file
						setColor(gameTheme);
						setPos(XX - 29, YY + 16); cout << "                                                                               ";
						setPos(XX - 29, YY + 17); cout << "                                                                               ";
						setPos(XX - 29, YY + 18); cout << "                                                                               ";

						// Import new name
					renameFile:
						string tmp;
						setPos(XX - 24, YY + 17); cout << (*selectedLanguage)[" New Name:                                                         "];
						if (!insertName(XX - 13, YY + 17, tmp = fileSave[S])) continue;

						// Check the same name
						bool checkSame = 0;
						for (int t = 0; t <= size; ++t)
							if (t != S && fileSave[t] == tmp)
								checkSame = 1;

						if (checkSame) {
							setPos(XX - 24, YY + 17); cout << (*selectedLanguage)[">> It already exists, do you want to change another name? Press Y/N"];
							while (true) {
								char key = _getch();
								if (key == 'N' || key == 'n') break;
								else if (key == 'Y' || key == 'y') goto renameFile;
							} break;
						}
						drawOutBoard(XX - 24, YY + 17, 5);

						// Process rename
						string old_name = fileSave[S] + ".txt";
						string new_name = tmp + ".txt";
						rename(old_name.c_str(), new_name.c_str());

						fileSave[S] = tmp;
						int siz = 14 - (int)tmp.size();

						for (int t = 1; 2 * t <= siz; ++t)
							tmp = ' ' + tmp + ' ';
						if (siz & 1) tmp += ' ';

						s1[S].str = "  " + tmp + "  ";
						s2[S].str = ">>" + tmp + "<<";
					}
					pushList();
					break;
				}
			} if (S != -1) s2[S].draw();
		}
		else {
			int mouSe = -1;
			if (inputt == 1) mouSe = S - 1;
			else if (inputt == 2) mouSe = S - 3;
			else if (inputt == 3) mouSe = S + 1;
			else if (inputt == 4) mouSe = S + 3;
			if (mouSe <= size && mouSe >= 0) S = mouSe;
		}
	}
}

void saveGame(int XX, int YY, vector<ii> moveMade, int Xscore, int Oscore, string name1, string name2, string& nameFile, bool vsBot) {
	if (nameFile == "") {
	insertNames:
		drawOutBoard(XX - 3, YY + 2 * boardSize - 1, 2);
		if (!insertName(XX + 10, YY + 2 * boardSize + 1, nameFile)) {
			drawOutBoard(XX + 18, YY + 2 * boardSize - 1, 1);
			return;
		} if (nameFile == "") goto insertNames;
	}

	bool checkSame = 0;
	for (string tmp : fileSave)
		if (tmp == nameFile) checkSame = 1;

	if (checkSame) {
		drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 3);
		while (true) {
			char key = _getch();
			if (key == 'N' || key == 'n') {
				drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 1);
				nameFile = "";
				drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 5);
				return;
			}
			else if (key == 'Y' || key == 'y') break;
		}
		drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 5);
	}
	else {
		while ((int)fileSave.size() >= 15)
			fileSave.erase(fileSave.begin());
		fileSave.push_back(nameFile);
	}

	drawOutBoard(XX - 3, YY + 2 * boardSize - 1, 1);
	drawName_LoadBoard(XX + 4 * boardSize - 13, YY + 2 * boardSize - 1, nameFile);
	pushList();

	ofstream File(nameFile + ".txt");
	File << bool(vsBot) << " " << Xscore << " " << Oscore << '\n';
	File << name1 << " " << name2 << '\n';

	for (const auto& tmp : moveMade) {
		File << tmp.first << " " << tmp.second << "\n";
	} File.close();
}

void loadFromFile(string nameFile, vector<ii>& Data, int& Xscore, int& Oscore, string& name1, string& name2, bool& vsBot) {	// Load data from file is saved
	Data.clear();
	nameFile += ".txt";
	ifstream file(nameFile);
	int x, y;

	file >> vsBot >> Xscore >> Oscore;
	file >> name1 >> name2;
	while (file >> x >> y) Data.emplace_back(x, y);
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