#include "Library.h"
#include "Graphic.h"
#include "Language.h"

#define gameTheme 15, 0

void about(int Xi, int Yi) {
	system("cls");
	//drawAboutText();
	int XX = Xi - 6, YY = Yi + 1;

	setPos(XX + 4, YY + 3);      cout << (*selectedLanguage)["HCMUS - 24CTT3 - Group 2:"];
	setPos(XX + 2, YY + 11); cout << (*selectedLanguage)["Lecturer: Dr.Truong Toan Thinh"];

	setColor(gameTheme);
	setPos(XX, YY + 5); cout << "24120240 - Vo Lan Tuan";
	setPos(XX, YY + 6); cout << "24120267 - Tran Huynh Gia Bao";
	setPos(XX, YY + 7); cout << "24120249 - Vo Nguyen Viet Hoang";
	setPos(XX, YY + 8); cout << "24120270 - Do Chi Cao";
	setPos(XX, YY + 9); cout << "24120238 - Pham Anh Tuan";

	decorate_draw_overlap(XX - 40, YY, "ARTS/amongus2.txt", 0);
	decorate_draw_overlap(XX - 50, YY + 4, "ARTS/amongus2-1.txt", 0);
	decorate_draw_overlap(XX - 33, YY + 7, "ARTS/amongus2-2.txt", 0);

	decorate_draw_overlap(XX + 40, YY + 2, "ARTS/amongus2_reversed.txt", 1);
	decorate_draw_overlap(XX + 50, YY + 6, "ARTS/amongus2_reversed-1.txt", 1);

	setColor(11, 0);
	setPos(XX + 5, YY + 13); cout << (*selectedLanguage)["<< Press ESC to exit >>"];
	setColor(gameTheme);

	while (isNextMove() != 5);
}