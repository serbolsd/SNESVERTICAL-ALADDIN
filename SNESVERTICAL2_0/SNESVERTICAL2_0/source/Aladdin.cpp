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
	JumpForce = new float(4.9);
	ParachuteForce = new float(9);
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
	balancingTime = new float(0);
	balancingSpeed = new float(3);
	balancingLarge = new float(100);
	haveParachute = true;
}

void Aladdin::onUpdate()
{
	sf::Joystick::update();
	for (size_t i = 0; i < 8; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			IndexControl = i;
			break;
		}
		else
		{
			IndexControl = -1;
		}
	}
	
	if (canPressForForce)
	{
		timeToPress += *deltaTime;
	}
	if (movingAfterBalacing)
	{
		TimeAddX += *deltaTime;
		if (TimeAddX <timeToStopAddX)
		{
			position->x += addforceX;
		}
		else
		{
			TimeAddX = 0;
			movingAfterBalacing = false;
		}
	}
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
      if (isBalancing)
      {
         *balancingTime += *deltaTime;
         hitbox->getBox()->setRotation(cos(*balancingTime**balancingSpeed)**balancingLarge);
		 std::cout<< hitbox->getBox()->getRotation();
		 system("cls");
      }
    }
    else
    {
      hitbox->getBox()->setRotation(0);
	  //*balancingTime = 0;
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
			isGrabbed = false;
			*fallTime = 0;
			canGoingUp = false;
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
	{delete grabbedTime;			grabbedTime = nullptr;}
	if (animationTime)
	{delete animationTime;			animationTime = nullptr;}
	if (position)
	{delete position;				position = nullptr;}
	if (balancingTime)
	{delete balancingTime;			balancingTime = nullptr;}
	if (animatedSpeed)
	{delete animatedSpeed;			animatedSpeed = nullptr;}
	if (balancingLarge)
	{delete balancingLarge;			balancingLarge = nullptr;}
}
