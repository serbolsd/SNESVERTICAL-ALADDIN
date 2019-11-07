#pragma once
#include "SFML/Audio.hpp"
struct SoundManager {
	bool  onOroff; 
	bool pause;
	SoundManager();//constructor
	void SoundFX(int GameID);
	void SceneSound(int&MusicID);
	


};