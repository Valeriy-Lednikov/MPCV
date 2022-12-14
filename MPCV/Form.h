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

		Text.setFont(font_Arial);
		Text.setCharacterSize(FontSize);
		sf::Vector2i Center = sf::Vector2i((Position.x + Size.x / 2), (Position.y + Size.y / 2));
		Center = sf::Vector2i(Center.x - Text.getGlobalBounds().width / 2, (Center.y - Text.getGlobalBounds().height / 2)-3);
		Text.setPosition(Center.x, Center.y);
		if (State) {
			Text.setPosition(Center.x+1, Center.y+1);
		}

		_window->draw(Text);


		sf::Color ColorA = sf::Color(255, 255, 255);
		sf::Color ColorB = sf::Color(128, 128, 128);
		if (State) {
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
	Button(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window, std::string text, int id) :Component(position, size, true, true, id) {
		_window = window;
		Text.setString(text);
		font_Arial.loadFromFile("arial.ttf");
	}

	bool State = false;
	sf::Text Text;
	int FontSize = 10;
	sf::Color FontColor;


private:
	sf::Font font_Arial;
	sf::RenderWindow* _window;
};



class ButtonSwitch : public Component
{
public:
	void draw() {

		sf::CircleShape shape;
		sf::Color foneColor;
		if (State) {
			foneColor = BackgroundColorOn;
		}
		else {
			foneColor = BackgroundColorOff;
		}

		shape = sf::CircleShape(Size.y / 2);
		shape.setFillColor(foneColor);
		shape.setPosition(Position.x, Position.y);
		_window->draw(shape);

		shape.setPosition(Position.x+ Size.x - Size.y, Position.y);
		_window->draw(shape);


		sf::RectangleShape fon(sf::Vector2f(Size.x - Size.y, Size.y));
		fon.setPosition(Position.x + Size.y/2, Position.y);
		fon.setFillColor(foneColor);
		_window->draw(fon);

		sf::CircleShape tog(Size.y / 2 -1);
		tog.setFillColor(sf::Color(100,100,100));

		if (State) {
			tog.setPosition(Position.x + Size.x - Size.y - 1, Position.y + 1);
		}
		else {
			tog.setPosition(Position.x + 1, Position.y + 1);
		}
		_window->draw(tog);


		Text.setFont(font_Arial);
		Text.setCharacterSize(FontSize);
		sf::Vector2i Center = sf::Vector2i((Position.x + Size.x / 2), (Position.y + Size.y / 2));
		Center = sf::Vector2i(Center.x - Text.getGlobalBounds().width / 2, (Center.y - Text.getGlobalBounds().height / 2) - 3);
		Text.setPosition(Center.x, Center.y);
		if (State) {
			Text.setPosition(Center.x + 1, Center.y + 1);
		}

		_window->draw(Text);



	}
	ButtonSwitch(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window, std::string text, int id) :Component(position, size, true, true, id) {
		_window = window;
		Text.setString(text);
		font_Arial.loadFromFile("arial.ttf");
	}

	bool State = true;
	sf::Text Text;
	int FontSize = 10;
	sf::Color FontColor;

	sf::Color BackgroundColorOff = sf::Color(0, 255, 0);
	sf::Color BackgroundColorOn = sf::Color(255, 255, 0);


private:
	sf::Font font_Arial;
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

	struct Event {
		int id = -1;
		int eventId = -1;

		Event(int _id, int _eventID) {
			id = _id;
			eventId = _eventID;
		}
	};

	/*
	***Events***
	0 - mouse down
	1 - mouse up
	2 - mouse enter
	3 - nouse leave
	4 - mouse click

	*/

	std::stack<Event> event;


	void Inicialize(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window);

	void Update();

	Event GetEvent() {
		Event t(-1, -1);
		if (!event.empty()) {
			t = event.top();
			event.pop();
		}
		return t;
	}


	void CreateButton(sf::Vector2i Position, sf::Vector2i Size, std::string text, int type, int id) {
		if (type == 0) {
			Components.push_back(new Button(Position + FormPosition, Size, Window, text, id));
		}
		else if (type == 1) {
			Components.push_back(new ButtonSwitch(Position + FormPosition, Size, Window, text, id));
		}
		else {
			Components.push_back(new Button(Position + FormPosition, Size, Window, text, id));
		}
	}




};

