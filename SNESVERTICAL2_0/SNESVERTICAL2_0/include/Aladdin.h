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
	bool isGrabbed = false;
	bool isjump = false;
	bool isjumpBPressed = false;
	bool isGrounded = false;
	bool isRun = false;
	bool isPlane = false;
	bool isIdle = false;
	bool isMove = false;
	bool isThrow = false;
	bool isCrouched = false;
	float sppedThrowTime = 1.5;
	float sppedJumpTime = 1.5;
	float throwTime = 0;
	float JumpTime = 0;
	std::string currentState = "Idle";
	int IndexControl = -1;
	
	//State* state = nullptr;
	sf::CircleShape *circuShape=new sf::CircleShape(50,50);
private:

};
