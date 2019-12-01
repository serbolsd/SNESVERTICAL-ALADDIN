#pragma once
#include "GameObject.h"

class InvisibleObject : public GameObject
{
public:
	InvisibleObject();
	~InvisibleObject();
	void onInit() override;
	void onUpdate() override;
	void draw(sf::RenderWindow& wind) override;
	void onDelete() override;
private:

};
