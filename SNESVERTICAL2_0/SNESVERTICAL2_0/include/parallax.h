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
	void update();
private:

};

inline void Parallax::update()
{
	float x = myObject->getPosition().x;
	x += ((*aladdin->actualSpeed / myObject->getPosition().z)* -aladdin->direction.x);
	myObject->setPosition(x, myObject->getPosition().y, myObject->getPosition().z);
}

