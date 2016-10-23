#include "HeroClass.h"

size_t HeroArchetype::get_name(std::string& result) const {
  result.clear();
  result = _name;
  return RC_OK;
}

size_t HeroArchetype::get_description(std::string& result) const {
  result.clear();
  result = _description;
  return RC_OK;
}

size_t HeroArchetype::get_power_mods(std::vector<size_t>& result) const {
  result.clear();
  result = _power_mods;
  return RC_OK;
}

size_t HeroArchetype::get_power_mods(const size_t& index, size_t& result) {
  if (index < _power_mods.size()) {
    result = _power_mods[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroArchetype::set_name(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _name.clear();
  _name = value;
  return RC_OK;
}

size_t HeroArchetype::set_description(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _description.clear();
  _description = value;
  return RC_OK;
}

size_t HeroArchetype::set_power_mods(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _power_mods.clear();
  _power_mods = value;
  return RC_OK;
}

size_t HeroArchetype::set_power_mods(const size_t& index, const size_t& value) {
  if (index < _power_mods.size()) {
    _power_mods[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::get_name(std::string& result) const {
  result.clear();
  result = _name;
  return RC_OK;
}

size_t HeroClass::get_description(std::string& result) const {
  result.clear();
  result = _description;
  return RC_OK;
}

size_t HeroClass::get_power_mods(std::vector<size_t>& result) const {
  return _archetype.get_power_mods(result);
}

size_t HeroClass::get_power_mods(const size_t& index, size_t& result) const {
  return _archetype.get_power_mods(index, result);
}

size_t HeroClass::get_stat_bonuses(std::vector<size_t>& result) {
  result.clear();
  result = _stat_bonuses;
  return RC_OK;
}

size_t HeroClass::get_stat_bonuses(const size_t& index, size_t& result) {
  if (index < _stat_bonuses.size()) {
    result = _stat_bonuses[index];
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::set_name(const std::string& value) {
  if (!value.empty()) {
    _name.clear();
    _name = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t HeroClass::set_description(const std::string& value) {
  if (!value.empty()) {
    _description.clear();
    _description = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t HeroClass::set_stat_bonuses(const std::vector<size_t>& value) {
  if (value.size() == SI_SIZE) {
    _stat_bonuses.clear();
    _stat_bonuses = value;
    return RC_OK;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t HeroClass::set_stat_bonuses(const size_t& index, const size_t& value) {
  if (index < _stat_bonuses.size()) {
    _stat_bonuses[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}


size_t HeroClass::what(std::string& result) const {
  result.clear();
  std::string buffer;
  result += _name;
  result.append(" class (");
  _archetype.get_name(buffer);
  result += buffer;
  result.append("):\n");
  result.append("---------------------\n");
  result.append("stats bonuses:\n");
  for (size_t i = 0; i < _power_mods.size(); ++i) {
    buffer.clear();
    TextStorage::get_hero_stat_name(i, buffer);
    result += buffer;
    result.append(": ");
    buffer.clear();
    convert_to_string<size_t>(_stat_bonuses[i], buffer);
    result += buffer;
    result.append("\n");
  }
  result.append("\n\"");
  result += _description;
  result.append("\"\n");
  return RC_OK;
}

size_t HeroClass::short_what(std::string& result) {
  result.clear();
  std::string buffer;
  result += _name;
  result.append(" class (");
  _archetype.get_name(buffer);
  result += buffer;
  result.append("):\n");
  return RC_OK;
}
