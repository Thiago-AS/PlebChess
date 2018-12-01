// "Copyright 2018"
#ifndef GAME_OBJECTS_H
#define  GAME_OBJECTS_H

#include <string>
#include <vector>
#include "./gui.h"

using namespace std;

class GameObject {
 public:
  GameObject(SDL_Texture*, int, int, int, int);
  ~GameObject();
  bool HandleMouse(SDL_MouseButtonEvent&);
  void Update(int, int);
  void Render();
  void Clean();

 private:
  SDL_Texture* obj_texture;
  SDL_Rect src_rect, dst_rect;
};

class VectorObjects {
 public:
  void AddObject(GameObject*);
  GameObject* GetObject(int);
  int HandleMouse(SDL_MouseButtonEvent&);
  void Draw();
  void Update();
  void Clean();

 private:
  vector<GameObject*> objects_vector;
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
