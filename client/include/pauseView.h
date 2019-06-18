#ifndef _PAUSE_VIEW_H_
#define _PAUSE_VIEW_H_

#include <string>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/textureManager.h"
#include "../include/Area.h"
#include "../include/pauseWidget.h"

class GameView;

enum PAUSE_STATUS: uint8_t {
	INIT,
	OPTIONS,
};

class PauseView{
private:
	const TextureManager& textureManager;
	GameView& gameView;
	SdlTexture* blackTexture;
	Area blackArea;
	PauseWidget pwPause;
	PauseWidget pwResume;
	PauseWidget pwOptions;
	PauseWidget pwExit;
	PAUSE_STATUS status = INIT;
	uint32_t resx = 0;
	uint32_t resy = 0;
	bool stop = false;
public:
	explicit PauseView(const TextureManager& textureManager,const SdlWindow& window,
		GameView& gv);
	~PauseView();
	void render(uint32_t resx,uint32_t resy);
	void mouseButtonDown(uint32_t x,uint32_t y);
	void back();
	bool stoped();
};

#endif
