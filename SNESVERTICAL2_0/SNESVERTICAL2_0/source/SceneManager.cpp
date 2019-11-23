#include "../include/SceneManager.h"
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::onInit()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->deltaTime = deltaTime;
	}
}

void SceneManager::culin(std::vector<GameObject*> &scene)
{
	for (int i = 0; i < gameObjects.size(); i++)//revisa cada objeto en la scena
	{
		//if (gameObjects[i].iscollision(camera.collider))//si esta colisionanado con la camara
		//{
		//	sceneObjects.push_back(gameObjects[i]);//se guardar en el vector de objetos que se mandara a pintar
		//}
		scene.push_back(gameObjects[i]);
	}
}

void SceneManager::checkOrder(std::vector<GameObject*> &scene)
{
	for (int i = 0; i < scene.size(); i++)//por cada objeto que se vaya a pintar
	{
		for (int j = i + 1; j < scene.size(); j++)//se compara con los demas
		{
			if (scene[i]->getPosition().z < scene[j]->getPosition().z)//si la posicion del objeto en z es menor a la de otro
			{
				GameObject* change = scene[i];//cambien de lugar
				scene[i] = scene[j];
				scene[j] = change;
			}
		}
	}
}

void SceneManager::onUpdate()
{
	std::vector<GameObject*> sceneObjects;
	culin(sceneObjects);//se revisa que objetos se van a pintar
	checkOrder(sceneObjects);//se ordenan los objetos por su posicion en z
	for (int i = 0; i < sceneObjects.size(); i++)//por cada objeto que va a pintar
	{
		sceneObjects[i]->onUpdate();//se actualiza
	}
	Render::render(wind,sceneObjects);//y se pintan
}

void SceneManager::onDelete()
{
	for (int i = 0; i < gameObjects.size(); i++)//por cada objeto que va a pintar
	{
		if (gameObjects[i]!=nullptr)
		{
			delete gameObjects[i];
		}
	}
}

void SceneManager::addObject(GameObject *& newObject)
{
	newObject->setID(IDmaxObject++);
	gameObjects.push_back(newObject);
}
