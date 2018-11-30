// "Copyright 2018"
#include "../include/gui.h"
#include "./texture_manager.h"
#include "./game_objects.h"
#include "./screens.h"

Gui* Gui::instance = NULL;
bool Gui::initialized = false;
SDL_Renderer* Gui::gRenderer = NULL;
TTF_Font* Gui::game_font = NULL;
GameScreen Gui::current_screen;

GameObject* hearth;
GameObject* start_button;
MainMenu* main_menu;
Map* map;

Gui* Gui::Instance() {
  if (instance == NULL)
    instance = new Gui();

  return instance;
}

void Gui::Release() {
  delete instance;
  instance = NULL;

  initialized = false;
}

bool Gui::Initialized() {
  return initialized;
}

Gui::Gui() {
  gRenderer = NULL;
  mWindow = NULL;
  current_screen = GameScreen::MAIN_MENU;
  initialized = Init();
}

Gui::~Gui() {
  SDL_DestroyWindow(mWindow);
  mWindow = NULL;
  SDL_DestroyRenderer(gRenderer);
  gRenderer = NULL;

  SDL_Quit();
  TTF_Quit();
  IMG_Quit();
}

bool Gui::Init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cout << "SDL não pode ser iniciado: " << SDL_GetError() << endl;
    return false;
  }

  mWindow = SDL_CreateWindow("JOGO", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (mWindow == NULL) {
    cout << "Falha ao criar janela: " << SDL_GetError() << endl;
    return false;
  }

  gRenderer = SDL_CreateRenderer(mWindow, -1, 0);
  if (gRenderer == NULL) {
    cout << "Falha ao criar renderer: " << SDL_GetError() << endl;
  } else {
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
  }

  if (TTF_Init() == -1) {
    cout << "Erro ao criar TTF: " << TTF_GetError() << endl;
  } else {
    game_font = TTF_OpenFont("../assets/emulogic.ttf", 20);
    if (game_font == NULL) {
      cout << "Falha ao carregar fonte: " << TTF_GetError() << endl;
    }
  }

  hearth = new GameObject(TextureManager::LoadTexture("../assets/hearth.png"),
                          0, 0, 64, 64);
  map = new Map();
  main_menu = new MainMenu();
  int w1, h1;
  SDL_Texture* fontSup = TextureManager::LoadTTF(Gui::game_font, "START GAME");
  SDL_QueryTexture(fontSup, NULL, NULL, &w1, &h1);
  start_button = new GameObject(fontSup, 300, 200, w1, h1);
  return true;
}

void Gui::Update() {
  switch (Gui::current_screen) {
    case GameScreen::MAIN_MENU:
      main_menu->Update();
      break;

    default:
      break;
  }
  hearth->Update();
  start_button->Update();
}

void Gui::Render() {
  SDL_RenderClear(gRenderer);
  switch (Gui::current_screen) {
    case GameScreen::MAIN_MENU:
      main_menu->Render();
      break;

    default:
      break;
  }
  map->DrawMap();
  hearth->Render();
=======
  // switch (Gui::current_screen) {
  //   case GameScreen::MAIN_MENU:
  //     main_menu->Render();
  //     break;
  //
  //   default:
  //     break;
  // }
  //map->DrawMap();
  //hearth->Render();
  start_button->Render();
>>>>>>> Arrumando TTF
  SDL_RenderPresent(gRenderer);
}
