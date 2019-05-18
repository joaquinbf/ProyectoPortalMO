#include <iostream>
#include <SDL2/SDL.h>
#include <exception>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/chell.h"
#include "../include/client.h"

Client::Client(){}
Client::~Client(){}

int Client::main(){
	try {
        SdlWindow window(800, 600);
        window.fill();
        // Usar factory
        //SdlTexture im("../resources/textures/chell-idle.png", window);
        Chell chell(window);
        //Area srcArea(0, 0, 104, 215);
        bool running = true;
        int x = 100;
        int y = 150;
        while (running) {
            SDL_Event event;
            //Area destArea(x, y, 104, 215);
            window.fill(); // Repinto el fondo gris
            //im.render(srcArea, destArea);
            chell.render(x,y);
            // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
            SDL_WaitEvent(&event);
            switch(event.type) {
                case SDL_KEYDOWN: {
                        SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                        switch (keyEvent.keysym.sym) {
                            case SDLK_LEFT:
                                x -= 10;
                                break;
                            case SDLK_RIGHT:
                                x += 10;
                                break;
                            case SDLK_UP:
                                y -= 10;
                                break;
                            case SDLK_DOWN:
                                y += 10;
                                break;
                            }
                    } // Fin KEY_DOWN
                    break;
                case SDL_QUIT:
                    running = false;
                    break;
            }
            window.render();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
	return 0;
}