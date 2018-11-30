// "Copyright 2018"
#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

<<<<<<< HEAD
=======
enum class GameScreen: int {
    MAIN_MENU = 0,
    NEW_GAME = 1,
    LOAD_GAME = 2
};

>>>>>>> Carregando TTF
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
<<<<<<< HEAD
=======
  static TTF_Font * game_font;
  static GameScreen current_screen;
<<<<<<< HEAD
>>>>>>> Carregando TTF
=======
  static bool quit;
>>>>>>> Adicionando verificação de botoes

  static Gui* Instance();
  static void Release();
  static bool Initialized();
  void Render();
  void Update();
};

#endif
