// "Copyright 2018"
#ifndef GAME_OBJECTS_H
#define  GAME_OBJECTS_H

#include <string>
#include "./gui.h"

using namespace std;

class GameObject {
 public:
  GameObject(SDL_Texture*, int, int, int, int);
  ~GameObject();
  bool HandleMouse(SDL_Event*);
  void Update(int, int, int, int);
  void Render();

 private:
  SDL_Texture* obj_texture;
  SDL_Rect src_rect, dst_rect;
};

<<<<<<< HEAD
=======
class VectorObjects {
 public:
  void AddObject(GameObject*);
  GameObject* GetObject(int);
  int HandleMouse(SDL_Event*);
  void Draw();
  void Update();
  void Clean();

 private:
  vector<GameObject*> objects_vector;
};

>>>>>>> Mudando função de atualização de posição
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
