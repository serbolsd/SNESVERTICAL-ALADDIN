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
	JumpForce = new float(5);
	ParachuteForce = new float(7.37);
	currentJumpForce = new float(0);
	currentParachuteForce = new float(0);
	setPosition(0, -50, 0);
	shape = new sf::RectangleShape(sf::Vector2f(5,5));
	shape->setOrigin(2.5,4);
	shape->scale(12,12);
	shape->setPosition(position->x,position->y);
	isJump = true;
	fallTime = new float(0);
	grabbedTime = new float(0);
	IndexControl = 0;
}

void Aladdin::onUpdate()
{
	if (isJump)
	{
		*fallTime += *deltaTime;
	}
	else
	{
		*fallTime = 0;
	}
	if (isGrabbed)
	{
		*fallTime = 0;
	}
	if (goingUp)
	{
		timeToGoingUp += *deltaTime;
		if (timeToGoingUp<0.8)
		{
			position->y -= 1.1;
		}
		else
		{
			goingUp = false;
			timeToGoingUp = 0;
		}
	}
	else
	{
		timeToGoingUp = 0;
	}
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
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->onDelete();
		if (components[i] != nullptr)
		{
			delete components[i];
		}
	}
	if (circuShape)	
	{delete circuShape;				circuShape = nullptr;}
	if (speed)
	{delete speed;					speed = nullptr;}
	if (actualSpeed)
	{delete actualSpeed;				actualSpeed = nullptr;}
	if (speedRun)
	{delete speedRun;				speedRun = nullptr;}
	if (speedJump)
	{delete speedJump;				speedJump = nullptr;}
	if (speedPlane)
	{delete speedPlane;				speedPlane = nullptr;}
	if (shape)
	{delete shape;					shape = nullptr;}
	if (currentJumpForce)
	{delete currentJumpForce;		currentJumpForce = nullptr;}
	if (JumpForce)
	{delete JumpForce;				JumpForce = nullptr;}
	if (ParachuteForce)
	{delete ParachuteForce;			ParachuteForce = nullptr;}
	if (currentParachuteForce)
	{delete currentParachuteForce;	currentParachuteForce = nullptr;}
	if (fallTime)
	{delete fallTime;				fallTime = nullptr;}
	if (grabbedTime)
	{delete grabbedTime;				grabbedTime = nullptr;}
	if (animationTime)
	{delete animationTime;			animationTime = nullptr;}
	if (position)
	{delete position;				position = nullptr;}
}
