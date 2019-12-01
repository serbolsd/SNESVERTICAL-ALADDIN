#include "../include/GraphicApi.h"
#include "../include/Quad.h"
#include "../include/boxCollider.h"
#include "../include/GravityAladdin.h"
#include "../include/footCollision.h"
#include "../include/HeadCollision.h"
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
		Component* Gravity = new GravityAladdin();
		aladdin->setComponente(Gravity);
		footsCollider* footaladdin = new footsCollider(5,2.5);
		footaladdin->setType(FOOTCOLLIDER);
		Component* footcollider = footaladdin;
		aladdin->setComponente(footcollider);
		headCollider* headAladdin = new headCollider(2,2);
		Component* headcoll = headAladdin;
		aladdin->setComponente(headcoll);
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

	QUAD* floor1 = new QUAD(50, 20);
	floor1->setFillColor(sf::Color::Green);
	floor1->setPosition(0,80,0);
	GameObject* floor = floor1;
		boxCollider* floorCollider1 = new boxCollider();
		floorCollider1->setSize(50,20);
		floorCollider1->setType(COLLIDERTYPE::FLOOTCOLLIDER);
		Component* floorCollider = floorCollider1;
		floor->setComponente(floorCollider);
	sceneManager.addObject(floor);

	QUAD* rebound = new QUAD(30, 20);
	rebound->setFillColor(sf::Color::Magenta);
	rebound->setPosition(50, 80, 0);
	floor = rebound;
	boxCollider* rebound1 = new boxCollider();
	rebound1->setSize(30, 20);
	rebound1->setType(COLLIDERTYPE::JUMPERCOLLIDER);
	floorCollider = rebound1;
	floor->setComponente(floorCollider);
	sceneManager.addObject(floor);

	QUAD* cornice1 = new QUAD(2, 2);
		cornice1->setFillColor(sf::Color::Blue);
		cornice1->setPosition(-20, 18, 1);
	GameObject* quad = cornice1;
	boxCollider* cornicecoll1 = new boxCollider();
		cornicecoll1->setSize(2,2);
		cornicecoll1->setType(COLLIDERTYPE::CORNICECOLLIDER);
	Component* quadCollider = cornicecoll1;
	quad->setComponente(quadCollider);
	sceneManager.addObject(quad);

	QUAD* cornice2 = new QUAD(2, 2);
		cornice2->setFillColor(sf::Color::Blue);
		cornice2->setPosition(60, 18, 1);
	quad = cornice2;
	boxCollider* cornicecoll2 = new boxCollider();
		cornicecoll2->setSize(2, 2);
		cornicecoll2->setType(COLLIDERTYPE::CORNICECOLLIDER);
	quadCollider = cornicecoll2;
	quad->setComponente(quadCollider);
	sceneManager.addObject(quad);
}