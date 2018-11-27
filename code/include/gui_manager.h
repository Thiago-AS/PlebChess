// "Copyright 2018"
#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include "./gui.h"

class GuiManager {
 private:
  static GuiManager* instance;
  bool quit;
  Gui* gui;

  GuiManager();
  ~GuiManager();

 public:
  static GuiManager* Instance();
  static void Release();

  void Run();
  void HandleEvents();
};

#endif  // GUI_MANAGER_H
