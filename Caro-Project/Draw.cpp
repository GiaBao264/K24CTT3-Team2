#include "Library.h"
#include "Console.h"

void drawA(int XX, int YY, int bground, int fground) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawB(int XX, int YY, int bground, int fground) { // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 4);
	setColor(fground, fground); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawC(int XX, int YY, int bground, int fground) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground);  cout << "  ";
	setColor(bground, fground);
	cout << char(201);
	for (int i = 1; i <= 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground);  cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground);  cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground);  cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawD(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	for (int i = 2; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(fground, fground); cout << "  ";
		setColor(bground, fground); cout << char(186) << "  ";
		setColor(fground, fground); cout << "  ";
		setColor(bground, fground); cout << char(186);
	}

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawE(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205) << char(188);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawF(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205) << char(188);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawG(int XX, int YY, int bground, int fground) {  // 6 * 9
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawH(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawI(int XX, int YY, int bground, int fground) {  // 6 * 3
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawJ(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX + 3, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX + 3, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX + 3, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX + 3, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);
}

void drawK(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(201) << char(205) << char(188);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawL(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	for (int i = 1; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(fground, fground); cout << "  ";
		setColor(bground, fground); cout << char(186);
	}

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawM(int XX, int YY, int bground, int fground) {  // 6 * 11
	setPos(XX, YY);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(187) << "   ";
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(187) << " ";
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(201);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << char(200);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << " " << char(200) << char(205) << char(188) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "     " << char(200) << char(205) << char(188);
}

void drawN(int XX, int YY, int bground, int fground) {  // 6 * 10
	setPos(XX, YY);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(187) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(187) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << char(200);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << " " << char(200);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200);
	for (int i = 0; i < 3; ++i) cout << char(205);
	cout << char(188);
}

void drawO(int XX, int YY, int bground, int fground) { // 6 * 9
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
	setColor(bground, fground);
}

void drawP(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205) << char(205) << char(188);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawQ(int XX, int YY, int bground, int fground) {  // 6 * 9
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(201) << char(205) << char(187);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(205) << char(188);
}

void drawR(int XX, int YY, int bground, int fground) { // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawS(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX + 1, YY);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX + 1, YY + 3);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
	setPos(XX + 6, YY + 3); setColor(fground, fground); cout << "  ";
	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(187);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawT(int XX, int YY, int bground, int fground) { // 6 * 9
	setPos(XX, YY);
	setColor(fground, fground);  cout << "        ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		setPos(XX + 3, YY + 2 + i);
		setColor(fground, fground); cout << "  ";
		setColor(bground, fground); cout << char(186);
	}

	setPos(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawU(int XX, int YY, int bground, int fground) { // 6 * 9
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "      ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawV(int XX, int YY, int bground, int fground) {  // 6 * 9
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	cout << char(200);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 4);
	cout << char(200);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 2, YY + 5);
	cout << char(200) << char(205) << char(205) << char(205) << char(188);
}

void drawW(int XX, int YY, int bground, int fground) {  // 6 * 10
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "    ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "    ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << " ";
	setColor(fground, fground); cout << " ";
	setColor(bground, fground); cout << char(187) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(187);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 4);
	setColor(bground, fground); cout << char(200);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(201);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(188);
}

void drawX(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "  ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	cout << char(200);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 2);
	cout << " " << char(200);
	setColor(fground, fground); cout << "   ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	cout << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(201) << char(188) << " ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
	setColor(bground, fground);
}

void drawY(int XX, int YY, int bground, int fground) {  // 6 * 9
	setPos(XX, YY);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186) << "   ";
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX, YY + 2);
	cout << char(200);
	setColor(fground, fground); cout << "     ";
	setColor(bground, fground); cout << char(201) << char(188);

	setPos(XX + 3, YY + 3);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX + 3, YY + 4);
	setColor(fground, fground); cout << "  ";
	setColor(bground, fground); cout << char(186);

	setPos(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawZ(int XX, int YY, int bground, int fground) {  // 6 * 8
	setPos(XX, YY);
	setColor(fground, fground); cout << "       ";
	setColor(bground, fground); cout << char(187);

	setPos(XX, YY + 1);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);

	setPos(XX + 4, YY + 2);
	cout << char(201) << char(205) << char(188);

	setPos(XX + 2, YY + 3);
	cout << char(201) << char(205) << char(188);

	setPos(XX, YY + 4);
	cout << char(201) << char(205) << char(188);
	setColor(fground, fground); cout << "    ";
	setColor(bground, fground); cout << char(187);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}