#pragma once
#include"GameObject.h"

class Physics
{
public:
	void onPrepare();
	void onShutDown();
	void update();
	void gravity();
	Physics();
	~Physics();

private:
	bool m_isFalling;
	GameObject& m_gameObject;
};