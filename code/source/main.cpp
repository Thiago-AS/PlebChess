// "Copyright 2018"
#include "../include/gui.h"

int main() {
  Gui *new_gui = NULL;
  new_gui = new Gui();

  if (new_gui->Init())
    SDL_Delay(2000);
  else
    cout << "Falha ao iniciar" << endl;

  new_gui->Close();
  return 0;
}
