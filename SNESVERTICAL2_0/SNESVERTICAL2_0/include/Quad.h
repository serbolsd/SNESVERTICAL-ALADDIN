#pragma once
#include "GameObject.h"

class QUAD :public GameObject
{
public:
	QUAD();
	QUAD(float sizex,float sizey);
	~QUAD();
	void onUpdate() override;
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

inline void QUAD::draw(sf::RenderWindow & wind)
{
	wind.draw(*shape);
}

inline void QUAD::setFillColor(sf::Color color)
{
	shape->setFillColor(color);
}
