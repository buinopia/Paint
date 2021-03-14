#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

int x = 4 / 2, y = 4 / 2;
bool onplay = true;
bool onspawn = false;
bool onclick = true;
string obj = " ";
int func = 1;
int index = 0;
int xp, yp;

char map[16][16] = {
		"####Welcome!###",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"#             #",
		"###############",
};

char player[4][4] = {
	"020",
	"202",
	"020",
};

void draw() {

	ofstream image;

	image.open("img.txt");

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (i == x - 0 && j == y) {
				cout << char(-7);
			}
			else
			{
				cout << map[i][j];
				image << map[i][j];
				if (obj.capacity() == 15 && onspawn == true && func == 1) {
					map[x][y] = char(index);
					onspawn = false;
				}
				if (obj.capacity() == 15 && onspawn == true && func == 2) {
					map[x][y] = char(32);
					onspawn = false;
				}
			}
		}
		cout << " " << endl;
		image << "\n" << endl;
	}
	if (_kbhit() && onclick == true) {
		switch (_getch())
		{

		case 'w':
			x--;
			break;

		case 's':
			x++;
			break;

		case 'a':
			y--;
			break;

		case 'd':
			y++;
			break;
		case 'f':
			onspawn = true;
			break;
		case 'r':
			func++;
			break;
		case 'q':
			index--;
			break;
		case 'e':
			index++;
			break;
		default:
			break;
		}
	}
	switch (func) {
	case 3:
		func = 1;
		break;
	}
	if (x == 16) x = 0;
	if (y == 15) y = 0;
	if (x == -1) x = 15;
	if (y == -1) y = 14;
	
	image.close();
}

int main() {
	while (onplay == true) {
		cout << char(index);
		obj = map[x][y];
		cout << func;
		Sleep(15);
		system("cls");
		draw();
	}
}