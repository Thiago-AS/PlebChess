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
  SDL_DestroyTexture(obj_texture);
  obj_texture = NULL;
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
      map[row][column].object = NULL;
    }
  }

  map[0][0].object = new GameObject(TextureManager::LoadTexture(
                           "../assets/castle.png"),
                           map[0][0].position.x,
                           map[0][0].position.y,
                           map[0][0].position.h,
                           map[0][0].position.w);
  map[0][0].player = 1;
  map[9][9].object = new GameObject(TextureManager::LoadTexture(
                           "../assets/castle.png"),
                           map[9][9].position.x,
                           map[9][9].position.y,
                           map[9][9].position.h,
                           map[9][9].position.w);
  map[9][9].player = 0;
  focus.x = -1;
  focus.y = -1;
}

Map::~Map() {
}

void Map::DrawMap() {
  SDL_Rect src;
  src.x = 0; src.y = 0; src.h = 64; src.w = 64;

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      TextureManager::Draw(tile, src, map[row][column].position);
      if (map[row][column].object != NULL)
        map[row][column].object->Render();
    }
  }
}

bool Map::InsertObject(int object_id, int player_turn, Player* player) {
  GameObject* obj;
  if (((focus.y == -1) && (focus.x == -1)) ||
      (map[focus.y][focus.x].object != NULL))
    return false;

  switch (object_id) {
    case 0:
      if (player->total_wood >= 30) {
        player->UpdateWood(30);
        player->amount_w++;
        map[focus.y][focus.x].unit = 'w';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/woodcut.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
        return false;
      }
      break;

    case 1:
      if (player->total_wood >= 50) {
        player->UpdateWood(50);
        map[focus.y][focus.x].unit = 'b';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/barrack.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
        return false;
      }
      break;
    case 2:
      if (player->total_wood >= 50) {
        player->UpdateWood(50);
        player->amount_m++;
        map[focus.y][focus.x].unit = 'm';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/mine.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
        return false;
      }
      break;
    case 3:
      if (player->total_gold >= 50) {
        player->UpdateGold(50);
        map[focus.y][focus.x].unit = 'A';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/archer.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
        return false;
      }
      break;
    case 4:
      if (player->total_gold >= 50) {
        player->UpdateGold(50);
        map[focus.y][focus.x].unit = 'K';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/knight.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
       return false;
      }
      break;
    case 5:
      if (player->total_gold >= 30) {
        player->UpdateGold(30);
        map[focus.y][focus.x].unit = 'W';
        obj = new GameObject(TextureManager::LoadTexture(
                             "../assets/warrior.png"),
                             map[focus.y][focus.x].position.x,
                             map[focus.y][focus.x].position.y,
                             map[focus.y][focus.x].position.h,
                             map[focus.y][focus.x].position.w);
      } else {
       return false;
      }
      break;

    default:
      break;
  }
  map[focus.y][focus.x].object = obj;
  obj = NULL;
  map[focus.y][focus.x].player = player_turn;
  return true;
}

MapTile Map::ReturnObject(int row, int column) {
  return map[row][column];
}

void Map::UpdateFocus(int row, int column, int player_turn) {
  if (player_turn == 1) {
    if ((row < 0) || (column < 0) || (row > 640) || (column > 320)) {
      focus.x = -1;
      focus.y = -1;
    } else {
      focus.x = static_cast<int>(row/64);
      focus.y = static_cast<int>(column/64);
    }
  } else {
    if ((row < 0) || (column < 320) || (row > 640) || (column > 640)) {
      focus.x = -1;
      focus.y = -1;
    } else {
      focus.x = static_cast<int>(row/64);
      focus.y = static_cast<int>(column/64);
    }
  }
}

Structure::Structure(SDL_Texture* texture, int x_pos, int y_pos,
                     int width, int height, int health, StructureType type,
                     int player): GameObject(texture, x_pos, y_pos, width,
                                             height) {
  this->type = type;
  this->health = health;
}

Player::Player() {
  total_wood = 150;
  total_gold = 0;
  amount_m = 0;
  amount_w = 0;

  fontSup = TextureManager::LoadTTF(Gui::game_font, "0000");
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  gold_text = new GameObject(fontSup, 700, 5, lw, lh);;

  fontSup = TextureManager::LoadTTF(Gui::game_font, "0150");
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  wood_text = new GameObject(fontSup, 700, 55, lw, lh);
}

void Player::UpdateWood(int value) {
  total_wood -= value;
}

void Player::UpdateGold(int value) {
  total_gold -= value;
}

void Player::FinishTurn() {
  total_gold += (amount_m * 10);
  total_wood += (amount_w * 5);

  gold_text->Clean();
  wood_text->Clean();
  delete gold_text;
  delete wood_text;

  fontSup = TextureManager::LoadTTF(Gui::game_font, to_string(total_gold));
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  gold_text = new GameObject(fontSup, 700, 5, lw, lh);

  fontSup = TextureManager::LoadTTF(Gui::game_font, to_string(total_wood));
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  wood_text = new GameObject(fontSup, 700, 55, lw, lh);
}
