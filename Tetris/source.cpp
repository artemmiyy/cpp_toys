#include <iostream>
#include <windows.h>

// there are 7 tetromino pieces
std::wstring tetromino[7];

// size of the tetris playing field
int playfield_w = 12;
int playfield_h = 18;


int windows_screen_w = 80;
int windows_screen_h = 30;

// for storing elements of the field
unsigned char *playfield = nullptr;

int rotate(int x_coord, int y_coord, int r) {
	switch (r % 4)
	{	// get indices from the array
		case 0: return y_coord * 4 + x_coord;        // 0 deg rotation
		case 1: return 12 + y_coord - (x_coord * 4); // 90 deg rotation
		case 2: return 15 - (y_coord * 4) - x_coord; // 180 deg rotation
		case 3: return 3 - y_coord + (x_coord * 4);  // 270 deg rotation
	}
	return 0;
}

int main() {
	// creating shapes
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");

	// initalize array for the playfield
	playfield = new unsigned char[playfield_w * playfield_h];
	// playfield boundary
	for (int x = 0; x < playfield_w; x++)
		for (int y = 0; y < playfield_h; y++)
			playfield[y * playfield_w + x] = (x == 0 || x == playfield_w - 1
			|| y == playfield_h - 1) ? 8 : 0; // 8 represents border

	wchar_t *screen = new wchar_t[windows_screen_w * windows_screen_h];
	// fill the screen with empty space
	for (int i = 0; i < windows_screen_w * windows_screen_h; i++) screen[i] = L' ';
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE | 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(console);

	return 0;
}
