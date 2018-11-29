// "Copyright 2018"
#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "./texture_manager.h"
#include "./game_objects.h"

using namespace std;

class Gui {
 private:
  static Gui* instance;
  static bool initialized;
  SDL_Window* mWindow;

  Gui();
  ~Gui();
  bool Init();

 public:
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 640;
  static SDL_Renderer* gRenderer;

  static Gui* Instance();
  static void Release();
  static bool Initialized();
  void Render();
  void Update();
};

#endif
