// "Copyright 2018"
#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include "./gui.h"

class GuiManager {
 private:
  static GuiManager* instance;
  bool quit;
  Gui* gui;
  SDL_Event events;

  GuiManager();
  ~GuiManager();

 public:
  static GuiManager* Instance();
  static void Release();

  void Run();
};

#endif  // GUI_MANAGER_H
