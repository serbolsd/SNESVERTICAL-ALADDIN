#pragma once
#include <SFML/Graphics.hpp>
#include"GameObject.h"
class CCamera
{
public:
	CCamera();//Constructor default
	~CCamera();//Destructor default
	sf::View * getView() {return m_view;};//Ve la que anguno de vista hay en la camara
	void setView(sf::Vector2f*pos, const float &width, const float &height);//Sete que tanta abarca la camara
	void incrementZoom();//Acerca el zoom
	void decrementZoom();//Aleja el zoom
	void moveCam(const float &dirx, const float &diry, const float &dirz);//Mueve la camara
	void initCamera(const float &posx, const float &posy, const float &width, const float &height);//Inicializa lo que ve la camara
	void onDelete();
	void setPosition(sf::CircleShape&Whatever);//Sigue al game object
	void Update();//Update la camra
	sf::Vector2f getPosition() { return sf::Vector2f(position->x, position->y);//Toma la posicion de la camara
	
	};
	
private:
	sf::View * m_view;
	float minZoom = 0.8f;
	float maxZoom = 1.2f;
	float moveSpeed = 0.50f;
	sf::Vector2f* position;
};

