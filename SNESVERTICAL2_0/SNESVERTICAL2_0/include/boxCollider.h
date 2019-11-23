#pragma once

#include "component.h"
#include <SFML/Graphics.hpp>

enum COLLIDERYPE
{
	UNKNOWCOLLIDER = 0,
	FLOOTCOLLIDER,
	CORNICECOLLIDER,
	BALANCERCOLLIDER,
	HITBOXCOLLIDER,
	FOOTCOLLIDER,
	HEADCOLLIDER,
	JUMPERCOLLIDER,
};
class boxCollider : public Component
{
public:
	boxCollider() {};
	~boxCollider() {};
	void setCenter(float posX,float posY);//for change de pivot position
	void setSize(float sizeX,float sizeY);//for change the size of the box
	COLLIDERYPE getType() { return type; };
	sf::RectangleShape* getBox() { return boxColl; };
protected:
	sf::RectangleShape* boxColl=nullptr;// box Collider
	COLLIDERYPE type = UNKNOWCOLLIDER;//the type of the collision

};

std::vector<boxCollider*> colliders;