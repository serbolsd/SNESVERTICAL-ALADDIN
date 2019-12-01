#pragma once
#include "GameObject.h"
class Aladdin :public GameObject
{
public:
	Aladdin();
	~Aladdin();
	void onInit() override;
	void onUpdate() override;
	void draw(sf::RenderWindow& wind) override;
	void onDelete() override;
	std::string currentState = "Idle";
	int IndexControl = -1;
	//State* state = nullptr;
	sf::CircleShape *circuShape=new sf::CircleShape(50,50);
	
private:

};
