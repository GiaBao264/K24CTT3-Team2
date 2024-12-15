#include "Library.h"
#include "Graphic.h"
#include "Language.h"

#define gameTheme 15, 0

void help(int Xi, int Yi) {
	system("cls");
	//drawHelpText();

	int XX = Xi - 27, YY = Yi - 1;

	setColor(gameTheme);
	for (int i = 1; i < 90; ++i) {
		setPos(XX + i - 9, YY + 8);
		cout << "=";
	}

	setColor(3, 0);
	setPos(XX + 30, YY - 4);
	cout << (*selectedLanguage)["KEYBOARD GUIDE"];

	setPos(XX + 31, YY + 10);
	cout << (*selectedLanguage)["HOW TO PLAY"];

	setColor(gameTheme);
	setPos(XX + 33, YY - 2);
	cout << (*selectedLanguage)["Player 1"];
	setPos(XX + 45, YY - 2);
	cout << (*selectedLanguage)["Player 2"];
	setPos(XX + 22, YY - 1);
	cout << (*selectedLanguage)["Go up:        W           Up"];
	setPos(XX + 22, YY);
	cout << (*selectedLanguage)["Go down:      S          Down"];
	setPos(XX + 22, YY + 1);
	cout << (*selectedLanguage)["Go left:      A          Left"];
	setPos(XX + 22, YY + 2);
	cout << (*selectedLanguage)["Go right:     D          Right"];
	setPos(XX + 22, YY + 3);
	cout << (*selectedLanguage)["Mark:       Space       Enter"];

	setColor(3, 0);
	setPos(XX + 34, YY + 5);
	cout << (*selectedLanguage)["Other"];
	setColor(gameTheme);
	setPos(XX + 22, YY + 6);
	cout << (*selectedLanguage)["Undo: U    Save: I    Exit: Esc"];

	setColor(11, 0);
	setPos(XX - 2, YY + 12);
	cout << (*selectedLanguage)["Chessboard:"];
	setPos(XX - 2, YY + 13);
	cout << (*selectedLanguage)["Players:"];
	setPos(XX - 2, YY + 14);
	cout << (*selectedLanguage)["Turn:"];
	setPos(XX - 2, YY + 15);
	cout << (*selectedLanguage)["Target:"];
	setPos(XX - 2, YY + 17);
	cout << (*selectedLanguage)["Tie:"];
	setColor(gameTheme);

	setPos(XX + 10, YY + 12);
	cout << (*selectedLanguage)["Square grid of 15x15 cells (225 cells)."];
	setPos(XX + 10, YY + 13);
	cout << (*selectedLanguage)["Two players, using two types of symbols (usually X and O)."];
	setPos(XX + 10, YY + 14);
	cout << (*selectedLanguage)["Players take turns marking an empty square on the board with their symbol."];
	setPos(XX + 10, YY + 15);
	cout << (*selectedLanguage)["The winner is the first person to get 5 consecutive symbols in one of"];
	setPos(XX + 12, YY + 16);
	cout << (*selectedLanguage)["the directions: horizontal, vertical, or diagonal."];
	setPos(XX + 10, YY + 17);
	cout << (*selectedLanguage)["The game is a draw if the board is full and no one wins."];

	setColor(11, 0);
	setPos(XX + 26, YY + 19); cout << (*selectedLanguage)["<< Press ESC to exit >>"];
	setColor(gameTheme);

	while (isNextMove() != 5);
}