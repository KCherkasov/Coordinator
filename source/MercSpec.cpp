#include "HeroClass.h"

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
  result.clear();
  result = _power_mods;
  return RC_OK;
}

size_t HeroClass::get_power_mods(const size_t& index, size_t& result) const {
  if (index < _power_mods.size()) {
    result = _power_mods[index];
    return RC_OK;
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

size_t HeroClass::set_power_mods(const std::vector<size_t>& value) {
  if (value.size() == SI_SIZE) {
    _power_mods.clear();
    _power_mods = value;
    return RC_OK;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t HeroClass::set_power_mods(const size_t& index, const size_t& value) {
  if (index < _power_mods.size()) {
    _power_mods[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}


size_t HeroClass::what(std::string& result) const {
  result.clear();
  result += _name;
  result.append(" class:\n");
  result.append("---------------------\n");
  result.append("\n\"");
  result += _description;
  result.append("\"\n");
  result.append("stats power mods:\n");
  for (size_t i = 0; i < _power_mods.size(); ++i) {
    std::string buffer;
    buffer.clear();
    TextStorage::get_hero_stat_name(i, buffer);
    result += buffer;
    result.append(": ");
    buffer.clear();
    convert_to_string<size_t>(_power_mods[i], buffer);
    result += buffer;
    result.append("\n");
  }
  return RC_OK;
}

