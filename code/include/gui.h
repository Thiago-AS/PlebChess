// "Copyright 2018"
#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Gui {
 private:
  static Gui* instance;
  static bool initialized;
  SDL_Window* mWindow;
  SDL_Surface* mBackBuffer;

  Gui();
  ~Gui();
  bool Init();

 public:
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  static Gui* Instance();
  static void Release();
  static bool Initialized();
  void Render();
};

#endif
