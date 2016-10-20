#include "Contract.h"
#include "Mercenary.h"

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
    Mercenary* new_merc = NULL;
    // some code here to get reference my merc's _onw_id
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
      _mercs[i]->remove_contract(this);
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
  save_data._mercs.clear();
  for (size_t i = 0; i < _mercs.size()) {
    if (_mercs[i] != NULL) {
      save_data._mercs.push_back(_mercs[i]->get_own_id());
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

size_t Contract::set_location(Location& value) {
  _location = value;
  return RC_OK;
}

size_t Contract::set_employer_faction(const size_t& value) {
  _employer_faction = value;
  return RC_OK;
}

size_t Contract::set_target_faction(const size_t& value) {
  _target_faction = value;
  return RC_OK;
}

size_t Contract::set_rewards(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _rewards.clear();
  _rewards = value;
  return RC_OK;
}

size_t Contract::set_rewards(const size_t& index, const size_t& value) {
  if (index < _rewards.size()) {
    _rewards[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Contract::set_bonuses(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _bonuses.clear();
  _bonuses = value;
  return RC_OK;
}

size_t Contract::set_bonuses(const size_t& index, const size_t& value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}
