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
	this->boxColl->setPosition(sf::Vector2f(myObject->position->x, (myObject->position->y-22)));
	if (myObject->isGrounded|| myObject->disGrabbed)
	{
		return;
	}
	for (int i = 0; i < colliders.size(); i++)
	{
		boxCollider* checkbox = colliders[i];
		if (this == checkbox)
		{
			continue;
		}
		if (boxColl->getGlobalBounds().intersects(checkbox->getBox()->getGlobalBounds()))
		{
			if (checkbox->getType() == CORNICECOLLIDER)
			{
				*myObject->fallTime = 0;
				*myObject->currentJumpForce = 0;
				myObject->isGrabbed = true;
				boxColl->setPosition(checkbox->getBox()->getPosition());
				myObject->position->x = boxColl->getPosition().x;
				myObject->position->y = (boxColl->getPosition().y +22);
			}
			else if (checkbox->getType() == BALANCERCOLLIDER)
			{
				if (!myObject->isGrabbed)
				{
					*myObject->fallTime = 0;
					*myObject->currentJumpForce = 0;
					myObject->isGrabbed = true;
					myObject->isBalancing = true;
					myObject->position->x = checkbox->getBox()->getPosition().x;
					myObject->position->y = -(checkbox->getBox()->getPosition().y + 17.5);
				}
			}
		}
	}
}
