#include "../include/SdlWindow.h"

SdlWindow::SdlWindow(int width, int height) :
        width(width), height(height) {
    int errCode = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (errCode) {
        throw SdlException("Error en la inicialización", SDL_GetError());
    }
    errCode = SDL_CreateWindowAndRenderer(
        this->width, this->height, SDL_RENDERER_ACCELERATED | SDL_WINDOW_BORDERLESS |
         SDL_WINDOW_ALWAYS_ON_TOP,
        &this->window, &this->renderer);
    if (errCode) {
        throw SdlException("Error al crear ventana", SDL_GetError());
    }   
    SDL_HideWindow(this->window);
}

SdlWindow::~SdlWindow() {
    if (this->renderer) {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }

    if (this->window) {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
}

void SdlWindow::show(){
    SDL_ShowWindow(this->window);
}

void SdlWindow::fill(int r, int g, int b, int alpha) {
    SDL_SetRenderDrawColor(this->renderer,
                           r, g, b, alpha);
    SDL_RenderClear(this->renderer);
}

void SdlWindow::fill() {
    this->fill(0x33,0x33,0x33,0xFF);
}

void SdlWindow::render() {
    SDL_RenderPresent(this->renderer);
}

int SdlWindow::getResX() const{
    int resx;
    int resy;
    SDL_GetWindowSize(this->window, &resx,&resy);
    return resx;
}

int SdlWindow::getResY() const{
    int resx;
    int resy;
    SDL_GetWindowSize(this->window, &resx,&resy);
    return resy;
}

SDL_Renderer* SdlWindow::getRenderer() const {
    return this->renderer;
}

void SdlWindow::fullscreen(){
    SDL_SetWindowFullscreen(this->window,SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void SdlWindow::windowed(){
    SDL_SetWindowFullscreen(this->window,0);
}
