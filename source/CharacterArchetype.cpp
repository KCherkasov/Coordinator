#include "CharacterArchetype.h"

size_t CharacterArchetype::get_name(std::string& result) const {
  result.clear();
  result = _name;
  return RC_OK;
}

size_t CharacterArchetype::get_description(std::string& result) const {
  result.clear();
  result = _description;
  return RC_OK;
}

size_t CharacterArchetype::get_power_mods(std::vector<size_t>& result) const {
  result.clear();
  result = _power_mods;
  return RC_OK;
}

size_t CharacterArchetype::get_power_mods(const size_t& index, size_t& result) const {
  if (index < _power_mods.size()) {
    result = _power_mods[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t CharacterArchetype::get_defense_mods(std::vector<size_t>& result) const {
  result.clear();
  result = _defense_mods;
  return RC_OK;
}

size_t CharacterArchetype::get_defense_mods(const size_t& index, size_t& result) const {
  if (index < _defense_mods.size()) {
    result = _defense_mods[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t CharacterArchetype::set_dictionary(TextStorage* value) {
  if (value == NULL) {
    return RC_BAD_INPUT;
  }
  _dictionary = value;
  return RC_OK;
}

size_t CharacterArchetype::set_name(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _name.clear();
  _name = value;
  return RC_OK;
}

size_t CharacterArchetype::set_description(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _description.clear();
  _description = value;
  return RC_OK;
}

size_t CharacterArchetype::set_power_mods(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _power_mods.clear();
  _power_mods = value;
  return RC_OK;
}

size_t CharacterArchetype::set_power_mods(const size_t& index, const size_t& value) {
  if (index < _power_mods.size()) {
    _power_mods[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t CharacterArchetype::set_defense_mods(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _defense_mods.clear();
  _defense_mods = value;
  return RC_OK;
}

size_t CharacterArchetype::set_defense_mods(const size_t& index, const size_t& value) {
  if (index < _defense_mods.size()) {
    _defense_mods[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t CharacterArchetype::what(std::string& result) const {
  result.clear();
  result += _name;
  result.append("\t(archetype):\n");
  result.append("-----------------\n");
  std::string buffer;
  buffer.clear();
  for (size_t i = 0; i < _power_mods.size(); ++i) {
    _dictionary->get_stat_name(i, buffer);
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string<size_t>(_power_mods[i], buffer);
    buffer.append("\n");
    result += buffer;
  }
  for (size_t i = 0; i < _defense_mods.size(); ++i) {
    _dictionary->get_stat_name(i, buffer);
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string<size_t>(_defense_mods[i], buffer);
    buffer.append("\n");
    result += buffer;
  }
  result.append("-----------------\n\"");
  result += description;
  result.append("\"\n");
  return RC_OK;
}

size_t CharacterArchetype::get_short_what(std::string& result) const {
  result.clear();
  result += _name;
  result.append("\n");
  return RC_OK;
}
