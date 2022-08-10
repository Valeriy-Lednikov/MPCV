
#pragma once
#include "Global.h"
//#include "Chars.h"


class LCD {
	int CharSize = 5;
	int SpaceSize = 1;

	ScreenSpace lcdSpace;
public:

	int* get_bits(int n, int bitswanted);
	void InicializeFont();
	int* GetBits(unsigned int num);
	—haracter GetCharacter(int id);
	void Draw—haracter(int x, int y, —haracter _char);
	void Draw—haracter(int x, int y, int _char);
	void PrintString(std::string line, int y);
	void AddString(std::string line, int y);
	void Clear();

	
	//void UpdateLCD(int mode) {
	//	//mode 0 - string
	//	//mode 1 - pixel
	//	//mode 2 - combinate
	//	
	//	for (int i = 0; i < 8; i++) {
	//		PrintString(lcdSpace.line[i], i);
	//	}
	//}
};



