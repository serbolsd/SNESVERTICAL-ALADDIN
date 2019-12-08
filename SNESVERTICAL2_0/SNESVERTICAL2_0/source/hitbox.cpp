#include "../include/hitbox.h"
#include "../include/GameObject.h"

HitBox::HitBox()
{
	typecolli = HITBOXCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Red);
	boxColl->setOutlineThickness(2);
	boxColl->setOrigin(10 / 2, 0);
}

HitBox::HitBox(float sizeX, float sizeY)
{
	typecolli = HITBOXCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Red);
	boxColl->setOutlineThickness(2);
	boxColl->setOrigin(sizeX/2, sizeY);
}

HitBox::~HitBox()
{
}

void HitBox::update()
{
	boxColl->setPosition(myObject->position->x, myObject->position->y);
}
