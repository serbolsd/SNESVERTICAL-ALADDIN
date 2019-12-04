#include "..\include\Vision.h"
#include<iostream>
#include "../include/GameObject.h"
void Vision::update()
{
	
	boxColl->setPosition(myObject->position->x,myObject->position->y);
	if (AladdinHitbox->getBox()->getGlobalBounds().intersects(boxColl->getGlobalBounds()))
	{
		std::cout<<"Choco"<<std::endl;
	}
}
void Vision::init()
{
	sf::Vector2f size(50, 50);
	boxColl->setSize(size);
}

void Vision::onDelete()
{
	delete boxColl;
}

