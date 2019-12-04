#include"../include/Jarron.h"


void Jarron(boxCollider& Aladdin)
{
	int SaltoLenght=40;
	int Salto = 0;
	int Limit = 3;
	GameObject* Jarron = new GameObject();
	sf::Vector3f PrevPosition= Jarron->getPosition();
	if (Jarron->shape->getGlobalBounds().intersects(Aladdin.getBox()->getGlobalBounds()))
	{
		for (int i = 0; i <Limit ; i++)
		{
			
			Salto += 10;
			Jarron->shape->setPosition(PrevPosition.x, Salto);
			if (Jarron->shape->getPosition().y == SaltoLenght)
			{
				
				while (Jarron->shape->getPosition().y != PrevPosition.y)
				{
					Salto = -10;
					Jarron->shape->setPosition(PrevPosition.x,Salto);
				}
			}
		}
	}
	
}
