// "Copyright 2018"
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

class Graphics {
 private:
  const int SCREEN_WIDTH = 680;
  const int SCREEN_HEIGHT = 680;
 public:
  bool init();
  void close();
};

#endif
