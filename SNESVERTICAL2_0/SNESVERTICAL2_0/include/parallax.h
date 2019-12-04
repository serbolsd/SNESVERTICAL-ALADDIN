#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include <vector>
#include "component.h"
#include "Aladdin.h"
class Parallax : public Component
{
public:
	Parallax(GameObject* &objectFollow)
	{ 
		type = parallax;
		aladdin = objectFollow;
	};
	~Parallax() {};
	GameObject* aladdin;
	sf::Vector2f posaladdin;
	void update();
private:

};

inline void Parallax::update()
{
	if (aladdin->position->x==posaladdin.x)
	{
		return;
	}
	posaladdin = { aladdin->position->x,aladdin->position->y };
	float x = myObject->getPosition().x;
	x += ((*aladdin->actualSpeed / myObject->getPosition().z)* -aladdin->direction.x);
	myObject->setPosition(x, myObject->getPosition().y, myObject->getPosition().z);
}

