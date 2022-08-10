// MPCV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <bitset>
#include <vector>
using namespace sf;

#include "Lcd.h"

Color foneColor = Color(239, 245, 184);



RenderWindow window(VideoMode(1400, 800), "MPCV");
LCD lcd;



int main()
{
	lcd.Inicialize(sf::Vector2i(0, 0), 8, sf::Vector2i(128, 64), &window);
	std::cout << (int)'?' << std::endl;

	/*lcd().InicializeFont();


	lcd().PrintString("ABCDEFGHIJKLMNOPQR", 0);
	lcd().PrintString("STUVWXYZ", 1);
	lcd().PrintString("abcdefghijklmnopqr", 2);
	lcd().PrintString("stuvwxyz", 3);
	lcd().PrintString("! ?", 4);
	lcd().PrintString("0123456789", 5);
	lcd().PrintString("0123456789", 6);
	lcd().PrintString("0123456789", 7);*/

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				if (event.key.code == sf::Keyboard::W)
				{
					lcd.PrintString("ABCDEFGHIJKLMNOPQR", 0);
					lcd.PrintString("STUVWXYZ", 1);
					lcd.PrintString("abcdefghijklmnopqr", 2);
					lcd.PrintString("stuvwxyz", 3);
					lcd.PrintString("! ?", 4);
					lcd.PrintString("0123456789", 5);
					lcd.PrintString("0123456789", 6);
					lcd.PrintString("0123456789", 7);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					lcd.Clear();
				}
			}
		}
		window.clear(Color(239, 245, 184));
		lcd.Update();




		// Отрисовка окна	
		window.display();
	}

	return 0;
}