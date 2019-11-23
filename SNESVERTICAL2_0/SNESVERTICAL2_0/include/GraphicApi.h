#pragma once
#include "GameObject.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "Animator.h"
#include "MoveComponent.h"
#include "parallax.h"
class GraphicApi
{
public:
	GraphicApi();
	~GraphicApi();
	static void loadResources(SceneManager &sceneManager,CCamera*camera, ResourceManger& resources);
private:
};

