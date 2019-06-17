#ifndef _PAUSE_VIEW_H_
#define _PAUSE_VIEW_H_

#include <SDL2/SDL_ttf.h>
#include <string>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/textureManager.h"
#include "../include/Area.h"

class PauseView{
private:
	const TextureManager& textureManager;
	const SdlWindow& window;
	SdlTexture* blackTexture;
	Area blackArea;
	TTF_Font* font = NULL;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
public:
	explicit PauseView(const TextureManager& textureManager,const SdlWindow& window);
	~PauseView();
	void render(uint32_t resx,uint32_t resy);
	void mouseButtonDown(uint32_t x,uint32_t y);
};

#endif
