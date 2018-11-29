// "Copyright 2018"
#include "../include/texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(string file_name) {
  SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Gui::gRenderer,
                                                      temp_surface);
  SDL_FreeSurface(temp_surface);

  return texture;
}
