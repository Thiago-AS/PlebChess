// "Copyright 2018"
#include "../include/map.h"

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
                           "../assets/castle1.png"),
                           map[0][0].position.x,
                           map[0][0].position.y,
                           map[0][0].position.h,
                           map[0][0].position.w);
  map[0][0].player = 1;
  map[0][0].unit = 'c';
  map[9][9].object = new GameObject(TextureManager::LoadTexture(
                           "../assets/castle0.png"),
                           map[9][9].position.x,
                           map[9][9].position.y,
                           map[9][9].position.h,
                           map[9][9].position.w);
  map[9][9].player = 0;
  map[9][9].unit = 'c';
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
  map[focus.y][focus.x].player = player_turn;
  obj = NULL;
  return true;
}

bool Map::UpdateFocus(int row, int column, int player_turn) {
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
  return true;
}

bool Map::Occupied(int player_turn) {
  if ((map[focus.y][focus.x].unit != 0) &&
      (map[focus.y][focus.x].player == player_turn))
    return true;
  else
    return false;
}

bool Map::MoveObject(SDL_Point object_location) {
  if ((map[object_location.y][object_location.x].unit == 'W') ||
      (map[object_location.y][object_location.x].unit == 'K') ||
      (map[object_location.y][object_location.x].unit == 'A')) {
    map[focus.y][focus.x].unit = map[object_location.y][object_location.x].unit;
    map[focus.y][focus.x].player = map[object_location.y]
                                   [object_location.x].player;
    map[focus.y][focus.x].object = map[object_location.y]
                                   [object_location.x].object;
    map[focus.y][focus.x].object->Update(map[focus.y][focus.x].position.x,
                                         map[focus.y][focus.x].position.y);
    map[object_location.y][object_location.x].unit = 0;
    map[object_location.y][object_location.x].player = -1;
    map[object_location.y][object_location.x].object = NULL;
    return true;
  } else {
    return false;
  }
}
