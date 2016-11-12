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
  return _archetype.get_power_mods(result);
}

size_t HeroClass::get_power_mods(const size_t& index, size_t& result) const {
  return _archetype.get_power_mods(index, result);
}

size_t HeroClass::get_defense_mods(std::vector<size_t>& result) const {
  return _archetype.get_defense_mods(result);
}

size_t HeroClass::get_defense_mods(const size_t& index, size_t& result) const {
  return _archetype.get_defense_mods(index, result);
}

size_t HeroClass::get_stat_bonuses(std::vector<size_t>& result) const {
  result.clear();
  result = _stat_bonuses;
  return RC_OK;
}

size_t HeroClass::get_stat_bonuses(const size_t& index, size_t& result) const {
  if (index < _stat_bonuses.size()) {
    result = _stat_bonuses[index];
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::get_att_power_modifiers(std::vector<size_t>& result) const {
  result.clear();
  result = _att_power_modifiers;
  return RC_OK;
}

size_t HeroClass::get_att_power_modifiers(const size_t& index, size_t& result) const {
  if (index < _att_power_modifiers.size()) {
    result = _att_power_modifiers[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::get_defense_modifiers(std::vector<size_t>& result) const {
  result.clear();
  result = _defense_modifiers;
  return RC_OK;
}

size_t HeroClass::get_defense_modifiers(const size_t& index, size_t& result) const {
  if (index < _defense_modifiers.size()) {
    result = _defense_modifiers[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::set_dictionary(TextStorage* value) {
  if (value == NULL) {
    return RC_BAD_INPUT;
  }
  _dictionary = value;
  return RC_OK;
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

size_t HeroClass::set_att_power_modifiers(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _att_power_modifiers.clear();
  _att_power_modifiers = value;
  return RC_OK;
}

size_t HeroClass::set_att_power_modifiers(const size_t& index, const size_t& value) {
  if (index < _att_power_modifiers.size()) {
    _att_power_modifiers[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t HeroClass::set_defense_modifiers(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _defense_modifiers.clear();
  _defense_modifiers = value;
  return RC_OK;
}

size_t HeroClass::set_defense_modifiers(const size_t& index, const size_t& value) {
  if (index < _defense_modifiers.size()) {
    _defense_modifiers[index] = value;
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
  result.append("Stat bonuses:\n");
  for (size_t i = 0; i < _stat_bonuses.size(); ++i) {
    buffer.clear();
    _dictionary->get_stat_name(i, buffer);
    result += buffer;
    result.append(": ");
    buffer.clear();
    convert_to_string<size_t>(_stat_bonuses[i], buffer);
    result += buffer;
    result.append("\n");
  }
  result.append("\nAttack power modifiers:\n");
  for (size_t i = 0; i < _att_power_modifiers.size(); ++i) {
    buffer.clear();
    result.append("vs. ");
    // some code here to retrieve the archetype name
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string(_att_power_modifiers[i], buffer);
    buffer.append("\%\n");
    result += buffer;
    buffer.clear();
  }
  buffer.clear();
  result.append("\nDefense modifiers:\n");
  for (size_t i = 0; i < _defense_modifiers.size(); ++i) {
    buffer.clear();
    result.append("vs. ");
    // some code here to retrieve the archetype name
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string(_defense_modifiers[i], buffer);
    buffer.append("\%\n");
    result += buffer;
    buffer.clear();
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
  result.append(")\n");
  return RC_OK;
}
