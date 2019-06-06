#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include <SDL_mixer.h>

#define MUSIC_ROUTE "../resources/sounds/portal-soundtrack-self-esteem-fund.mp3"

class SoundManager{
private:
	Mix_Music * music = NULL;
public:
	SoundManager();
	~SoundManager();
	void playMusic();	
};

#endif
