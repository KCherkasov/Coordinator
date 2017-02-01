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
  for (size_t i = 0; i < _items.size(); ++i) {
    if (_items[i] != NULL) {
      delete _items[i];
    }
  }
  _items.clear();
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

size_t World::apply_reward(const size_t& index) {
  if (index < _quests.size()) {
    if (_quests[index] == NULL) {
      return RC_BAD_INPUT;
    }
    if (!_quests[index]->to_delete()) {
      return RC_BAD_INPUT;
    }
    QuestReward reward;
    _quests[index]->give_reward(reward);
    _player->add_cash(reward._cash);
    _player->remove_cash(reward._fees);
    _player->add_experience(reward._experience);
    for (size_t i = 0; i < reward._loot.size(); ++i) {
      Item* to_add = NULL;
      _storage->make_item(to_add, reward._loot[i], reward._level);
      if (to_add != NULL) {
        _player->add_item(to_add);
      }
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

World::World(): _storage(NULL), _player(NULL), _turn_number(1), _storage_filled(false) {
  _heroes.clear();
  _quests.clear();
}

World::~World() {
  cleanup();
}

size_t World::new_game(const std::string& player_name, const std::string& player_description) {
  srand(static_cast<size_t>(time(0)));
  if (_storage == NULL) {
    return RC_NO_STORAGE;
  }
  if (_player != NULL || !_items.empty() || !_heroes.empty() || !_quests.empty()) {
    return RC_GAME_IN_PROCESS;
  }
  // generate some heroes
  for (size_t i = 0; i < INITIAL_HEROES_COUNT; ++i) {
    size_t level = START_LEVEL + roll_dice(LEVELS_RANGE);
    _heroes.push_back(NULL);
    _storage->make_hero(_heroes[i], level);
  }
  // then generate some items (if needed)
  for (size_t i = 0; i < INITIAL_ITEMS_COUNT; ++i) {
    size_t level = START_LEVEL + roll_dice(LEVELS_RANGE);
    _items.push_back(NULL);
    _storage->make_item(_items[i], level);
  }
  // then generate some quests
  for (size_t i = 0; i < INITIAL_QUESTS_COUNT; ++i) {
    size_t level = START_LEVEL + roll_dice(LEVELS_RANGE);
    _quests.push_back(NULL);
    _storage->make_quest(_quests[i], level);
  }
  // and finally generate the player
  _player = new Player(player_name, player_description);
  return RC_OK;
}
size_t World::load_game(const WorldTemplate& save_data) {
  cleanup();
  // generate heroes from save data
  for (size_t i = 0; i < save_data._heroes.size(); ++i) {
    _heroes.push_back(NULL);
    _storage->make_hero(_heroes[i], save_data._heroes[i]);
  }
  for (size_t i = 0; i < save_data._items.size(); ++i) {
    _items.push_back(NULL);
    _storage->make_item(_items[i], save_data._items[i]);
  }
  // generate quests from save data
  for (size_t i = 0; i < save_data._quests.size()) {
    _quests.push_back(NULL);
    _storage->make_quest(_quests[i], save_data._quests[i]);
  }
  // generate the player
  _player = new Player(save_data._player, _items, _heroes);
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

size_t  World::get_save_data(WorldTemplate& result) const {
  result._items.clear();
  for (size_t i = 0 ; i < _items.size(); ++i) {
    if (_items[i] != NULL) {
      ItemTemplate buffer;
      _items[i]->get_save_data(buffer);
      result._items.push_back(buffer);
    }
  }
  result._heroes.clear();
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      HeroTemplate buffer;
      _heroes[i]->get_save_data(buffer);
      result._heroes.push_back(buffer);
    }
  }
  result._quests.clear();
  for (size_t i = 0; i < _quests.size(); ++i) {
    if (_quests[i] != NULL) {
      QuestTemplate buffer;
      _quests[i]->get_save_data(buffer);
      result._quests.push_back(buffer);
    }
  }
  _player->get_save_data(result._player);
  result._turn_number = _turn_number;
  return RC_OK;
}

size_t World::update() {
  size_t j = SIZE_T_DEFAULT_VALUE;
  while (!_quests.empty() && j < _quests.size()) {
    if (_quests[j] != NULL) {
      _quests[j]->update();
      if (_quests[j]->to_delete()) {
        apply_reward(j);
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
  while (!_items.empty() && j < _items.size()) {
    if (_items[j] != NULL) {
      _items[j]->update();
      if (_items[j]->to_delete()) {
        delete _items[j];
        _items.erase(_items.begin() + j);
      } else {
        ++j;
      }
    } else {
      _items.erase(_items.begin() + j);
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
      return _heroes[hero_id]->add_quest(_quests[quest_id]);
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t World::reject_hero(const size_t& hero_id, const size_t& quest_id) {
  if (hero_id < _heroes.size() && quest_id < _quests.size()) {
    if (_heroes[hero_id] != NULL && _quests[quest_id] != NULL) {
      if (_heroes->get_guild() == NULL || _heroes[hero_id]->get_quest() != _quests[quest_id]) {
        return RC_BAD_INPUT;
      }
      return _heroes[hero_id]->remove_quest();
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t World::hire_hero(const size_t& hero_id) {
  if (hero_id < _heroes.size()) {
    if (_heroes[hero_id] == NULL || _player == NULL) {
      return RC_BAD_INPUT;
    }
    if (_heroes[hero_id]->get_guild() != NULL) {
      return RC_BAD_INPUT;
    }
    return _heroes[hero_id]->enter_guild(_player);
  } else {
    return RC_BAD_INDEX;
  }
}

size_t World::fire_hero(const size_t& hero_id) {
  if (hero_id < _heroes.size()) {
    if (_heroes[hero_id] == NULL) {
      return RC_BAD_INPUT;
    }
    if (_heroes[hero_id]->get_guild() == NULL) {
      return RC_BAD_INPUT;
    }
    return _heroes[hero_id]->leave_guild();
  } else {
    return RC_BAD_INDEX;
  }
}
