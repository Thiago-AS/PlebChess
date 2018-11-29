// "Copyright 2018"
#include "../include/game_objects.h"
#include "../include/texture_manager.h"

GameObject::GameObject(string texture_sheet, int x_pos, int y_pos) {
  this->x_pos = x_pos;
  this->y_pos = y_pos;
  obj_texture = TextureManager::LoadTexture(texture_sheet.c_str());
}

void GameObject::Update() {
  dst_rect.x = x_pos;
  dst_rect.y = y_pos;
  dst_rect.w = 64;
  dst_rect.h = 64;
}


void GameObject::Render() {
  SDL_RenderCopy(Gui::gRenderer, obj_texture, NULL, &dst_rect);
}
