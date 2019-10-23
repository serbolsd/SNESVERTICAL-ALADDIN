#include "../include/RenderManager.h"


RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::render(CWindow *&window, std::vector<GameObject*> objects)
{
	window->getWindow()->clear(sf::Color::Cyan);
	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->draw(*window->getWindow());
		//window->getWindow()->draw(objects[i].getshape());
	}
}
