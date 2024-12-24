#include "Library.h"
#include "Maincaro.h"
#include "Newgame.h"
#include "Loadgame.h"
#include "Console.h"
#include "Graphic.h"
#include "About.h"
#include "Help.h"
#include "Language.h"
#include "Tictactoe.h"

using namespace std;

map<string, string>* selectedLanguage = &english;


void exit() {
	system("cls");
	exit(0);
}

void drawMainMenu(int XX, int YY) {
	struct mainMenu {
		int x, y, size, bgColor;
		string str;

		void draw1() {
			drawMenu2(x, y, size, bgColor, str);
		}
		void draw2() {
			drawMenu3(x, y, size, bgColor, str);
		}
	};

	int menuTextLength = 20;
	int defaultTextColor = 15;
	int selectedTextColor = 15;

	mainMenu a1[6], a2[6];
	a1[0] = { XX - 1, YY + 1, menuTextLength, defaultTextColor, "     NEW GAME     " };
	a1[1] = { XX - 1, YY + 6, menuTextLength, defaultTextColor, "     LOAD GAME    " };
	a1[2] = { XX - 1, YY + 11, menuTextLength, defaultTextColor, "      ABOUT       " };
	a1[3] = { XX - 1, YY + 16, menuTextLength, defaultTextColor, "       HELP       " };
	a1[4] = { XX - 1, YY + 21, menuTextLength, defaultTextColor, "     LANGUAGE     " };
	a1[5] = { XX - 1, YY + 26, menuTextLength, defaultTextColor, "       EXIT       " };


	a2[0] = { XX, YY + 2, menuTextLength, selectedTextColor, ">>   NEW GAME   <<" };
	a2[1] = { XX, YY + 7, menuTextLength, selectedTextColor, ">>   LOAD GAME  <<" };
	a2[2] = { XX, YY + 12, menuTextLength, selectedTextColor, ">>     ABOUT    <<" };
	a2[3] = { XX, YY + 17, menuTextLength, selectedTextColor, ">>     HELP     <<" };
	a2[4] = { XX, YY + 22, menuTextLength, defaultTextColor, ">>   LANGUAGE   <<" };
	a2[5] = { XX, YY + 27, menuTextLength, selectedTextColor, ">>     EXIT     <<" };


	pullList();
	int S = 0;
	while (true) {
		drawCaroMain(XX - 6, YY - 7);
		setPos(38, 3);
		cout << char(201);
		for (int i = 1; i <= 64; i++)
			cout << char(205);
		cout << char(187);
		for (int i = 1; i <= 8; i++) {
			setPos(38, 3 + i);
			cout << char(186);
			setPos(38 + 64 + 1, 3 + i);
			cout << char(186);
		}
		setPos(38, 11);
		cout << char(200);
		for (int i = 1; i <= 64; ++i)
			cout << char(205);
		cout << char(188);
		decorate_draw(XX - 40, YY + 5, "ARTS/amongus2.txt");
		decorate_draw(XX + 33, YY + 5, "ARTS/amongus2_reversed.txt");
		decorate_draw(XX + 50, YY - 7, "ARTS/star.txt");
		decorate_draw(XX - 40, YY - 7, "ARTS/star.txt");
		for (int i = 0; i < 6; ++i)
			a1[i].draw1();
		a2[S].draw2();

		ShowCur(0);
		int input = isNextMove();
		if (input == 1) S = (S + 5) % 6;
		else if (input == 3) S = (S + 1) % 6;
		else if (input == 0) {
			if (S == 0) newGame(XX, YY);
			else if (S == 1) loadGame(XX, YY);
			else if (S == 2) about(XX, YY);
			else if (S == 3) help(XX, YY);
			else if (S == 4) {
				language(XX, YY);
				for (int i = 0; i < 6; ++i) {
					a1[i].str = (*selectedLanguage)[a1[i].str];
					a2[i].str = (*selectedLanguage)[a2[i].str];
				}
			}
			else if (S == 5) exit();
			else assert(false);
			system("cls");
		}
	}
}

int main() {
	dict();
	fixConsoleWindow(67, 98);
	SetConsoleTitle(L"CaroGame - 24CTT3 - Group 2");
	ShowCur(0);
	//introAnimation("ARTS/pic.txt", 20, 3000, 0, 0);

	drawMainMenu(61, 12);

	return 0;
}
