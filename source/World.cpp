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
  for (size_t i = 0; i < save_data._heroes.size(); ++i) {
    _heroes.push_back(NULL);
    _storage->make_hero(_heroes[i], save_data._heroes[i]);
  }
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

size_t World::update() {
  size_t j = SIZE_T_DEFAULT_VALUE;
  while (!_quests.empty() && j < _quests.size()) {
    
    if (_quests[j] != NULL) {
      _quests[j]->update();
      if (_quests[j]->to_delete()) {
        delete _quests[j];
        _quests.erase(_quests.begin() + j);
      } else {
        ++j; 
      }
    } else {
      _quests.erase(_quests.begin() + j);
    }
  }
  j = SIZE_T_DEFAULT_VALUE;
  while (!_heroes.empty() && j < _heroes.size()) {
    if (_heroes[j] != NULL) {
      _heroes[j]->update();
      if (_heroes[j]->to_delete()) {
        delete _heroes[j];
        _heroes.erase(_heroes.begin() + j);
      } else {
        ++j;
      }
    } else {
      _heroes.erase(_heroes.begin() + j);
    }
  }
  return RC_OK;
}

size_t World::take_quest(const size_t& quest_id) {
  if (quest_id < _quests.size()) {
    if (_quests[quest_id] != NULL) {
      if (_quests[quest_id]->get_phase() == QP_PENDING) {
        _quests[quest_id]->set_phase(QP_RECRUITING);
      } else {
        return RC_BAD_INPUT;
      }
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t World::decline_quest(const size_t& quest_id) {
  if (quest_id < _quests.size()) {
    if (_quests[quest_id] != NULL) {
      if (_quests[quest_id]->get_phase() > QP_PENDING && _quests[quest_id]->get_phase() < QP_SUCCESS_TOTAL) {
        _quests[quest_id]->set_phase(QP_DECLINED);
      } else {
        return RC_BAD_INPUT;
      }      
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t World::assign_hero(const size_t& hero_id, const size_t& quest_id) {
  if (hero_id < _heroes.size() && quest_id < _quests.size()) {
    if (_heroes[hero_id] != NULL && _quests[quest_id] != NULL) {
      if (_quests[quest_id]->get_phase() != QP_RECRUITING || _heroes[hero_id]->get_quest() != NULL || _heroes[hero_id]->get_guild() == NULL) {
        return RC_BAD_INPUT;
      }
    }
  } else {
    return RC_BAD_INDEX;
  }
}

