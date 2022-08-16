
#pragma once
#include "font.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "MPCV.h"


class LCD {
	int With = 128;
	int Height = 64;
	int ScreenSizeX = 1024;
	int ScreenSizeY = 512;
	int PixelSize = 8;

	

	//************************************************
	bool CursorActive = true;
	bool CursorState = false;
	sf::Vector2i CursorPos = sf::Vector2i(1,0);
	sf::Int32 CursorTimer = 0;
	sf::Clock CursorClock;
	Character SaveSpace;
	//************************************************\

	sf::Vector2i ScreenPos;
	sf::RenderWindow *window;
	//************************************************
	struct ScreenSpace {std::string line[8];};
	struct Cell { bool active = false;};
	//************************************************
	Cell *screen; //[With * Height];
	ScreenSpace lcdSpace;
	Character FontTable[255];
	//************************************************
	void InicializeFont();
	int* GetBits(unsigned int num);
	bool GetPixel(int x, int y);
	void UpdateCursor();

public:

	void SetCursorPos(int x, int y);

	sf::Vector2i GetCursorPos();



	void Inicialize(sf::Vector2i pos, int pixelScale, sf::Vector2i countPixel, sf::RenderWindow* _window);
	void Update();
	void Clear();
	Character GetCharacterByID(int id); 
	void DrawCharacter(int x, int y, Character _char);
	void DrawCharacter(int x, int y, int _char);
	
	void DelCharacter(int x, int y);

	void PrintCharacter(int _char, int x, int y);
	void PrintString(std::string line, int y);

	Character GetCharacterOnScreen(int pos, int y);

	void Dot(int x, int y);
	void Line(sf::Vector2i start, sf::Vector2i end);

	void Circle(sf::Vector2i pos, int radius);
	void Rectangle(sf::Vector2i start, sf::Vector2i end);

	void InvertScreen();
};



