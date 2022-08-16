#pragma once
#include "Lcd.h"
#include "font.cpp"


void LCD::SetCursorPos(int x, int y)
{
	if (x <= 17 && x >= 0 && y >= 0 && y <= 7) {
	if (CursorState) {
		DelCharacter(CursorPos.x * 7, CursorPos.y * 8);
		DrawCharacter(CursorPos.x * 7, CursorPos.y * 8, SaveSpace);
		SaveSpace = ch_NULL;
	}
		CursorPos.x = x;
		CursorPos.y = y;
		CursorState = false;
	}
}

sf::Vector2i LCD::GetCursorPos() {
	return CursorPos;

}

void LCD::UpdateCursor() {
	if (CursorClock.getElapsedTime().asMilliseconds() >= 500) {
		if (CursorState) {
			DelCharacter(CursorPos.x * 7, CursorPos.y * 8);
			DrawCharacter(CursorPos.x*7, 0, SaveSpace);
		}
		if(!CursorState) {
			SaveSpace = GetCharacterOnScreen(CursorPos.x, CursorPos.y);
			DrawCharacter(CursorPos.x*7, CursorPos.y* 8, 219);
		}
		CursorState = !CursorState;
		CursorClock.restart();
	}
}

void LCD::Inicialize(sf::Vector2i pos, int pixelScale, sf::Vector2i countPixel, sf::RenderWindow* _window)
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

	//==================
	FontTable[219] = ch_FullBlock;
	FontTable[0] = ch_NULL;
}

int* LCD::GetBits(unsigned int num)
{
	int bits[8];
	int count = 0;
	for (int i = 128; i > 0; i = i / 2) {
		if (num & i)
			bits[count] = 1;
		else
			bits[count] = 0;

		count++;
	}
	return bits;
}

bool LCD::GetPixel(int x, int y)
{
	return screen[x + y * With].active;
}

void LCD::Update()
{
	sf::RectangleShape fon(sf::Vector2f(ScreenSizeX, ScreenSizeY));
	fon.setPosition(ScreenPos.x, ScreenPos.y);
	fon.setFillColor(sf::Color(50, 50, 50));

	window->draw(fon);

	UpdateCursor();


	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < With; j++) {
			if (LCD::screen[j + i * With].active) {
				sf::RectangleShape rectangle(sf::Vector2f(8, 8));
				rectangle.setPosition((j * 8) + ScreenPos.x, (i * 8) + ScreenPos.y);
				rectangle.setFillColor(sf::Color::Green);
				window->draw(rectangle);
			}
		}
	}

	//Cursor Update
	//sf::Int32 msec = time.asMilliseconds();
}

void LCD::Clear()
{
	for (int i = 0; i < With * Height; i++) {
		screen[i].active = false;
	}
}

Character LCD::GetCharacterByID(int id)
{
	return FontTable[id];
}

void LCD::DrawCharacter(int x, int y, Character _char)
{
	for (int i = 0; i < 8; i++) {
		int* line = new int[8];
		line = GetBits(_char.character[i]);
		for (int j = 0; j < 8; j++) {
			if (line[j] == 1) {
				screen[((x + 2+ j)) + ((y + i) * With)].active = true;//x+y*With
			}
		}
	}
}

void LCD::DrawCharacter(int x, int y, int _char)
{
	Character temp = GetCharacterByID(_char);
	for (int i = 0; i < 8; i++) {
		int* line = new int[8];
		line = GetBits(temp.character[i]);
		for (int j = 0; j < 8; j++) {
			if (line[j] == 1) {
				screen[((x + 2 + j)) + ((y + i) * With)].active = true;
			}
			//x+y*With
		}
	}
}

void LCD::DelCharacter(int x, int y)
{
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {

				screen[((x +2 +   j)) + ((y + i) * With)].active = false;
			
			//x+y*With
		}
	}
}





void LCD::PrintCharacter(int _char, int x, int y)
{
	DrawCharacter(x * 7, y * 8, _char);
}

void LCD::PrintString(std::string line, int y)
{
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != '\0' || line[i] != '\n' || line[i] != ' ') {
			DrawCharacter(i * 7, y * 8, (int)line[i]);
		}
	}
}

Character LCD::GetCharacterOnScreen(int x, int y)
{
	Character temp{ 0,0,0,0,0,0,0,0 };
	for (int i = y * 8; i < y * 8 + 8; i++) {
		int z = 8;
		for (int ii = x*7 + 1; ii < x * 7 + 8; ii++) {
			if (GetPixel(ii, i)) {
				temp.character[i] = temp.character[i] + pow(2, z);
			}
			z--;
		}
	}
	return temp;
}

void LCD::Dot(int x, int y)
{
	screen[x + y * With].active = true;
}


void LCD::InvertScreen()
{
	for (int i = 0; i < With * Height; i++) {
		screen[i].active = !screen[i].active;
	}
}



void LCD::Line(sf::Vector2i start, sf::Vector2i end) {
	double dx = abs(end.x - start.x);
	double sx = start.x < end.x ? 1 : -1;
	double dy = -abs(end.y - start.y);
	double sy = start.y < end.y ? 1 : -1;
	double error = dx + dy;

	while (true){
		Dot(start.x, start.y);
		if (start.x == end.x && start.y == end.y) { break; }
		double e2 = 2 * error;
		if (e2 >= dy) {
			if (start.x == end.x) { break; }
			error = error + dy;
			start.x = start.x + sx;
		}
		if (e2 <= dx) {
			if (start.y == end.y){ break; }
			error = error + dx;
			start.y = start.y + sy;
		}
	}
}

void LCD::Circle(sf::Vector2i pos, int r)
{
	int x1, y1, yk = 0;
	int sigma, delta, f;

	x1 = 0;
	y1 = r;
	delta = 2 * (1 - r);

	do
	{
		Dot(pos.x + x1, pos.y + y1);
		Dot(pos.x - x1, pos.y + y1);
		Dot(pos.x + x1, pos.y - y1);
		Dot(pos.x - x1, pos.y - y1);

		f = 0;
		if (y1 < yk)
			break;
		if (delta < 0)
		{
			sigma = 2 * (delta + y1) - 1;
			if (sigma <= 0)
			{
				x1++;
				delta += 2 * x1 + 1;
				f = 1;
			}
		}
		else
			if (delta > 0)
			{
				sigma = 2 * (delta - x1) - 1;
				if (sigma > 0)
				{
					y1--;
					delta += 1 - 2 * y1;
					f = 1;
				}
			}
		if (!f)
		{
			x1++;
			y1--;
			delta += 2 * (x1 - y1 - 1);
		}
	} while (1);
}

void LCD::Rectangle(sf::Vector2i start, sf::Vector2i end)
{
	Line(sf::Vector2i(start.x, start.y), sf::Vector2i(end.x, start.y));
	Line(sf::Vector2i(end.x, start.y), sf::Vector2i(end.x, end.y));
	Line(sf::Vector2i(start.x, start.y), sf::Vector2i(start.x, end.y));
	Line(sf::Vector2i(start.x, end.y), sf::Vector2i(end.x, end.y));
}
