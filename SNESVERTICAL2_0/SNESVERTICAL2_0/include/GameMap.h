#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<cctype>
#include<iostream>
#include<fstream>
#include"../include/CWindow.h"

using namespace std;

class GameMap
{
public:
	void Init(string file);
	void draw(sf::RenderWindow& win);

	GameMap();
	~GameMap();
private:
	sf::Texture m_background;
	sf::Texture m_tileTexture;
	sf::Sprite m_tiles;
	sf::Sprite m_back;
	sf::Vector2i m_map[5][5];
	sf::Vector2i m_loadCounter;
};

