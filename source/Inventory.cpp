#include "Inventory.h"

Inventory::Inventory(InventoryTemplate& table) {
  for (size_t i = 0; i < table._equipment.size(); ++i) {
    Item* to_add = NULL;
    // some code here to not to spawn anything in empty slots
    to_add = new Item(table._equipment[i]);
    _equipment.push_back(to_add);
    to_add = NULL;
  }
}

Inventory::~Inventory() {
  for (size_t i = 0; i < _equipment.size(); ++i) {
    if (_equipment[i] != NULL) {
      delete _equipment[i];
    }
  }
}

size_t Inventory::get_equipment(std::vector<Item*>& result) const {
  for (size_t i = 0; i < result.size(); ++i) {
    if (result[i] != NULL) {
      delete result[i];
    }
  }
  result.clear();
  result = _equipment;
  return RC_OK;
}

size_t Inventory::get_equipment(const size_t& index, Item*& result) const {
  if (index < _equipment.size()) {
    if (result != NULL) {
      delete result;
    }
    result = _equipment[index];
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Inventory::get_bonuses(std::vector<size_t>& result) const {
  result.clear();
  for (size_t i = 0; i < SI_SIZE; ++i) {
    result.push_back(SIZE_T_DEFAULT_VALUE);
  }
  std::vector<size_t> item_bonuses;
  for (size_t i = 0; i < _equipment.size(); ++i) {
    item_bonuses.clear();
    if (_equipment[i] != NULL) {
      _equipment[i]->get_bonuses(item_bonuses);
      for (size_t j = 0; j < result.size(); ++j) {
        result[j] += item_bonuses[j];
      }
    }
  }
  return RC_OK;
}

size_t Inventory::get_bonuses(const size_t& index, size_t& result) const {
  if (index < SI_SIZE) {
    result = SIZE_T_DEFAULT_VALUE;
    for (size_t i = 0; i < _equipment.size(); ++i) {
      if (_equipment[i] != NULL) {
        size_t item_bonus = SIZE_T_DEFAULT_VALUE;
        _equipment[i]->get_bonuses(index, item_bonus);
        result += item_bonus;
      }
    }
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Inventory::set_equipment(const std::vector<Item*>& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  if (value.size() != IS_SIZE) {
    return RC_BAD_SIZE;
  }
  for (size_t i = 0; i < _equipment.size(); ++i) {
    if (_equipment[i] != NULL) {
      delete _equipment[i];
    }
  }
  _equipment.clear();
  _equipment = value;
  return RC_OK;
}

size_t Inventory::set_equipment(const size_t& index, Item*& value, bool if_swap) {
  if (index < _equipment.size()) {
    if (!if_swap) {
      if (_equipment[index] != NULL) {
        delete _equipment[index];
      }
    }
    Item* buffer = _equipment[index];
    _equipment[index] = value;
    value = buffer;
    return RC_OK;
  } else {
    return RC_BAD_INDEX;
  }
}

size_t Inventory::get_save_data(InventoryTemplate& result) const {
  result._equipment.clear();
  for (size_t i = 0; i < _equipment.size(); ++i) {
    if (_equipment[i] != NULL) {
      ItemTemplate table;
      _equipment[i]->get_save_data(table);
      result._equipment.push_back(table);
    } else {
      // code here to place something if slot is empty
    }
  }
  return RC_OK;
}

size_t Inventory::what(std::string& result) const {
  result.clear();
  return RC_OK;
}

