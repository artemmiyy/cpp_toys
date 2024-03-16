#include <iostream>

// there are 7 tetromino pieces
std::wstring tetromino[7];

int rotation(int px, int py, int r) {
	switch (r % 4)
	{
		case 0: return py * 4 + px;        // 0 deg rotation
		case 1: return 12 + py - (px * 4); // 90 deg rotation
		case 2: return 15 - (py * 4) - px; // 180 deg rotation
		case 3: return 3 - py + (px * 4);  // 270 deg rotation
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

	return 0;
}