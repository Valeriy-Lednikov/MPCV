#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Global.h"
#include <stack>
//#include "MPCV.cpp"

//fon = 192,192,192
//button up, lite fon = 255 255 255
//button un, dark fon = 128 128 128
//button down, lite fon = 128 128 128
//button down, dark fon = 255 255 255
//

class Component
{
public:
	sf::Vector2i Position = sf::Vector2i(0, 0);
	sf::Vector2i Size = sf::Vector2i(0, 0);
	bool Active = true;
	bool Visible = true;
	int Id;


	Component(sf::Vector2i position, sf::Vector2i size, bool isActive, bool isVisible, int id) {
		Position = position;
		Size = size;
		Active = isActive;
		Visible = isVisible;
		Id = id;
	}
	virtual void draw() {}
	virtual ~Component() = default;
};


class Button : public Component
{
public:
	void draw() {

		sf::RectangleShape fon(sf::Vector2f(Size.x, Size.y));
		fon.setPosition(Position.x, Position.y);
		fon.setFillColor(sf::Color(0, 0, 0));
		_window->draw(fon);

		fon = sf::RectangleShape(sf::Vector2f(Size.x-4, Size.y-4));
		fon.setPosition(Position.x+3, Position.y+3);
		fon.setFillColor(sf::Color(88, 56, 48));
		_window->draw(fon);

		sf::Color ColorA = sf::Color(255, 255, 255);
		sf::Color ColorB = sf::Color(128, 128, 128);
		if (state) {
			ColorB = sf::Color(255, 255, 255);
			ColorA = sf::Color(128, 128, 128);
		}


		sf::RectangleShape line;
		line = sf::RectangleShape(sf::Vector2f(Size.x - 2, 1)); //Up Up Up
		line.setFillColor(ColorA);
		line.setPosition(Position.x + 1, Position.y + 1);
		_window->draw(line);

		line = sf::RectangleShape(sf::Vector2f(Size.y - 2, 1)); //left Up Up
		line.setFillColor(ColorA);
		line.setPosition(Position.x + 2, Position.y + 1);
		line.rotate(90);
		_window->draw(line);

		line = sf::RectangleShape(sf::Vector2f(Size.x - 4, 1)); //Up down Up
		line.setFillColor(ColorA);
		line.setPosition(Position.x + 2, Position.y + 2);
		_window->draw(line);

		line = sf::RectangleShape(sf::Vector2f(Size.y - 4, 1)); //left down Up
		line.setFillColor(ColorA);
		line.setPosition(Position.x + 3, Position.y + 2);
		line.rotate(90);
		_window->draw(line);

		////////////////////////////////////////////////////////////////////////////////////

		line = sf::RectangleShape(sf::Vector2f(Size.x - 3, 1));
		line.setFillColor(ColorB);
		line.setPosition(Position.x - 1 + Size.x, Position.y - 1 + Size.y);
		line.rotate(180);
		_window->draw(line);

		line = sf::RectangleShape(sf::Vector2f(Size.x - 5, 1));
		line.setFillColor(ColorB);
		line.setPosition(Position.x - 2 + Size.x, Position.y - 2 + Size.y);
		line.rotate(180);
		_window->draw(line);



		line = sf::RectangleShape(sf::Vector2f(Size.y - 3, 1));
		line.setFillColor(ColorB);
		line.setPosition(Position.x - 2 + Size.x, Position.y - 1 + Size.y);
		line.rotate(270);
		_window->draw(line);


		line = sf::RectangleShape(sf::Vector2f(Size.y - 4, 1));
		line.setFillColor(ColorB);
		line.setPosition(Position.x - 3 + Size.x, Position.y - 1 + Size.y);
		line.rotate(270);
		_window->draw(line);



	}
	Button(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window, int id) :Component(position, size, true, true, id) {
		_window = window;
	}

	bool state = false;
private:
	
	sf::RenderWindow* _window;
};


class Form
{
private:
	sf::Vector2i FormPosition = sf::Vector2i(0, 0);
	sf::Vector2i FormSize = sf::Vector2i(0, 0);
	sf::Color BackgroundColor = sf::Color(192);

	sf::RenderWindow* Window;

	std::vector<Component*> Components;

	bool PointInRect(sf::Vector2i point, sf::Vector2i rectA, sf::Vector2i rectB);

public:
	std::stack<int> event;


	void Inicialize(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window);

	void Update();

	int GetEvent() {
		int t = -1;
		if (!event.empty()) {
			t = event.top();
			event.pop();
		}
		return t;
	}


	void CreateButton(sf::Vector2i Position, sf::Vector2i Size, int id) {
		Components.push_back(new Button(Position + FormPosition, Size, Window, id));
	}




};

