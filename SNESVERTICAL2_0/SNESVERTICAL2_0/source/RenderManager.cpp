#include "../include/RenderManager.h"


RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::render(CWindow *&window, std::vector<GameObject> objects)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		window->getWindow()->draw(objects[i].getshape());
	}
}
