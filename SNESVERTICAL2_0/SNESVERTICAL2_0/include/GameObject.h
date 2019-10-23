#pragma once
#include "component.h"
#include "SFML/System/Vector3.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
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

	GameObject() {};
	virtual ~GameObject() {};
	virtual void onInit() {};
	virtual void onUpdate() 
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->update();
		}
	};
	virtual void draw(sf::RenderWindow& wind)
	{
		sprite.setPosition(position.x, position.y);
		wind.draw(sprite);
	};
	void onDelete();
	void setComponente(Component*);
	Component* getComponente(typecomponent);
	void setTypeObject(TypeObject typeobject);
	TypeObject getTypeObject() { return type; };
	void setPosition(sf::Vector3f pos);
	void setPosition(float posx = 0, float posy = 0, float posz = 0);
	sf::Vector3f getPosition() { return position; };
	void setID(int id) { ID = id; };
	int getID() { return ID; };
	void setTextureID(int id) { IDtexture = id; };
	int getTextureID() { return IDtexture; };
	sf::RectangleShape getshape() { return shape; };
	sf::Sprite getsprite() { return sprite; };
	sf::Sprite sprite;

	float* speed = nullptr;
	float* actualSpeed = nullptr;
	float* speedRun = nullptr;
	float* speedJump = nullptr;
	float* speedPlane = nullptr;

	sf::Vector2f direction;
private:
	std::vector<Component*> components;
	int ID;
	int IDtexture = 0;
	TypeObject type;
	sf::Vector3f position;
	sf::RectangleShape shape;
	
};