#pragma once
#include "GraphicApi.h"
#include "Render.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "CWindow.h"
#include "CCamera.h"
#include <imgui-SFML.h>
#include <imgui.h>

class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void init();
	void onUpdate();
	void onDelete();
	bool run;
	void imguiAladdinDebug();
	void imguiParallaxDebug();
private:
	GameObject *aladdin;
	GameObject *fondo1;
	GameObject *fondo2;
	Render renderManager;
	ResourceManger resources;
	//SoundManager soundManager;
	SceneManager sceneManager;
	CWindow* window;
	CCamera* camera;
	void initParallax();
	float* deltaTime;
};
