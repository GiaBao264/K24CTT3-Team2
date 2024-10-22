#include "Graphic.h"

#define gameTheme 15, 0

const int boardSize = 15;

struct st {
	int topLeft = 201;
	int topRight = 187;
	int botLeft = 200;
	int botRight = 188;

	int vertiBar = 179;
	int horiBar = 196;

	int blank = 255;
	int dotSquare = 176;
	int boldDotSquare = 178;
} symbol;

// Draw Menu
// Based function menu, will be the merge of those 2 after this function
void drawMenu1(int x, int y, int size, int bgColor, string text)
{
		setColor(gameTheme);

		setPos(x, y);														// Top Left Corner
		cout << char(symbol.topLeft);
		for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
		cout << char(symbol.topRight);										// Top Right Corner
		cout << char(symbol.blank);

		setPos(x, y + 1);													// Left Vertical Bar
		cout << char(symbol.vertiBar);

		setPos(x + size - 1, y + 1);										// Right Vertical Bar
		cout << char(symbol.vertiBar);
		setPos(x + size, y + 1);
		cout << char(symbol.blank);

		setPos(x, y + 2);													// Bottom Left Corner
		cout << char(symbol.botLeft);

		for (int i = 0; i < size - 2; ++i) cout << char(symbol.horiBar);	// Horizontal Bar
		cout << char(symbol.botRight);										// Bottom Right Corner

		setPos(x + 1, y + 1);												// Print desired text
		setColor(bgColor, 0);
		cout << text;
		setColor(gameTheme);
}

// Unselected
void drawMenu2(int x, int y, int size, int bgColor, string text)
{
	setColor(gameTheme);

	setPos(x, y);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);
	setPos(x, y + 1);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);
	setPos(x, y + 2);
	for (int i = 0; i < size; ++i) cout << char(symbol.dotSquare);


	setPos(x + 1, y + 1);						// Print desired text
	setColor(bgColor, 0);
	cout << text;
	setColor(gameTheme);
}

// Selected
void drawMenu3(int x, int y, int size, int bgColor, string text)
{
	setColor(gameTheme);
	
	setPos(x, y);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x, y + 1);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x, y + 2);
	for (int i = 0; i < size; ++i) cout << char(symbol.boldDotSquare);
	setPos(x, y + 3);
	for (int i = 0; i < size; ++i) cout << char(symbol.blank);
	for (int i = 0; i <= 3; ++i) {
		setPos(x + size, y + i);
		cout << char(symbol.blank);
	}

	setPos(x + 1, y + 1);						// Print desired text
	setColor(bgColor, 0);
	cout << text;
	setColor(gameTheme);
}

void drawBoard(int Xi, int Yi, string name1, string name2, int Xscore, int Oscore, string fileName = "X") {
	setColor(gameTheme); 
	int XX = Xi - 31, YY = Yi - 2;
	// Characters for board drawing
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
	char horizontal = 205, vertical = 186, intersect = 197;
	char topIntersect = 203, bottomIntersect = 202, leftIntersect = 199, rightIntersect = 182;

	// Draw top border
	setPos(XX, YY);  // Assuming setPos() is defined elsewhere
	cout << topLeft;
	for (int x = 1; x < 4 * boardSize; x++) {
		if (x % 4 == 0) cout << topIntersect;
		else cout << horizontal;
	}
	cout << topRight;

	// Draw middle part of the board
	for (int y = 1; y < 2 * boardSize; y++) {
		setPos(XX, YY + y);

		// Vertical borders and intersections
		if (y % 2 == 0) {
			cout << leftIntersect;
			for (int x = 1; x < 4 * boardSize; x++) {
				if (x % 4 == 0) cout << intersect;
				else cout << horizontal;
			}
			cout << rightIntersect;
		}
		else {
			cout << vertical;
			for (int x = 1; x < 4 * boardSize; x++) {
				if (x % 4 == 0) cout << vertical;
				else cout << " ";
			}
			cout << vertical;
		}
	}

	// Draw bottom border
	setPos(XX, YY + 2 * boardSize);
	cout << bottomLeft;
	for (int x = 1; x < 4 * boardSize; x++) {
		if (x % 4 == 0) cout << bottomIntersect;
		else cout << horizontal;
	}
	cout << bottomRight;
}