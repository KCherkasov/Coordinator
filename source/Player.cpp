#include "Hero.h"
#include "Player.h"

size_t Player::_id = SIZE_T_DEFAULT_VALUE;

// possibly it's worthy to add something like std::vector<Hero*> to the args. That arg'll contain 2-3 initial guild members. Or they'll be chosen from the main pool?
Player::Player(const std::string& name, const std:::string& description): _own_id(++_id), _name(name), _description(description), _to_delete(false), _level(START_LEVEL), _cash(START_CASH) {
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

size_t Player::level_up() {
  return RC_OK;
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

size_t Player::get_free_heroes.count() {
  size_t free_heroes = SIZE_T_DEFAULT_VALUE;
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      if (_heroes[i]->get_quest() == NULL) {
        ++free_heroes;
      }
    }
  }
  return free_heroes;
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
  result._own_id = _own_id;
  result._name.clear();
  result._name = _name;
  result._description.clear();
  result._description = _description();
  result._level = _level;
  result._cash = _cash;
  result._experience.clear();
  result._experience = _experience;
  result._history.clear();
  result._history = _history;
  result._heroes.clear();
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (_heroes[i] != NULL) {
      result._heroes.push_back(_heroes[i]->get_own_id());
    }
  }
  return RC_OK;
}

size_t Player::what(std::string& result) const {
  result.clear();
  std::string buffer;
  buffer.clear();
  result.append("Guild name: ");
  result += _name;
  result.append(" ");
  convert_to_string(_level, buffer);
  buffer.append(" level (");
  result += buffer;
  buffer.clear();
  convert_to_string(_experience[0], buffer);
  buffer.append("/");
  result += buffer;
  buffer.clear();
  convert_to_string(_experience[1], buffer);
  buffer.append ("Exp)\nHeroes in the guild: ");
  result += buffer;
  buffer.clear();
  convert_to_string(_heroes.size(), buffer);
  buffer.append("\n\nGuild statistics:\n");
  result += buffer;
  buffer.clear();
  for (size_t i = 0; i < PH_SIZE; ++i) {
    _dictionary->get_player_history_name(i, buffer);
   buffer.append(": ");
   result += buffer;
   buffer.clear();
   convert_to_string(_history[i], buffer);
   buffer.append("\n");
   result += buffer;
   buffer.clear();
  }
  buffer.clear();
  return RC_OK;
};

size_t Player::short_what(std::string& result) const {
  result.clear();
  std::string buffer;
  buffer.clear();
  result.append("Guild name: ");
  result += _name;
  result.append(" ");
  convert_to_string(_level, buffer);
  buffer.append(" level\n");
  result += buffer;
  buffer.clear();
  convert_to_string(_heroes.size(), buffer);
  buffer.append(" heroes in the guild.\n");
  result += buffer;
  buffer.clear();
  return RC_OK;
}

size_t Player::update() {
  if (_experience[0] >= _experience[1]) {
    level_up();
  }
  return RC_OK;
}

size_t Player::set_cash(const size_t& value) {
  _cash = value;
  return RC_OK;
}

size_t Player::set_experience(const std::vector<size_t>& result) {
  if (value.empty()) {
    return RC_EMPTY_VECTOR;
  }
  _experience.clear();
  _experience = value;
  return RC_OK;
}

size_t Player::set_experience(const size_t& index, const size_t& value) {
  if (index < _experience.size()) {
    _experience[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::set_history(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_EMPTY_VECTOR;
  }
  _history.clear();
  _history = value;
  return RC_OK;
}

size_t Player::set_history(const size_t& index, const size_t& value) {
  if (index < _history.size()) {
    _history[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::add_hero(Hero* to_add) {
  if (_heroes.size() >= START_HEROES_CAP) {
    return RC_GUILD_IS_FULL;
  }
  if (to_add == NULL) {
    return RC_BAD_INPUT;
  }
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (to_add == _heroes[i]) {
      return RC_ALREADY_HIRED;
    }
  }
  _heroes.push_back(to_add);
  return RC_OK;
}

size_t Player::remove_hero(const size_t& index) {
  if (index < _heroes.size()) {
    _heroes.erase(_heroes.begin() + index);
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::remove_hero(Hero* to_remove) {
  for (size_t i = 0; i < _heroes.size(); ++i) {
    if (to_remove == _heroes[i]) {
      _heroes.erase(_heroes.begin() + i);
      return RC_OK;
    }
  }
  return RC_NOT_FOUND;
}

size_t Player::add_cash(const size_t& amount) {
  _cash += amount;
  return RC_OK;
}

size_t Player::remove_cash(const size_t& amount) {
  if (_cash >= amount) {
    _cash -= amount;
  } else {
    _cash = SIZE_T_DEFAULT_VALUE;
  }
  return RC_OK;
}

size_t Player::add_experience(const size_t& amount) {
  if (_experience.empty()) {
    return RC_EMPTY_VECTOR;
  }
  _experience[0] += amount;
  return RC_OK;
}

size_t Player::remove_experience(const size_t& amount) {
  if (_experience.empty()) {
    return RC_EMPTY_VECTOR;
  }
  if (_experience[0] >= amount) {
    _experience[0] -= amount;
  } else {
    _experience[0] = SIZE_T_DEFAULT_VALUE;
  }
  return RC_OK;
}

size_t Player::add_history(const size_t& index, const size_t& amount) {
  if (index < _history.size()) {
    _history[index] += amount;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Player::remove_history(const size_t& index, const size_t& amount) {
  if (index < _history.size()) {
    if (_history[index] >= amount) {
      _history[index] -= amount;
    } else {
      _history[index] = SIZE_T_DEFAULT_VALUE;
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

