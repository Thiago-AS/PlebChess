// "Copyright 2018"
#ifndef GAME_OBJECTS_H
#define  GAME_OBJECTS_H

#include <string>
#include <vector>
#include "./gui.h"

using namespace std;

enum class StructureType: int{
  CASTLE = 0,
  WOOD_CUT = 1,
  MINE = 2,
  BARRACK = 3
};

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
  SDL_Rect dst_rect;
};

class Structure:public GameObject {
 public:
  Structure(SDL_Texture*, int, int, int, int, int, StructureType, int);
 private:
  StructureType type;
  int health;
  int player;
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

class MapTile {
 public:
  char unit;
  SDL_Rect position;
  int player;
  GameObject* object;
};

class Map {
 public:
  SDL_Point focus;
  MapTile map[10][10];

  Map();
  ~Map();

  void DrawMap();
  void UpdateFocus(int, int, int);
  bool InsertObject(int, int);
  MapTile ReturnObject(int, int);

 private:
  SDL_Texture* tile;
};

#endif  // GAME_OBJECTS_H
