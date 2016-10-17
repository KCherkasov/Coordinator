#include "Contract.h"

size_t Contract::_id = SIZE_T_DEFAULT_VALUE;

Contract::Contract(ContractTemplate& data, Location& location): _own_id(data._own_id), _name(data._name), _description(data._description), _level(data._level), _employer_faction(data._employer_faction), _target_faction(data._target_faction), _phase(data._phase), _life_time(data._life_time), _birth_time(data._birth_time), _rewards(data._rewards), _bonuses(data._bonuses) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_own_id > _id) {
      _id = _own_id;
    }
  }
  for (size_t i = 0; i < data._mercs.size(); ++i) {
    Mercenary* new_merc = new Mercenary(data._mercs[i], /* some code here to receive merc spec by spec_id */);
    _merc.push_back(new_merc);
    new_merc = NULL;
  }
  for (size_t i = 0; i < data._enemies.size(); ++i) {
    Enemy* new_enemy = new Enemy(data._enemies[i]);
    _enemies.push_back(new_enemy);
    new_enemy = NULL;
  }
}

Contract::~Contract() {
  for (size_t i = 0; i < _mercs.size(); ++i) {
    if (_mercs[i] != NULL) {
      delete _mercs[i];
    }
  }
  for (size_t i = 0; i < _enemies.size(); ++i) {
    if (_enemies[i] != NULL) {
      delete _enemies[i];
    }
  }
}

size_t Contract::get_location(Location& result) {
  result = _location;
  return RC_OK;
}

size_t Contract::get_rewards(std::vector<size_t>& result) const {
  result.clear();
  result = _rewards;
  return RC_OK;
}

size_t Contract::get_rewards(const size_t& index, size_t& result) const {
  if (index < _rewards.size()) {
    result = _rewards[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Contract::get_bonuses(std::vector<size_t>& result) const {
  result.clear();
  result = _bonuses;
  return RC_OK;
}

size_t Contract::get_bonuses(const size_t& index, size_t& result) const {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Contract::get_mercs(std::vector<Mercenary*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _mercs;
    return RC_OK;
  }
}

size_t Contract::get_mercs(const size_t& index, Mercenary*& result) const {
  if (index < _mercs.size()) {
    if (result == NULL) {
      result = _mercs[index];
      return RC_OK;
    } else {
      return RC_BAD_INPUT;
    }
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Contract::get_enemies(std::vector<Enemy*>& result) const {
  if (!result.empty()) {
    return RC_BAD_INPUT;
  } else {
    result = _enemies;
    return RC_OK;
  }
}

size_t Contract::get_enemies(const size_t& index, Enemy*& result) const {
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

size_t Contract::get_save_data(ContractTemplate& save_data) const {

  return RC_OK;
}
