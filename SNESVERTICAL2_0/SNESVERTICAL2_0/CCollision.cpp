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


