#include "boxCollider.h"

void boxCollider::setCenter(float posX, float posY)
{
	if (boxColl==nullptr)
	{
		boxColl = new sf::RectangleShape(sf::Vector2f(10,10));
	}
	boxColl->setOrigin(posX, posY);
}

void boxCollider::setSize(float sizeX, float sizeY)
{
	if (boxColl == nullptr)
	{
		boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
	}
	else
	{
		boxColl->setSize(sf::Vector2f(sizeX, sizeY));
	}
}
