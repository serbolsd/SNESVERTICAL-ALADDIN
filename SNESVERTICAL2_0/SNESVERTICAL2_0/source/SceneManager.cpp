#include "../include/SceneManager.h"
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::culin()
{
	for (int i = 0; i < gameObjects.size(); i++)//revisa cada objeto en la scena
	{
		//if (gameObjects[i].iscollision(camera.collider))//si esta colisionanado con la camara
		//{
		//	sceneObjects.push_back(gameObjects[i]);//se guardar en el vector de objetos que se mandara a pintar
		//}
	}
}

void SceneManager::checkOrder()
{
	for (int i = 0; i < sceneObjects.size(); i++)//por cada objeto que se vaya a pintar
	{
		for (int j = i + 1; j < sceneObjects.size(); j++)//se compara con los demas
		{
			if (sceneObjects[i].getPosition().z < sceneObjects[j].getPosition().z)//si la posicion del objeto en z es menor a la de otro
			{
				GameObject change = sceneObjects[i];//cambien de lugar
				sceneObjects[i] = sceneObjects[j];
				sceneObjects[i] = change;
			}
		}
	}
}

void SceneManager::onUpdate()
{
	culin();//se revisa que objetos se van a pintar
	checkOrder();//se ordenan los objetos por su posicion en z
	for (int i = 0; i < sceneObjects.size(); i++)//por cada objeto que va a pintar
	{
		sceneObjects[i].onUpdate();//se actualiza
	}
	RenderManager::render(wind,sceneObjects);//y se pintan
}
