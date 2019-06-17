#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_

#include <cstdint>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <unistd.h>
#include <exception>
#include <map>
#include <list>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/entity.h"
#include "../include/entityFactory.h"
#include "../include/serverManager.h"
#include "../include/soundManager.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/textureManager.h"
#include "../include/background.h"
#include "../include/pauseView.h"

#include "../../common/include/port.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"

class GameView{
private:
	int resx;
	int resy;	
	SdlWindow window;
	TextureManager textureManager;
	const SoundManager& soundManager;
	std::map<uint32_t,Entity *> entities;
	std::map<uint32_t,Chell *> chells;
	Chell* myChell;
	uint32_t myChellId;
	float scale;
	bool paused;
	bool danceMode = false;
	Background background;
	SDL_Cursor* cursor;
	PauseView pauseView;
public:
	explicit GameView(uint32_t x, uint32_t y,const SoundManager& sm);
	~GameView();
	void step();
	void render();
	void updateHandler(Update update);
	void zoomIn();
	void zoomOut();
	uint32_t getChellId() const;
	void setChellId(uint32_t id);
	void show();
	void updateResolution();
	void fullscreen();
    void windowed();
    bool isPaused() const;
    void pause();
    int32_t pixelToCoordX(int32_t x) const;
    int32_t pixelToCoordY(int32_t y) const;
    SDL_Renderer* getRenderer() const;
    uint32_t getResX() const;
    uint32_t getResY() const;
    PauseView* getPausePtr();
private:
	uint8_t getRand() const;
};

#endif
