// "Copyright 2018"

#include "../include/screens.h"
#include "../include/texture_manager.h"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

void MainMenu::LoadScreen() {
  GameObject* start_button = NULL;
  GameObject* load_button = NULL;
  GameObject* exit_button = NULL;
  GameObject* cursor = NULL;

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

void MainMenu::EventHandler(SDL_Event &event) {
  int mouse_over;
  switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
      mouse_over = screen_objects.HandleMouse(event.button);
      switch (mouse_over) {
        case 0:
          Gui::current_screen = GameScreen::NEW_GAME;
          break;
        case 1:
          Gui::current_screen = GameScreen::LOAD_GAME;
          break;
        case 2:
          Gui::quit = true;
          break;
        default:
          break;
      }
      break;

    case SDL_MOUSEMOTION:
      mouse_over = screen_objects.HandleMouse(event.button);
      switch (mouse_over) {
        case 0:
          screen_objects.GetObject(3)->Update(240, 185);
          break;
        case 1:
          screen_objects.GetObject(3)->Update(240, 225);
          break;
        case 2:
          screen_objects.GetObject(3)->Update(240, 265);
          break;
        default:
          screen_objects.GetObject(3)->Update(-500, -500);
          break;
      }
      break;

    default:
      break;
  }
}

void MainMenu::Render() {
  screen_objects.Draw();
}

void MainMenu::Clean() {
  screen_objects.Clean();
}

GameScene::GameScene() {
  insertion_flag = -1;
  player_turn = 0;
}

GameScene::~GameScene() {
}

void GameScene::LoadScreen() {
  map = new Map();

  GameObject* archer_button = NULL;
  GameObject* knight_button = NULL;
  GameObject* warrior_button = NULL;
  GameObject* gold_icon = NULL;
  GameObject* wood_icon = NULL;
  GameObject* castle_icon = NULL;
  GameObject* wood_cutter_button = NULL;
  GameObject* barrack_button = NULL;
  GameObject* gold_mine_button = NULL;

  gold_icon = new GameObject(TextureManager::LoadTexture
                         ("../assets/gold.png"), 645, 5, 64, 64);
  wood_icon = new GameObject(TextureManager::LoadTexture
                         ("../assets/wood.png"), 730, 5, 64, 64);

  wood_cutter_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/woodcut.png"), 645, 512, 64, 64);
  button_objects.AddObject(wood_cutter_button);
  barrack_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/barrack.png"), 645, 576, 64, 64);
  button_objects.AddObject(barrack_button);
  gold_mine_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/mine.png"), 730, 576, 64, 64);
  button_objects.AddObject(gold_mine_button);

  archer_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/archer.png"), 645, 320, 64, 64);
  button_objects.AddObject(archer_button);
  knight_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/knight.png"), 645, 384, 64, 64);
  button_objects.AddObject(knight_button);
  warrior_button = new GameObject(TextureManager::LoadTexture
                         ("../assets/warrior.png"), 730, 384, 64, 64);
  button_objects.AddObject(warrior_button);
}

void GameScene::EventHandler(SDL_Event &event) {
  int mouse_over, x, y;
  switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
      mouse_over = button_objects.HandleMouse(event.button);
      cout << mouse_over << endl;
      if (mouse_over != -1) {
        insertion_flag = mouse_over;
      }
      if ((mouse_over == -1) && (insertion_flag != -1)) {
        cout << insertion_flag << endl;
        SDL_GetMouseState(&x, &y);
        map->UpdateFocus(x, y, player_turn);
        if (map->InsertObject(insertion_flag, player_turn)) {
          player_turn ^= 1;
          insertion_flag = -1;
        }
      }
      break;

    default:
      break;
  }
}

void GameScene::Render() {
  map->DrawMap();
  button_objects.Draw();
}

void GameScene::Clean() {
}
