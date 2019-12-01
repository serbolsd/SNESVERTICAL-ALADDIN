#include "../include/boxCollider.h"
#include "../include/GameObject.h"
std::vector<boxCollider*> colliders;
boxCollider* AladdinHitbox;
boxCollider::boxCollider()
{
	type = collider; 
	boxColl = new sf::RectangleShape();
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Black);
	boxColl->setOutlineThickness(2);
}
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
	boxColl->setOrigin(sizeX/2,sizeY);
}

void boxCollider::update()
{
	boxColl->setPosition(myObject->position->x,myObject->position->y);
}

void boxCollider::draw(sf::RenderWindow &wind)
{
	wind.draw(*boxColl);
}

void boxCollider::onDelete()
{
	if (boxColl!=nullptr)
	{
		delete boxColl;
	}
}
