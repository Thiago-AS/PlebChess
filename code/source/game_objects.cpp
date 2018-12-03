// "Copyright 2018"
#include "../include/game_objects.h"

GameObject::GameObject(SDL_Texture* texture, int x_pos, int y_pos,
                       int width, int height) {
  this->dst_rect.x = x_pos;
  this->dst_rect.y = y_pos;
  this->dst_rect.h = height;
  this->dst_rect.w = width;
  obj_texture = texture;
}

GameObject::~GameObject() {
  Clean();
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

Player::Player(int id) {
  total_wood = 150;
  total_gold = 0;
  amount_m = 0;
  amount_w = 0;
  this->id = id;

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

  delete gold_text;
  delete wood_text;

  fontSup = TextureManager::LoadTTF(Gui::game_font, to_string(total_gold));
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  gold_text = new GameObject(fontSup, 700, 5, lw, lh);

  fontSup = TextureManager::LoadTTF(Gui::game_font, to_string(total_wood));
  SDL_QueryTexture(fontSup, NULL, NULL, &lw, &lh);
  wood_text = new GameObject(fontSup, 700, 55, lw, lh);
}

Player::~Player() {
  delete gold_text;
  gold_text = NULL;
  delete wood_text;
  wood_text = NULL;
  SDL_DestroyTexture(fontSup);
  fontSup = NULL;
}
