#include "SoundManager.h"
#include"SFML/Audio.hpp"
#include<string>
SoundManager::SoundManager()
{
	std::cout << "Este objeto esta aqui" << std::endl;
}

void SoundManager::SoundFX(int& GameID)
{
	sf::Sound Lmao;
	sf::SoundBuffer Lmao2;
	std::string Transformmm = std::to_string(GameID);
	std::string FileName = Transformmm + ".wav";
	Lmao2.loadFromFile(FileName);
	Lmao.setBuffer(Lmao2);
	Lmao.play();
}
