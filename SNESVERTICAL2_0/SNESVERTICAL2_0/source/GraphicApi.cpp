#include "../include/GraphicApi.h"
#include "../include/Quad.h"
#include "../include/boxCollider.h"
#include "../include/GravityAladdin.h"
#include "../include/footCollision.h"
#include "../include/HeadCollision.h"
#include "../include/hitboxAladdin.h"
#include "../include/hitbox.h"
#include "../include/InvisibleObject.h"
GraphicApi::GraphicApi()
{
}

GraphicApi::~GraphicApi()
{
}

void GraphicApi::loadResources(SceneManager &sceneManager, CCamera*camera, ResourceManger& resources)
{
  Component *hitbox;
  InitializeCamera(camera);
	
  InitializeAladdin(sceneManager, camera);

  InitializeBackGround1(sceneManager,resources, hitbox);

  InitializeBackGround2();

  InitializeColliders(sceneManager, hitbox);
 

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
		cornice2->setPosition(20, 90, 1);
	quad = cornice2;
	hitbox=new HitBox(2,2);
	boxCollider* cornicecoll2 = new boxCollider();
		cornicecoll2->setSize(2, 2);
		cornicecoll2->setType(COLLIDERTYPE::BALANCERCOLLIDER);
	quadCollider = cornicecoll2;
	quad->setComponente(quadCollider);
	quad->setComponente(hitbox);
	sceneManager.addObject(quad);

	QUAD* wall1 = new QUAD(20, 50);
	wall1->setFillColor(sf::Color::Yellow);
	wall1->setPosition(-40, 80, 0);
	GameObject* wall = wall1;
	boxCollider* wallCollider1 = new boxCollider();
	wallCollider1->setSize(20, 50);
	wallCollider1->setType(COLLIDERTYPE::WALLCOLLIDER);
	Component* wallCollider = wallCollider1;
	wall->setComponente(wallCollider);
	sceneManager.addObject(wall);

// 	QUAD* wall2 = new QUAD(20, 50);
// 	wall2->setFillColor(sf::Color::Yellow);
// 	wall2->setPosition(40, 80, 0);
// 	wall = wall2;
// 	boxCollider* wallCollider2 = new boxCollider();
// 	wallCollider2->setSize(20, 50);
// 	wallCollider2->setType(COLLIDERTYPE::WALLCOLLIDER);
// 	wallCollider = wallCollider2;
// 	wall->setComponente(wallCollider);
// 	sceneManager.addObject(wall);
}

void GraphicApi::InitializeCamera(CCamera * _Camera)
{
  boxCollider* cameraHitbox = new HitBox(65, 65);
  cameraHitbox->setCenter(32.5, 32.5);
  _Camera->hitbox = cameraHitbox;
  colliders.push_back(cameraHitbox);
}

void GraphicApi::InitializeAladdin(SceneManager &sceneManager, CCamera * _Camera)
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
  //aladdin->setPosition(504, 30, 0);

  Animator *AladdinAnimation = new Animator;
  //init animator of aladdin
  AladdinAnimation->Init(PathDescriptorAladdin, aladdin->getshape(), 0);
  Component* castAnimator = AladdinAnimation;
  //set animator to Aladdin
  aladdin->setComponente(castAnimator);
  //set camera to follow aladdin
  _Camera->setObjectFollow(aladdin);
  //create the move component for aladdin
  AladdinHitbox = new HitBoxAladdin(5, 14);
  aladdin->setComponente(AladdinHitbox);
  Component* move = new Movement();
  aladdin->setComponente(move);
  Component* Gravity = new GravityAladdin();
  aladdin->setComponente(Gravity);
  footsCollider* footaladdin = new footsCollider(1, 0.5);
  footaladdin->setType(FOOTCOLLIDER);
  Component* footcollider = footaladdin;
  aladdin->setComponente(footcollider);
  headCollider* headAladdin = new headCollider(0.2, 0.2);

  Component* headcoll = headAladdin;
  aladdin->setComponente(headcoll);

  sceneManager.m_AladdinID = aladdin->getID();
  sceneManager.addObject(aladdin);
}

void GraphicApi::InitializeBackGround1(SceneManager &sceneManager, ResourceManger& resources, Component *& hitbox)
{
  int idtex;
  GameObject* fondo1 = new GameObject();
  sceneManager.addObject(fondo1);
  resources.loadTextures("resources\\Levels\\LevelFull.png", idtex, sceneManager.gameObjects[fondo1->getID()]->sprite);
  sceneManager.gameObjects[fondo1->getID()]->setTextureID(idtex);
  sceneManager.gameObjects[fondo1->getID()]->setPosition(-10, 0, 5);
  sceneManager.gameObjects[fondo1->getID()]->getsprite().setScale(0.3, 0.3);
  int tmpX = sceneManager.gameObjects[fondo1->getID()]->getsprite().getTexture()->getSize().x;
  int tmpY = sceneManager.gameObjects[fondo1->getID()]->getsprite().getTexture()->getSize().y;
  HitBox* hitBoxBG = new HitBox(tmpX, tmpY);
  hitBoxBG->setCenter(0, 0);

  hitbox = hitBoxBG;
  sceneManager.gameObjects[fondo1->getID()]->setComponente(hitbox);
}

void GraphicApi::InitializeBackGround2()
{
  // 	GameObject* fondo2 = new GameObject();
// 	fondo2->setComponente(new Parallax(aladdin));
// 	sceneManager.addObject(fondo2);
// 		resources.loadTextures("resources\\fondo2.jpg", idtex, sceneManager.gameObjects[fondo2->getID()]->sprite);
// 		sceneManager.gameObjects[fondo2->getID()]->setTextureID(idtex);
// 		sceneManager.gameObjects[fondo2->getID()]->setPosition(0, -10, 6);
}

void GraphicApi::InitializeColliders(SceneManager &sceneManager, Component *& hitbox)
{
  InvisibleObject* GroundIO = new InvisibleObject();
  //floor1->setFillColor(sf::Color::Green);
  GroundIO->setPosition(0, 155, 0);

  GameObject* GroundGO = GroundIO;
  boxCollider* floorCollider1 = new boxCollider();
  floorCollider1->setSize(3291, 20);
  //floorCollider1->setSize(50,20);
  floorCollider1->setCenter(25, 20);
  floorCollider1->setType(COLLIDERTYPE::FLOOTCOLLIDER);
  Component* floorCollider = floorCollider1;
  GroundGO->setComponente(floorCollider);
  HitBox* hitBoxFloor = new HitBox(3291, 20);
  hitBoxFloor->setCenter(25, 20);
  hitbox = hitBoxFloor;
  GroundGO->setComponente(hitbox);
  sceneManager.addObject(GroundGO);

//   QUAD* rebound = new QUAD(20, 1);
//   rebound->setFillColor(sf::Color::Magenta);
//   rebound->setPosition(50, 108, 0);
//   GroundGO = rebound;
//   boxCollider* rebound1 = new boxCollider();
//   rebound1->setSize(20, 1);
//   rebound1->setType(COLLIDERTYPE::FLOOT_TRASPASABLE_COLLIDER);
//   floorCollider = rebound1;
//   GroundGO->setComponente(floorCollider);
//   hitbox = new HitBox(30, 20);
//   GroundGO->setComponente(hitbox);
//   sceneManager.addObject(GroundGO);

  newTent(GroundGO, floorCollider, sceneManager, hitbox, 50, 108, 20, 1);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 24, 135, 9, 8, 125, 9);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 87, 135, 9, 8, 125, 9);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 96, 135, 9, 18, 115, 9);
  
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 127, 108, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 155, 108, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 190, 108, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 220, 108, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 280, 108, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 325, 104, 20, 1);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 324, 141, 33, 8, 131,33);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 367, 108, 20, 1);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 453, 141, 38, 8, 131,38);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 454, 104, 20, 1);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 504, 138, 68, 8, 128,68);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 557, 141, 38, 8, 131,38);
  newFloor(GroundGO, floorCollider, sceneManager, hitbox, 504, 102, 47, 2.5);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 483, 102,2, 2);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 527, 102,2, 2);
  newFloor(GroundGO, floorCollider, sceneManager, hitbox, 504.5, 73, 28, 2.5);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 492, 73, 2, 2);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 518, 73, 2, 2);
  newFloor(GroundGO, floorCollider, sceneManager, hitbox, 504.5, 44.5, 18, 2.5);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 497, 44.5, 2, 2);
  newCornice(GroundGO, floorCollider, sceneManager, hitbox, 511, 44.5, 2, 2);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 554, 104, 20, 1);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 775, 108, 20, 1);

  newWall(GroundGO, floorCollider, sceneManager, hitbox, 740, 135, 38, 8, 125, 40);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 740, 125, 18, 8, 115, 20);
  
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 817, 135, 38, 8, 125, 40);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 817, 125, 18, 8, 115, 20);

  newTent(GroundGO, floorCollider, sceneManager, hitbox, 850, 107, 9, 3);
  newTent(GroundGO, floorCollider, sceneManager, hitbox, 874, 88, 9, 3);

  /**
   * @brief : Barrel Wall
   */
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 870, 135, 9, 8, 125, 9);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 879, 135, 9, 18, 115, 9);
  newWall(GroundGO, floorCollider, sceneManager, hitbox, 887, 135, 9, 28, 105, 9);
}

void GraphicApi::newWall(GameObject *& GroundGO, Component *& floorCollider, SceneManager &sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY, float _posTopWall, float _hitBoxSize)
{
  QUAD* Barrel1 = new QUAD(_sizeX, _SizeY);
  Barrel1->setFillColor(sf::Color::Magenta);
  Barrel1->setFillColor(sf::Color::Transparent);
  Barrel1->setPosition(_posX, _PosY, 0);
  GroundGO = Barrel1;
  boxCollider* Barrel1_BC = new boxCollider();
  Barrel1_BC->setSize(_sizeX, _SizeY);
  Barrel1_BC->setType(COLLIDERTYPE::WALLCOLLIDER);
  floorCollider = Barrel1_BC;
  GroundGO->setComponente(floorCollider);
  hitbox = new HitBox(_sizeX, _SizeY);
  GroundGO->setComponente(hitbox);
  sceneManager.addObject(GroundGO);

  QUAD* WallTop = new QUAD(_sizeX, 1);
  WallTop->setFillColor(sf::Color::Yellow);
  WallTop->setFillColor(sf::Color::Transparent);
  WallTop->setPosition(_posX, _posTopWall, 0);
  GroundGO = WallTop;
  boxCollider* WallTop_BC = new boxCollider();
  WallTop_BC->setSize(_hitBoxSize, 1);
  WallTop_BC->setType(COLLIDERTYPE::FLOOT_TRASPASABLE_COLLIDER);
  floorCollider = WallTop_BC;
  GroundGO->setComponente(floorCollider);
  hitbox = new HitBox(_hitBoxSize, 1);
  GroundGO->setComponente(hitbox);
  sceneManager.addObject(GroundGO);
}

void GraphicApi::newTent(GameObject *& GroundGO, Component *& floorCollider, SceneManager & sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY)
{
  QUAD* rebound = new QUAD(_sizeX, _SizeY);
  rebound->setFillColor(sf::Color::Magenta);
  rebound->setFillColor(sf::Color::Transparent);
  rebound->setPosition(_posX, _PosY, 0);
  GroundGO = rebound;
  boxCollider* rebound1 = new boxCollider();
  rebound1->setSize(_sizeX, _SizeY);
  rebound1->setType(COLLIDERTYPE::FLOOT_TRASPASABLE_COLLIDER);
  floorCollider = rebound1;
  GroundGO->setComponente(floorCollider);
  hitbox = new HitBox(_sizeX, _SizeY);
  GroundGO->setComponente(hitbox);
  sceneManager.addObject(GroundGO);
}

void GraphicApi::newFloor(GameObject *& GroundGO, Component *& floorCollider, SceneManager & sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY)
{
	QUAD* rebound = new QUAD(_sizeX, _SizeY);
	rebound->setFillColor(sf::Color::Magenta);
	rebound->setFillColor(sf::Color::Transparent);
	rebound->setPosition(_posX, _PosY, 0);
	GroundGO = rebound;
	boxCollider* rebound1 = new boxCollider();
	rebound1->setSize(_sizeX, _SizeY);
	rebound1->setType(COLLIDERTYPE::FLOOTCOLLIDER);
	floorCollider = rebound1;
	GroundGO->setComponente(floorCollider);
	hitbox = new HitBox(_sizeX, _SizeY);
	GroundGO->setComponente(hitbox);
	sceneManager.addObject(GroundGO);
}

void GraphicApi::newCornice(GameObject *& GroundGO, Component *& floorCollider, SceneManager & sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY)
{
	QUAD* rebound = new QUAD(_sizeX, _SizeY);
	rebound->setFillColor(sf::Color::Magenta);
	rebound->setFillColor(sf::Color::Transparent);
	rebound->setPosition(_posX, _PosY, 0);
	GroundGO = rebound;
	boxCollider* rebound1 = new boxCollider();
	rebound1->setSize(_sizeX, _SizeY);
	rebound1->setType(COLLIDERTYPE::CORNICECOLLIDER);
	floorCollider = rebound1;
	GroundGO->setComponente(floorCollider);
	hitbox = new HitBox(_sizeX, _SizeY);
	GroundGO->setComponente(hitbox);
	sceneManager.addObject(GroundGO);
}
