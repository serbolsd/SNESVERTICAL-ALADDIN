#include "../include/Render.h"


Render::Render()
{
}

Render::~Render()
{
}

void Render::render(CWindow *&window, std::vector<GameObject*> objects)
{
	window->getWindow()->clear(sf::Color::Cyan);
	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->draw(*window->getWindow());
		//window->getWindow()->draw(objects[i].getshape());
	}
}
