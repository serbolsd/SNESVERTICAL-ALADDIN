#include "../include/Aladdin.h"
#include "../include/InputManager.h"
Aladdin::Aladdin()
{
	circuShape = new sf::CircleShape(30, 30);
	speed = new float(10);
	actualSpeed = new float(10);
	speedRun = new float(20);
	speedJump = new float(10);
	speedPlane = new float(10);
	setPosition(0, -50, 0);
}

Aladdin::~Aladdin()
{
	delete circuShape;
	delete speed;
	delete actualSpeed;
	delete speedRun;
	delete speedJump;
	delete speedPlane;
}

void Aladdin::onInit()
{
	circuShape = new sf::CircleShape(10,10);
	circuShape->setFillColor(sf::Color::Blue);
	speed=new float(1);
	actualSpeed = new float(10);
	speedRun = new float(1.5);
	speedJump = new float(10);
	speedPlane = new float(10);
	setPosition(0, -50, 0);
	shape = new sf::RectangleShape(sf::Vector2f(5,5));
	shape->setOrigin(2.5,2.5);
	shape->scale(12,12);
	shape->setPosition(position->x,position->y);
}

void Aladdin::onUpdate()
{
	
	InputManager::OnUpdate(*this);
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->update();
	}
}

void Aladdin::draw(sf::RenderWindow & wind)
{
	shape->setPosition(position->x,position->y);
	wind.draw(*getshape());
}

void Aladdin::onDelete()
{
	delete circuShape;
	delete speed;
	delete actualSpeed;
	delete speedRun;
	delete speedJump;
	delete speedPlane;
}
