#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include "CWindow.h"

using namespace std;

class GameMap
{
public:
	void Init(string file);//Leemos los datos del archivo
	void draw(sf::RenderWindow& win, float size);//Dibujamos en una ventana lo que tenemos

	GameMap();
	~GameMap();
private:
	sf::Texture m_background;//Textura del Background
	sf::Texture m_tileTexture;//Tile Sheet completo
	sf::Sprite m_tiles;//Sprite invididual de un tile
	sf::Sprite m_back;//Sprite del fondo
	sf::Vector2i m_map[20][15];//Mapa donde colocaaremos los tiles
	sf::Vector2i m_loadCounter;//Nos ayudará a posicionar los tiles
	int m_nx, m_ny;//Almacenaremos las dimensiones del mapa que hay en el archivo
};

