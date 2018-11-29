// "Copyright 2018"
#ifndef GAME_OBJECTS_H
#define  GAME_OBJECTS_H

#include <string>
#include "./gui.h"

class GameObject {
 public:
  GameObject(string, SDL_Renderer*, int, int);
  ~GameObject();
 private:
  int x_pos;
  int y_pos;
  SDL_Texture* obj_texture;
  SDL_Rect src_rect, dst_rect;
  SDL_Renderer* renderer;
};


#endif
