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
<<<<<<< HEAD
=======
  current_screen = GameScreen::MAIN_MENU;
>>>>>>> Carregando TTF
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

  hearth = new GameObject("../assets/hearth.png", 0, 0);
  map = new Map();
  main_menu = new MainMenu();
  return true;
}

void Gui::Update() {
<<<<<<< HEAD
=======
  switch (Gui::current_screen) {
    case GameScreen::MAIN_MENU:
      main_menu->Update();
      break;

    default:
      break;
  }
>>>>>>> Carregando TTF
  hearth->Update();
}

void Gui::Render() {
  SDL_RenderClear(gRenderer);
<<<<<<< HEAD
=======
  switch (Gui::current_screen) {
    case GameScreen::MAIN_MENU:
      main_menu->Render();
      break;

    default:
      break;
  }
>>>>>>> Carregando TTF
  map->DrawMap();
  hearth->Render();
  SDL_RenderPresent(gRenderer);
}
