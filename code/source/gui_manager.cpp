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
  quit = false;
  gui = Gui::Instance();

  if (!Gui::Initialized())
    quit = true;
}

GuiManager::~GuiManager() {
  Gui::Release();
  gui = NULL;
}

void GuiManager::HandleEvents() {
  SDL_Event events;
  SDL_PollEvent(&events);
  switch (events.type) {
    case SDL_QUIT:
      quit = true;
      break;

    default:
      break;
  }
}

void GuiManager::Run() {
  while (!quit) {
    HandleEvents();
    gui->Update();
    gui->Render();
  }
}
