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
	circuShape = new sf::CircleShape(50,50);
	circuShape->setFillColor(sf::Color::Blue);
	speed=new float(10);
	actualSpeed = new float(10);
	speedRun = new float(20);
	speedJump = new float(10);
	speedPlane = new float(10);
	setPosition(0, -50, 0);
	shape = new sf::RectangleShape(sf::Vector2f(100,100));
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

