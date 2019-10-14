#include "../incluide/CCamera.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::setView(const float & posx, const float & posy, const float & width, const float & height)
{
	position->x = posx;
	position->y = posy;
	m_view->reset(sf::FloatRect(position->x, position->y, width, height));
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
	position = new sf::Vector2f;
	position->x = posx;
	position->x = posy;
	m_view = new sf::View(sf::FloatRect(position->x, position->y, width, height));
}

void CCamera::onDelete()
{
	delete m_view, position;
}
