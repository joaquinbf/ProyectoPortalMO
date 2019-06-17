#ifndef _PAUSE_VIEW_H_
#define _PAUSE_VIEW_H_

#include "../include/textureManager.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

class PauseView{
private:
	const TextureManager& textureManager;
	SdlTexture* blackTexture;
	Area blackArea;
public:
	explicit PauseView(const TextureManager& textureManager);
	~PauseView();
	void render(uint32_t resx,uint32_t resy);
};

#endif
