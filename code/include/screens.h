// "Copyright 2018"
#ifndef SCREENS_H
#define  SCREENS_H

#include "./game_objects.h"

class MainMenu {
 public:
  MainMenu();
  ~MainMenu();

  void EventHandler(SDL_MouseButtonEvent&);
  void LoadScreen();
  void Update();
  void Render();
  void Clean();

 private:
  VectorObjects screen_objects;
};








#endif  // SCREENS_H
