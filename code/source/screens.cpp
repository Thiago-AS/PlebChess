// "Copyright 2018"
#include "../include/screens.h"
#include "../include/texture_manager.h"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
  screen_objects.Clean();
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
          Gui::quit = true;
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

PauseMenu::PauseMenu() {
}

PauseMenu::~PauseMenu() {
  screen_objects.Clean();
}

void PauseMenu::LoadScreen() {
  GameObject* continue_button = NULL;
  GameObject* exit_button = NULL;
  GameObject* cursor = NULL;

  int sw, sh, lw, lh, ew, eh;
  SDL_Texture* fontSup = TextureManager::LoadTTF(Gui::game_font, "CONTINUE");
  SDL_QueryTexture(fontSup, NULL, NULL, &sw, &sh);
  continue_button = new GameObject(fontSup, 315, 200, sw, sh);
  screen_objects.AddObject(continue_button);

  SDL_Texture* fontSup3 = TextureManager::LoadTTF(Gui::game_font, "EXIT GAME");
  SDL_QueryTexture(fontSup3, NULL, NULL, &ew, &eh);
  exit_button = new GameObject(fontSup3, 310, 240, ew, eh);
  screen_objects.AddObject(exit_button);

  cursor = new GameObject(TextureManager::LoadTexture
                         ("../assets/cursorBlack.png"), -500, -500, 64, 64);
  screen_objects.AddObject(cursor);
}

void PauseMenu::EventHandler(SDL_Event &event) {
  int mouse_over;
  switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
      mouse_over = screen_objects.HandleMouse(event.button);
      switch (mouse_over) {
        case 0:
          Gui::current_screen = GameScreen::NEW_GAME;
          break;
        case 1:
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
          screen_objects.GetObject(2)->Update(240, 185);
          break;
        case 1:
          screen_objects.GetObject(2)->Update(240, 225);
          break;
        default:
          screen_objects.GetObject(2)->Update(-500, -500);
          break;
      }
      break;

    default:
      break;
  }
}

void PauseMenu::Render() {
  screen_objects.Draw();
}

GameScene::GameScene() {
  insertion_flag = -1;
  move_flag = -1;
  player_turn = 0;
  player0 = new Player();
  player1 = new Player();
}

GameScene::~GameScene() {
  delete map;
  map = NULL;
  delete player0;
  player0 = NULL;
  delete player1;
  player1 = NULL;
}

void GameScene::LoadScreen() {
  int lw, lh;

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
  GameObject* gold_text = NULL;
  GameObject* wood_text = NULL;

  gold_icon = new GameObject(TextureManager::LoadTexture
                         ("../assets/gold.png"), 645, 5, 42, 42);
  texts.AddObject(gold_icon);

  wood_icon = new GameObject(TextureManager::LoadTexture
                         ("../assets/wood.png"), 645, 55, 42, 42);
  texts.AddObject(wood_icon);

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
      if (mouse_over != -1) {
        insertion_flag = mouse_over;
      }
      if ((mouse_over == -1) && (insertion_flag != -1)) {
        SDL_GetMouseState(&x, &y);
        map->UpdateFocus(x, y, player_turn);
        if (player_turn == 0) {
          if (map->InsertObject(insertion_flag, player_turn, player0)) {
            player_turn ^= 1;
            player1->FinishTurn();
            player0->FinishTurn();
            insertion_flag = -1;
          }
        } else {
          if (map->InsertObject(insertion_flag, player_turn, player1)) {
            player_turn ^= 1;
            player1->FinishTurn();
            player0->FinishTurn();
            insertion_flag = -1;
          }
        }
      }
      if ((mouse_over == -1) && (insertion_flag == -1)) {
        SDL_GetMouseState(&x, &y);
        if ((map->UpdateFocus(x, y, player_turn)) &&
            (map->Occupied(player_turn))) {
            move_flag = 1;
            to_be_moved.x = map->focus.x;
            to_be_moved.y = map->focus.y;
        }
      }
      if ((mouse_over == -1) && (move_flag != -1)) {
        SDL_GetMouseState(&x, &y);
        if ((map->UpdateFocus(x, y, player_turn)) &&
            !(map->Occupied(player_turn))) {
          if (map->MoveObject(to_be_moved)) {
            player_turn ^= 1;
            player1->FinishTurn();
            player0->FinishTurn();
            move_flag = -1;
          } else {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                    "Impossible Movement",
                                     "Not allowed to move to the space", NULL);
            move_flag = -1;
          }
        }
      }
      break;

    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        Gui::current_screen = GameScreen::PAUSE_MENU;
      break;

    default:
      break;
  }
}

void GameScene::Render() {
  map->DrawMap();
  button_objects.Draw();
  texts.Draw();
  if (move_flag == 1) {
    map->DrawPossibleMoves(to_be_moved);
  }
  if (player_turn == 0) {
    player0->wood_text->Render();
    player0->gold_text->Render();
  } else {
    player1->wood_text->Render();
    player1->gold_text->Render();
  }
}
