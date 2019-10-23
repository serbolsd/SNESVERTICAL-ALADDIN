#include "../include/Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	m_imageCount = imageCount;
	m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0; // Need to start Animation on zero

	m_uvRect.width = texture->getSize().x / float(imageCount.x);
	m_uvRect.height = texture->getSize().y / float(imageCount.y);
}


Animation::~Animation()
{
}

void Animation::Init(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	m_imageCount = imageCount;
	m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0; // Need to start Animation on zero

	m_uvRect.width = texture->getSize().x / float(imageCount.x);
	m_uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::update(int row, float deltaTime, bool isFaceRight)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;
	// Normalize Time to frame rate
	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0; // Set back to 0 if the index count is upper
		}
	}

	m_uvRect.top = m_currentImage.y * m_uvRect.height;
	// Rotate sprite
	if (isFaceRight)
	{
		m_uvRect.left = m_currentImage.x * abs(m_uvRect.width);
		m_uvRect.width = abs(m_uvRect.width);
	}
	else
	{
		m_uvRect.left = (m_currentImage.x + 1) * abs(m_uvRect.width);
		m_uvRect.width = -abs(m_uvRect.width);
	}
}