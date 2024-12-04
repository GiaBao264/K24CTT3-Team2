#include "Console.h"

// Fix Console Buffer Screen
void fixConsoleWindow(int WIDTH, int HEIGHT) {
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

	MoveWindow(consoleWindow, 248, 10, NewSize.X, NewSize.Y, TRUE);
	SetConsoleScreenBufferSize(Handle, NewSize);
	SetConsoleWindowInfo(Handle, TRUE, &r);
	ShowScrollBar(consoleWindow, SB_VERT, FALSE);
	ShowScrollBar(consoleWindow, SB_HORZ, FALSE);
}

// Set Cursor's Position
void setPos(int x, int y) {
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void saveCurPos(COORD& currentPos) {
	CONSOLE_SCREEN_BUFFER_INFO csp;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csp);
	currentPos = csp.dwCursorPosition; 
}

// Set Cursor's Color
void setColor(int backgroundColor, int foregroundColor) {
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 16 * backgroundColor + foregroundColor;
	SetConsoleTextAttribute(consoleHandler, color);
}

// CursorVisibility = 0 is hide, = 1 is appear
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// Get the location of pointer
void currCoordinate(int& x, int& y) {
	CONSOLE_SCREEN_BUFFER_INFO curr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr);
	x = curr.dwCursorPosition.X;
	y = curr.dwCursorPosition.Y;
}

/*                  Get Input from user's keyboard

	Movement functions are declared as:
		1 is UP
		2 is LEFT
		3 is DOWN
		4 is RIGHT

	Console's functions are declared as:
		0 is ENTER
		5 is EXIT
*/
int isNextMove()
{
	while (true)
	{
		// Get user's Input
		char ch = _getch();

		// Press Enter
		if (ch == 13 || ch == ' ') return 0;

		// Press ESC
		if (ch == 27) return 5;

		//Press U
		if (ch == 'U' || ch == 'u') return 6;

		//Press I
		if (ch == 'I' || ch == 'i') return 7;

		if (ch == -32) {						// Arrow
			ch = _getch();

			if (ch == 72) return 1;			// Up
			if (ch == 75) return 2;			// Left
			if (ch == 80) return 3;			// Down
			if (ch == 77) return 4;			// Right
		}

		// WASD Keys
		if (ch == 'W' || ch == 'w') return 1;
		if (ch == 'A' || ch == 'a') return 2;
		if (ch == 'S' || ch == 's') return 3;
		if (ch == 'D' || ch == 'd') return 4;
	}
}
void drawSquare(int i, int j, int x, int y, int color) {
	x = (x - 1) * 2 + 1;
	setPos(x + i, y + j);
	setColor(color, color);
	cout << "  ";
	setColor(15, 15);
}

void txtDraw(int x, int y, const string& nameFile) {
	ifstream file(nameFile.c_str());
	string s;
	int i = 0;
	while (getline(file, s))
	{
		i++;
		stringstream ss(s);
		int j = 0;
		while (!ss.eof())
		{
			j++;
			int color;
			ss >> color;
			drawSquare(x, y, j, i, color);
		}
	}
}
void draw_square(int i, int j, int x, int y, int color) {
	x = (x - 1) * 2 + 1;
	setPos(x + i, y + j);
	setColor(color, color);
	cout << "  ";
	setColor(15, 15);
}

void decorate_draw(int x, int y, const string& nameFile) {
	ifstream file(nameFile.c_str());
	string s;
	int i = 0;
	while (getline(file, s))
	{
		i++;
		stringstream ss(s);
		int j = 0;
		while (!ss.eof())
		{
			j++;
			int color;
			ss >> color;
			draw_square(x, y, j, i, color);
		}
	}
}