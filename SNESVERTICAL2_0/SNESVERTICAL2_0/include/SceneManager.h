#pragma once
#include "Render.h"
#include "GameObject.h"
#include "CCamera.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void onInit();
	void onUpdate();
	void onDelete();

	void addObject(GameObject* & newObject);
	CWindow* wind;
	CCamera* cam;
	std::vector<GameObject*> gameObjects;
	int IDmaxObject=0;
	float *deltaTime;
  int m_AladdinID;
private:
	
	void culin(std::vector<GameObject*> &scene);
	void checkOrder(std::vector<GameObject*> &scene);

};