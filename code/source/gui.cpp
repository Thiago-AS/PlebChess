// "Copyright 2018"
#include "../include/gui.h"

Gui* Gui::instance = NULL;
bool Gui::initialized = false;

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
  mRenderer = NULL;
  mWindow = NULL;
  initialized = Init();
}

Gui::~Gui() {
  SDL_DestroyWindow(mWindow);
  mWindow = NULL;
  SDL_DestroyRenderer(mRenderer);
  mRenderer = NULL;

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

  mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
  if (mRenderer == NULL) {
    cout << "Falha ao criar renderer: " << SDL_GetError() << endl;
  } else {
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
  }
  hearth = new GameObject("../assets/hearth.png", mRenderer, 0, 0);
  return true;
}

void Gui::Update() {
  hearth->Update();
}

void Gui::Render() {
  SDL_RenderClear(mRenderer);
  hearth->Render();
  SDL_RenderPresent(mRenderer);
}
