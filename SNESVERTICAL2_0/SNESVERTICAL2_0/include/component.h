#pragma once
enum typecomponent
{
	unknow = 0,
	collider,
	sprite,
	physic,
	parallax,
	movement,
	gravity
};
class GameObject;
class Component
{
public:
	Component();
	virtual ~Component();
	virtual void update() {};
	virtual void onDelete() {};
	typecomponent type = unknow;
	GameObject* myObject;
	int ID;
	//agregar id, y el objeto al que pertenece
private:

};
