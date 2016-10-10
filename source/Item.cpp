#include "Item.h"

size_t Item::_id = FREE_ID;

Item::Item(const ItemTemplate& table, const size_t& level, const size_t& owner_id, const size_t& rarity) {
  if (table._own_id > FREE_ID) {
    _own_id = table._own_id;
    if (_id < _own_id) {
      _id = _own_id;
    }
  } else {
    _own_id = ++_id;
  }
  _name.clear();
  _name = table._name;
  _description.clear();
  _description = table._description;
  if (level > START_LEVEL) {
    _level = level;
  } else {
    _level = table._level;
  }
  if (owner_id > FREE_ID) {
    _owner_id = owner_id;
  } else {
    _owner_id = table._owner_id;
  }
  if (rarity != IR_COMMON) {
    _rarity = rarity;
  } else {
    _rarity = table._rarity;
  }
  _kind = table._kind;
  _price = table._price;
  _bonuses.clear();
  _bonuses = table._bonuses;
  if (_bonuses.size() != SI_SIZE) {
    _bonuses.clear();
    _bonuses.resize(SI_SIZE);
    for (size_t i = 0; i < _bonuses.size(); ++i) {
      _bonuses[i] = SIZE_T_DEFAULT_VALUE;
    }
  }
  _slots.clear();
  _slots = table._slots;
  if (_slots.size() != IS_SIZE) {
    _slots.clear();
    _slots.resize(IS_SIZE);
    for (size_t i = 0; i < _slots.size(); ++i) {
      _slots[i] = false;
    }
  }
}

size_t Item::level_up() {
  size_t points = POINTS_PER_LEVEL * (_level - START_LEVEL);
  while (points > SIZE_T_DEFAULT_VALUE) {
    size_t roll = roll_dice(_bonuses.size());
    if (_kind != IK_GEAR && roll == SI_ENDURANCE) {
      continue;
    }
    ++_bonuses[roll];
    --points;
  }
  return RC_OK;
}

size_t Item::get_bonuses(std::vector<size_t>& result) const {
  result.clear();
  result = _bonuses;
  return RC_OK;
}

size_t Item::get_bonuses(const size_t& index, size_t& result) const {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
    return RC_OK;
  } else {
    result = SIZE_T_DEFAULT_VALUE;
    return RC_BAD_INDEX;
  }
}

size_t Item::get_slots(std::vector<bool>& result) const {
  result.clear();
  result = _slots;
  return RC_OK;
}

size_t Item::get_slots(const size_t& index, bool& result) const {
  if (index < _slots.size()) {
    result = _slots[index];
    return RC_OK;
  } else {
    result = BOOL_DEFAULT_VALUE;
    return RC_BAD_INDEX;
  }
}

size_t Item::set_owner_id(const size_t& value) {
  _owner_id = value;
  return RC_OK;
}

size_t Item::set_rarity(const size_t& value) {
  if (value < IR_SIZE) {
    _rarity = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t Item::set_kind(const size_t& value) {
  if (value < IK_SIZE) {
    _kind = value;
    return RC_OK;
  } else {
    return RC_BAD_INPUT;
  }
}

size_t Item::set_price(const size_t& value) {
  _price = value;
  return RC_OK;
}

size_t Item::set_bonuses(const std::vector<size_t>& value) {
  if (value.size() == SI_SIZE) {
    _bonuses.clear();
    _bonuses = value;
    return RC_OK;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t Item::set_bonuses(const size_t& index, const size_t& value) {
  if (index < _bonuses.size()) {
    _bonuses[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Item::set_slots(const std::vector<bool>& value) {
  if (value.size() == IS_SIZE) {
    _slots.clear();
    _slots = value;
    return RC_OK;
  } else {
    return RC_BAD_SIZE;
  }
}

size_t Item::set_slots(const size_t& index, const bool& value) {
  if (index < _slots.size()) {
    _slots[index] = value;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Item::get_save_data(ItemTemplate& save_data) const {
  save_data._own_id = _own_id;
  save_data._name.clear();
  save_data._name = _name;
  save_data._description.clear();
  save_data._description = _description;
  save_data._level = _level;
  save_data._owner_id = _owner_id;
  save_data._rarity = _rarity;
  save_data._kind = _kind;
  save_data._price = _price;
  save_data._bonuses.clear();
  save_data._bonuses = _bonuses;
  save_data._slots.clear();
  save_data._slots = _slots;
  return RC_OK;
}

size_t Item::what(std::string& result) const {
  size_t dashes_string = 0;
  result.clear();
  result += _name;
  result.append("\n");
  std::string buffer;
  buffer.clear();
  buffer.append("<");
  for (size_t i = 0; i < _name.size() - 2; ++i) {
    buffer.append("-");
    ++dashes_string;
  }
  buffer.append(">\n");
  result += buffer;
  buffer.clear();
  TextStorage::get_item_rarity_name(_rarity, buffer);
  result += buffer;
  buffer.clear();
  result.append("\t");
  TextStorage::get_item_kind_name(_kind, buffer);
  result += buffer;
  buffer.clear();
  result.append("\n");
  result.append("price: ");
  convert_to_string<size_t>(_price, buffer);
  result += buffer;
  buffer.clear();
  result.append("\nStats:\n------\n");
  for (size_t i = 0; i < _bonuses.size(); ++i) {
    TextStorage::get_item_stat_name(i, buffer);
    buffer.append(": ");
    result += buffer;
    buffer.clear();
    convert_to_string<size_t>(_bonuses[i], buffer);
    result += buffer;
    result.append("\n");
    buffer.clear();
  }
  result.append("------\n\"");
  result += _description;
  result.append("\"");
  return RC_OK;
}

size_t Item::update() {
  return RC_OK;
}
