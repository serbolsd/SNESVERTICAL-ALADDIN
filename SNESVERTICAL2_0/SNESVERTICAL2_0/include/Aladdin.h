#pragma once
#include "GameObject.h"
class Aladdin :public GameObject
{
public:
	Aladdin();
	~Aladdin();
	void onInit();
	void onUpdate();
	void draw(sf::RenderWindow& wind);
	void onDelete();
	std::string currentState = "Idle";
	int IndexControl = -1;
	//State* state = nullptr;
	sf::CircleShape *circuShape=new sf::CircleShape(50,50);
	
private:

};
