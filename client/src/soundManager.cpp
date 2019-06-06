#include "../include/soundManager.h"

SoundManager::SoundManager(){
	if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0){
		throw SdlException("Error en la inicialización de mixer", Mix_GetError());
	}
	this->music = Mix_LoadMUS(MUSIC_ROUTE); 
	if(this->music == nullptr) { 
		throw SdlException("Error abriendo archivo", Mix_GetError());
	}	
	this->jumpSound = Mix_LoadWAV( JUMP_SOUND_ROUTE ); 
	if(this->jumpSound == nullptr) { 
		throw SdlException("Error abriendo archivo", Mix_GetError());	
	}
	this->deathSound = Mix_LoadWAV( DEATH_SOUND_ROUTE ); 
	if(this->deathSound == nullptr) { 
		throw SdlException("Error abriendo archivo", Mix_GetError());	
	}
	this->fireSound = Mix_LoadWAV( FIRE_SOUND_ROUTE ); 
	if(this->fireSound == nullptr) { 
		throw SdlException("Error abriendo archivo", Mix_GetError());	
	}
}

SoundManager::~SoundManager(){
	Mix_FreeMusic(this->music);	
	Mix_FreeChunk(this->jumpSound);	
	Mix_FreeChunk(this->fireSound);
	Mix_FreeChunk(this->deathSound);
	Mix_Quit();	
}

void SoundManager::playMusic() const{
	if(Mix_PlayMusic(this->music, -1)==-1) {
    	throw SdlException("Error en la reproduciendo musica", Mix_GetError());    	
	}
}

void SoundManager::setMusicVolume(int volume){ //de 0 a 128	
	Mix_VolumeMusic(volume);
}

int SoundManager::getMusicVolume() const{
	return Mix_VolumeMusic(-1);
}

void SoundManager::resumeMusic() const{
	Mix_ResumeMusic();
}

void SoundManager::pauseMusic() const{
	Mix_PauseMusic();
}	

bool SoundManager::isMusicPaused() const{
	return Mix_PausedMusic()?true:false;
}

void SoundManager::playJumpSound() const{
	Mix_PlayChannel(-1, this->jumpSound, 0 );
}

void SoundManager::playFireSound() const{
	Mix_PlayChannel(-1, this->fireSound, 0 );
}

void SoundManager::playDeathSound() const{
	Mix_PlayChannel(-1, this->deathSound, 0 );
}

