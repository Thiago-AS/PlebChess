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

char Map::map[10][10] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

Map::Map() {
  tile = TextureManager::LoadTexture("../assets/dirt.png");
  src.x = src.y = 0;
  dst.x = dst.y = 0;
  src.w = dst.w = 32;
  src.h = dst.h = 32;
}

Map::~Map() {
}

void Map::DrawMap() {
  char tile_type = 0;

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      tile_type = map[row][column];

      dst.x = column * 32;
      dst.y = row * 32;

      switch (tile_type) {
        case 0:
          TextureManager::Draw(tile, src, dst);
          break;
        default:
          break;
      }
    }
  }
}
