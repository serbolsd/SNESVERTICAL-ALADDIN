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
  /**
   * Members 
   */
private:

  /**
   * Methods 
   */
public:
	static void loadResources
  (
    SceneManager &sceneManager,
    CCamera*camera, 
    ResourceManger& resources
  );
private:
  /**
    * @brief  : Function that sets the camera hitbox.
    * @bug    : No know bugs.
    */
  static void InitializeCamera(CCamera * _Camera);
  /**
    * @brief  : Function that sets the main character properties.
    * @bug    : No know bugs.
    */
  static void InitializeAladdin(SceneManager &sceneManager, CCamera * _Camera);
  /**
    * @brief  : Function that sets level background.
    * @bug    : No know bugs.
    */
  static void InitializeBackGround1(SceneManager &sceneManager, ResourceManger& resources, Component *& hitbox);
  /**
    * @brief  : Function that sets the parallax background.
    * @bug    : No know bugs.
    */
  static void InitializeBackGround2();
  /**
    * @brief  : Function that sets level Colliders;
    * @bug    : No know bugs.
    */
  static void InitializeColliders(SceneManager &sceneManager, Component *& hitbox);

  static void newWall(GameObject *& GroundGO, Component *& floorCollider, SceneManager &sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY, float _posTopWall, float _hitBoxSize);
  static void newTent(GameObject *& GroundGO, Component *& floorCollider, SceneManager &sceneManager, Component *& hitbox, float _posX, float _PosY, float _sizeX, float _SizeY);
};

