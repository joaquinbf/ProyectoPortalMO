#include <SDL2/SDL_image.h>
#include <string>

#include "../include/SdlTexture.h"
#include "../include/SdlWindow.h"
#include "../include/SdlException.h"

SdlTexture::SdlTexture(const SdlWindow& window)   
    : renderer(window.getRenderer()){}

SdlTexture::SdlTexture(const std::string &filename, const SdlWindow& window)
    : renderer(window.getRenderer()) {
    this->texture = loadTexture(filename);
}

SdlTexture::~SdlTexture() {
    SDL_DestroyTexture(this->texture);
}

SDL_Texture* SdlTexture::loadTexture(const std::string &filename) {
    SDL_Texture* texture = IMG_LoadTexture(this->renderer,
                                           filename.c_str());
    if (!texture) {
        throw SdlException("Error al cargar la textura", SDL_GetError());
    }
    return texture;
}

int SdlTexture::render(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };

    return SDL_RenderCopy(this->renderer, this->texture, &sdlSrc, &sdlDest);
}

int SdlTexture::renderFlipedVertical(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, SDL_FLIP_VERTICAL);
}

int SdlTexture::renderFlipedHorizontal(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, SDL_FLIP_HORIZONTAL);
}

int SdlTexture::renderFlipedDiagonal(const Area& src, const Area& dest) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {0, 0};
    
    SDL_RendererFlip flip =(SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);

    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        0,&center, flip);
}


int SdlTexture::renderInAngle(const Area& src, const Area& dest,double angle) const {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    SDL_Point center = {dest.getWidth()/2, dest.getHeight()/2};

    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest,
        angle,&center, SDL_FLIP_NONE);
}