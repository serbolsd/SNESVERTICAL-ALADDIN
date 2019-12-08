#include "../include/GameObject.h"
#include <iostream>
#include "../include/boxCollider.h"

void GameObject::onDelete()
{
	//Al terminar libera los componentes de su lista
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->onDelete();
		delete components[i];
	}
	if (speed)
	{
		delete speed;					speed = nullptr;
	}
	if (actualSpeed)
	{
		delete actualSpeed;				actualSpeed = nullptr;
	}
	if (speedRun)
	{
		delete speedRun;				speedRun = nullptr;
	}
	if (speedJump)
	{
		delete speedJump;				speedJump = nullptr;
	}
	if (speedPlane)
	{
		delete speedPlane;				speedPlane = nullptr;
	}
	if (shape)
	{
		delete shape;					shape = nullptr;
	}
	if (currentJumpForce)
	{
		delete currentJumpForce;		currentJumpForce = nullptr;
	}
	if (JumpForce)
	{
		delete JumpForce;				JumpForce = nullptr;
	}
	if (ParachuteForce)
	{
		delete ParachuteForce;			ParachuteForce = nullptr;
	}
	if (currentParachuteForce)
	{
		delete currentParachuteForce;	currentParachuteForce = nullptr;
	}
	if (fallTime)
	{
		delete fallTime;				fallTime = nullptr;
	}
	if (grabbedTime)
	{
		delete grabbedTime;				grabbedTime = nullptr;
	}
	if (animationTime)
	{
		delete animationTime;			animationTime = nullptr;
	}
	if (position)
	{
		delete position;				position = nullptr;
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

void GameObject::getColliders(std::vector<boxCollider*> &colls)
{
	for (size_t i = 0; i < mycolliders.size(); i++)
	{
		colls.push_back(mycolliders[i]);
	}
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
					if (box2->getType()==COLLIDERTYPE::HITBOXCOLLIDER)
					{
						hitbox = box2;
					}
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
		mycolliders.push_back(box2);
		colliders.push_back(box2);
	}
	newcomponent->myObject = this;
	//si no se encuentra su existencia se agrega
	components.push_back(newcomponent);
}

