#pragma once
enum typecomponent
{
	unknow = 0,
	collider,
	sprite,
	physic
};
class Component
{
public:
	Component();
	~Component();
	void update() {};
	typecomponent type = unknow;
private:

};
