#pragma once
#include "CWindow.h"
#include "GameObject.h"
#include <vector>
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	static void render(CWindow *&window, std::vector<GameObject> objects);
private:

};

