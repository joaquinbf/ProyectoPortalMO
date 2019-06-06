#include "../include/soundManager.h"

SoundManager::SoundManager(){
	 Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ); 
	this->music = Mix_LoadMUS(MUSIC_ROUTE); 
}

SoundManager::~SoundManager(){
	Mix_FreeMusic(this->music);
}

void SoundManager::playMusic(){
	if(Mix_PlayMusic(this->music, -1)==-1) {
    	printf("Mix_PlayMusic: %s\n", Mix_GetError());    	
	}
	//Mix_PlayMusic(this->music, -1 );
}
