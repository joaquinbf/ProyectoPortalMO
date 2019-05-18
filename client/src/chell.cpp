#include "../include/chell.h"
#include "../include/Area.h"
#include "../include/SdlTexture.h"

Chell::Chell(const SdlWindow& window)
: texture(window), area(0, 0, 104, 215){
	this->texture.loadTexture(IDLE_TEXTURE);
}

Chell::~Chell(){}

int Chell::render(int x, int y){
	return this->texture.render(this->area, Area(x,y,104,215));
}
