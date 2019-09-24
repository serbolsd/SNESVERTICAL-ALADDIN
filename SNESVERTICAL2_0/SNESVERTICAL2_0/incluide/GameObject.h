#pragma once
#include "component.h"
#include "SFML/System/Vector3.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
enum TypeObject
{
	flat = 0,
	player,
	Plataform,
	jumping,
	item
};
class GameObject
{
public:

	GameObject();
	~GameObject();
	void onInit();
	void onUpdate();
	void onDelete();
	void setComponente(Component*);
	Component* getComponente(typecomponent);
	void setTypeObject(TypeObject typeobject);
	TypeObject getTypeObject() { return type; };
	void setPosition(sf::Vector3f pos);
	void setPosition(float posx=0,float posy=0,float posz=0);
	sf::Vector3f getPosition() { return position; };
	void setID(int id) { ID = id; };
	int getID() { return ID; };
	sf::RectangleShape getshape() { return shape; };
private:
	std::vector<Component*> components;
	int ID;
	TypeObject type;
	sf::Vector3f position;
	sf::RectangleShape shape;
};