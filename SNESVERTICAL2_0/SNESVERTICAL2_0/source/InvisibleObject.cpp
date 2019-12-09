#include "../include/InvisibleObject.h"

InvisibleObject::InvisibleObject()
{
}

InvisibleObject::~InvisibleObject()
{
}

void InvisibleObject::onInit()
{
}

void InvisibleObject::onUpdate()
{
  for (int i = 0; i < components.size(); i++)
  {
    components[i]->update();
  }
}

void InvisibleObject::draw(sf::RenderWindow & wind)
{

}

void InvisibleObject::onDelete()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->onDelete();
		if (components[i]!=nullptr)
		{
			delete components[i];
		}
	}
	if (speed)
	{
		delete speed;					speed = nullptr;
	}
	if (actualSpeed)
	{
		delete actualSpeed;				actualSpeed = nullptr;
	}
	if (speedRun)
	{
		delete speedRun;				speedRun = nullptr;
	}
	if (speedJump)
	{
		delete speedJump;				speedJump = nullptr;
	}
	if (speedPlane)
	{
		delete speedPlane;				speedPlane = nullptr;
	}
	if (shape)
	{
		delete shape;					shape = nullptr;
	}
	if (currentJumpForce)
	{
		delete currentJumpForce;		currentJumpForce = nullptr;
	}
	if (JumpForce)
	{
		delete JumpForce;				JumpForce = nullptr;
	}
	if (ParachuteForce)
	{
		delete ParachuteForce;			ParachuteForce = nullptr;
	}
	if (currentParachuteForce)
	{
		delete currentParachuteForce;	currentParachuteForce = nullptr;
	}
	if (fallTime)
	{
		delete fallTime;				fallTime = nullptr;
	}
	if (grabbedTime)
	{
		delete grabbedTime;				grabbedTime = nullptr;
	}
	if (animationTime)
	{
		delete animationTime;			animationTime = nullptr;
	}
	if (position)
	{
		delete position;				position = nullptr;
	}
}
