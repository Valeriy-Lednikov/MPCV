// MPCV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <bitset>
#include <vector>
using namespace sf;

#include "Lcd.h"

Color foneColor = Color(239, 245, 184);



RenderWindow window(VideoMode(1400, 800), "MPCV");

#include "Global.h"

LCD lcd();

void UpdateScreen() {

	sf::RectangleShape fon(sf::Vector2f(ScreenSizeX, ScreenSizeY));
	fon.setPosition(0, 0);
	fon.setFillColor(Color(50, 50, 50));
	window.draw(fon);

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < With; j++) {
			if (screen[j + i * With].active) {
				sf::RectangleShape rectangle(sf::Vector2f(8, 8));
				rectangle.setPosition(j * 8, i * 8);
				rectangle.setFillColor(Color::Green);
				window.draw(rectangle);

				sf::RectangleShape rectangle1(sf::Vector2f(6, 6));
				rectangle1.setPosition(j * 8 + 1, i * 8 + 1);
				rectangle1.setFillColor(Color::Green);
				window.draw(rectangle1);
			}
		}
	}
}

int main()
{
	std::cout << (int)'?' << std::endl;

	lcd().InicializeFont();


	lcd().PrintString("ABCDEFGHIJKLMNOPQR", 0);
	lcd().PrintString("STUVWXYZ", 1);
	lcd().PrintString("abcdefghijklmnopqr", 2);
	lcd().PrintString("stuvwxyz", 3);
	lcd().PrintString("! ?", 4);
	lcd().PrintString("0123456789", 5);
	lcd().PrintString("0123456789", 6);
	lcd().PrintString("0123456789", 7);

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
					lcd().PrintString("ABCDEFGHIJKLMNOPQR", 0);
					lcd().PrintString("STUVWXYZ", 1);
					lcd().PrintString("abcdefghijklmnopqr", 2);
					lcd().PrintString("stuvwxyz", 3);
					lcd().PrintString("! ?", 4);
					lcd().PrintString("0123456789", 5);
					lcd().PrintString("0123456789", 6);
					lcd().PrintString("0123456789", 7);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					lcd().Clear();
				}
			}
		}
		window.clear(Color(239, 245, 184));
		UpdateScreen();





		// Отрисовка окна	
		window.display();
	}

	return 0;
}