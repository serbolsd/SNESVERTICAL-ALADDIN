#pragma once
#include "component.h"
#include <SFML/Graphics.hpp>
enum COLLIDERTYPE
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
	boxCollider() ;
	~boxCollider() {};
	void setCenter(float posX,float posY);//for change de pivot position
	void setSize(float sizeX,float sizeY);//for change the size of the box
	void setType(COLLIDERTYPE typeCollider = UNKNOWCOLLIDER) 
	{ 
		typecolli = typeCollider; 
	};//para definir el tipo de colision
	void update() override;
	void draw(sf::RenderWindow &wind);
	COLLIDERTYPE getType() { return typecolli; };
	sf::RectangleShape* getBox() { return boxColl; };
protected:
	sf::RectangleShape* boxColl=nullptr;// box Collider
	COLLIDERTYPE typecolli = UNKNOWCOLLIDER;//the type of the collision
};

extern std::vector<boxCollider*> colliders;