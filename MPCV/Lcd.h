
#pragma once
#include "font.h"
#include <iostream>
#include <SFML/Graphics.hpp>


class LCD {
	int With = 128;
	int Height = 64;
	int ScreenSizeX = 1024;
	int ScreenSizeY = 512;
	int PixelSize = 8;

	sf::Vector2i ScreenPos;
	sf::RenderWindow *window;
	//************************************************
	struct ScreenSpace {std::string line[8];};
	struct Cell { bool active = false;};
	//************************************************
	Cell *screen; //[With * Height];
	ScreenSpace lcdSpace;
	—haracter FontTable[127];
	//************************************************
	void InicializeFont();
	int* GetBits(unsigned int num);



public:


	void Inicialize(sf::Vector2i pos, int pixelScale, sf::Vector2i countPixel, sf::RenderWindow* _window);
	void Update();
	void Clear();
	—haracter GetCharacter(int id);
	void Draw—haracter(int x, int y, —haracter _char);
	void Draw—haracter(int x, int y, int _char);
	void PrintString(std::string line, int y);
};



