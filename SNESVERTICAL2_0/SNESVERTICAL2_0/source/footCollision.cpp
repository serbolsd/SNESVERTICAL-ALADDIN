#include "../include/footCollision.h"
#include "../include/GameObject.h"
footsCollider::footsCollider()
{
	boxColl = new sf::RectangleShape(sf::Vector2f(10,10));//default size of box
}

footsCollider::footsCollider(float sizeX, float sizeY)
{
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//custom size of box
}

footsCollider::~footsCollider()
{
}

void footsCollider::update()
{
	this->boxColl->setPosition(sf::Vector2f(myObject->position->x, myObject->position->y));
	for (size_t i = 0; i < colliders.size(); i++)
	{
		if (this== colliders[i])
		{
			continue;
		}
		if (this->boxColl->getGlobalBounds().intersects(colliders[i]->getBox()->getGlobalBounds()))
		{
			if (colliders[i]->getType() == JUMPERCOLLIDER)
			{
			    
				*myObject->fallTime = 0;
				*myObject->currentJumpForce = *myObject->JumpForce;
				myObject->canPressForForce = true;
				myObject->timeToPress = 0;

			}
			else if (colliders[i]->getType() == FLOOTCOLLIDER)
			{
				
				if (this->boxColl->getPosition().y > (colliders[i]->getBox()->getPosition().y - (colliders[i]->getBox()->getSize().y / 2)) - 1)
				{
					myObject->position->y = (colliders[i]->getBox()->getPosition().y - (colliders[i]->getBox()->getSize().y / 2));
					//position->y *= -1;
				}
				myObject->isGrounded= true;
				if (myObject->isJump)
				{
					myObject->isJump = false;
				}
				return;
			}

		}
		else
		{
			myObject->isGrounded = false;
			myObject->isjump = true;
		}
	}
}