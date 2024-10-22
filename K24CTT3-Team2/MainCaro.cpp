#include "Library.h"
#include "Maincaro.h"
#include "Console.h"
#include "Graphic.h"
#include "Tictactoe.h"

using namespace std;

void outGame()
{
	system("cls");
	exit(0);
}

void drawMainMenu(int XX, int YY)
{
	struct mainMenu
	{
		int x, y, size, bgColor;
		string str;

		// Unselected Menu
		void draw1()
		{
			drawMenu2(x, y, size, bgColor, str);
		}

		// Selected Menu
		void draw2()
		{
			drawMenu3(x, y, size, bgColor, str);
		}
	};

	int menuTextLength = 20;
	int defaultTextColor = 15;
	int selectedTextColor = 15;

	mainMenu a1[6], a2[6];
	a1[0] = { XX, YY,		menuTextLength, defaultTextColor, "     NEW GAME     " };
	a1[1] = { XX, YY + 4,	menuTextLength, defaultTextColor, "     LOAD GAME    " };
	a1[2] = { XX, YY + 8,	menuTextLength, defaultTextColor, "      ABOUT       " };
	a1[3] = { XX, YY + 12,	menuTextLength, defaultTextColor, "      HELP        " };
	a1[4] = { XX, YY + 16,	menuTextLength, defaultTextColor, "     LANGUAGE     " };
	a1[5] = { XX, YY + 20,	menuTextLength, defaultTextColor, "      EXIT        " };

	a2[0] = { XX - 1, YY - 1,	menuTextLength, selectedTextColor, "     NEW GAME     " };
	a2[1] = { XX - 1, YY + 3,	menuTextLength, selectedTextColor, "     LOAD GAME    " };
	a2[2] = { XX - 1, YY + 7,	menuTextLength, selectedTextColor, "      ABOUT       " };
	a2[3] = { XX - 1, YY + 11,	menuTextLength, selectedTextColor, "      HELP        " };
	a2[4] = { XX - 1, YY + 15,	menuTextLength, selectedTextColor, "     LANGUAGE     " };
	a2[5] = { XX - 1, YY + 19,	menuTextLength, selectedTextColor, "      EXIT        " };

	int S = 0;
	
	while (true)
	{
		for (int i = 0; i < 5; ++i) a1[i].draw1();
		a2[S].draw2();

		ShowCur(0);
		int input = isInput();

		//To do: get returned value from isInput() in Console.cpp to do the next functions
	}
}

int main()
{
	SetConsoleTitle(L"CaroGame - 24CTT3 - Group 2");
	fixConsoleWindow(1068, 708);

	ShowCur(0);

	// To do: need to change the starting position when the main board is completed
	drawMainMenu(20, 20);

	return 0 ^ 0;
}