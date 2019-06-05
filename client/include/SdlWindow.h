#ifndef __SDL_WINDOW_H__
#define __SDL_WINDOW_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
//#include <SDL2/SDL_mixer.h> 
#include <SDL_mixer.h>

#include "../include/SdlException.h"
#include "Area.h"


class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class SdlWindow {
public:
    SdlWindow(int width, int height);
    ~SdlWindow();
    void show();
    void fill();
    void fill(int r, int g, int b, int alpha);
    void render();
    void fullscreen();
    void windowed();
    int getResX() const;
    int getResY() const;
    SDL_Renderer* getRenderer() const;
private:
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
