#pragma once
#include "RenderManager.h"
#include "GameObject.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void onUpdate();
	CWindow* wind;
private:
	std::vector<GameObject> gameObjects;
	std::vector<GameObject> sceneObjects;
	void culin();
	void checkOrder();


};