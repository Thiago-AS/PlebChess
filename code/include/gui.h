// "Copyright 2018"
#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

class Gui {
 private:
  const int SCREEN_WIDTH = 680;
  const int SCREEN_HEIGHT = 680;
 public:
  bool init();
  void close();
};

#endif
