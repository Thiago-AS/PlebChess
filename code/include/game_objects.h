// "Copyright 2018"
#ifndef GAME_OBJECTS_H
#define  GAME_OBJECTS_H

#include <string>
#include "./gui.h"

using namespace std;

class GameObject {
 public:
  GameObject(string, int, int);
  ~GameObject();
  void Update();
  void Render();

 private:
  int x_pos;
  int y_pos;
  SDL_Texture* obj_texture;
  SDL_Rect src_rect, dst_rect;
};


#endif
