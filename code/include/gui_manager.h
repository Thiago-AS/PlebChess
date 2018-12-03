/**
 * @file gui_manager.h
 * @brief Arquivo que instancia e controla o jogo.
 * @author Thiago Araujo (@Thiago-AS)
 * @copyright Copyright (c) 2018
 */
#ifndef CODE_INCLUDE_GUI_MANAGER_H_
#define CODE_INCLUDE_GUI_MANAGER_H_

#include "./gui.h"

class GuiManager {
 private:
  static GuiManager* instance;
  Gui* gui;

  GuiManager();
  ~GuiManager();

 public:
  static GuiManager* Instance();
  static void Release();

  void Run();
};

#endif  // CODE_INCLUDE_GUI_MANAGER_H_
