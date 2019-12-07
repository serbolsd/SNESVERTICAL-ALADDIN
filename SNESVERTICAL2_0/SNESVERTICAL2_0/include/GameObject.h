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
	virtual ~GameObject() 
	{
		delete animatedSpeed;
	};
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
		sprite.setPosition(position->x, position->y);
		wind.draw(sprite);
	};
	virtual void onDelete();
	//this function is for add a new component
	void setComponente(Component*);
	//you call this function with the type of component you want
	Component* getComponente(typecomponent);
	//setea el tipo de objeto que sera
	void setTypeObject(TypeObject typeobject);
	//return the type of th object
	TypeObject getTypeObject() { return type; };
	void setPosition(sf::Vector3f pos);
	void setPosition(float posx = 0, float posy = 0, float posz = 0);
	sf::Vector3f getPosition() { return *position; };
	//set the identificator of the object
	void setID(int id) { ID = id; };
	//get the identificator of the object
	int getID() { return ID; };
	//you can set texture to sprite with the id of the texture
	void setTextureID(int id) { IDtexture = id; };
	//return the texture id of the sprite
	int getTextureID() { return IDtexture; };
	//return the rectangleShape ptr
	sf::RectangleShape* getshape() { return shape; };
	//return the sprite
	sf::Sprite getsprite() { return sprite; };
	sf::Sprite sprite;

	float* speed = nullptr;//the speed with the object move normaly
	float* actualSpeed = nullptr;//the actual speed of the objetc
	float* speedRun = nullptr;// the speed with the object move when is run
	float* speedJump = nullptr;// the speed with the object move when is jump
	float* speedPlane = nullptr;// the speed with the object move when is plane
	float* animatedSpeed = new float(.2f);// the speed with the object play the animations
	sf::Vector2f direction;// the direction of the object move
	float *deltaTime;//the global time
	float *fallTime;//the time it has been falling
	float *grabbedTime;//the time it has been falling
	float *animationTime;//the current time of the animation on this object
	int animatorID = 0;//the id of the actual animation
	bool isGrabbed = false;// if grabbed is true
	bool disGrabbed = false;// if isnt grabbed is true, this is for time whit it can grabbed again
	bool isJump = false;// if grabbed is true
	bool isBalancing= false;// if balacing is true
	bool isjumpBPressed = false;// if the buton for jump is hold press
	bool isGrounded = false;// if it if gorunded is true
	bool isRun = false;// if is run is true
	bool isPlane = false;// if isPlane is true, this is for change the force of the falling
	bool haveParachute = false;//if have parachute
	bool goingUp = false;//if is grabbed can goingup
	bool canGoingUp = false;//if the cornice is the tipe cornice
	float timeToGoingUp = 0;//el tiempo que se tarda en subir
	bool isIdle = false;
	bool isMove = false;
	bool isThrow = false;
	bool isCrouched = false;
	bool isSwinging = false;
	bool canPressForForce = false;//si rebotas esto sirve para precionar en un tiempo derterminado el boton de salto para ganar impulso
	float timeToPress = 0;//esto es el tiempo que cuenta cuanto a pasado desde que puedes precionar para ganar fuerza, si se pasa del tiempo, no se gana fuerza
	float sppedThrowTime = 1.5;
	float sppedJumpTime = 1.5;
	float throwTime = 0;
	float JumpTime = 0;

	float* currentJumpForce;//the actual force of jump, this cheng if isJumpPressed
	float* JumpForce;//The normal jump force
	float* ParachuteForce;//the normal force if isPlane
	float* currentParachuteForce;//the actual force of parachute
public:
	std::vector<Component*> components;//the list of its components
	int ID;//its id
	int IDtexture = 0;//its id texture
	TypeObject type;//its type object
	sf::Vector3f *position;//its actual position
	sf::RectangleShape* shape;//its rectangleShape
	
};