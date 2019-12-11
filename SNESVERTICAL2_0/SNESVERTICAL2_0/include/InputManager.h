#pragma once
#include "Aladdin.h"
#include "hitbox.h"
#include <iostream>
class InputManager
{
public:
	InputManager();
	~InputManager();
	static void OnUpdate(Aladdin & player);
	static void keyboard(Aladdin & player);
	static void controller(Aladdin & player);
private:

};

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{
}
void InputManager::OnUpdate(Aladdin & player)
{
	if (player.IndexControl<0)
	{
		keyboard(player);
	}
	else
	{
		controller(player);
	}
}

inline void InputManager::keyboard(Aladdin & player)
{
	player.animatorID = 0;
	if (//Veo si la cruzeta esta siendo precionada
		(sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Left) ||
		sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Right)) && !player.goingUp && !player.isGrabbed
		)
	{
		player.isMove = true;
		sf::Vector2f direcction;
		direcction.x = 0;
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Left))
		{
			direcction.x += -1;
			player.animatorID = 1;
		}
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Right))
		{
			direcction.x += 1;
			player.animatorID = 2;
		}
		
		//si lo esta, le aplicao la direccion
		player.direction = {
			direcction.x,
			0
		};
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Z))//veo si se presiona el boton de correr
		{
			player.isRun = true;//si lo hace cambia a verdadero
			*player.actualSpeed = *player.speedRun;
			if (player.animatorID == 1)
			{
				player.animatorID = 3;
			}
			else
			{
				player.animatorID = 4;
			}
		}
		else
		{
			player.isRun = false;//si no, es falso
			*player.actualSpeed = *player.speed;
		}
	}
	else
	{
		player.animatorID = 0;
		*player.actualSpeed = 0;
		player.isMove = false;
		player.isRun = false;//si no, es falso
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Space))//veo si se presiona el boton de saltar
	{
		if (!player.alreadyPressJump)
		{
			player.alreadyPressJump = true;
			if (!player.isjumpBPressed)//si ya se esta saltando no se vuelve a aplicar 
			{
				player.animatorID = 5;
				player.isJump = true;
				player.isGrounded = false;
				player.isjumpBPressed = true;
				*player.currentJumpForce = *player.JumpForce;
			}
			if (player.canPressForForce)
			{
				player.timeToPress += *player.deltaTime;
				if (player.timeToPress > .8)
				{
					player.canPressForForce = false;
				}
				else
				{
					player.isjumpBPressed = true;
				}
			}
			if (player.isBalancing)
			{
				player.canPressForForce = true;
				player.movingAfterBalacing = true;
				player.timeToPress = 0;
				player.disGrabbed = true;
				player.isBalancing = false;
				*player.fallTime = 0;
				*player.balancingTime = 0;
				player.isGrabbed = false;
				if (player.hitbox->getBox()->getRotation() > 180)
				{
					player.addforceX = 3;
				}
				else
				{
					player.addforceX = -3;
				}
			}
		}
		
	}
	else
	{
		player.alreadyPressJump = false;
		player.isjumpBPressed = false;
	}
	if (player.isJump)
	{
		player.animatorID = 5;
		if (player.isjumpBPressed)
		{
			if (*player.currentJumpForce>*player.JumpForce*2)
			{
				*player.currentJumpForce = *player.JumpForce * 2;
			}
			else
			{
				*player.currentJumpForce += 0.3;
			}
		}
		*player.fallTime += *player.deltaTime;
		if (player.haveParachute)
		{
			if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::A))//veo si se presiona el boton de planear
			{
				player.animatorID = 6;
				player.isPlane = true;
			}
			else
			{
				player.animatorID = 5;
				player.isPlane = false;
			}
		}
	
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::X))//veo si se presiona el boton de lanzar
	{
		player.animatorID = 7;
		player.isThrow = true;
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Down) && !player.goingUp)//veo si se esta agachando
	{
		if (player.isGrabbed)
		{
			player.disGrabbed = true;
			*player.fallTime = 0;
			*player.balancingTime = 0;
			player.isGrabbed = false;
			player.shape->setRotation(0);
			player.isBalancing = false;
			player.animatorID = 8;
		}
		else
		{
			player.isCrouched = true;
			player.animatorID = 9;
		}
	}
	else
	{
		player.isCrouched = false;
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Up) && player.canGoingUp && !player.goingUp)
	{
		player.goingUp = true;
		player.timeToGoingUp = 0;
		player.animatorID = 10;
	}
	if (player.disGrabbed)
	{
		*player.grabbedTime += *player.deltaTime;
		if (*player.grabbedTime > 0.20)
		{
			player.disGrabbed = false;
			*player.grabbedTime = 0;
		}
	}
}

inline void InputManager::controller(Aladdin & player)
{
	if (//Veo si la cruzeta esta siendo precionada
		(sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) > 10 ||
		sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) < -10)&&!player.goingUp &&!player.isGrabbed
		)
	{
		player.isMove = true;
		//si lo esta, le aplicao la direccion
		player.direction = {
			sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) / 100,
			0
		};
		if (player.direction.x<1)
		{
			player.animatorID = 1;
		}
		else
		{
			player.animatorID = 2;
		}
		if (sf::Joystick::isButtonPressed(player.IndexControl, 3))//veo si se presiona el boton de correr
		{
			player.isRun = true;//si lo hace cambia a verdadero
			*player.actualSpeed = *player.speedRun;
			if(player.animatorID == 1)
			{
				player.animatorID = 3;
			}
			else
			{
				player.animatorID = 4;
			}
		}
		else
		{
			player.isRun = false;//si no, es falso
			*player.actualSpeed = *player.speed;
		}
	}
	else
	{
		player.animatorID = 0;
		*player.actualSpeed = 0;
		player.isMove = false;
		player.isRun = false;//si no, es falso
	}
	if (sf::Joystick::isButtonPressed(player.IndexControl, 2))//veo si se presiona el boton de saltar
	{
		if (!player.isJump)
		{
			if (!player.alreadyPressJump)
			{
				player.alreadyPressJump = true;
				if (!player.isjumpBPressed)//si ya se esta saltando no se vuelve a aplicar 
				{
					player.animatorID = 5;
					player.isJump = true;
					player.isGrounded = false;
					player.isjumpBPressed = true;
					*player.currentJumpForce = *player.JumpForce;
				}
				if (player.canPressForForce)
				{
					player.timeToPress += *player.fallTime;
					if (player.timeToPress > .8)
					{
						player.canPressForForce = false;
					}
					else
					{
						player.isjumpBPressed = true;
					}
				}
				if (player.isBalancing)
				{
					player.canPressForForce = true;
					player.movingAfterBalacing = true;
					player.timeToPress = 0;
					player.disGrabbed = true;
					player.isBalancing = false;
					*player.fallTime = 0;
					*player.balancingTime = 0;
					player.isGrabbed = false;
					if (player.hitbox->getBox()->getRotation() > 180)
					{
						player.addforceX = 3;
					}
					else
					{
						player.addforceX = -3;
					}
				}
			}
		}
		
		
	}
	else
	{
		player.alreadyPressJump = false;
		player.isjumpBPressed = false;
	}
	if (player.isJump)
	{
		player.animatorID = 5;
		if (player.isjumpBPressed)
		{
			if (*player.currentJumpForce > *player.JumpForce * 2)
			{
				*player.currentJumpForce = *player.JumpForce * 2;
			}
			*player.currentJumpForce += 0.3;
		}
		*player.fallTime += *player.deltaTime;
		if (player.haveParachute)
		{
			if (sf::Joystick::isButtonPressed(player.IndexControl, 5))//veo si se presiona el boton de planear
			{
				player.animatorID = 6;
				player.isPlane = true;
				*player.currentParachuteForce = *player.ParachuteForce;
				*player.currentJumpForce = 0;

			}
			else if(player.isPlane)
			{
				player.animatorID = 5;
				player.isPlane = false;
				*player.currentParachuteForce = 0;
				*player.fallTime = 0;
			}
			else
			{
				player.animatorID = 5;
				player.isPlane = false;
				*player.currentParachuteForce = 0;
			}
		}

	}
	if (sf::Joystick::isButtonPressed(player.IndexControl, 1))//veo si se presiona el boton de lanzar
	{
		player.animatorID = 7;
		player.isThrow = true;
	}
	float axisy = sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::Y);
	std::cout << axisy << std::endl;
	system("cls");
	if (sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::Y) > 10 && !player.goingUp)//veo si se esta agachando
	{
		if (player.isGrabbed)
		{
			player.disGrabbed = true;
			*player.fallTime = 0;
			player.isGrabbed = false;
			player.shape->setRotation(0);
			player.isBalancing = false;
			player.canGoingUp = false;
			*player.balancingTime = 0;
		}
		player.animatorID = 8;
		player.isCrouched = true;
	}
	else if ((sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::Y) < -10) && player.canGoingUp &&!player.goingUp)
	{
		player.goingUp = true;
		player.timeToGoingUp = 0;
		player.animatorID = 10;
	}
	else
	{
		player.isCrouched = false;
	}
	if (player.disGrabbed)
	{
		*player.grabbedTime += *player.deltaTime;
		if (*player.grabbedTime > 0.30)
		{
			player.disGrabbed=false;
			*player.grabbedTime = 0;
		}
	}
}
