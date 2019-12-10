#include "../include/hitboxAladdin.h"
#include "../include/GameObject.h"
HitBoxAladdin::HitBoxAladdin()
{
	typecolli = COLLIDERTYPE::HITBOXCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Red);
	boxColl->setOutlineThickness(0.1);
	boxColl->setOrigin(10 / 2, 0);
}

HitBoxAladdin::HitBoxAladdin(float sizeX, float sizeY)
{
	typecolli = COLLIDERTYPE::HITBOXCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Cyan);
	boxColl->setOutlineThickness(0.2);
	boxColl->setOrigin(sizeX/2,0);
}

HitBoxAladdin::~HitBoxAladdin()
{
}

void HitBoxAladdin::update()
{
	this->boxColl->setPosition(sf::Vector2f(myObject->position->x, (myObject->position->y - 22)));
	if (myObject->goingUp)
	{
		return;
	}
	if (myObject->isGrounded || myObject->disGrabbed)
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
				myObject->canGoingUp = true;
				boxColl->setPosition(checkbox->getBox()->getPosition());
				myObject->position->x = boxColl->getPosition().x;
				myObject->position->y = (boxColl->getPosition().y + 22);
				return;
			}
			else if (checkbox->getType() == BALANCERCOLLIDER)
			{
				if (!myObject->isGrabbed)
				{
					*myObject->fallTime = 0;
					*myObject->currentJumpForce = 0;
					myObject->isGrabbed = true;
					myObject->isBalancing = true;
					boxColl->setPosition(checkbox->getBox()->getPosition());
					myObject->position->x = boxColl->getPosition().x;
					myObject->position->y = (boxColl->getPosition().y + 22);
					//myObject->position->x = checkbox->getBox()->getPosition().x;
					//myObject->position->y = -(checkbox->getBox()->getPosition().y + 17.5);
					return;
				}
			}
		}
		else
		{
			myObject->isGrabbed = false;
			myObject->isBalancing = false;
			myObject->canGoingUp = false;
		}
	}
}