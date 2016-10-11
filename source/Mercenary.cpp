#include "Mercenary.cpp"

size_t Mercenary::_id = SIZE_T_DEFAULT_VALUE;

Mercenary::Mercenary(const MercenaryTemplate& data, MercSpec& spec): _own_id(data._own_id), _name(data._name), _description(data._description), _level(START_LEVEL), _stats(data._stats), _spec(spec), _experience(data._experience), _personality(data._personality), _history(data._history), _equipment(data._equipment) {
  if (_own_id == FREE_ID) {
    _own_id = ++_id;
  } else {
    if (_id > _own_id) {
      _id = _own_id;
    }
  }
  if (data._level > _level) {
    _level = data._level;
  }
}

size_t Mercenary::get_merc_spec(MercSpec& result) const {
  result = _spec;
  return RC_OK;
}

size_t Mercenary::get_experience(std::vector<size_t>& result) const {
  result.clear();
  result = _experience;
  return RC_OK;
}

size_t Mercenary::get_experience(const size_t& index, size_t& result) const  {
  if (index < _experience.size()) {
    result = _experience[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::get_personality(std::vector<size_t>& result) const {
  result.clear();
  result = _personality;
  return RC_OK;
}

size_t Mercenary::get_personality(const size_t& index, size_t& result) const {
  if (index < _personality.size()) {
    result = _personality[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::get_history(std::vector<size_t>& result) const {
  result.clear();
  result = _history;
  return RC_OK;
}

size_t Mercenary::get_history(const size_t& index, size_t& result) const {
  if (index < _history.size()) {
    result = _history[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::get_equipment(Inventory& result) const {
  result = _equipment;
  return RC_OK;
}

size_t Mercenary::get_save_data(MercenaryTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear()
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  save_data._stats.clear();
  save_data._stats = _stats;
  save_data._spec_id = _spec.get_own_id;
  save_data._experience.clear();
  save_data._experience = _experience;
  save_data._personality.clear();
  save_data._personality = _personality;
  save_data._history.clear();
  save_data._history = _history;
  _equipment.get_save_data(save_data._equipment);
  return RC_OK;
}

size_t Mercenary::set_spec(MercSpec& value) {
  _spec = value;
  return RC_OK;
}

size_t Mercenary::set_experience(const std::vector<size_t>& value) {
  if (value.empty) {
    return RC_BAD_INPUT;
  }
  _experience.clear();
  _experience = value;
  return RC_OK;
}

size_t Mercenary::set_experience(const size_t& index, const size_t& value) {
  if (index < _experience.size()) {
    _experience[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::set_personality(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _personality.clear();
  _personality = value;
  return RC_OK;
}

size_t Mercenary::set_personality(const size_t& index, const size_t& value) {
  if (index < _personality.size()) {
    _personality[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::set_history(const std::vector<size_t>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _history.clear();
  _history = value;
  return RC_OK;
}

size_t Mercenary::set_history(const size_t& index, const size_t& value) {
  if (index < _history.size()) {
    _history[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Mercenary::what(std::string& result) const {
  result.clear();
  result += _name;
  result.append("        ");
  std::string buffer;
  buffer.clear();
  _spec.get_name(buffer);
  result += buffer;
  buffer.clear();
  result.append("\n\n");
  convert_to_string(_level, buffer);
  result += buffer;
  buffer.clear();
  result.append(" Level        ");
  convert_to_string(_experience[0], buffer);
  result += buffer;
  buffer.clear();
  result.append(" / ");
  convert_to_string(_experience[1], buffer);
  result += buffer;
  buffer.clear();
  result.append("Exp\n");
  result.append("\nStats:\n");
  std::vector<size_t> equipment_bonuses;
  _equipment.get_bonuses(equipment_bonuses);
  for (size_t i = 0; i < _stats.size(); ++i) {
    // some code here to add stat name (storage class needed)
    result.append(": ");
    buffer.clear();
    convert_to_string(_stats[i] + equipment_bonuses[i], buffer);
    result += buffer;
    buffer.clear();
    result.append(" (");
    convert_to_string(_stats[i], buffer);
    result += buffer;
    buffer.clear();
    convert_to_string(equipment_bonuses[i], buffer);
    result.append(" + ");
    result += buffer;
    buffer.clear();
    result.append(")\n");
  }
  result.apppend("History:\n");
  for (size_t i = 0; i < _history.size(); ++i) {
    // some code here to add history field's name (storage class needed)
    result.append(": ");
    buffer.clear();
    convert_to_string(_history[i], buffer);
    result += buffer;
    buffer.clear();
    result.append("\n");
  }
  return RC_OK;
}

size_t Mercenary::update() {
  return RC_OK;
}

size_t Mercenary::add_history(const size_t& index, const size_t& amount) {
  if (index < _history.size()) {
    _history[index] += amount;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}
