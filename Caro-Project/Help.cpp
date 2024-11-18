#include "Library.h"
#include "Graphic.h"

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
	cout << "KEYBOARD GUIDE";

	setPos(XX + 31, YY + 10);
	cout << "HOW TO PLAY";

	setColor(gameTheme);
	setPos(XX + 33, YY - 2);
	cout << "Player 1";
	setPos(XX + 45, YY - 2);
	cout << "Player 2";
	setPos(XX + 22, YY - 1);
	cout << "Go up:        W           Up";
	setPos(XX + 22, YY);
	cout << "Go down:      S          Down";
	setPos(XX + 22, YY + 1);
	cout << "Go left:      A          Left";
	setPos(XX + 22, YY + 2);
	cout << "Go right:     D          Right";
	setPos(XX + 22, YY + 3);
	cout << "Mark:       Space       Enter";

	setColor(3, 0);
	setPos(XX + 34, YY + 5);
	cout << "Other";
	setColor(gameTheme);
	setPos(XX + 22, YY + 6);
	cout << "Undo: U    Save: I    Exit: Esc";

	setColor(11, 0);
	setPos(XX - 2, YY + 12);
	cout << "Chessboard:";
	setPos(XX - 2, YY + 13);
	cout << "Players:";
	setPos(XX - 2, YY + 14);
	cout << "Turn:";
	setPos(XX - 2, YY + 15);
	cout << "Target:";
	setPos(XX - 2, YY + 17);
	cout << "Tie:";
	setColor(gameTheme);

	setPos(XX + 9, YY + 12);
	cout << "Square grid of 15x15 cells (225 cells).";
	setPos(XX + 7, YY + 13);
	cout << "Two players, using two types of symbols (usually X and O).";
	setPos(XX + 4, YY + 14);
	cout << "Players take turns marking an empty square on the board with their symbol.";
	setPos(XX + 6, YY + 15);
	cout << "The winner is the first person to get 5 consecutive symbols in one of";
	setPos(XX + 8, YY + 16);
	cout << "the directions: horizontal, vertical, or diagonal.";
	setPos(XX + 3, YY + 17);
	cout << "The game is a draw if the board is full and no one wins.";

	setColor(11, 0);
	setPos(XX + 26, YY + 19); cout << "<< Press ESC to exit >>";
	setColor(gameTheme);

	while (isNextMove() != 5);
}