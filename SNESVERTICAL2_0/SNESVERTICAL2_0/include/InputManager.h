#pragma once
#include "Aladdin.h"
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
		sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Left) ||
		sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Right)
		)
	{
		player.isMove = true;
		sf::Vector2f direcction;
		direcction.x = 0;
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Left))
		{
			player.animatorID = 1;
			direcction.x += -1;
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
		if (!player.isjumpBPressed)//si ya se esta saltando no se vuelve a aplicar 
		{
			player.animatorID = 5;
			player.isJump = true;
			player.isGrounded = false;
		}
		player.isjumpBPressed = true;
	}
	else
	{
		player.isjumpBPressed = false;
	}
	if (player.isJump)
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
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::X))//veo si se presiona el boton de lanzar
	{
		player.animatorID = 7;
		player.isThrow = true;
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Down))//veo si se esta agachando
	{
		player.animatorID = 8;
		player.isCrouched = true;
	}
	else
	{
		player.isCrouched = false;
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
			player.timeToPress = *player.fallTime;
			if (player.timeToPress > 8)
			{
				player.canPressForForce = false;
			}
			else
			{
				player.isjumpBPressed = true;
			}
		}
		
	}
	else
	{
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
				player.isPlane = true;
			}
			else
			{
				player.isPlane = false;
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
		}
		player.animatorID = 8;
		player.isCrouched = true;
	}
	else if ((sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::Y) < -10) && player.canGoingUp &&!player.goingUp)
	{
		player.goingUp = true;
		player.timeToGoingUp = 0;
	}
	else
	{
		player.isCrouched = false;
	}
	if (player.disGrabbed)
	{
		*player.grabbedTime += *player.deltaTime;
		if (*player.grabbedTime > 0.20)
		{
			player.disGrabbed=false;
			*player.grabbedTime = 0;
		}
	}
}
