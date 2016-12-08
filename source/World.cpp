#include "World.h"

bool operator == (const WorldTemplate& lhs, const WorldTemplate& rhs) {
  if (lhs._heroes != rhs._heroes) {
    return false;
  }
  if (lhs._quests != rhs._quests) {
    return false;
  }
  if (lhs._player != rhs._player) {
    return false;
  }
  if (lhs._turn_number != rhs._turn_number) {
    return false;
  }
  return true;
}

bool operator < (const WorldTemplate& lhs, const WorldTemplate& rhs) {
  return lhs._turn_number < rhs._turn_number;
}

bool operator > (const WorldTemplate& lhs, const WorldTemplate& rhs) {
  return lhs._turn_number > rhs._turn_number;
}

size_t World::cleanup() {
  if (_storage != NULL) {
    delete _storage;
  }
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      delete _heroes[i];
    }
  }
  _heroes.clear();
  for (size_t i = 0; i < _quests.size(); ++i) {
    if (_quests[i] != NULL) {
      delete _quests[i];
    }
  }
  _quests.clear();
  if (_player != NULL) {
    delete _player;
  }
  return RC_OK;
}

World::World(): _storage(NULL), _player(NULL), _turn_number(1), _storage_filled(false) {
  _heroes.clear();
  _quests.clear();
}

World::~World() {
  cleanup();
}

size_t World::new_game(const std::string& player_name) {
  if (_storage == NULL) {
    return RC_NO_STORAGE;
  }
  if (_player != NULL || !_heroes.empty() || !_quests.empty()) {
    return RC_GAME_IN_PROCESS;
  }
  // generate some heroes
  
  // then generate some quests
  
  // and finally generate the player
  
  return RC_OK;
}
size_t World::load_game(const WorldTemplate& save_data) {
  cleanup();
  // generate heroes from save data
  
  // generate quests from save data
  
  // generate the player
  
  return RC_OK;
}

size_t World::fill_storage(const std::string& texts_db_name, const std::string& templates_db_name, const std::string& type_objects_db_name) {
  if (_storage != NULL) {
    return RC_GAME_IN_PROCESS;
  }
  _storage = new WorldStorage(texts_db_name, templates_db_name, type_objects_db_name);
  return RC_OK;
}

size_t World::clear_storage() {
  if (_storage == NULL) {
    return RC_NO_STORAGE;
  }
  return _storage->clear_storage();
}
