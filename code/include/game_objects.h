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

class Map{
 public:
  Map();
  ~Map();

  void DrawMap();

 private:
  SDL_Rect src, dst;
  SDL_Texture* tile;

  static char map[10][10];
};

#endif  // GAME_OBJECTS_H
