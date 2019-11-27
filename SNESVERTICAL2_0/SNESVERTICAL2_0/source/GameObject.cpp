#include "../include/GameObject.h"
#include <iostream>
#include "../include/boxCollider.h"

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
	if (position==nullptr)
	{
		position = new sf::Vector3f();
	}
	*position = pos;
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
			if (newcomponent->type==collider)
			{
				boxCollider* box1 = dynamic_cast<boxCollider*> (components[i]);
				boxCollider* box2 = dynamic_cast<boxCollider*> (newcomponent);
				if (box1->getType()==box2->getType())
				{
					//se manda un mensaje de que ya existe y se retorna la funcion
					std::cout << "the collider is already exists" << std::endl;
					return;
				}
				else
				{
					continue;
				}
			}
			else
			{
				//se manda un mensaje de que ya existe y se retorna la funcion
				std::cout << "the componet is already exists" << std::endl;
				return;
			}
		}
	}
	if (newcomponent->type==collider)
	{
		boxCollider* box2 = dynamic_cast<boxCollider*>(newcomponent);
		colliders.push_back(box2);
	}
	newcomponent->myObject = this;
	//si no se encuentra su existencia se agrega
	components.push_back(newcomponent);
}

