#pragma once
#include "GameObject.h"

class QUAD :public GameObject
{
public:
	QUAD();
	QUAD(float sizex,float sizey);
	~QUAD();
	void onUpdate() override;
	void onDelete() override;
	void draw(sf::RenderWindow& wind) override;
	void setFillColor(sf::Color color);
private:

};

QUAD::QUAD()
{
	shape = new sf::RectangleShape(sf::Vector2f(5, 5));
	shape->setOrigin(2.5,5);
}

inline QUAD::QUAD(float sizex, float sizey)
{
	shape = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
	shape->setOrigin(sizex/2, sizey);
}

QUAD::~QUAD()
{

}

inline void QUAD::onUpdate()
{
	shape->setPosition(position->x,position->y);
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->update();
	}
}

inline void QUAD::onDelete()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->onDelete();
		delete components[i];
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

inline void QUAD::draw(sf::RenderWindow & wind)
{
	wind.draw(*shape);
}

inline void QUAD::setFillColor(sf::Color color)
{
	shape->setFillColor(color);
}
