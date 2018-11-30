// "Copyright 2018"
#include "../include/gui_manager.h"

GuiManager* GuiManager::instance = NULL;

GuiManager* GuiManager::Instance() {
  if (instance == NULL)
    instance = new GuiManager();

  return instance;
}

void GuiManager::Release() {
  delete instance;
  instance = NULL;
}

GuiManager::GuiManager() {
  gui = Gui::Instance();

  if (!Gui::Initialized())
    Gui::quit = true;
}

GuiManager::~GuiManager() {
  Gui::Release();
  gui = NULL;
}

void GuiManager::Run() {
  while (!Gui::quit) {
    gui->HandleEvents();
    gui->Update();
    gui->Render();
  }
}
