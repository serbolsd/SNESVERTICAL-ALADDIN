#include "CCollision.h"



CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}

bool CCollision::Collision(sf::RectangleShape & check, sf::RectangleShape & collision)
{
	if ((check.getPosition().x + (check.getSize().x * 0.5f)) >= (collision.getPosition().x - (collision.getSize().x * 0.5f)) && (check.getPosition().x - (check.getSize().x * 0.5f)) <= (collision.getPosition().x + (collision.getSize().x * 0.5f))) { // condicionamos la colision a las dimensiones en x del objeto a checar

		if (((check.getPosition().y - check.getSize().y) <= (collision.getPosition().y)) && (check.getPosition().y >= (collision.getPosition().y - collision.getSize().y))) { // solo tomar en cuenta el rango del rectangulo, la priemra parte del and capea hacia abajo del rectangulo y segunda parte de arriba


			if (((check.getPosition().y) <= (collision.getPosition().y - collision.getSize().y))) { // objeto A tiene su punto minimo sobre el punto maximo de objeto B
				std::cout << "COLISION VERTICAL" << std::endl;
			}
			else { //si no supera el munto minimo, aun se cuenta como lateral, esto en el juego hace que alladin reciba daño
				std::cout << "COLISION LATERAL" << std::endl;
			}

			return true;
		}
	
	}
	else {
		return false;
	}
}

bool CCollision::Collision(sf::CircleShape & circle, sf::RectangleShape & rectangle)
{
	float testX = circle.getPosition().x;
	float testY = circle.getPosition().y;

	// which edge is closest?
	if (circle.getPosition().x < rectangle.getPosition().x - (rectangle.getSize().x * 0.5f))         testX = rectangle.getPosition().x - (rectangle.getSize().x * 0.5f);      // test left edge
	else if (circle.getPosition().x > rectangle.getPosition().x + (rectangle.getSize().x * 0.5f)) testX = rectangle.getPosition().x + (rectangle.getSize().x * 0.5f);   // right edge
	if (circle.getPosition().y < rectangle.getPosition().y - (rectangle.getSize().y * 0.5f))         testY = rectangle.getPosition().y - (rectangle.getSize().y * 0.5f);      // top edge
	else if (circle.getPosition().y > rectangle.getPosition().y + (rectangle.getSize().y * 0.5f)) testY = rectangle.getPosition().y + (rectangle.getSize().y * 0.5f);   // bottom edge

	// get distance from closest edges
	float distX = circle.getPosition().x - testX;
	float distY = circle.getPosition().y - testY;
	float distance = sqrt((distX*distX) + (distY*distY));

	// if the distance is less than the radius, collision!
	if (distance <= circle.getRadius()) {
		return true;
	}
	return false;
}


