// "Copyright 2018"
#include "../include/gui.h"
#include "./texture_manager.h"
#include "./screens.h"
#include "./game_objects.h"

Gui* Gui::instance = NULL;
bool Gui::initialized = false;
bool Gui::quit = false;
SDL_Renderer* Gui::gRenderer = NULL;
TTF_Font* Gui::game_font = NULL;
GameScreen Gui::current_screen;

MainMenu* main_menu;
GameScene* game_scene;
PauseMenu* pause_menu;

Gui* Gui::Instance() {
  if (instance == NULL)
    instance = new Gui();

  return instance;
}

void Gui::Release() {
  delete instance;
  instance = NULL;
  delete main_menu;
  main_menu = NULL;
  delete game_scene;
  game_scene = NULL;
  delete pause_menu;
  pause_menu = NULL;

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
  TTF_CloseFont(game_font);
  game_font = NULL;

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
    SDL_SetRenderDrawColor(gRenderer, 222, 184, 135, 255);
  }

  if (TTF_Init() == -1) {
    cout << "Erro ao criar TTF: " << TTF_GetError() << endl;
  } else {
    game_font = TTF_OpenFont("../assets/emulogic.ttf", 20);
    if (game_font == NULL) {
      cout << "Falha ao carregar fonte: " << TTF_GetError() << endl;
    }
  }

  main_menu = new MainMenu();
  main_menu->LoadScreen();
  game_scene = new GameScene();
  game_scene->LoadScreen();
  pause_menu = new PauseMenu();
  pause_menu->LoadScreen();
  return true;
}

void Gui::HandleEvents() {
  SDL_Event events;
  while (SDL_PollEvent(&events) != 0) {
    if (events.type == SDL_QUIT) {
      quit = true;
    }
    switch (Gui::current_screen) {
      case GameScreen::MAIN_MENU:
        main_menu->EventHandler(events);
        break;

      case GameScreen::NEW_GAME:
        game_scene->EventHandler(events);
        break;

      case GameScreen::PAUSE_MENU:
        pause_menu->EventHandler(events);
        break;

      default:
        break;
    }
  }
}

void Gui::Render() {
  SDL_RenderClear(gRenderer);
  switch (Gui::current_screen) {
    case GameScreen::MAIN_MENU:
      main_menu->Render();
      break;

    case GameScreen::NEW_GAME:
      game_scene->Render();
      break;

    case GameScreen::PAUSE_MENU:
      pause_menu->Render();
      break;

    case GameScreen::WINNER_SCREEN:
      break;

    default:
      break;
  }
  SDL_RenderPresent(gRenderer);
}
