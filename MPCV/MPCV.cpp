// MPCV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <bitset>
#include <vector>
#include <Windows.h>
using namespace sf;

#include "Lcd.h"


#include "font.h"

Color foneColor = Color(239, 245, 184);
RenderWindow window(VideoMode(1400, 800), "MPCV");
LCD lcd;



int main()
{
	lcd.Inicialize(sf::Vector2i(200, 100), 8, sf::Vector2i(128, 64), &window);
	//std::cout << (int)'█' << std::endl;


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (window.isOpen())
	{
		lcd.PrintString("ABCDEFGHIJKLMNOPQR", 0);
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				if (event.key.code == sf::Keyboard::Numpad8)
				{
					lcd.SetCursorPos(lcd.GetCursorPos().x, lcd.GetCursorPos().y - 1);
				}
				if (event.key.code == sf::Keyboard::Numpad2)
				{
					lcd.SetCursorPos(lcd.GetCursorPos().x, lcd.GetCursorPos().y + 1);
				}
				if (event.key.code == sf::Keyboard::Numpad4)
				{
					lcd.SetCursorPos(lcd.GetCursorPos().x -1, lcd.GetCursorPos().y);
				}
				if (event.key.code == sf::Keyboard::Numpad6)
				{
					lcd.SetCursorPos(lcd.GetCursorPos().x + 1, lcd.GetCursorPos().y);
				}

			}
		}
		window.clear(Color(239, 245, 184));
		lcd.Update();
		window.display();
	}

	return 0;
}