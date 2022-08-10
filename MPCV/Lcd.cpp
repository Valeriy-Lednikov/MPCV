#pragma once
#include "Lcd.h"
#include "font.cpp"


void LCD::Inicialize(sf::Vector2i pos, int pixelScale, sf::Vector2i countPixel, sf::RenderWindow*_window)
{
	window = _window;
	ScreenPos = pos;
	screen = new Cell[With * Height];
	LCD::InicializeFont();
}

void LCD::InicializeFont()
{
	FontTable[65] = ch_A;
	FontTable[66] = ch_B;
	FontTable[67] = ch_C;
	FontTable[68] = ch_D;
	FontTable[69] = ch_E;
	FontTable[70] = ch_F;
	FontTable[71] = ch_G;
	FontTable[72] = ch_H;
	FontTable[73] = ch_I;
	FontTable[74] = ch_J;
	FontTable[75] = ch_K;
	FontTable[76] = ch_L;
	FontTable[77] = ch_M;
	FontTable[78] = ch_N;
	FontTable[79] = ch_O;
	FontTable[80] = ch_P;
	FontTable[81] = ch_Q;
	FontTable[82] = ch_R;
	FontTable[83] = ch_S;
	FontTable[84] = ch_T;
	FontTable[85] = ch_U;
	FontTable[86] = ch_V;
	FontTable[87] = ch_W;
	FontTable[88] = ch_X;
	FontTable[89] = ch_Y;
	FontTable[90] = ch_Z;

	//==================
	FontTable[97] = ch_a;
	FontTable[98] = ch_b;
	FontTable[99] = ch_c;
	FontTable[100] = ch_d;
	FontTable[101] = ch_e;
	FontTable[102] = ch_f;
	FontTable[103] = ch_g;
	FontTable[104] = ch_h;
	FontTable[105] = ch_i;
	FontTable[106] = ch_j;
	FontTable[107] = ch_k;
	FontTable[108] = ch_l;
	FontTable[109] = ch_m;
	FontTable[110] = ch_n;
	FontTable[111] = ch_o;
	FontTable[112] = ch_p;
	FontTable[113] = ch_q;
	FontTable[114] = ch_r;
	FontTable[115] = ch_s;
	FontTable[116] = ch_t;
	FontTable[117] = ch_u;
	FontTable[118] = ch_v;
	FontTable[119] = ch_w;
	FontTable[120] = ch_x;
	FontTable[121] = ch_y;
	FontTable[122] = ch_z;

	//==================
	FontTable[48] = ch_0;
	FontTable[49] = ch_1;
	FontTable[50] = ch_2;
	FontTable[51] = ch_3;
	FontTable[52] = ch_4;
	FontTable[53] = ch_5;
	FontTable[54] = ch_6;
	FontTable[55] = ch_7;
	FontTable[56] = ch_8;
	FontTable[57] = ch_9;

	//==================

	FontTable[33] = ch_Exclamation;
	FontTable[63] = ch_Question;
}

void LCD::Update()
{
	sf::RectangleShape fon(sf::Vector2f(ScreenSizeX, ScreenSizeY));
	fon.setPosition(0, 0);
	fon.setFillColor(sf::Color(50, 50, 50));
	
	window->draw(fon);

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < With; j++) {
			if (LCD::screen[j + i * With].active) {
				sf::RectangleShape rectangle(sf::Vector2f(8, 8));
				rectangle.setPosition(j * 8, i * 8);
				rectangle.setFillColor(sf::Color::Green);
				window->draw(rectangle);
			}
		}
	}
}






//int* LCD::get_bits(int n, int bitswanted) {
//	int* bits = (int*)malloc(sizeof(int) * bitswanted);
//
//	int k;
//	for (k = 0; k < bitswanted; k++) {
//		int mask = 1 << k;
//		int masked_n = n & mask;
//		int thebit = masked_n >> k;
//		bits[k] = thebit;
//	}
//
//	return bits;
//}
//
//
//
//
//Ñharacter FontTable[127];
//
//
//
//
//void LCD::InicializeFont() {
//	FontTable[65] = ch_A;
//	FontTable[66] = ch_B;
//	FontTable[67] = ch_C;
//	FontTable[68] = ch_D;
//	FontTable[69] = ch_E;
//	FontTable[70] = ch_F;
//	FontTable[71] = ch_G;
//	FontTable[72] = ch_H;
//	FontTable[73] = ch_I;
//	FontTable[74] = ch_J;
//	FontTable[75] = ch_K;
//	FontTable[76] = ch_L;
//	FontTable[77] = ch_M;
//	FontTable[78] = ch_N;
//	FontTable[79] = ch_O;
//	FontTable[80] = ch_P;
//	FontTable[81] = ch_Q;
//	FontTable[82] = ch_R;
//	FontTable[83] = ch_S;
//	FontTable[84] = ch_T;
//	FontTable[85] = ch_U;
//	FontTable[86] = ch_V;
//	FontTable[87] = ch_W;
//	FontTable[88] = ch_X;
//	FontTable[89] = ch_Y;
//	FontTable[90] = ch_Z;
//
//	//==================
//	FontTable[97] = ch_a;
//	FontTable[98] = ch_b;
//	FontTable[99] = ch_c;
//	FontTable[100] = ch_d;
//	FontTable[101] = ch_e;
//	FontTable[102] = ch_f;
//	FontTable[103] = ch_g;
//	FontTable[104] = ch_h;
//	FontTable[105] = ch_i;
//	FontTable[106] = ch_j;
//	FontTable[107] = ch_k;
//	FontTable[108] = ch_l;
//	FontTable[109] = ch_m;
//	FontTable[110] = ch_n;
//	FontTable[111] = ch_o;
//	FontTable[112] = ch_p;
//	FontTable[113] = ch_q;
//	FontTable[114] = ch_r;
//	FontTable[115] = ch_s;
//	FontTable[116] = ch_t;
//	FontTable[117] = ch_u;
//	FontTable[118] = ch_v;
//	FontTable[119] = ch_w;
//	FontTable[120] = ch_x;
//	FontTable[121] = ch_y;
//	FontTable[122] = ch_z;
//
//	//==================
//	FontTable[48] = ch_0;
//	FontTable[49] = ch_1;
//	FontTable[50] = ch_2;
//	FontTable[51] = ch_3;
//	FontTable[52] = ch_4;
//	FontTable[53] = ch_5;
//	FontTable[54] = ch_6;
//	FontTable[55] = ch_7;
//	FontTable[56] = ch_8;
//	FontTable[57] = ch_9;
//
//	//==================
//
//	FontTable[33] = ch_Exclamation;
//	FontTable[63] = ch_Question;
//}
//
//int* LCD::GetBits(unsigned int num)
//{
//	int bits[8];
//	int count = 0;
//	for (int i = 128; i > 0; i = i / 2) {
//		if (num & i)
//			bits[count] = 1;
//		else
//			bits[count] = 0;
//
//		count++;
//	}
//	return bits;
//}
//
//Ñharacter LCD::GetCharacter(int id) {
//	return FontTable[id];
//}
//
//void LCD::DrawÑharacter(int x, int y, Ñharacter _char) {
//	for (int i = 0; i < 8; i++) {
//		int* line = new int[8];
//		line = GetBits(_char.Ñharacter[i]);
//		for (int j = 0; j < 8; j++) {
//			if (line[j] == 1) {
//				screen[((x + j)) + ((y + i) * With)].active = true;
//			}
//
//
//			//x+y*With
//		}
//	}
//}
//
//void LCD::DrawÑharacter(int x, int y, int _char) {
//	Ñharacter temp = GetCharacter(_char);
//	for (int i = 0; i < 8; i++) {
//		int* line = new int[8];
//		line = GetBits(temp.Ñharacter[i]);
//		for (int j = 0; j < 8; j++) {
//			if (line[j] == 1) {
//				screen[((x + 2 + j)) + ((y + i) * With)].active = true;
//			}
//			//x+y*With
//		}
//	}
//}
//
//void LCD::PrintString(std::string line, int y) {
//	for (int i = 0; i < line.length(); i++) {
//		if (line[i] != '\0' || line[i] != '\n' || line[i] != ' ') {
//			DrawÑharacter(i * 7, y * 8, (int)line[i]);
//		}
//	}
//}
//
//void LCD::AddString(std::string line, int y) {
//	lcdSpace.line[y] = line;
//}
//
//
//void LCD::Clear() {
//	for (int i = 0; i < With * Height; i++) {
//		screen[i].active = false;
//	}
//}


