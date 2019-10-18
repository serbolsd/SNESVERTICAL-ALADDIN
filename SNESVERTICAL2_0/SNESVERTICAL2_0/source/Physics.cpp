#include"../include/Physics.h"

Physics::Physics()
{

}

void Physics::onPrepare()
{
	m_isFalling = true;
}

void Physics::onShutDown()
{

}

void Physics::update()
{
	gravity();
}

void Physics::gravity()
{
	// Aun falta que en el while compare si el gameobject esta colisionando
	while (m_isFalling == true)
	{
		m_gameObject.setPosition(m_gameObject.getPosition().x,
			m_gameObject.getPosition().y - 1);
	}
}

Physics::~Physics()
{

}