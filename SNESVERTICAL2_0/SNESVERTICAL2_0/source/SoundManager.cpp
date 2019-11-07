#include "../include/SoundManager.h"

SoundManager::SoundManager()
{
}

void SoundManager::SoundFX(int  GameID)
{
	sf::Sound Lmao;
	sf::SoundBuffer Lmao2;
	std::string Transformmm = std::to_string(GameID);
	std::string FileName = Transformmm + ".wav";
	Lmao2.loadFromFile(FileName);
	Lmao.setBuffer(Lmao2);
	Lmao.play();
}

void SoundManager::SceneSound(int& MusicID)
{
	sf::Sound Lmao;
	sf::SoundBuffer Lmao2;
	std::string Transformmm = std::to_string(MusicID);
	std::string FileName = Transformmm + ".wav";
	Lmao2.loadFromFile(FileName);
	Lmao.setBuffer(Lmao2);
	
	if (onOroff == true)
	{

		Lmao.setLoop(true);


	}
	else if (onOroff == false)
	{
		Lmao.setLoop(false);
	}
	if (pause == true)
	{
		Lmao.pause();
	}
	Lmao.play();

	
}

