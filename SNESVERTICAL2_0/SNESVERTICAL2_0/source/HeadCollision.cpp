#include "../include/HeadCollision.h"
#include "../include/GameObject.h"
headCollider::headCollider()
{
	typecolli = HEADCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Red);
	boxColl->setOutlineThickness(2);
}

headCollider::headCollider(float sizeX, float sizeY)
{
	typecolli = HEADCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Red);
	boxColl->setOutlineThickness(2);
}

headCollider::~headCollider()
{
}

void headCollider::update()
{
	this->boxColl->setPosition(sf::Vector2f(myObject->position->x, (myObject->position->y - 22)));
	if (myObject->goingUp)
	{
		return;
	}
	for (size_t i = 0; i < colliders.size(); i++)
	{
		boxCollider* checkbox = colliders[i];
		if (this == checkbox)
		{
			continue;
		}
		if (boxColl->getGlobalBounds().intersects(checkbox->getBox()->getGlobalBounds()))
		{
			if (checkbox->getType() == FLOOTCOLLIDER)
			{

				if (this->boxColl->getPosition().y + boxColl->getSize().y < (checkbox->getBox()->getPosition().y) - 1)
				{
					float y = boxColl->getPosition().y + boxColl->getSize().y + checkbox->getBox()->getPosition().y;
					boxColl->setPosition(boxColl->getPosition().x, y);
					myObject->setPosition(boxColl->getPosition().x,y+22);
				}
				*myObject->currentJumpForce = 0;
				*myObject->fallTime = 0;
				return;
			}
		}
	}
}
