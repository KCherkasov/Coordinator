#include "Hero.h"
#include "Player.h"

size_t Player::_id = SIZE_T_DEFAULT_VALUE;

// possibly it's worthy to add something like std::vector<Hero*> to the args. That arg'll contain 2-3 initial guild members. Or they'll be chosen from the main pool?
Player::Player(const std::string& name, const std:::string& description): _own_id(++_id), _name(name), _description(description), _level(START_LEVEL), _cash(START_CASH) {
  _experience.resize(PAIR_ARR_SIZE);
  _experience[0] = SIZE_T_DEFAULT_VALUE;
  _experience[1] = FIRST_LEVELUP_CAP;
  _history.resize(PH_SIZE);
  for (size_t i = 0; i < _history.size(); ++i) {
    _history[i] = SIZE_T_DEFAULT_VALUE;
  }
}

Player::Player(const PlayerTemplate& data, const std::vector<Hero*> heroes): _own_id(data._own_id), _name(data._name), _description(data._description), _level(data._level), _cash(data._cash), _experience(data._experience), _history(data._history) {
  if (_own_id == FREE_INDEX) {
    _own_id = ++_id;
  } else {
    if (_id < _own_id) {
      _id = _own_id;
    }
  }
  for (size_t i = 0; i < data._heroes.size(); ++i) {
    for (size_t j = 0; j < heroes.size(); ++j) {
      if (heroes[j] != NULL) {
        if (heroes[j]->get_own_id() == data._heroes[i]) {
          _heroes.push_back(heroes[j]);
          _heroes[_heroes.size() - 1]->enter_guild(this);
        }
      }
    }
  }
}

size_t Player::get_experience(std::vector<size_t>& result) const {
  result.clear();
  result = _experience;
  return RC_OK;
}

size_t Player::get_experience(const size_t& index, size_t& result) const {
  if (index < _experience.size()) {
    result = _experience[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::get_history(std::vector<size_t>& result) const {
  result.clear();
  result = _history;
  return RC_OK;
}

size_t Player::get_history(const size_t& index, size_t& result) const {
  if (index < _history.size()) {
    result = _history[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::get_heroes(std::vector<Hero*>& result) const {
  if (!result.empty()) {
    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = NULL;
    }
    result.clear();
  }
  result = _heroes;
  return RC_OK;
}

size_t Player::get_heroes(const size_t& index, Hero*& result) const {
  if (index < _heroes.size()) {
    result = _heroes[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::get_save_data(PlayerTemplate& result) const {
  return RC_OK;
}