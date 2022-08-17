#include "Form.h"


//void Form::Draw()
//{
//	sf::RectangleShape fon(sf::Vector2f(FormSize.x, FormSize.y));
//	fon.setPosition(FormPosition.x, FormPosition.y);
//	fon.setFillColor(sf::Color(192, 192, 192));
//	Window->draw(fon);
//
//	for (int i = 0; i < Components.size(); i++) {
//
//	}
//}



bool Form::PointInRect(sf::Vector2i point, sf::Vector2i rectA, sf::Vector2i rectB)
{
	if (point.x > rectA.x && point.x<rectB.x && point.y>rectA.y && point.y < rectB.y) {
		return true;
	}
	else
	{
		return false;
	}
}

void Form::Inicialize(sf::Vector2i position, sf::Vector2i size, sf::RenderWindow* window)
{
	Window = window;
	FormPosition = position;
	FormSize = size;
}

void Form::Update()
{
	sf::RectangleShape fon(sf::Vector2f(FormSize.x, FormSize.y));
	fon.setPosition(FormPosition.x, FormPosition.y);
	fon.setFillColor(sf::Color(192, 192, 192));
	Window->draw(fon);



	for (int i = 0; i < Components.size(); i++) {
		if (dynamic_cast<Button*>(Components[i]))
		{
			Button* button = dynamic_cast<Button*>(Components[i]);


			if (PointInRect(sf::Mouse::getPosition(*Window), Components[i]->Position, Components[i]->Position + Components[i]->Size)) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					if (!button->State) {
						event.push(Components[i]->Id);
					}
					button->State = true;
				}
				else {
					button->State = false;
				}

			}
		}
	}



	for (int i = 0; i < Components.size(); i++) {
		if (dynamic_cast<Button*>(Components[i]))
		{
			Components[i]->draw();
		}
	}

}
