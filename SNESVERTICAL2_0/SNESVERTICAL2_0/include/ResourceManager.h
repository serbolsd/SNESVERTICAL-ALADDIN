#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class ResourceManger
{
public:
	ResourceManger();
	~ResourceManger(); 
	static ResourceManger* resource;
	void loadTextures(std::string dirArchivo, int& IDout, sf::Sprite& sprite);
	void loadTextures(std::string dirArchivo, int& IDout);
	sf::Texture getTexture(int ID);
	void onDelete();
private:
	int numid = -1;
	std::vector<sf::Texture*> textures;
	
private:

};
