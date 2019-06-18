#ifndef _PAUSE_VIEW_H_
#define _PAUSE_VIEW_H_

#include <string>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/textureManager.h"
#include "../include/Area.h"
#include "../include/pauseWidget.h"

class PauseView{
private:
	const TextureManager& textureManager;
	SdlTexture* blackTexture;
	Area blackArea;
	PauseWidget pwPause;
	PauseWidget pwResume;
	PauseWidget pwOptions;
	PauseWidget pwExit;
public:
	explicit PauseView(const TextureManager& textureManager,const SdlWindow& window);
	~PauseView();
	void render(uint32_t resx,uint32_t resy);
	void mouseButtonDown(uint32_t x,uint32_t y);
};

#endif
