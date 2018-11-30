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

<<<<<<< HEAD
void GameObject::Update() {
  dst_rect.x = x_pos;
  dst_rect.y = y_pos;
  dst_rect.w = width;
  dst_rect.h = height;
=======
GameObject::~GameObject() {
}

void GameObject::Update(int new_x, int new_y, int new_width, int new_height) {
  dst_rect.x = new_x;
  dst_rect.y = new_y;
  dst_rect.w = new_width;
  dst_rect.h = new_height;
}

bool GameObject::HandleMouse(SDL_MouseButtonEvent &button_event) {
    if (button_event.button = SDL_BUTTON_LEFT) {
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
<<<<<<< HEAD
  }
>>>>>>> Mudando função de atualização de posição
=======
    }
>>>>>>> Adicionando verificação de botoes
}

void GameObject::Render() {
  SDL_RenderCopy(Gui::gRenderer, obj_texture, NULL, &dst_rect);
}

<<<<<<< HEAD
=======
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

>>>>>>> Carregando TTF
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
