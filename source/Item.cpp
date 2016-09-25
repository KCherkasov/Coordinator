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
  _bonuses.clear();
  _bonuses = table._bonuses;
  if (_bonuses.size() != TS_SIZE) {
    _bonuses.clear();
    _bonuses.resize(TS_SIZE);
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

size_t Item::get_bonuses(std::vector<size_t>& result) {
  result.clear();
  result = _bonuses;
  return RC_OK;
}

size_t Item::get_bonuses(const size_t& index, size_t& result) {
  if (index < _bonuses.size()) {
    result = _bonuses[index];
    return RC_OK;
  } else {
    result = SIZE_T_DEFAULT_VALUE;
    return RC_BAD_INDEX;
  }
}

size_t Item::get_slots(std::vector<bool>& result) {
  result.clear();
  result = _slots;
  return RC_OK;
}

size_t Item::get_slots(const size_t& index, bool& result) {
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
  if (value.size() == TS_SIZE) {
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

size_t Item::what(std::string& result) {
  result.clear();
  
  return RC_OK;
}

size_t Item::update() {
  return RC_OK;
}
