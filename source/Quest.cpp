#include "Quest.h"
#include "Hero.h"

size_t Quest::_id = SIZE_T_DEFAULT_VALUE;

Quest::Quest(QuestTemplate& data, Location& location): _own_id(data._own_id), _name(data._name), _description(data._description), _level(data._level), _employer_faction(data._employer_faction), _target_faction(data._target_faction), _phase(data._phase), _life_time(data._life_time), _birth_time(data._birth_time), _rewards(data._rewards), _bonuses(data._bonuses) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_own_id > _id) {
      _id = _own_id;
    }
  }
  for (size_t i = 0; i < data._mercs.size(); ++i) {
    Hero* new_hero = NULL;
    // some code here to get reference my merc's _onw_id
    _heroes.push_back(new_hero);
    new_hero = NULL;
  }
  for (size_t i = 0; i < data._enemies.size(); ++i) {
    Enemy* new_enemy = new Enemy(data._enemies[i]);
    _enemies.push_back(new_enemy);
    new_enemy = NULL;
  }
}

Quest::~Quest() {
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      _heroes[i]->remove_contract(this);
    }
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
}

size_t Quest::get_location(Location& result) {
  result = _location;
  return RC_OK;
}

size_t Quest::get_rewards(std::vector<size_t>& result) const {
  result.clear();
  result = _rewards;
  return RC_OK;
}

size_t Quest::get_rewards(const size_t& index, size_t& result) const {
  if (index < _rewards.size()) {
    result = _rewards[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_bonuses(std::vector<size_t>& result) const {
  result.clear();
  result = _bonuses;
  return RC_OK;
}

size_t Quest::get_bonuses(const size_t& index, size_t& result) const {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_heroes(std::vector<Hero*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _heroes;
    return RC_OK;
  }
}

size_t Quest::get_heroes(const size_t& index, Hero*& result) const {
  if (index < _heroes.size()) {
    if (result == NULL) {
      result = _heroes[index];
      return RC_OK;
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_enemies(std::vector<Enemy*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _enemies;
    return RC_OK;
  }
}

size_t Quest::get_enemies(const size_t& index, Enemy*& result) const {
  if (index < _enemies.size()) {
    if (result == NULL) {
      result = _enemies[index];
      return RC_OK;
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::get_save_data(QuestTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  save_data._location_id = _location.get_own_id();
  save_data._employer_faction = _employer_faction;
  save_data._target_faction = _target_faction;
  save_data._phase = _phase;
  save_data._life_time;
  save_data._birth_time;
  save_data._rewards.clear();
  save_data._rewards = _rewards;
  save_data._bonuses = _bonuses;
  save_data._heroes.clear();
  for (size_t i = 0; i < _heroes.size()) {
    if (_heroes[i] != NULL) {
      save_data._heroes.push_back(_heroes[i]->get_own_id());
    }
  }
  save_data._enemies.clear();
  for(size_t i = 0; i < _enemies.size()) {
    if (_enemies[i] = NULL) {
      EnemyTemplate to_add;
      _enemies[i]->get_save_data(to_add);
      save_data._enemies.push_back(to_add);
    }
  }
  return RC_OK;
}

size_t Quest::set_location(Location& value) {
  _location = value;
  return RC_OK;
}

size_t Quest::set_employer_faction(const size_t& value) {
  _employer_faction = value;
  return RC_OK;
}

size_t Quest::set_target_faction(const size_t& value) {
  _target_faction = value;
  return RC_OK;
}

size_t Quest::set_rewards(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _rewards.clear();
  _rewards = value;
  return RC_OK;
}

size_t Quest::set_rewards(const size_t& index, const size_t& value) {
  if (index < _rewards.size()) {
    _rewards[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_bonuses(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _bonuses.clear();
  _bonuses = value;
  return RC_OK;
}

size_t Quest::set_bonuses(const size_t& index, const size_t& value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_heroes(const std::vector<Hero*>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _heroes.clear();
  _heroes = value;
  return RC_OK;
}

size_t Quest::set_heroes(const size_t& index, const Hero*& value) {
  if (index < _heroes.size()) {
    if (value == NULL) {
      return RC_BAD_INPUT;
    }
    _heroes[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::set_enemies(const std::vector<Enemy*>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
  _enemies.clear();
  _enemies = value;
  return RC_OK;
}

size_t Quest::set_enemies(const size_t& index, const Enemy*& value) {
  if (index < _enemies.size()) {
    if (value == NULL) {
      return RC_BAD_INPUT;
    }
    if (_enemies[index] != NULL) {
      delete _enemies[index];
    }
    _enemies[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Quest::what(std::string& result) {
  result.clear();

  return RC_OK;
}

size_t Quest::update() {
  return RC_OK;
}

