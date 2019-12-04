#include "..\include\Vision.h"
#include<iostream>
void Vision::update()
{
	
	boxColl->setPosition(CollisionBox->getPosition().x, CollisionBox->getPosition().y);
	if (hitBox->getGlobalBounds().intersects(CollisionBox->getGlobalBounds()))
	{
		std::cout<<"Choco"<<std::endl;
	}
}
void Vision::init()
{
	sf::Vector2f size(50, 50);
	CollisionBox->setSize(size);
}

void Vision::Delete()
{ 
	delete CollisionBox;
}

