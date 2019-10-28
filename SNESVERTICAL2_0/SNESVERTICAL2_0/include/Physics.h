#pragma once
#include"GameObject.h"

class Physics : public Component
{
public:
	void onPrepare();//Setea las variables
	void onShutDown();//Llama al destructor
	void update();//Llama a la función gravity
	void gravity();//Si el GameObject está cayendo y no esta colisionando,
				   //entonces su posición en "y" disminuye
	Physics();
	~Physics();

private:
	bool m_isFalling;//Nos servirá para saber si el GameObject esta cayendo
	GameObject& m_gameObject;//Para modificar la posición del GameObject
};