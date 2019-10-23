#include "../include/ResourceManager.h"}

ResourceManger::ResourceManger()
{
}

ResourceManger::~ResourceManger()
{
}

void ResourceManger::loadTextures(std::string dirArchivo, int & IDout, sf::Sprite & sprite)
{
	numid++;
	IDout = numid;
	textures.push_back(new sf::Texture());
	if (!textures[IDout]->loadFromFile(dirArchivo))
	{
		std::cout << "cant lodad texture\n";
	}
	sprite.setTexture(*textures[IDout]);
}

void ResourceManger::loadTextures(std::string dirArchivo, int & IDout)
{
	numid++;
	IDout = numid;
	textures.push_back(new sf::Texture());
	if (!textures[IDout]->loadFromFile(dirArchivo))
	{
		std::cout << "cant lodad texture";
	}
}

sf::Texture ResourceManger::getTexture(int ID)
{
	if (ID<0 || ID>numid)
	{
		std::cout << "no se encuentra una textura con ese ID";
		return sf::Texture();
	}
	return *textures[ID];
}

void ResourceManger::onDelete()
{
	for (int i = 0; i < textures.size(); i++)
	{
		delete textures[i];
	}
}
