#ifndef _TEXT_WIDGET_H_
#define _TEXT_WIDGET_H_

#include <SDL2/SDL_ttf.h>
#include <string>
#include <stdexcept>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"

#define FONT_DIR "../resources/fonts/font.ttf"

class TextWidget{
private:	
	const SdlWindow& window;
	std::string str;
	TTF_Font* font = nullptr;
	SDL_Color textColor;
	SDL_Surface* textSurface = nullptr;
	SDL_Texture* texturePtr = nullptr;	
	float x;
	float y;
	bool selected;
public:
	explicit TextWidget(const SdlWindow& window,const std::string str,float x,float y);
	explicit TextWidget(const SdlWindow& window,const std::string str,float x,float y,
		uint32_t size);
	~TextWidget();
	void render(uint32_t resx,uint32_t resy);
	bool cursorOn(uint32_t x,uint32_t y,uint32_t resx,uint32_t resy);
	void select();
	void deselect();
	void changeString(const std::string& s);
	void lock();
	void unlock();
private:
	void changeColor(uint8_t r,uint8_t g,uint8_t b);	
};

#endif
