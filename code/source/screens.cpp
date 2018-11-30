// "Copyright 2018"

#include "../include/screens.h"
#include "../include/texture_manager.h"

GameObject* start_button = NULL;
GameObject* load_button = NULL;
GameObject* exit_button = NULL;
GameObject* cursor = NULL;

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

void MainMenu::LoadScreen() {
  int sw, sh, lw, lh, ew, eh;
  SDL_Texture* fontSup = TextureManager::LoadTTF(Gui::game_font, "START GAME");
  SDL_QueryTexture(fontSup, NULL, NULL, &sw, &sh);
  start_button = new GameObject(fontSup, 300, 200, sw, sh);
  screen_objects.AddObject(start_button);

  SDL_Texture* fontSup2 = TextureManager::LoadTTF(Gui::game_font, "LOAD GAME");
  SDL_QueryTexture(fontSup2, NULL, NULL, &lw, &lh);
  load_button = new GameObject(fontSup2, 310, 240, lw, lh);
  screen_objects.AddObject(load_button);

  SDL_Texture* fontSup3 = TextureManager::LoadTTF(Gui::game_font, "EXIT GAME");
  SDL_QueryTexture(fontSup3, NULL, NULL, &ew, &eh);
  exit_button = new GameObject(fontSup3, 310, 280, ew, eh);
  screen_objects.AddObject(exit_button);

  cursor = new GameObject(TextureManager::LoadTexture
                         ("../assets/cursorBlack.png"), -500, -500, 64, 64);
  screen_objects.AddObject(cursor);
}

void MainMenu::EventHandler(SDL_MouseButtonEvent &button_event) {
  int mouse_over;
  mouse_over = screen_objects.HandleMouse(button_event);
  switch (mouse_over) {
    case 0:
      cout << "AK0" << endl;
      break;
    case 1:
      cout << "AK1" << endl;
      break;
    case 2:
      Gui::quit = true;
      break;
    default:
      cout << "nenhum botao" << endl;
      break;
  }
}

void MainMenu::Update() {
}

void MainMenu::Render() {
  screen_objects.Draw();
}

void MainMenu::Clean() {
  screen_objects.Clean();
}
