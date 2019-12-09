#include "../include/CCamera.h"
#include "../include/boxCollider.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::setView(sf::Vector3f* pos, const float & width, const float & height)
{
	position = pos;
	m_view->reset(sf::FloatRect(position->x, position->y, width, height));
	m_view->setCenter(position->x, position->y);
}

void CCamera::incrementZoom()
{
	m_view->zoom(maxZoom);
}

void CCamera::decrementZoom()
{
	m_view->zoom(minZoom);
}

void CCamera::moveCam(const float & dirx, const float & diry, const float & dirz)
{
	position->x += dirx * moveSpeed;
	position->y += diry * moveSpeed;
	m_view->setCenter(position->x, position->y);
}

void CCamera::initCamera(const float & posx, const float & posy, const float & width, const float & height)
{
	position = new sf::Vector3f;
	position->x = posx;
	position->x = posy;
	m_view = new sf::View(sf::FloatRect(position->x, position->y, width, height));
}

void CCamera::onDelete()
{
	delete m_view, position;
}

void CCamera::setObjectFollow(GameObject* object)
{
	position = object->position;
}

void CCamera::Update()
{
  float addY = -30;
	m_view->setCenter(position->x,position->y+ addY);
	hitbox->getBox()->setPosition(position->x, position->y+ addY);
}

