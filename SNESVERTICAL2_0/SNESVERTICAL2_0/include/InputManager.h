#pragma once
#include "Aladdin.h"
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
			direcction.x += -1;
		}
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Right))
		{
			direcction.x += 1;
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
		}
		else
		{
			player.isRun = false;//si no, es falso
			*player.actualSpeed = *player.speed;
		}
	}
	else
	{
		*player.actualSpeed = 0;
		player.isMove = false;
		player.isRun = false;//si no, es falso
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Space))//veo si se presiona el boton de saltar
	{
		if (!player.isjumpBPressed)//si ya se esta saltando no se vuelve a aplicar 
		{
			player.isjump = true;
			player.isGrounded = false;
		}
		player.isjumpBPressed = true;
	}
	else
	{
		player.isjumpBPressed = false;
	}
	if (player.isjump)
	{
		if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::A))//veo si se presiona el boton de planear
		{
			player.isPlane = true;
		}
		else
		{
			player.isPlane = false;
		}
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::X))//veo si se presiona el boton de lanzar
	{
		player.isThrow = true;
	}
	if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Down))//veo si se esta agachando
	{
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
		sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) > 10 ||
		sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) < -10
		)
	{
		player.isMove = true;
		//si lo esta, le aplicao la direccion
		player.direction = {
			sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::X) / 100,
			0
		};
		if (sf::Joystick::isButtonPressed(player.IndexControl, 3))//veo si se presiona el boton de correr
		{
			player.isRun = true;//si lo hace cambia a verdadero
			*player.actualSpeed = *player.speedRun;
		}
		else
		{
			player.isRun = false;//si no, es falso
			*player.actualSpeed = *player.speed;
		}
	}
	else
	{
		*player.actualSpeed = 0;
		player.isMove = false;
		player.isRun = false;//si no, es falso
	}
	if (sf::Joystick::isButtonPressed(player.IndexControl, 2))//veo si se presiona el boton de saltar
	{
		if (!player.isjumpBPressed)//si ya se esta saltando no se vuelve a aplicar 
		{
			player.isjump = true;
			player.isGrounded = false;
		}
		player.isjumpBPressed = true;
	}
	else
	{
		player.isjumpBPressed = false;
	}
	if (player.isjump)
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
	if (sf::Joystick::isButtonPressed(player.IndexControl, 1))//veo si se presiona el boton de lanzar
	{
		player.isThrow = true;
	}
	if (sf::Joystick::getAxisPosition(player.IndexControl, sf::Joystick::Y) < -10)//veo si se esta agachando
	{
		player.isCrouched = true;
	}
	else
	{
		player.isCrouched = false;
	}
}
