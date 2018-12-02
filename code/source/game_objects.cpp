// "Copyright 2018"
#include "../include/game_objects.h"
#include "../include/texture_manager.h"

GameObject::GameObject(SDL_Texture* texture, int x_pos, int y_pos,
                       int width, int height) {
  this->dst_rect.x = x_pos;
  this->dst_rect.y = y_pos;
  this->dst_rect.h = height;
  this->dst_rect.w = width;
  obj_texture = texture;
}

GameObject::~GameObject() {
}

void GameObject::Update(int new_x, int new_y) {
  dst_rect.x = new_x;
  dst_rect.y = new_y;
}

bool GameObject::HandleMouse(SDL_MouseButtonEvent &button_event) {
      int x = button_event.x , y = button_event.y;
      bool inside = true;

      if (x < dst_rect.x) {
        inside = false;
      } else if (x > dst_rect.x + dst_rect.w) {
        inside = false;
      } else if (y < dst_rect.y) {
        inside = false;
      } else if (y > dst_rect.y + dst_rect.h) {
        inside = false;
      }
      return inside;
}

void GameObject::Render() {
  SDL_RenderCopy(Gui::gRenderer, obj_texture, NULL, &dst_rect);
}

void GameObject::Clean() {
}

void VectorObjects::AddObject(GameObject* object) {
  objects_vector.push_back(object);
}

GameObject* VectorObjects::GetObject(int position) {
  return objects_vector.at(position);
}

void VectorObjects::Update() {
}

int VectorObjects::HandleMouse(SDL_MouseButtonEvent& button_event) {
  if (!objects_vector.empty()) {
    for (int i = 0; i < objects_vector.size(); i++) {
      if (objects_vector.at(i)->HandleMouse(button_event))
        return i;
    }
  }
  return -1;
}

void VectorObjects::Draw() {
  if (!objects_vector.empty()) {
    for (int i = 0; i < objects_vector.size(); i++) {
      objects_vector.at(i)->Render();
    }
  }
}

void VectorObjects::Clean() {
  if (!objects_vector.empty()) {
    for (int i = 0; i < objects_vector.size(); i++) {
      objects_vector.at(i)->Clean();
    }
  }
}

Map::Map() {
  tile = TextureManager::LoadTexture("../assets/dirt.png");

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      map[row][column].unit = 0;
      map[row][column].position.x = column * 64;
      map[row][column].position.y = row * 64;
      map[row][column].position.h = 64;
      map[row][column].position.w = 64;
      map[row][column].player = -1;
    }
  }

  focus.x = -1;
  focus.y = -1;
}

Map::~Map() {
}

void Map::DrawMap() {
  char tile_type;
  SDL_Rect src;
  src.x = 0; src.y = 0; src.h = 64; src.w = 64;

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      tile_type = map[row][column].unit;

      switch (tile_type) {
        case 0:
          TextureManager::Draw(tile, src, map[row][column].position);
          break;
        default:
          break;
      }
    }
  }
}

void Map::InsertObject(char object, int player_turn) {
}

MapTile Map::ReturnObject(int row, int column) {
  return map[row][column];
}

void Map::UpdateFocus(int row, int column) {
  if ((row < 0) || (row < 0) || (column > 640) || (column > 640)) {
    focus.x = -1;
    focus.y = -1;
  } else {
    focus.x = static_cast<int>(row/64);
    focus.y = static_cast<int>(column/64);
  }
}
