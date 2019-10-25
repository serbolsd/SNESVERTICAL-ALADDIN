#pragma once
#include "component.h"
#include "GameObject.h"
class Movement : public Component
{
public:
	Movement() { type = movement; };
	~Movement() {};
	void update();
private:

};
inline void Movement::update()
{

	*myObject->position += sf::Vector3f
	(
		myObject->direction.x * *myObject->actualSpeed,
		myObject->direction.y **myObject->actualSpeed,
		0
	);
}
