// "Copyright 2018"
#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

enum class GameScreen: int {
    MAIN_MENU = 0,
    NEW_GAME = 1,
    PAUSE_MENU = 2
};

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
  static TTF_Font * game_font;
  static GameScreen current_screen;
  static bool quit;

  static Gui* Instance();
  static void Release();
  static bool Initialized();
  void HandleEvents();
  void Render();
  void Update();
};

#endif
