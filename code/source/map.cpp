// "Copyright 2018"
#include "../include/map.h"

Map::Map(Player* player0, Player* player1) {
  tile = TextureManager::LoadTexture("../assets/dirt.png");
  possible_tile = TextureManager::LoadTexture("../assets/green.png");
  attack_tile = TextureManager::LoadTexture("../assets/red.png");

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      map[row][column].unit = 0;
      map[row][column].health = 0;
      map[row][column].position.x = column * 64;
      map[row][column].position.y = row * 64;
      map[row][column].position.h = 64;
      map[row][column].position.w = 64;
      map[row][column].player = NULL;
      map[row][column].object = NULL;
    }
  }

  map[0][0].object = new GameObject(TextureManager::LoadTexture(
                           "../assets/castle1.png"),
                           map[0][0].position.x,
                           map[0][0].position.y,
                           map[0][0].position.h,
                           map[0][0].position.w);
  map[0][0].player = player1;
  map[0][0].unit = 'c';
  map[0][0].health = 5;
  map[9][9].object = new GameObject(TextureManager::LoadTexture(
                           "../assets/castle0.png"),
                           map[9][9].position.x,
                           map[9][9].position.y,
                           map[9][9].position.h,
                           map[9][9].position.w);
  map[9][9].player = player0;
  map[9][9].unit = 'c';
  map[9][9].health = 5;
  focus.x = -1;
  focus.y = -1;
}

Map::~Map() {
  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      if (map[row][column].object != NULL) {
        map[row][column].object->Clean();
        delete map[row][column].object;
        map[row][column].object = NULL;
      }
    }
  }

  SDL_DestroyTexture(tile);
  tile = NULL;
}

void Map::DrawMap() {
  SDL_Rect src, dst;
  src.x = 0; src.y = 0; src.h = 64; src.w = 64;
  dst.w = 64; dst.h = 64;

  for (int row = 0; row < 10; row++) {
    for (int column = 0; column < 10; column++) {
      dst.x = map[row][column].position.x;
      dst.y = map[row][column].position.y;
      TextureManager::Draw(tile, src, dst);

      if (map[row][column].unit != 0) {
        map[row][column].object->Render();
      }
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
        map[focus.y][focus.x].health = 3;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/woodcut0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/woodcut1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough wood to create woodcutter", NULL);
        return false;
      }
      break;

    case 1:
      if (player->total_wood >= 50) {
        player->UpdateWood(50);
        map[focus.y][focus.x].unit = 'b';
        map[focus.y][focus.x].health = 3;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/barrack0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/barrack1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough wood to create barrack", NULL);
        return false;
      }
      break;
    case 2:
      if (player->total_wood >= 50) {
        player->UpdateWood(50);
        player->amount_m++;
        map[focus.y][focus.x].unit = 'm';
        map[focus.y][focus.x].health = 3;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/mine0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/mine1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough wood to create mine", NULL);
        return false;
      }
      break;
    case 3:
      if (player->total_gold >= 50) {
        player->UpdateGold(50);
        map[focus.y][focus.x].unit = 'A';
        map[focus.y][focus.x].health = 1;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/archer0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/archer1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough gold to create archer", NULL);
        return false;
      }
      break;
    case 4:
      if (player->total_gold >= 50) {
        player->UpdateGold(50);
        map[focus.y][focus.x].unit = 'K';
        map[focus.y][focus.x].health = 3;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/knight0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/knight1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough gold to create knight", NULL);
        return false;
      }
      break;
    case 5:
      if (player->total_gold >= 30) {
        player->UpdateGold(30);
        map[focus.y][focus.x].unit = 'W';
        map[focus.y][focus.x].health = 2;
        if (player_turn == 0) {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/warrior0.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        } else {
          obj = new GameObject(TextureManager::LoadTexture(
                               "../assets/warrior1.png"),
                               map[focus.y][focus.x].position.x,
                               map[focus.y][focus.x].position.y,
                               map[focus.y][focus.x].position.h,
                               map[focus.y][focus.x].position.w);
        }
      } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Not enough resources",
                                 "Not enough gold to create warrior", NULL);
        return false;
      }
      break;

    default:
      break;
  }
  map[focus.y][focus.x].object = obj;
  map[focus.y][focus.x].player = player;
  obj = NULL;
  return true;
}

bool Map::UpdateFocus(int row, int column, int player_turn, bool insertion) {
  if (insertion) {
    if (player_turn == 1) {
      if ((row < 0) || (column < 0) || (row > 640) || (column > 320)) {
        focus.x = -1;
        focus.y = -1;
        return false;
      } else {
        focus.x = static_cast<int>(row/64);
        focus.y = static_cast<int>(column/64);
      }
    } else {
      if ((row < 0) || (column < 320) || (row > 640) || (column > 640)) {
        focus.x = -1;
        focus.y = -1;
        return false;
      } else {
        focus.x = static_cast<int>(row/64);
        focus.y = static_cast<int>(column/64);
      }
    }
    if ((row < 0) || (column < 0) || (row > 640) || (column > 640)) {
      focus.x = -1;
      focus.y = -1;
      return false;
    } else {
      focus.x = static_cast<int>(row/64);
      focus.y = static_cast<int>(column/64);
    }
  } else {
    if ((row < 0) || (column < 0) || (row > 640) || (column > 640)) {
      focus.x = -1;
      focus.y = -1;
      return false;
    } else {
      focus.x = static_cast<int>(row/64);
      focus.y = static_cast<int>(column/64);
    }
  }
  return true;
}

bool Map::Occupied() {
  if (map[focus.y][focus.x].unit != 0)
    return true;
  else
    return false;
}

bool Map::MoveObject(SDL_Point object_location) {
  bool possible_move = false;
  switch (map[object_location.y][object_location.x].unit) {
    case 'W':
      if (IsMovePossible('W', object_location)) {
        possible_move = true;
      }
      break;
    case 'K':
      if (IsMovePossible('K', object_location)) {
        possible_move = true;
      }
      break;
    case 'A':
      if (IsMovePossible('A', object_location)) {
        possible_move = true;
      }
      break;

    default:
      possible_move = false;
      break;
  }
  if (possible_move) {
    map[focus.y][focus.x].unit = map[object_location.y][object_location.x].unit;
    map[focus.y][focus.x].player = map[object_location.y]
                                   [object_location.x].player;
    map[focus.y][focus.x].object = map[object_location.y]
                                   [object_location.x].object;
    map[focus.y][focus.x].health = map[object_location.y]
                                   [object_location.x].health;
    map[focus.y][focus.x].object->Update(map[focus.y][focus.x].position.x,
                                         map[focus.y][focus.x].position.y);

    EraseUnit(object_location);
    return true;
  } else {
    return false;
  }
}

bool Map::IsMovePossible(char unit, SDL_Point object_location) {
  int movement_x, movement_y;
  movement_x = abs(focus.x - object_location.x);
  movement_y = abs(focus.y - object_location.y);
  if (movement_x == 0 && movement_y == 0) {
    return false;
  }

  switch (unit) {
    case 'W':
      if (movement_x <= 2 && movement_y <= 2) {
        return true;
      }
      break;
    case 'K':
      if (movement_x <= 1 && movement_y <= 1) {
        return true;
      }
      break;
    case 'A':
      if (movement_x <= 3 && movement_y <= 3) {
        return true;
      }
      break;

    default:
      return false;
      break;
  }
  return false;
}

void Map::DrawPossibleMoves(SDL_Point object_location) {
  SDL_Rect src, dst;
  src.x = 0; src.y = 0; src.h = 64; src.w = 64;
  dst.w = 64; dst.h = 64;
  switch (map[object_location.y][object_location.x].unit) {
    case 'W':
      for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
          if ((object_location.y + i < 0) || (object_location.x + j < 0) ||
              (object_location.y + i > 9) || (object_location.x + j > 9) ||
              (i == 0 && j == 0)) {
          } else {
            if (map[object_location.y + i][object_location.x + j].unit != 0) {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(attack_tile, src, dst);
            } else {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(possible_tile, src, dst);
            }
          }
        }
      }
      break;
    case 'K':
      for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
          if ((object_location.y + i < 0) || (object_location.x + j < 0) ||
              (object_location.y + i > 9) || (object_location.x + j > 9) ||
              (i == 0 && j == 0)) {
          } else {
            if (map[object_location.y + i][object_location.x + j].unit != 0) {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(attack_tile, src, dst);
            } else {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(possible_tile, src, dst);
            }
          }
        }
      }
      break;
    case 'A':
      for (int i = -3; i <= 3; ++i) {
        for (int j = -3; j <= 3; ++j) {
          if ((object_location.y + i < 0) || (object_location.x + j < 0) ||
              (object_location.y + i > 9) || (object_location.x + j > 9) ||
              (i == 0 && j == 0)) {
          } else {
            if (map[object_location.y + i][object_location.x + j].unit != 0) {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(attack_tile, src, dst);
            } else {
              dst.x = map[object_location.y + i]
                      [object_location.x + j].position.x;
              dst.y = map[object_location.y + i]
                      [object_location.x + j].position.y;
              TextureManager::Draw(possible_tile, src, dst);
            }
          }
        }
      }
      break;

    default:
      break;
  }
}

bool Map::AttackObject(SDL_Point object_location) {
  bool possible_attack = false;
  switch (map[object_location.y][object_location.x].unit) {
    case 'W':
      if (IsMovePossible('W', object_location)) {
        possible_attack = true;
      }
      break;
    case 'K':
      if (IsMovePossible('K', object_location)) {
        possible_attack = true;
      }
      break;
    case 'A':
      if (IsMovePossible('A', object_location)) {
        possible_attack = true;
      }
      break;

    default:
      possible_attack = false;
      break;
  }
  if (possible_attack) {
    map[focus.y][focus.x].health--;
    if (map[focus.y][focus.x].health == 0) {
      if (map[focus.y][focus.x].unit == 'm') {
        map[focus.y][focus.x].player->amount_m--;
      }
      if (map[focus.y][focus.x].unit == 'w') {
        map[focus.y][focus.x].player->amount_w--;
      }
      EraseUnit(focus);
    }
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HIT",
                          ("Unity Life: " + to_string(map[focus.y]
                          [focus.x].health)).c_str(), NULL);
    return true;
  }
  return false;
}

void Map::EraseUnit(SDL_Point object_location) {
  map[object_location.y][object_location.x].unit = 0;
  map[object_location.y][object_location.x].player = NULL;
  map[object_location.y][object_location.x].health = 0;
  map[object_location.y][object_location.x].object = NULL;
}

bool Map::IsEnemy(int player_turn) {
  if (map[focus.y][focus.x].player->id != player_turn)
    return true;
  else
    return false;
}
