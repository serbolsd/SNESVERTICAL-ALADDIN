#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation() = default;
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Init(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void update(int row, float deltaTime, bool isFaceRight);

public:
	sf::IntRect m_uvRect;
private:
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;

	float m_totalTime;
	float m_switchTime; // Time that takes to change image
};
