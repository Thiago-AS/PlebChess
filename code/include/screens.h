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

 private:
  VectorObjects screen_objects;
};

class PauseMenu {
 public:
  PauseMenu();
  ~PauseMenu();

  void EventHandler(SDL_Event&);
  void LoadScreen();
  void Render();

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

 private:
  Player* player0;
  Player* player1;
  int player_turn;
  VectorObjects button_objects;
  VectorObjects texts;
  Map* map;
  int insertion_flag;
  int move_flag;
  SDL_Point to_be_moved;
};







#endif  // SCREENS_H
