#include "../include/GameObject.h"
#include <iostream>


void GameObject::onDelete()
{
	//Al terminar libera los componentes de su lista
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

Component* GameObject::getComponente(typecomponent componenttype)
{
	for (int i = 0; i < components.size(); i++)//revisara todos los componente en su lista de componentes
	{
		if (components[i]->type== componenttype)//si encuentra el componente que se busca se retorna
		{
			return components[i];
		}
	}
	std::cout << "not find that component type"<<std::endl;//si no se encuentra se manda un mensaje y se retorna null
	return NULL;
}

void GameObject::setTypeObject(TypeObject typeobject)
{
	type = typeobject;
}

void GameObject::setPosition(sf::Vector3f pos)
{
	position = pos;
}

void GameObject::setPosition(float posx, float posy, float posz)
{
	setPosition(sf::Vector3f(posx,posy,posz));
}

void GameObject::setComponente(Component *newcomponent)	
{
	for (int i = 0; i < components.size(); i++)//revisara todos los componente en su lista de componentes
	{
		if (components[i]->type == newcomponent->type)//si encuentra que el componente ya existe no se agrega
		{
			//se manda un mensaje de que ya existe y se retorna la funcion
			std::cout << "the componet already exists" << std::endl;
			return;
		}
	}
	newcomponent->myObject = this;
	//si no se encuentra su existencia se agrega
	components.push_back(newcomponent);
}

