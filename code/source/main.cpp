// "Copyright 2018"
#include "../include/gui_manager.h"

int main() {
  GuiManager* game = GuiManager::Instance();
  game->Run();
  GuiManager::Release();
  game = NULL;
  return 0;
}
