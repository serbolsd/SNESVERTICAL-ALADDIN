#pragma once
#include "CWindow.h"
#include "GameObject.h"
#include <vector>
class Render
{
public:
	Render();
	~Render();
	static void render(CWindow *&window, std::vector<GameObject*> objects);
private:

};

