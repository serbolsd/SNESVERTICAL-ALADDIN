#include "../include/Animator.h"
#include <iostream>

Animator::Animator()
{
}

Animator::~Animator()
{
}

Animation Animator::Init(AnimatorDesc _pathsDesc, sf::RectangleShape * _Player, unsigned int _animID)
{
	pathsDesc = _pathsDesc;
	Player = _Player;
	animID = _animID;
  if (_animID == 0)
  {
    /**
     * @brief : Idle Animation
     */
	if (!m_playerTexture.loadFromFile(_pathsDesc.IdlePath))
	{
	  std::cout << "cant lodad texture\n";
	}
    _Player->setTexture(&m_playerTexture);
    m_animation.Init(&m_playerTexture, _pathsDesc.idleProportion, .2f);
    return m_animation;
  }
  if (_animID == 1)
  {
    /**
     * @brief : Swing Animation
     */
    if (!m_playerTexture.loadFromFile(_pathsDesc.RunPath))
    {
      std::cout << "cant lodad texture\n";
    }
    _Player->setTexture(&m_playerTexture);
    m_animation.Init(&m_playerTexture, _pathsDesc.runProportion, .2f);
    return m_animation;
  }
}

void Animator::update()
{
  if (myObject->animatorID != animID)
  {
	  changeAnim();
  }
  m_animation.update(0, *myObject->deltaTime, true);
  myObject->getshape()->setTextureRect(m_animation.m_uvRect);
}

Animation Animator::changeAnim()
{
	animID=myObject->animatorID;
	if (myObject->animatorID == 0)
	{
		/**
		 * @brief : Idle Animation
		 */
		if (!m_playerTexture.loadFromFile(pathsDesc.IdlePath))
		{
			std::cout << "cant lodad texture\n";
		}
		myObject->getshape()->setTexture(&m_playerTexture);
		m_animation.Init(&m_playerTexture, pathsDesc.idleProportion, .2f);
		return m_animation;
	}
	if (myObject->animatorID == 1)
	{
		/**
		 * @brief : walk for left Animation
		 */
		if (!m_playerTexture.loadFromFile(pathsDesc.RunPath))
		{
			std::cout << "cant lodad texture\n";
		}
		myObject->getshape()->setTexture(&m_playerTexture);
		m_animation.Init(&m_playerTexture, pathsDesc.runProportion, 0.15f);
		if (right)
		{
			right = false;
			myObject->shape->scale(-1, 1);
		}
		return m_animation;
	}
	if (myObject->animatorID == 2)
	{
		/**
		 * @brief : walk for right Animation
		 */
		if (!m_playerTexture.loadFromFile(pathsDesc.RunPath))
		{
			std::cout << "cant lodad texture\n";
		}
		myObject->getshape()->setTexture(&m_playerTexture);
		m_animation.Init(&m_playerTexture, pathsDesc.runProportion, 0.15f);
		if (!right)
		{
			right = true;
			myObject->shape->scale(-1, 1);
		}
		return m_animation;
	}
	if (myObject->animatorID == 3)
	{
		/**
		 * @brief : run for left Animation
		 */
		if (!m_playerTexture.loadFromFile(pathsDesc.RunPath))
		{
			std::cout << "cant lodad texture\n";
		}
		myObject->getshape()->setTexture(&m_playerTexture);
		m_animation.Init(&m_playerTexture, pathsDesc.runProportion, 0.085f);
		if (right)
		{
			right = false;
			myObject->shape->scale(-1, 1);
		}
		return m_animation;
	}
	if (myObject->animatorID == 4)
	{
		/**
		 * @brief : run for right Animation
		 */
		if (!m_playerTexture.loadFromFile(pathsDesc.RunPath))
		{
			std::cout << "cant lodad texture\n";
		}
		myObject->getshape()->setTexture(&m_playerTexture);
		if (!right)
		{
			right = true;
			myObject->shape->scale(-1, 1);
		}
		m_animation.Init(&m_playerTexture, pathsDesc.runProportion, 0.085f);
		return m_animation;
	}
	
}

Animation & Animator::getAnimation()
{
  return m_animation;
}

