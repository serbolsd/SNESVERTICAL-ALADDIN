#include "../include/GraphicApi.h"

GraphicApi::GraphicApi()
{
}

GraphicApi::~GraphicApi()
{
}

void GraphicApi::loadResources(SceneManager &sceneManager, CCamera*camera, ResourceManger& resources)
{
	//animator descriptor of aladdin
	AnimatorDesc PathDescriptorAladdin;
	PathDescriptorAladdin.RunPath = "resources\\AladdinAnimations\\sprint.png";
	PathDescriptorAladdin.runProportion = sf::Vector2u(11, 1);
	PathDescriptorAladdin.SwingPath = "resources\\AladdinAnimations\\swing.png";
	PathDescriptorAladdin.IdlePath = "resources\\AladdinAnimations\\idle_Pos.png";
	PathDescriptorAladdin.idleProportion = sf::Vector2u(1, 1);
	//init aladdin
	GameObject* aladdin = new Aladdin();
	aladdin->onInit();
	aladdin->setPosition(0, 30, 0);

		Animator *AladdinAnimation = new Animator;
		//init animator of aladdin
		AladdinAnimation->Init(PathDescriptorAladdin, aladdin->getshape(), 0);
		Component* castAnimator = AladdinAnimation;
		//set animator to aladin
		aladdin->setComponente(castAnimator);
		//set camera to follow aladdin
		camera->setObjectFollow(aladdin);
		//create de move component for aladdin
		Component* move = new Movement();
		aladdin->setComponente(move);
	sceneManager.addObject(aladdin);
	//init the parallax
	int idtex;
	GameObject* fondo1 = new GameObject();
	sceneManager.addObject(fondo1);
		resources.loadTextures("resources\\Levels\\level1.gif", idtex, sceneManager.gameObjects[fondo1->getID()]->sprite);
		sceneManager.gameObjects[fondo1->getID()]->setTextureID(idtex);
		sceneManager.gameObjects[fondo1->getID()]->setPosition(0, 0, 5);

	GameObject* fondo2 = new GameObject();
	fondo2->setComponente(new Parallax(aladdin));
	sceneManager.addObject(fondo2);
		resources.loadTextures("resources\\fondo2.jpg", idtex, sceneManager.gameObjects[fondo2->getID()]->sprite);
		sceneManager.gameObjects[fondo2->getID()]->setTextureID(idtex);
		sceneManager.gameObjects[fondo2->getID()]->setPosition(0, -10, 6);
}