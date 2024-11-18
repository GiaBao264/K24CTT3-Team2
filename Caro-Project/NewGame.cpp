#include "Newgame.h"

using namespace std;

bool insertName(int XX, int YY, string& str) {
	string originName = str;
	int origin_XX = XX, origin_YY = YY;
	int b = 0;

	setPos(XX, YY);
	cout << str;

	while (true) {
		char a = _getch();
		if ((int)a < 0) {
			a = _getch();
			continue;
		}
		if (a == 13) break;
		if (a == 27) return 0;
		if (a == '\b' && b) {
			str.pop_back(); --b; --XX;
			setPos(XX, YY);
			cout << " ";
			setPos(XX, YY);

			if (b == 0) {
				setColor(15, 8);
				setPos(origin_XX, origin_YY);
				cout << str;
			}
		}
		else if ((('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z') || isdigit(a)) && b < 10) {
			if (b == 0) {
				str = "";
				setColor(15, 0);
				setPos(origin_XX, origin_YY);
				cout << "          ";
			}

			str.push_back(a); ++b;
			setPos(XX, YY);
			cout << a; ++XX;
		}
	}
	return 1;
}

void mode1(int XX, int YY) {
	system("cls");

	string name;
	drawMenu1(XX, YY, 27, 15, "PLAYER NAME: ");
	if (!insertName(XX + 15, YY + 1, name = "[PLAYER]")) return;

	startGame(true, true, XX - 3, YY, name, "Bot", {}, "", 0, 0);
}

void mode2(int XX, int YY) {
	system("cls");
	string name1, name2;

	drawMenu1(XX, YY, 29, 15, "PLAYER NAME 1: ");
	if (!insertName(XX + 15, YY + 1, name1 = "[player1]")) return;

	drawMenu1(XX, YY + 3, 29, 15, "PLAYER NAME 2: ");
	if (!insertName(XX + 15, YY + 4, name2 = "[player2]")) return;

	startGame(false, true, XX - 3, YY, name1, name2, {}, "", 0, 0);
}

void newGame(int XX, int YY) {
	struct newGameMenu {
		int xx, yy, sizee, bg_colorr;
		string strr;

		void draw() {
			drawMenu1(xx, yy, sizee, bg_colorr, strr);
		}
	};

	newGameMenu a1[2], a2[2];
	a1[0] = { XX, YY + 10, 25, 15,  "     PLAY WITH BOT     " };
	a1[1] = { XX, YY + 15, 25, 15,  "    PLAY WITH HUMAN    " };

	a2[0] = { XX, YY + 10, 25, 15,  ">>   PLAY WITH BOT   <<" };
	a2[1] = { XX, YY + 15, 25, 15,  ">>  PLAY WITH HUMAN  <<" };

	system("cls");
	int S = 0;

	while (true) {
		newGameText(XX, YY);
		for (int i = 0; i < 2; ++i)
			a1[i].draw();
		a2[S].draw();

		int inputNewGame = isNextMove();
		system("cls");
		if (inputNewGame == 1 || inputNewGame == 3) S ^= 1;
		else if (inputNewGame == 0) {
			if (S == 0)mode1(XX - 2, YY);
			else if (S == 1)mode2(XX - 3, YY);
			else assert(false);
			break;
		}
		else if (inputNewGame == 5) break;
	}
}