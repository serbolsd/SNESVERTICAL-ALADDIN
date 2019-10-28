#pragma once
#include"GameObject.h"

class Physics : public Component
{
public:
	void onPrepare();//Setea las variables
	void onShutDown();//Llama al destructor
	void update();//Llama a la funci�n gravity
	void gravity();//Si el GameObject est� cayendo y no esta colisionando,
				   //entonces su posici�n en "y" disminuye
	Physics();
	~Physics();

private:
	bool m_isFalling;//Nos servir� para saber si el GameObject esta cayendo
	GameObject& m_gameObject;//Para modificar la posici�n del GameObject
};