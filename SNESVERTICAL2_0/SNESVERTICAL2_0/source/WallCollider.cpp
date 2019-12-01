#include "../include/WallCollider.h"
WallCollider::WallCollider()
{
	typecolli = WALLCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(10, 10));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Yellow);
	boxColl->setOutlineThickness(2);
	boxColl->setOrigin(5, 10);
}

WallCollider::WallCollider(float sizeX, float sizeY)
{
	typecolli = WALLCOLLIDER;
	boxColl = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));//default size of box
	boxColl->setFillColor(sf::Color::Transparent);
	boxColl->setOutlineColor(sf::Color::Yellow);
	boxColl->setOutlineThickness(2);
	boxColl->setOrigin(sizeX/2, sizeY);
}

WallCollider::~WallCollider()
{
}

void WallCollider::update()
{
}
