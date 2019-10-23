#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
class CCollision
{
public:
	CCollision();
	~CCollision();
	bool Collision(sf::RectangleShape & check, sf::RectangleShape & collision);
};

