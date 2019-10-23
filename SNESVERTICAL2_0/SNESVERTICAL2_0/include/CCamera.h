#pragma once
#include <SFML/Graphics.hpp>
class CCamera
{
public:
	CCamera();
	~CCamera();
	sf::View * getView() {return m_view;};
	void setView(const float &posx, const float &posy, const float &width, const float &height);
	void incrementZoom();
	void decrementZoom();
	void moveCam(const float &dirx, const float &diry, const float &dirz);
	void initCamera(const float &posx, const float &posy, const float &width, const float &height);
	void onDelete();
	sf::Vector2f getPosition() { return sf::Vector2f(position->x, position->y); };

private:
	sf::View * m_view;
	float minZoom = 0.8f;
	float maxZoom = 1.2f;
	float moveSpeed = 0.5f;
	sf::Vector2f* position;
};

