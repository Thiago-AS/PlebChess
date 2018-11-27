// "Copyright 2018"
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL_image.h>
#include <string>
#include "./gui.h"

using namespace std;

class TextureManager {
 public:
  static SDL_Texture* LoadTexture(string, SDL_Renderer* renderer);
};

#endif
