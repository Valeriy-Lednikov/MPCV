// MPCV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#pragma once
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <bitset>
#include <vector>
#include <Windows.h>
using namespace sf;

#include "Lcd.h"
#include "font.h"

#include "Form.h"



static sf::RenderWindow renderWindow(sf::VideoMode(1400, 800), "MPCV");


Color foneColor = Color(239, 245, 184);

LCD lcd;
Form form;


int main()
{

	

	lcd.Inicialize(sf::Vector2i(0, 0), 8, sf::Vector2i(128, 64), &renderWindow);
	//std::cout << (int)'█' << std::endl;
	form.Inicialize(sf::Vector2i(1024, 0), sf::Vector2i(1440-1024, 512), &renderWindow);

	form.CreateButton(sf::Vector2i(10, 50), sf::Vector2i(40, 30), 0);
	form.CreateButton(sf::Vector2i(60, 50), sf::Vector2i(40, 30), 1);
	form.CreateButton(sf::Vector2i(110, 50), sf::Vector2i(40, 30), 2);
	form.CreateButton(sf::Vector2i(60, 10), sf::Vector2i(40, 30), 3);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (renderWindow.isOpen())
	{

		Event event;
		while (renderWindow.pollEvent(event))
		{

			if (event.type == Event::Closed)
				renderWindow.close();
			if (event.type == Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape)
				{
					renderWindow.close();
				}
				if (event.key.code == sf::Keyboard::W)
				{
					//form.A();
				}
				if (event.key.code == sf::Keyboard::D)
				{
					lcd.InvertScreen();
				}
				if (event.key.code == sf::Keyboard::F)
				{
					lcd.PrintString("ABCDEFGHIJKLMNOPQR", 0);
					lcd.Circle(sf::Vector2i(60, 20), 10);
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
		renderWindow.clear(Color(239, 245, 184));
		//renderWindow.clear();
		lcd.Update();

		int a = form.GetEvent();
		if (a != -1) {
			std::cout << a;
			if (a == 3) {
				lcd.SetCursorPos(lcd.GetCursorPos().x, lcd.GetCursorPos().y - 1);
			}
			if (a == 0) {
				lcd.SetCursorPos(lcd.GetCursorPos().x - 1, lcd.GetCursorPos().y);
			}
			if (a == 1) {
				lcd.SetCursorPos(lcd.GetCursorPos().x, lcd.GetCursorPos().y + 1);
			}
			if (a == 2) {
				lcd.SetCursorPos(lcd.GetCursorPos().x + 1, lcd.GetCursorPos().y);
			}

		}


		form.Update();
		renderWindow.display();

		
	}

	return 0;
}