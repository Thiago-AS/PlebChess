// "Copyright 2018"
#ifndef SCREENS_H
#define  SCREENS_H

#include "./game_objects.h"
#include <vector>

class MainMenu {
 public:
  MainMenu();
  ~MainMenu();

  void EventHandler(SDL_Event&);
  void LoadScreen();
  void Render();
  void Clean();

 private:
  VectorObjects screen_objects;
};

class GameScene {
 public:
  GameScene();
  ~GameScene();

  void EventHandler(SDL_Event&);
  void LoadScreen();
  void Render();
  void Clean();

 private:
  int player_turn;
  VectorObjects button_objects;
  vector<Structure> structure_objects;
  Map* map;
  int insertion_flag;
};







#endif  // SCREENS_H
