// "Copyright 2018"
#include "../include/gui.h"

Gui* Gui::instance = NULL;
bool Gui::initialized = false;
SDL_Renderer* Gui::gRenderer = NULL;

GameObject* hearth;

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
  initialized = Init();
}

Gui::~Gui() {
  SDL_DestroyWindow(mWindow);
  mWindow = NULL;
  SDL_DestroyRenderer(gRenderer);
  gRenderer = NULL;

  SDL_Quit();
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
  hearth = new GameObject("../assets/hearth.png", 0, 0);
  return true;
}

void Gui::Update() {
  hearth->Update();
}

void Gui::Render() {
  SDL_RenderClear(gRenderer);
  hearth->Render();
  SDL_RenderPresent(gRenderer);
}
