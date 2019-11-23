#include "../include/HeadCollision.h"
#include "../include/GameObject.h"
headCollider::headCollider()
{
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//default size of box
}

headCollider::headCollider(float sizeX, float sizeY)
{
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//default size of box
}

headCollider::~headCollider()
{
}

void headCollider::update()
{
	this->boxColl->setPosition(sf::Vector2f(myObject->position->x, myObject->position->y));
	if (myObject->isGrounded)
	{
		return;
	}
	for (size_t i = 0; i < colliders.size(); i++)
	{
		if (this->boxColl->getGlobalBounds().intersects(colliders[i]->getBox()->getGlobalBounds()))
		{
			if (colliders[i]->getType() == CORNICECOLLIDER)
			{
				*myObject->fallTime = 0;
				*myObject->currentJumpForce = 0;
				myObject->isGrabbed = true;
				myObject->position->x = colliders[i]->getBox.getPosition().x;
				myObject->position->y = -(colliders[i]->getBox.getPosition().y + 17.5);
			}
			else if (colliders[i]->getType() == BALANCERCOLLIDER)
			{
				if (!myObject->isGrabbed)
				{
					*myObject->fallTime = 0;
					*myObject->currentJumpForce = 0;
					myObject->isGrabbed = true;
					myObject->isBalancing = true;
					myObject->position->x = colliders[i]->getBox.getPosition().x;
					myObject->position->y = -(colliders[i]->getBox.getPosition().y + 17.5);
				}
			}
		}
	}
}
