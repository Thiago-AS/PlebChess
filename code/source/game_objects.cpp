// "Copyright 2018"
#include "../include/game_objects.h"
#include "../include/texture_manager.h"

GameObject::GameObject(string texture_sheet, SDL_Renderer* renderer,
                       int x_pos, int y_pos) {
  this->renderer = renderer;
  this->x_pos = x_pos;
  this->y_pos = y_pos;
  obj_texture = TextureManager::LoadTexture(texture_sheet.c_str(), renderer);
}

void GameObject::Update() {
  dst_rect.x = x_pos;
  dst_rect.y = y_pos;
  dst_rect.w = 64;
  dst_rect.h = 64;
}


void GameObject::Render() {
  SDL_RenderCopy(renderer, obj_texture, NULL, &dst_rect);
}
