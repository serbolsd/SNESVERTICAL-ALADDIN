#include "../include/footCollision.h"
#include "../include/GameObject.h"
#include <iostream>
footsCollider::footsCollider()
{
	typecolli = FOOTCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(10,10));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Yellow);
	boxColl->setOutlineThickness(2);
}

footsCollider::footsCollider(float sizeX, float sizeY)
{
	typecolli = FOOTCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//custom size of box
	boxColl->setOrigin(sizeX/2,sizeY);
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Yellow);
	boxColl->setOutlineThickness(2);
}

footsCollider::~footsCollider()
{
}

void footsCollider::update()
{
	boxColl->setPosition(sf::Vector2f(myObject->position->x, (myObject->position->y-4)));
	
	for (size_t i = 0; i < colliders.size(); i++)
	{
		boxCollider* checkbox = colliders[i];
		if (this == checkbox)
		{
			continue;
		}
		if (boxColl->getGlobalBounds().intersects(checkbox->getBox()->getGlobalBounds()))
		{
			if (checkbox->getType() == WALLCOLLIDER)
			{

				if (this->boxColl->getPosition().x > checkbox->getBox()->getPosition().x)
				{
					myObject->position->x = checkbox->getBox()->getPosition().x + (checkbox->getBox()->getSize().x / 2 + myObject->shape->getSize().x / 2);
				}
				else
				{
					myObject->position->x = checkbox->getBox()->getPosition().x - (checkbox->getBox()->getSize().x / 2 + myObject->shape->getSize().x / 2);
				}

			}
		}
	}
	for (size_t i = 0; i < colliders.size(); i++)
	{
		boxCollider* checkbox = colliders[i];
		if (this== checkbox)
		{
			continue;
		}
		if (boxColl->getGlobalBounds().intersects(checkbox->getBox()->getGlobalBounds()))
		{
			if (checkbox->getType() == JUMPERCOLLIDER)
			{
				*myObject->fallTime = 0;
				*myObject->currentJumpForce = *myObject->JumpForce;
				myObject->canPressForForce = true;
				myObject->timeToPress = 0;
				
				
			}
			else if (checkbox->getType() == FLOOTCOLLIDER)
			{

				if (this->boxColl->getPosition().y > (checkbox->getBox()->getPosition().y - (checkbox->getBox()->getSize().y)) + 1)
				{

					//position->y *= -1;
				}
				myObject->isGrounded = true;
				if (myObject->isJump)
				{
					myObject->isJump = false;
				}
				//float ypos = (checkbox->getBox()->getPosition().y - (checkbox->getBox()->getSize().y));
				float ypos = (checkbox->getBox()->getPosition().y - (checkbox->getBox()->getSize().y));
				boxColl->setPosition(sf::Vector2f(myObject->position->x, ypos));
				myObject->position->y = boxColl->getPosition().y + 4;
			}
	
		}
		else
		{
			myObject->isGrounded = false;
			myObject->isJump = true;
		}
	}
}