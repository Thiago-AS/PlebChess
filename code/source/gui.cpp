// "Copyright 2018"
#include "../include/gui.h"

bool Gui::Init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL nao pode iniciar! SDL Error: " << SDL_GetError() << endl;
        success = false;
    } else {
        gWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

        if (gWindow == NULL) {
            cout << "Janela nao pode ser criada! SDL Error: " << SDL_GetError()
            << endl;
            success = false;
        } else {
          gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

void Gui::Close() {
  SDL_FreeSurface(gScreenSurface);
  gScreenSurface = NULL;

  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  SDL_Quit();
}
