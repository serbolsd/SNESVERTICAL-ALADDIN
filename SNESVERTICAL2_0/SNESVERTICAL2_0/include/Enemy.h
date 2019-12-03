#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy() {};
	~Enemy() {};
	void onInit() {};
	void onUpdate() {};
	void draw(sf::RenderWindow& wind) {};
	void onDelete() {};
private:
	bool seeAladdin=false;//if aladdin enter to the vision, this is true

};
