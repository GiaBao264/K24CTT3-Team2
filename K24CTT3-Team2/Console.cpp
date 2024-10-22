#include "Console.h"
#include "Library.h"

// Fix Console Buffer Screen
void fixConsoleWindow(int WIDTH, int HEIGHT)
{
	system("COLOR f0");
	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	SMALL_RECT r{};
	r.Top = r.Left = 0;
	r.Right = WIDTH - 1;
	r.Bottom = HEIGHT - 1;

	COORD NewSize{};
	NewSize.X = WIDTH;
	NewSize.Y = HEIGHT;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	MoveWindow(consoleWindow, 300, 30, NewSize.X, NewSize.Y, TRUE);
	SetConsoleScreenBufferSize(Handle, NewSize);
	SetConsoleWindowInfo(Handle, TRUE, &r);
	ShowScrollBar(consoleWindow, SB_VERT, FALSE);
	ShowScrollBar(consoleWindow, SB_HORZ, FALSE);
}

// Set Cursor's Position
void setPos(int x, int y)
{
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Set Cursor's Color
void setColor(int backgroundColor, int foregroundColor)
{
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 16 * backgroundColor + foregroundColor;
	SetConsoleTextAttribute(consoleHandler, color);
}

// CursorVisibility = 0 means hide
void ShowCur(bool CursorVisibility)
{
	CONSOLE_CURSOR_INFO info = { 1, CursorVisibility };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// Check user's keyboard
int isInput()
{
	/* To do: AWSD + arrow keys return the same values
	ESC = exit
	ENTER = receive input as a yes, do the next function
	*/

	char key = _getch();

	return key;
}